#include <chrono>  // std::chrono_literals::operator""ms;
#include <functional>  // std::bind<F, Args...>
#include <memory>  // std::make_shared<T>

#include <rclcpp/utilities.hpp> // rclcpp::init, rclcpp::shutdown
#include <rclcpp/executors.hpp> // rclcpp::spin
#include <rclcpp/timer.hpp>  // rclcpp::Timer
#include <rclcpp/publisher.hpp> // rclcpp::Publisher<MsgT>
#include <rclcpp/node.hpp>  // rclcpp::Node

#include <std_msgs/msg/header.hpp> // std_msgs::msg::Header

/*
Purpose: Create a node that publishes the current time
Documentation:
  - rclcpp::Node: https://docs.ros2.org/foxy/api/rclcpp/classrclcpp_1_1Node.html
  - std_msgs::msg::Header: https://docs.ros2.org/foxy/api/std_msgs/msg/Header.html
*/

class TimePublisherNode: public rclcpp::Node {
  // class fields are default private until overidden
  // private:
  // must be class scoped so they have class lifetime
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::Header>::SharedPtr publisher_;

  public:
  TimePublisherNode(): rclcpp::Node("time_publisher_node") {
    // Bring only literal operator ms into scope
    using std::chrono_literals::operator""ms;

    // publish in a timer at a fixed interval, need not oversaturate the CPU
    timer_ = create_wall_timer(100ms,
      std::bind(&TimePublisherNode::timer_callback, this));

    // topics that do not start with `/` are relative to the node namspace
    // otherwise it is absolute
    publisher_ = create_publisher<std_msgs::msg::Header>("current_time_topic", 10);
  }

  void timer_callback() {
    // no argument constructors
    std_msgs::msg::Header header; // use header, header{}, but not header()
    // std_msgs::msg::Header header(); ERROR - Vexing Parse: same syntax as a function delcaration
    header.stamp = get_clock()->now(); // implicit conversion from rclcpp::Time to rcl_interfaces::msg::Time

    publisher_->publish(header);

    /*
      Use `ros2 topic list` to see the new topic
      Then `ros2 topic info pub_sub_example/current_time_topic` to see one publisher
      Then `ros2 topic echo pub_sub_example/current_time_topic` to see the time messages
    */

}
};

int main(int argc, char ** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TimePublisherNode>());
  rclcpp::shutdown();

  return 0;
}
