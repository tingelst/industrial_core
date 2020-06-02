cmake_minimum_required(VERSION 3.5)

project(industrial_msgs)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)
find_package(trajectory_msgs REQUIRED)

rosidl_generate_interfaces(industrial_msgs
                           "msg/DebugLevel.msg"
                           "msg/DeviceInfo.msg"
                           "msg/RobotMode.msg"
                           "msg/RobotStatus.msg"
                           "msg/ServiceReturnCode.msg"
                           "msg/TriState.msg"
                           "srv/CmdJointTrajectory.srv"
                           "srv/GetRobotInfo.srv"
                           "srv/SetDrivePower.srv"
                           "srv/SetRemoteLoggerLevel.srv"
                           "srv/StartMotion.srv"
                           "srv/StopMotion.srv"
                           DEPENDENCIES
                           std_msgs
                           trajectory_msgs)

ament_export_dependencies(rosidl_default_runtime)
ament_package()
