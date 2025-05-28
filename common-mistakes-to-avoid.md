# Common pitfalls and pro tips

1. Always run `colcon build` inside `ros2_ws`. Don't run it inside `ros2_ws/src`.
2. Always `colcon build` any time you change a file. You can build just the package with `colcon build --packages-select [the_package]`.
3. Always name launch files with the extension `.launch.py` or ROS2 will not find it.
4. Don't forget to source setup .sh files (`source install/setup.bash`) periodically in The Construct.
