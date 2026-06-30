// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mpc_msgs:srv/SetPose.idl
// generated code does not contain a copyright notice

#ifndef MPC_MSGS__SRV__DETAIL__SET_POSE__TRAITS_HPP_
#define MPC_MSGS__SRV__DETAIL__SET_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mpc_msgs/srv/detail/set_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace mpc_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetPose_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetPose_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetPose_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace mpc_msgs

namespace rosidl_generator_traits
{

[[deprecated("use mpc_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mpc_msgs::srv::SetPose_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  mpc_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mpc_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const mpc_msgs::srv::SetPose_Request & msg)
{
  return mpc_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mpc_msgs::srv::SetPose_Request>()
{
  return "mpc_msgs::srv::SetPose_Request";
}

template<>
inline const char * name<mpc_msgs::srv::SetPose_Request>()
{
  return "mpc_msgs/srv/SetPose_Request";
}

template<>
struct has_fixed_size<mpc_msgs::srv::SetPose_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<mpc_msgs::srv::SetPose_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct is_message<mpc_msgs::srv::SetPose_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace mpc_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetPose_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetPose_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetPose_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace mpc_msgs

namespace rosidl_generator_traits
{

[[deprecated("use mpc_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mpc_msgs::srv::SetPose_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  mpc_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mpc_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const mpc_msgs::srv::SetPose_Response & msg)
{
  return mpc_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mpc_msgs::srv::SetPose_Response>()
{
  return "mpc_msgs::srv::SetPose_Response";
}

template<>
inline const char * name<mpc_msgs::srv::SetPose_Response>()
{
  return "mpc_msgs/srv/SetPose_Response";
}

template<>
struct has_fixed_size<mpc_msgs::srv::SetPose_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<mpc_msgs::srv::SetPose_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<mpc_msgs::srv::SetPose_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<mpc_msgs::srv::SetPose>()
{
  return "mpc_msgs::srv::SetPose";
}

template<>
inline const char * name<mpc_msgs::srv::SetPose>()
{
  return "mpc_msgs/srv/SetPose";
}

template<>
struct has_fixed_size<mpc_msgs::srv::SetPose>
  : std::integral_constant<
    bool,
    has_fixed_size<mpc_msgs::srv::SetPose_Request>::value &&
    has_fixed_size<mpc_msgs::srv::SetPose_Response>::value
  >
{
};

template<>
struct has_bounded_size<mpc_msgs::srv::SetPose>
  : std::integral_constant<
    bool,
    has_bounded_size<mpc_msgs::srv::SetPose_Request>::value &&
    has_bounded_size<mpc_msgs::srv::SetPose_Response>::value
  >
{
};

template<>
struct is_service<mpc_msgs::srv::SetPose>
  : std::true_type
{
};

template<>
struct is_service_request<mpc_msgs::srv::SetPose_Request>
  : std::true_type
{
};

template<>
struct is_service_response<mpc_msgs::srv::SetPose_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MPC_MSGS__SRV__DETAIL__SET_POSE__TRAITS_HPP_
