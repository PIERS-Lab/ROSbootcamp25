# Review of what we learned on Day 1

Filesystem structure, workspace directory, difference between workspace source directory and individual package source directory

What to do if you're asked to "make a ROS package": navigate to workspace source directory (`ros_ws/src`), create the package, add executables to CMakeLists, build code. Tips:

- Typically, a package does one thing. You might want to have it do multiple things if it's, e.g., a tools package.
- You can usually tab complete the package creation command so you don't have to remember every little thing about the syntax. Don't forget to add needed dependencies.

Publisher: something that puts data out.

- Structure of cpp files: include rclcpp, init, somehow make a node.

Subscriber: reads from a node.

- Structure: may or may not use classes.

`package.xml` and `CMakeLists`:

- `package.xml` is for ROS and `CMakeLists` is for C++
- `package.xml` is helpful for forcing the order in which you find and compile dependencies
