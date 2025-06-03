from launch import LaunchDescription
from launch_ros.actions import Node


# namepsace is important, it will prefix node names, topics, and services without a leading '/'
def generate_launch_description():
    return LaunchDescription([
        Node(
            package='pub_sub_examples',
            namespace='pub_sub_examples',
            executable='current_time_publisher',
            name='current_time_publisher'
        ),
        Node(
            package='pub_sub_examples',
            namespace='pub_sub_examples',
            executable='laser_scan_publisher',
            name='laser_scan_publisher'
        )
    ])
