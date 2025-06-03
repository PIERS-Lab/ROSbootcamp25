cmake_minimum_required(VERSION 3.8)
project(pub_sub_examples)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED) # REQUIRED will throw an error if the pkg is not found
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# DONT FORGET THESE
# IF YOU FORGET: Will get a cmake error
add_executable(current_time_publisher src/current_time_publisher.cpp)
add_executable(laser_scan_publisher src/laser_scan_publisher.cpp)

# IF YOU FORGET: Will get a compilation error about an unknown include
ament_target_dependencies(current_time_publisher rclcpp std_msgs)
ament_target_dependencies(laser_scan_publisher rclcpp std_msgs sensor_msgs)

# If you forget, you will not be able to run/launch the file
install(TARGETS 
  current_time_publisher laser_scan_publisher
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME})

ament_package()
