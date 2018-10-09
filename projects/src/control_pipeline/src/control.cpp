#include <ros/ros.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <std_msgs/UInt16.h>
#include </home/vikas-crip/Desktop/ros workspace/person_tracking/devel/include/aruco_mapping/ArucoMarker.h>

ros::Publisher pub1;
ros::Publisher pub2;


using namespace std;

void aruco_position_callback(const aruco_mapping::ArucoMarker::ConstPtr& msg)
{
	std_msgs::UInt16 servo1;
	if(msg->global_camera_pose.position.y <= 0)
	{
		servo1.data = -1 *(((msg->global_camera_pose.position.y) * -30) - 90) ;
	}
	else
	{
		servo1.data = ((msg->global_camera_pose.position.y) * 40) + 90;
	}
	cout<<msg->global_camera_pose.position.y<<"             ";
	pub1.publish(servo1);

	std_msgs::UInt16 servo2;
	if(msg->global_camera_pose.position.x < 0)
	{
		servo2.data = -1 * (((msg->global_camera_pose.position.x) * -50) - 91) ;
	}
	else
	{
		servo2.data = 91 - (msg->global_camera_pose.position.x) * 50 ;
	}
	cout<<msg->global_camera_pose.position.x<<endl;
	servo2.data = 91;
	pub2.publish(servo2);
		
}
int main(int argc, char** argv)
{
	ros::init(argc, argv, "control_node");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("/aruco_poses", 1, aruco_position_callback);
	pub1 = n.advertise<std_msgs::UInt16>("servo1", 1);
	pub2 = n.advertise<std_msgs::UInt16>("servo2", 1);
	ros::spin();
}
