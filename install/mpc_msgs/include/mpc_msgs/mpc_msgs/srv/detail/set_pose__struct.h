// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mpc_msgs:srv/SetPose.idl
// generated code does not contain a copyright notice

#ifndef MPC_MSGS__SRV__DETAIL__SET_POSE__STRUCT_H_
#define MPC_MSGS__SRV__DETAIL__SET_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in srv/SetPose in the package mpc_msgs.
typedef struct mpc_msgs__srv__SetPose_Request
{
  geometry_msgs__msg__Pose pose;
} mpc_msgs__srv__SetPose_Request;

// Struct for a sequence of mpc_msgs__srv__SetPose_Request.
typedef struct mpc_msgs__srv__SetPose_Request__Sequence
{
  mpc_msgs__srv__SetPose_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mpc_msgs__srv__SetPose_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetPose in the package mpc_msgs.
typedef struct mpc_msgs__srv__SetPose_Response
{
  bool result;
} mpc_msgs__srv__SetPose_Response;

// Struct for a sequence of mpc_msgs__srv__SetPose_Response.
typedef struct mpc_msgs__srv__SetPose_Response__Sequence
{
  mpc_msgs__srv__SetPose_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mpc_msgs__srv__SetPose_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MPC_MSGS__SRV__DETAIL__SET_POSE__STRUCT_H_
