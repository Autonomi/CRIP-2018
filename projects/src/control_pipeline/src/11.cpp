#include <stdio.h>
#include <errno.h>
#include <fstream>

#include <wiringPi.h>
#include <softServo.h>

#include <ros/ros.h>
#include <iostream>
#include </home/vikas-crip/Desktop/ros workspace/person_tracking/devel/include/aruco_mapping/ArucoMarker.h>



void aruco_position_callback(const aruco_mapping::ArucoMarker::ConstPtr& msg)
{
	


	softServoWrite (0,  msg->global_camera_pose.position.x) ;
	
	softServoWrite (1,  	msg->global_camera_pose.position.y) ; 
	
	
	       		
}
int main(int argc, char** argv)
{
	ros::init(argc, argv, "control_node");
	ros::NodeHandle n;
	softServoSetup (0, 1, 2, 3, 4, 5, 6, 7);
	ros::Subscriber sub = n.subscribe<aruco_mapping::ArucoMarker>("/aruco_poses", 1, aruco_position_callback);

	ros::spin();
	return 0;
}
