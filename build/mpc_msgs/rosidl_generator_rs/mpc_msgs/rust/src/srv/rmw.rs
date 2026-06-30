#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "mpc_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__mpc_msgs__srv__SetPose_Request() -> *const std::ffi::c_void;
}

#[link(name = "mpc_msgs__rosidl_generator_c")]
extern "C" {
    fn mpc_msgs__srv__SetPose_Request__init(msg: *mut SetPose_Request) -> bool;
    fn mpc_msgs__srv__SetPose_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetPose_Request>, size: usize) -> bool;
    fn mpc_msgs__srv__SetPose_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetPose_Request>);
    fn mpc_msgs__srv__SetPose_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetPose_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetPose_Request>) -> bool;
}

// Corresponds to mpc_msgs__srv__SetPose_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetPose_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub pose: geometry_msgs::msg::rmw::Pose,

}



impl Default for SetPose_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !mpc_msgs__srv__SetPose_Request__init(&mut msg as *mut _) {
        panic!("Call to mpc_msgs__srv__SetPose_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetPose_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { mpc_msgs__srv__SetPose_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { mpc_msgs__srv__SetPose_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { mpc_msgs__srv__SetPose_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetPose_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetPose_Request where Self: Sized {
  const TYPE_NAME: &'static str = "mpc_msgs/srv/SetPose_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__mpc_msgs__srv__SetPose_Request() }
  }
}


#[link(name = "mpc_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__mpc_msgs__srv__SetPose_Response() -> *const std::ffi::c_void;
}

#[link(name = "mpc_msgs__rosidl_generator_c")]
extern "C" {
    fn mpc_msgs__srv__SetPose_Response__init(msg: *mut SetPose_Response) -> bool;
    fn mpc_msgs__srv__SetPose_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetPose_Response>, size: usize) -> bool;
    fn mpc_msgs__srv__SetPose_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetPose_Response>);
    fn mpc_msgs__srv__SetPose_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetPose_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetPose_Response>) -> bool;
}

// Corresponds to mpc_msgs__srv__SetPose_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetPose_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub result: bool,

}



impl Default for SetPose_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !mpc_msgs__srv__SetPose_Response__init(&mut msg as *mut _) {
        panic!("Call to mpc_msgs__srv__SetPose_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetPose_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { mpc_msgs__srv__SetPose_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { mpc_msgs__srv__SetPose_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { mpc_msgs__srv__SetPose_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetPose_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetPose_Response where Self: Sized {
  const TYPE_NAME: &'static str = "mpc_msgs/srv/SetPose_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__mpc_msgs__srv__SetPose_Response() }
  }
}






#[link(name = "mpc_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__mpc_msgs__srv__SetPose() -> *const std::ffi::c_void;
}

// Corresponds to mpc_msgs__srv__SetPose
#[allow(missing_docs, non_camel_case_types)]
pub struct SetPose;

impl rosidl_runtime_rs::Service for SetPose {
    type Request = SetPose_Request;
    type Response = SetPose_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__mpc_msgs__srv__SetPose() }
    }
}


