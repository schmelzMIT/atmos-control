// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mpc_msgs:srv/SetPose.idl
// generated code does not contain a copyright notice

#ifndef MPC_MSGS__SRV__DETAIL__SET_POSE__BUILDER_HPP_
#define MPC_MSGS__SRV__DETAIL__SET_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mpc_msgs/srv/detail/set_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mpc_msgs
{

namespace srv
{

namespace builder
{

class Init_SetPose_Request_pose
{
public:
  Init_SetPose_Request_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mpc_msgs::srv::SetPose_Request pose(::mpc_msgs::srv::SetPose_Request::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mpc_msgs::srv::SetPose_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mpc_msgs::srv::SetPose_Request>()
{
  return mpc_msgs::srv::builder::Init_SetPose_Request_pose();
}

}  // namespace mpc_msgs


namespace mpc_msgs
{

namespace srv
{

namespace builder
{

class Init_SetPose_Response_result
{
public:
  Init_SetPose_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mpc_msgs::srv::SetPose_Response result(::mpc_msgs::srv::SetPose_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mpc_msgs::srv::SetPose_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mpc_msgs::srv::SetPose_Response>()
{
  return mpc_msgs::srv::builder::Init_SetPose_Response_result();
}

}  // namespace mpc_msgs

#endif  // MPC_MSGS__SRV__DETAIL__SET_POSE__BUILDER_HPP_
