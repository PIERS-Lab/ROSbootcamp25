# ROSbootcamp25

Day 1 (5/27/255)

1. Intro to the course, course staff
2. Intro to The Construct
3. [Linux for Robotics Course](https://app.theconstruct.ai/courses/185)
   - [Linux (for Robotics) Cheatsheet and Checkpoint](linux-for-robotics-cheatsheet.md)
4. [Getting Started with ROS Notes](getting-started-ROS.md)
   - Introduction to [ROS2 Basics in 5 Days (C++) Course](https://app.theconstruct.ai/courses/133)
   - Review of [simple cpp file](simple.cpp)
   - ROS Basics in 5 Days C++ The Construct course - start from the beginning (1.1 Introduction)
   - Discuss structure of example CMakeLists.txt and launch file from lesson 2.7 Create Your First ROS2 Program
5. What does ROS do?
   - Structure of a [simple topic publisher](simple_topic_publisher.app): queue size (rarely need to care too much about)
   - Confused about all the concepts? That's okay! See the [ROS concepts apple tree metaphor](https://ktiwari9.gitlab.io/ros101/JargonSection.html)
     - _Note: Ignore "catkin" here -- that's a reference to ROS1. You can just imagine that it says says "ROS workspace"._

Day 2 (5/28/25)

1. Review of what we learned yesterday - [Day 1 review](day1-review.md)
2. Work through publishers, subscribers, up through topics quiz

Day 3 (5/29/25)

1. [Git and github](git-cheatsheet.md)
   - Walkthrough of UML Race repository
   - rviz (just an intro for now - more to come)
   - [git and package creation assignment](day3-assigment.md)
   - UML Race assignment

Day 4 (5/30/25)

1. Publisher/subscriber exercise
   - Make a new package & create a publisher that publishes a std_msgs header using the current time in rostime. Check it using `ros2 topic echo /topic`.
   - Make a second node as part of the same package. Add the sensor_msgs laser_scan dependency. Add a subscriber that subscribes to the header from your prior topic, set the header to be that, set four other fields to anything, and publish the laser scan message as is. The result should be: a publisher sends the stamp, the subscriber gets the stamp and adds it to the laser scan message - and also sets at least four of the other fields to random floats - and publishes that.
