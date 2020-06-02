cmake_minimum_required(VERSION 3.5)
project(simple_message)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_ros REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rcutils REQUIRED)
find_package(industrial_msgs REQUIRED)

# uncomment the following section in order to fill in further dependencies
# manually. find_package(<dependency> REQUIRED)

# The simple_message library is designed to cross compile on Ubuntu and various
# robot controllers.  This requires conditionally compiling certain functions
# and headers.  The definition below enables compiling for a ROS node.
add_definitions(-DROS=1) # build using ROS libraries
add_definitions(-DLINUXSOCKETS=1) # use linux sockets for communication

set(SRC_FILES
    src/byte_array.cpp
    src/simple_message.cpp
    src/smpl_msg_connection.cpp
    src/socket/simple_socket.cpp
    src/socket/udp_socket.cpp
    src/socket/udp_client.cpp
    src/socket/udp_server.cpp
    src/socket/tcp_socket.cpp
    src/socket/tcp_client.cpp
    src/socket/tcp_server.cpp
    src/message_handler.cpp
    src/message_manager.cpp
    src/ping_handler.cpp
    src/ping_message.cpp
    src/joint_data.cpp
    src/joint_feedback.cpp
    src/joint_traj_pt.cpp
    src/joint_traj_pt_full.cpp
    src/joint_traj.cpp
    src/robot_status.cpp
    src/messages/joint_message.cpp
    src/messages/joint_feedback_message.cpp
    src/messages/joint_traj_pt_message.cpp
    src/messages/joint_traj_pt_full_message.cpp
    src/messages/robot_status_message.cpp
    src/simple_comms_fault_handler.cpp)

add_library(simple_message ${SRC_FILES})
target_include_directories(
  simple_message
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include>)
ament_target_dependencies(simple_message
                          "rclcpp"
                          "rcutils"
                          "industrial_msgs")

# Causes the visibility macros to use dllexport rather than dllimport, which is
# appropriate when building the dll but not consuming it.
target_compile_definitions(simple_message PRIVATE
                           "SIMPLE_MESSAGE_BUILDING_LIBRARY")

install(DIRECTORY include/ DESTINATION include)
install(TARGETS simple_message
        EXPORT export_${PROJECT_NAME}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights uncomment
  # the line when a copyright and license is not present in all source files
  # set(ament_cmake_copyright_FOUND TRUE) the following line skips cpplint (only
  # works in a git repo) uncomment the line when this package is not in a git
  # repo set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_export_include_directories(include)
ament_export_interfaces(export_${PROJECT_NAME})
ament_export_libraries(simple_message)

ament_package()
