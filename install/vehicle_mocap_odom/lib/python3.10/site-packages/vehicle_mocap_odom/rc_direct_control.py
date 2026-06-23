import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy, QoSDurabilityPolicy
from px4_msgs.msg import ManualControlInput, ActuatorMotors, OffboardControlMode
import socket
import re

THRESHOLD = 0.1


class RCDirectControl(Node):
    def __init__(self):
        super().__init__('rc_direct_control')

        namespace = self.declare_parameter('namespace', '').value
        if namespace == '':
            namespace = socket.gethostname()
            namespace = re.sub(r'[^a-zA-Z0-9_~{}]', '_', namespace)

        self.get_logger().info(f'Namespace: {namespace}')

        qos_pub = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            durability=QoSDurabilityPolicy.TRANSIENT_LOCAL,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=1
        )
        qos_sub = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            durability=QoSDurabilityPolicy.VOLATILE,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=1
        )

        self.actuator_pub = self.create_publisher(
            ActuatorMotors,
            f'/{namespace}/fmu/in/actuator_motors',
            qos_pub
        )
        self.offboard_pub = self.create_publisher(
            OffboardControlMode,
            f'/{namespace}/fmu/in/offboard_control_mode',
            qos_pub
        )
        self.rc_sub = self.create_subscription(
            ManualControlInput,
            f'/{namespace}/fmu/out/manual_control_input',
            self.rc_callback,
            qos_sub
        )

        self.roll = 0.0
        self.pitch = 0.0
        self.yaw = 0.0
        self.throttle = 0.0

        self.create_timer(0.05, self.publish)  # 20 Hz

    def rc_callback(self, msg: ManualControlInput):
        self.roll = msg.y
        self.pitch = msg.x
        self.yaw = msg.r
        self.throttle = msg.z

    def deadband(self, value):
        return value if abs(value) > THRESHOLD else 0.0

    def map_rc_to_actuators(self):
        pitch = self.deadband(self.pitch)   # right stick up/down → X axis
        roll = self.deadband(self.roll)     # right stick left/right → Y axis
        yaw = self.deadband(self.yaw)       # left stick left/right → yaw

        motors = [0.0] * 8  # T1-T8 (index 0-7)

        # X axis: T1+T3 forward, T2+T4 backward
        if pitch > 0:
            motors[0] = pitch   # T1 +X
            motors[2] = pitch   # T3 +X
        elif pitch < 0:
            motors[1] = -pitch  # T2 -X
            motors[3] = -pitch  # T4 -X

        # Y axis: T5+T7 right, T6+T8 left
        if roll > 0:
            motors[4] = roll    # T5 +Y
            motors[6] = roll    # T7 +Y
        elif roll < 0:
            motors[5] = -roll   # T6 -Y
            motors[7] = -roll   # T8 -Y

        # Yaw: diagonal pairs — adjust if rotation direction is wrong
        if yaw > 0:
            motors[0] = max(motors[0], yaw)   # T1
            motors[3] = max(motors[3], yaw)   # T4
        elif yaw < 0:
            motors[1] = max(motors[1], -yaw)  # T2
            motors[2] = max(motors[2], -yaw)  # T3

        return motors

    def publish(self):
        now = int(self.get_clock().now().nanoseconds / 1000)

        offboard_msg = OffboardControlMode()
        offboard_msg.timestamp = now
        offboard_msg.direct_actuator = True
        offboard_msg.position = False
        offboard_msg.velocity = False
        offboard_msg.acceleration = False
        offboard_msg.attitude = False
        offboard_msg.body_rate = False
        self.offboard_pub.publish(offboard_msg)

        motors = self.map_rc_to_actuators()

        actuator_msg = ActuatorMotors()
        actuator_msg.timestamp = now
        actuator_msg.timestamp_sample = now
        for i, v in enumerate(motors):
            actuator_msg.control[i] = float(v)
        self.actuator_pub.publish(actuator_msg)


def main(args=None):
    rclpy.init(args=args)
    node = RCDirectControl()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
