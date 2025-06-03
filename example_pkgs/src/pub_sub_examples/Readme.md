# About
This package demonstrates basic usage for using ros2 publishers
and subscribers in C++

This is the solution for an assignment given by Jordan on May 29

#Instructions
Create a new package that publishes a std_msgs::header, setting the stamp using the Node::now() function

Afterwards, modify your package to add a dependency to sensor_msgs, and create a new subscriber that
subscribes to the header you previously created,. It should create a new sensor_msgs laser_scan msg. 
Set the header for this new message as the one you subscribed too, and also set the angle_min, angle_max,
range_min, range_max to arbitrary floats. Publish this message
