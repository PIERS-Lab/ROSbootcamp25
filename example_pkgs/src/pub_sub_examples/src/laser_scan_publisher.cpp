#include <chrono>  // std::chrono_literals::operator""ms;
#include <functional>  // std::bind<F, Args...>
#include <memory>  // std::make_shared<T>


// You can just include `rclcpp/rclcpp.hpp`
// including individual files explicitely is more explicit and may speed up
// compilation for heavily templatated code but adds extra lines
#include <rclcpp/utilities.hpp> // rclcpp::init, rclcpp::shutdown
#include <rclcpp/executors.hpp> // rclcpp::spin
#include <rclcpp/subscription.hpp>  // rclcpp::Timer
#include <rclcpp/publisher.hpp> // rclcpp::Publisher<MsgT>
#include <rclcpp/node.hpp>  // rclcpp::Node

#include <std_msgs/msg/header.hpp>  // std_msgs::msg::Header
#include <sensor_msgs/msg/laser_scan.hpp>  // sensor_msgs::msg::Header

/*
Purpose: Create a node that subscribes to the `std_msgs::msg::Time` current_time_topic topic and 
  publises a `sensor_msgs::msg::LaserScan` with the header set and a few fields modified
Documentation:
  - rclcpp::Node: https://docs.ros2.org/foxy/api/rclcpp/classrclcpp_1_1Node.html
  - std_msgs::msg::Header: https://docs.ros2.org/foxy/api/std_msgs/msg/Header.html
  - sensor_msgs::msg::LaserScan: https://docs.ros2.org/foxy/api/sensor_msgs/msg/LaserScan.html
  */

class LaserScanPublisherNode: public rclcpp::Node {
  // class fields are default private until overidden
  // private:
  // must be class scoped so they have class lifetime
  rclcpp::Subscription<std_msgs::msg::Header>::SharedPtr subscription_;
  rclcpp::Publisher<sensor_msgs::msg::LaserScan>::SharedPtr publisher_;

  public:
  LaserScanPublisherNode(): rclcpp::Node("laser_scan_publisher") {
    // Bring only literal operator ms into scope
    using std::chrono_literals::operator""ms;

    subscription_ = create_subscription<std_msgs::msg::Header>(
      "current_time_topic", 10,
      std::bind(&LaserScanPublisherNode::current_time_callback, this,
        std::placeholders::_1)); 

    // topics that do not start with `/` are relative to the node namspace
    // otherwise it is absolute
    publisher_ = create_publisher<sensor_msgs::msg::LaserScan>("laser_scan_topic", 10);
  }

  void current_time_callback(const std_msgs::msg::Header::SharedPtr header) {
    sensor_msgs::msg::LaserScan laser_scan;
    
    // Define additional fields as requested
    laser_scan.header.stamp = header->stamp;
    laser_scan.angle_min = 0.0f;
    laser_scan.angle_max = 3.1415f;
    laser_scan.range_min = 0.001f;
    laser_scan.range_max = 5.0f;

    publisher_->publish(laser_scan);

    /*
      Use `ros2 topic list` to see the new topic
      Then `ros2 topic info /laser_scan` to see one publisher
      Then `ros2 topic echo /laser_scan` to see the time messages
    */
}
};

int main(int argc, char ** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<LaserScanPublisherNode>());
  rclcpp::shutdown();

  return 0;
}
