// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mpc_msgs:srv/SetPose.idl
// generated code does not contain a copyright notice
#include "mpc_msgs/srv/detail/set_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
mpc_msgs__srv__SetPose_Request__init(mpc_msgs__srv__SetPose_Request * msg)
{
  if (!msg) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    mpc_msgs__srv__SetPose_Request__fini(msg);
    return false;
  }
  return true;
}

void
mpc_msgs__srv__SetPose_Request__fini(mpc_msgs__srv__SetPose_Request * msg)
{
  if (!msg) {
    return;
  }
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
}

bool
mpc_msgs__srv__SetPose_Request__are_equal(const mpc_msgs__srv__SetPose_Request * lhs, const mpc_msgs__srv__SetPose_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  return true;
}

bool
mpc_msgs__srv__SetPose_Request__copy(
  const mpc_msgs__srv__SetPose_Request * input,
  mpc_msgs__srv__SetPose_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  return true;
}

mpc_msgs__srv__SetPose_Request *
mpc_msgs__srv__SetPose_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mpc_msgs__srv__SetPose_Request * msg = (mpc_msgs__srv__SetPose_Request *)allocator.allocate(sizeof(mpc_msgs__srv__SetPose_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mpc_msgs__srv__SetPose_Request));
  bool success = mpc_msgs__srv__SetPose_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mpc_msgs__srv__SetPose_Request__destroy(mpc_msgs__srv__SetPose_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mpc_msgs__srv__SetPose_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mpc_msgs__srv__SetPose_Request__Sequence__init(mpc_msgs__srv__SetPose_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mpc_msgs__srv__SetPose_Request * data = NULL;

  if (size) {
    data = (mpc_msgs__srv__SetPose_Request *)allocator.zero_allocate(size, sizeof(mpc_msgs__srv__SetPose_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mpc_msgs__srv__SetPose_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mpc_msgs__srv__SetPose_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mpc_msgs__srv__SetPose_Request__Sequence__fini(mpc_msgs__srv__SetPose_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mpc_msgs__srv__SetPose_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mpc_msgs__srv__SetPose_Request__Sequence *
mpc_msgs__srv__SetPose_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mpc_msgs__srv__SetPose_Request__Sequence * array = (mpc_msgs__srv__SetPose_Request__Sequence *)allocator.allocate(sizeof(mpc_msgs__srv__SetPose_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mpc_msgs__srv__SetPose_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mpc_msgs__srv__SetPose_Request__Sequence__destroy(mpc_msgs__srv__SetPose_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mpc_msgs__srv__SetPose_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mpc_msgs__srv__SetPose_Request__Sequence__are_equal(const mpc_msgs__srv__SetPose_Request__Sequence * lhs, const mpc_msgs__srv__SetPose_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mpc_msgs__srv__SetPose_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mpc_msgs__srv__SetPose_Request__Sequence__copy(
  const mpc_msgs__srv__SetPose_Request__Sequence * input,
  mpc_msgs__srv__SetPose_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mpc_msgs__srv__SetPose_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mpc_msgs__srv__SetPose_Request * data =
      (mpc_msgs__srv__SetPose_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mpc_msgs__srv__SetPose_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mpc_msgs__srv__SetPose_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mpc_msgs__srv__SetPose_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
mpc_msgs__srv__SetPose_Response__init(mpc_msgs__srv__SetPose_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  return true;
}

void
mpc_msgs__srv__SetPose_Response__fini(mpc_msgs__srv__SetPose_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
}

bool
mpc_msgs__srv__SetPose_Response__are_equal(const mpc_msgs__srv__SetPose_Response * lhs, const mpc_msgs__srv__SetPose_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (lhs->result != rhs->result) {
    return false;
  }
  return true;
}

bool
mpc_msgs__srv__SetPose_Response__copy(
  const mpc_msgs__srv__SetPose_Response * input,
  mpc_msgs__srv__SetPose_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  output->result = input->result;
  return true;
}

mpc_msgs__srv__SetPose_Response *
mpc_msgs__srv__SetPose_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mpc_msgs__srv__SetPose_Response * msg = (mpc_msgs__srv__SetPose_Response *)allocator.allocate(sizeof(mpc_msgs__srv__SetPose_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mpc_msgs__srv__SetPose_Response));
  bool success = mpc_msgs__srv__SetPose_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mpc_msgs__srv__SetPose_Response__destroy(mpc_msgs__srv__SetPose_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mpc_msgs__srv__SetPose_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mpc_msgs__srv__SetPose_Response__Sequence__init(mpc_msgs__srv__SetPose_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mpc_msgs__srv__SetPose_Response * data = NULL;

  if (size) {
    data = (mpc_msgs__srv__SetPose_Response *)allocator.zero_allocate(size, sizeof(mpc_msgs__srv__SetPose_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mpc_msgs__srv__SetPose_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mpc_msgs__srv__SetPose_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mpc_msgs__srv__SetPose_Response__Sequence__fini(mpc_msgs__srv__SetPose_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mpc_msgs__srv__SetPose_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mpc_msgs__srv__SetPose_Response__Sequence *
mpc_msgs__srv__SetPose_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mpc_msgs__srv__SetPose_Response__Sequence * array = (mpc_msgs__srv__SetPose_Response__Sequence *)allocator.allocate(sizeof(mpc_msgs__srv__SetPose_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mpc_msgs__srv__SetPose_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mpc_msgs__srv__SetPose_Response__Sequence__destroy(mpc_msgs__srv__SetPose_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mpc_msgs__srv__SetPose_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mpc_msgs__srv__SetPose_Response__Sequence__are_equal(const mpc_msgs__srv__SetPose_Response__Sequence * lhs, const mpc_msgs__srv__SetPose_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mpc_msgs__srv__SetPose_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mpc_msgs__srv__SetPose_Response__Sequence__copy(
  const mpc_msgs__srv__SetPose_Response__Sequence * input,
  mpc_msgs__srv__SetPose_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mpc_msgs__srv__SetPose_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mpc_msgs__srv__SetPose_Response * data =
      (mpc_msgs__srv__SetPose_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mpc_msgs__srv__SetPose_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mpc_msgs__srv__SetPose_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mpc_msgs__srv__SetPose_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
