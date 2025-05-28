# Getting started with ROS

### ROS concepts

`ros_ws`
ROS workspace - where all of the ROS code lives.

`ros_ws/src`
ROS workspace source directory - packages live here.

`ros2 pkg create`
Create a ROS package (example: `ros2 pkg create wall-follower` to make a package for a robot to follow a wall).
Can be used with...

`--build-type ament_[something]` to specify the language - usually `ament_cmake` for C++.

`--dependencies` to specify dependencies.

Example: `ros2 pkg create --build-type ament_cmake wall-follower --dependencies rclcpp sensor_msgs std_msgs` creates a package called `wall-follower` that uses CMake and depends on three other packages.

Creating a package will give you two child directories:

`src`
Your C++ source code goes here. When you run a package, it will look for the source code inside this directory -- don't accidentally put your code outside this folder.

`include`
Your C++ header files and libraries go here.

It will also give you two files:

`package.xml`
This contains important information about your package, including its name, build type, and dependencies. You can change the package's name and add dependencies here. If you want to change something more integrated (e.g., switch to python from C++), you can do that here, too -- but it might be easier/safer just to make a new package. The most common reason for editing this file is adding dependencies; aside from that, you will often ignore it.

`CMakeLists.txt`
This is a "C++ thing", not a "ROS thing" (in contrast to package.xml, which is ROS-specific). This is how dependencies are specified to C++. If you add dependencies, add them here.

`colcon build`
This builds your package from within the ROS workspace (it won't work if you're outside the workspace).
