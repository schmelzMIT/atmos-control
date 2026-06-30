#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to mpc_msgs__srv__SetPose_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetPose_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub pose: geometry_msgs::msg::Pose,

}



impl Default for SetPose_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetPose_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SetPose_Request {
  type RmwMsg = super::srv::rmw::SetPose_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Owned(msg.pose)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Borrowed(&msg.pose)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      pose: geometry_msgs::msg::Pose::from_rmw_message(msg.pose),
    }
  }
}


// Corresponds to mpc_msgs__srv__SetPose_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetPose_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub result: bool,

}



impl Default for SetPose_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetPose_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SetPose_Response {
  type RmwMsg = super::srv::rmw::SetPose_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        result: msg.result,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      result: msg.result,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      result: msg.result,
    }
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


