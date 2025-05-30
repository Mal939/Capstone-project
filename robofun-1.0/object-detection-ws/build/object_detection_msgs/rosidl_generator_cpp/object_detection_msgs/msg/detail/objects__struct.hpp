// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from object_detection_msgs:msg/Objects.idl
// generated code does not contain a copyright notice

#ifndef OBJECT_DETECTION_MSGS__MSG__DETAIL__OBJECTS__STRUCT_HPP_
#define OBJECT_DETECTION_MSGS__MSG__DETAIL__OBJECTS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'objects'
#include "object_detection_msgs/msg/detail/object__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__object_detection_msgs__msg__Objects __attribute__((deprecated))
#else
# define DEPRECATED__object_detection_msgs__msg__Objects __declspec(deprecated)
#endif

namespace object_detection_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Objects_
{
  using Type = Objects_<ContainerAllocator>;

  explicit Objects_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit Objects_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _objects_type =
    std::vector<object_detection_msgs::msg::Object_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<object_detection_msgs::msg::Object_<ContainerAllocator>>>;
  _objects_type objects;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__objects(
    const std::vector<object_detection_msgs::msg::Object_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<object_detection_msgs::msg::Object_<ContainerAllocator>>> & _arg)
  {
    this->objects = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    object_detection_msgs::msg::Objects_<ContainerAllocator> *;
  using ConstRawPtr =
    const object_detection_msgs::msg::Objects_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<object_detection_msgs::msg::Objects_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<object_detection_msgs::msg::Objects_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      object_detection_msgs::msg::Objects_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<object_detection_msgs::msg::Objects_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      object_detection_msgs::msg::Objects_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<object_detection_msgs::msg::Objects_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<object_detection_msgs::msg::Objects_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<object_detection_msgs::msg::Objects_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__object_detection_msgs__msg__Objects
    std::shared_ptr<object_detection_msgs::msg::Objects_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__object_detection_msgs__msg__Objects
    std::shared_ptr<object_detection_msgs::msg::Objects_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Objects_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->objects != other.objects) {
      return false;
    }
    return true;
  }
  bool operator!=(const Objects_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Objects_

// alias to use template instance with default allocator
using Objects =
  object_detection_msgs::msg::Objects_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace object_detection_msgs

#endif  // OBJECT_DETECTION_MSGS__MSG__DETAIL__OBJECTS__STRUCT_HPP_
