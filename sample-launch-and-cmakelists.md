# Simple CMakeLists.txt and launch file

_The below is from a lesson from The Construct and is copy-pasted here for educational purposes only._

Launch file (`my_package_launch_file.launch.py`)

```
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='my_package',
            executable='simple_node',
            output='screen'),
    ])
```

`CMakeLists.txt`
_Comments added by ChatGPT and checked by Sam_

```
# This line sets the minimum required version of CMake to process this file.
cmake_minimum_required(VERSION 3.8)

# This defines the name of the package/project.
project(my_package)

# If the compiler is GCC or Clang, add extra compile-time warning flags to help catch common errors.
# -Wall enables most warning messages.
# -Wextra enables even more warnings.
# -Wpedantic enforces strict ISO C++ compliance.
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find the ament_cmake build system package (a dependency), which is required for building ROS 2 packages.
find_package(ament_cmake REQUIRED)

# Find the rclcpp package (another dependency), which provides the C++ API for interacting with ROS 2.
find_package(rclcpp REQUIRED)

# If we are building tests (e.g., when running `colcon test`), configure the linters.
if(BUILD_TESTING)
  # Find the ament_lint_auto package, which helps automatically enable code quality checks.
  find_package(ament_lint_auto REQUIRED)

  # The following line tells the linter to skip the copyright checker.
  # Uncomment this if your source files don’t have copyright/license headers.
  #set(ament_cmake_copyright_FOUND TRUE)

  # The following line tells the linter to skip the cpplint checker.
  # Uncomment this if your package is not inside a Git repository (which cpplint requires).
  #set(ament_cmake_cpplint_FOUND TRUE)

  # This finds and sets up dependencies needed by the linters.
  ament_lint_auto_find_test_dependencies()
endif()

# Add an executable called 'simple_node' that is built from the source file 'src/simple.cpp'.
add_executable(simple_node src/simple.cpp)

# Link the 'simple_node' executable to the rclcpp library so it can use ROS 2 C++ APIs.
ament_target_dependencies(simple_node rclcpp)

# Install the built executable into the install space under the 'lib' directory for this package.
install(TARGETS
   simple_node
   DESTINATION lib/${PROJECT_NAME}
 )

# Install the 'launch' directory (which contains launch files) into the install space
# so that launch files can be found by other ROS tools.
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

# This must be called at the end of every ROS 2 CMake file.
# It sets up the package so other packages can find and use it.
ament_package()
```
