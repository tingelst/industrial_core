cmake_minimum_required(VERSION 3.5)
project(industrial_robot_client)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_ros REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(control_msgs REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(simple_message REQUIRED)
find_package(urdf REQUIRED)
find_package(industrial_msgs REQUIRED)

# The definition is copied from the CMakeList for the simple_message package.
add_definitions(-DROS=1) # build using ROS libraries
add_definitions(-DLINUXSOCKETS=1) # build using LINUX SOCKETS libraries

set(SRC_FILES
    # src/joint_relay_handler.cpp
    src/robot_status_relay_handler.cpp
    # src/joint_trajectory_downloader.cpp
    # src/joint_trajectory_streamer.cpp
    # src/joint_trajectory_interface.cpp
    # src/robot_state_interface.cpp
    # src/utils.cpp
    )

# add_library(industrial_robot_client ${SRC_FILES})
# target_include_directories(
#   industrial_robot_client
#   PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#          $<INSTALL_INTERFACE:include>)
# ament_target_dependencies(industrial_robot_client "simple_message" "industrial_msgs")

# # Causes the visibility macros to use dllexport rather than dllimport, which is
# # appropriate when building the dll but not consuming it.
# target_compile_definitions(industrial_robot_client PRIVATE
#                            "INDUSTRIAL_ROBOT_CLIENT_BUILDING_LIBRARY")

# install(DIRECTORY include/ DESTINATION include)
# install(TARGETS industrial_robot_client
#         EXPORT export_${PROJECT_NAME}
#         ARCHIVE DESTINATION lib
#         LIBRARY DESTINATION lib
#         RUNTIME DESTINATION bin)

add_executable(robot_state src/generic_robot_state_node.cpp)
target_include_directories(robot_state PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_link_libraries(robot_state industrial_robot_client)
ament_target_dependencies(robot_state "simple_message" "industrial_msgs")


install(TARGETS robot_state
  EXPORT export_${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME})

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
ament_export_libraries(industrial_robot_client)

ament_package()
