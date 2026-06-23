import rclpy
from rclpy.node import Node
from px4_msgs.msg import VehicleOdometry, VehicleAttitude, VehicleLocalPosition
from geometry_msgs.msg import PoseStamped, TwistStamped
from nav_msgs.msg import Odometry
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy, QoSDurabilityPolicy
import socket, re
import numpy as np

class MyPublisher(Node):
    def __init__(self):
        super().__init__('vehicle_mocap_odom')
        namespace = self.declare_parameter('namespace', '').value
        if namespace == '':
            namespace = socket.gethostname()
            namespace = re.sub(r'[^a-zA-Z0-9_~{}]', '_', namespace)        
        
        # QoS profiles
        qos_profile_pub = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            durability=QoSDurabilityPolicy.TRANSIENT_LOCAL,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=0
        )

        qos_profile_sub = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            durability=QoSDurabilityPolicy.VOLATILE,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=0
        )

        self.publisher_ = self.create_publisher(VehicleOdometry,
            f"/{namespace}/fmu/in/vehicle_visual_odometry",
            qos_profile_pub
        )
        self.vehicle_pose_pub = self.create_publisher(
            PoseStamped,
            f"/{namespace}/mocap_log/vehicle_pose",
            10
        )
        
        self.odom_sub = self.create_subscription(Odometry,
            f"/{namespace}/odom",
            self.odom_cb,
            10
        )
        self.attitude_sub = self.create_subscription(
            VehicleAttitude,
            f"/{namespace}/fmu/out/vehicle_attitude",
            self.vehicle_attitude_callback,
            qos_profile_sub,
        )
        self.local_position_sub = self.create_subscription(
            VehicleLocalPosition,
            f"/{namespace}/fmu/out/vehicle_local_position",
            self.vehicle_local_position_callback,
            qos_profile_sub
        )

        timer_period = 0.01  # seconds
        self.got_odom = False
        self.pose = PoseStamped()
        self.twist = TwistStamped()
        self.odom = Odometry()
        self.vehicle_attitude = np.array([1.0, 0.0, 0.0, 0.0])
        self.vehicle_local_position = np.array([0.0, 0.0, 0.0])
        self.vehicle_local_velocity = np.array([0.0, 0.0, 0.0])
        self.timer = self.create_timer(timer_period, self.publish_message)

    def publish_message(self):
        if self.got_odom:
            msg = VehicleOdometry()

            # Set time
            time_us = int(self.get_clock().now().nanoseconds / 1000)
            msg.timestamp = time_us 
            msg.timestamp_sample = time_us

            # Build the message
            # Here we convert frames from mocap's /odom to PX4's /vehicle_visual_odometry
            
            # Set the frames
            msg.pose_frame = VehicleOdometry.POSE_FRAME_NED
            msg.velocity_frame = VehicleOdometry.VELOCITY_FRAME_BODY_FRD
            
            # Position in global NED frame
            msg.position = [self.pose.position.y, self.pose.position.x, -self.pose.position.z]
            
            # Quaternion (qw, qx, qy, qz) as body FRD frame to global ENU frame
            q_ned = self.q_enu_to_q_ned([self.pose.orientation.w, self.pose.orientation.x, self.pose.orientation.y, self.pose.orientation.z])
            msg.q = [q_ned[0], q_ned[1], q_ned[2], q_ned[3]]

            # Velocity in body FRD frame
            msg.velocity = [self.twist.linear.x, -self.twist.linear.y, -self.twist.linear.z]

            # Angular velocity in body FRD frame
            msg.angular_velocity = [self.twist.angular.x, -self.twist.angular.y, -self.twist.angular.z]

            self.publisher_.publish(msg)

            # Log vehicle local position
            vehicle_pose_msg = self.vector2PoseMsg(
                "mocap", self.vehicle_local_position, self.vehicle_attitude
            )
            self.vehicle_pose_pub.publish(vehicle_pose_msg)

    def odom_cb(self, msg: Odometry):
        # Receives odom message from mocap
        # Position is in global ENU frame
        # Quaternion (qw, qx, qy, qz) is in body FLU frame to global ENU frame
        # Velocity is in body FLU frame
        # Angular velocity is in body FLU frame
        self.pose = msg.pose.pose
        self.twist = msg.twist.twist
        self.got_odom = True

    def vehicle_attitude_callback(self, msg):
        # Receives quaternion in NED frame as (qw, qx, qy, qz) as body frame to global frame
        q_ned = np.array([msg.q[0], msg.q[1], msg.q[2], msg.q[3]])
        q_enu = self.q_ned_to_q_enu(q_ned)
        self.vehicle_attitude = q_enu

    def q_ned_to_q_enu(self, q_ned):
        # Convert NED quaternion to ENU quaternion
        # q is in the form (qw, qx, qy, qz) and describes the rotation from body frame to global frame
        # Yes, NED <-> ENU  is symmetric
        q_enu = 1/np.sqrt(2) * np.array([q_ned[0] + q_ned[3], q_ned[1] + q_ned[2], q_ned[1] - q_ned[2], q_ned[0] - q_ned[3]])
        q_enu /= np.linalg.norm(q_enu)
        return q_enu.astype(float)
    
    def q_enu_to_q_ned(self, q_enu):
        # Convert ENU quaternion to NED quaternion
        # q is in the form (qw, qx, qy, qz) and describes the rotation from body frame to global frame
        # Yes, NED <-> ENU  is symmetric
        q_ned = 1/np.sqrt(2) * np.array([q_enu[0] + q_enu[3], q_enu[1] + q_enu[2], q_enu[1] - q_enu[2], q_enu[0] - q_enu[3]])
        q_ned /= np.linalg.norm(q_ned)
        return q_ned.astype(float)

    def vehicle_local_position_callback(self, msg):
        # NED-> ENU transformation
        # Vehicle Local Position and Vehicle Local Velocity are in global NED frame
        self.vehicle_local_position[0] = msg.y
        self.vehicle_local_position[1] = msg.x
        self.vehicle_local_position[2] = -msg.z
        self.vehicle_local_velocity[0] = msg.vy
        self.vehicle_local_velocity[1] = msg.vx
        self.vehicle_local_velocity[2] = -msg.vz

    def vector2PoseMsg(self, frame_id, position, attitude):
        pose_msg = PoseStamped()
        pose_msg.header.stamp = self.get_clock().now().to_msg()
        pose_msg.header.frame_id = frame_id
        pose_msg.pose.orientation.w = attitude[0]
        pose_msg.pose.orientation.x = attitude[1]
        pose_msg.pose.orientation.y = attitude[2]
        pose_msg.pose.orientation.z = attitude[3]
        pose_msg.pose.position.x = float(position[0])
        pose_msg.pose.position.y = float(position[1])
        pose_msg.pose.position.z = float(position[2])
        return pose_msg

def main(args=None):
    rclpy.init(args=args)

    my_publisher = MyPublisher()

    rclpy.spin(my_publisher)

    my_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
