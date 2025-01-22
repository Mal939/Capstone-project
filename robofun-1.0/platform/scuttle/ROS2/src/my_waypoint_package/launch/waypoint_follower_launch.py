from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # Include Navigation2 launch file
        Node(
            package='nav2_bringup',
            executable='bringup_launch.py',
            output='screen',
        ),
        # Launch Waypoint Follower Node
        Node(
            package='nav2_waypoint_follower',
            executable='waypoint_follower_node',
            name='waypoint_follower',
            output='screen',
            parameters=[
                {'waypoints_file': '/home/amr01/workspace/robofun-1.0/my_map.yaml'}
            ]
        ),
    ])
