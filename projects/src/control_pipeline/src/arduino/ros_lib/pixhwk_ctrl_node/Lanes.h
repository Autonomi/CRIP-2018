#ifndef _ROS_pixhwk_ctrl_node_Lanes_h
#define _ROS_pixhwk_ctrl_node_Lanes_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point32.h"

namespace pixhwk_ctrl_node
{

  class Lanes : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t lane_left_points_length;
      typedef geometry_msgs::Point32 _lane_left_points_type;
      _lane_left_points_type st_lane_left_points;
      _lane_left_points_type * lane_left_points;
      uint32_t lane_right_points_length;
      typedef geometry_msgs::Point32 _lane_right_points_type;
      _lane_right_points_type st_lane_right_points;
      _lane_right_points_type * lane_right_points;

    Lanes():
      header(),
      lane_left_points_length(0), lane_left_points(NULL),
      lane_right_points_length(0), lane_right_points(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->lane_left_points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lane_left_points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lane_left_points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lane_left_points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_left_points_length);
      for( uint32_t i = 0; i < lane_left_points_length; i++){
      offset += this->lane_left_points[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->lane_right_points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lane_right_points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lane_right_points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lane_right_points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lane_right_points_length);
      for( uint32_t i = 0; i < lane_right_points_length; i++){
      offset += this->lane_right_points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t lane_left_points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      lane_left_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      lane_left_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      lane_left_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->lane_left_points_length);
      if(lane_left_points_lengthT > lane_left_points_length)
        this->lane_left_points = (geometry_msgs::Point32*)realloc(this->lane_left_points, lane_left_points_lengthT * sizeof(geometry_msgs::Point32));
      lane_left_points_length = lane_left_points_lengthT;
      for( uint32_t i = 0; i < lane_left_points_length; i++){
      offset += this->st_lane_left_points.deserialize(inbuffer + offset);
        memcpy( &(this->lane_left_points[i]), &(this->st_lane_left_points), sizeof(geometry_msgs::Point32));
      }
      uint32_t lane_right_points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      lane_right_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      lane_right_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      lane_right_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->lane_right_points_length);
      if(lane_right_points_lengthT > lane_right_points_length)
        this->lane_right_points = (geometry_msgs::Point32*)realloc(this->lane_right_points, lane_right_points_lengthT * sizeof(geometry_msgs::Point32));
      lane_right_points_length = lane_right_points_lengthT;
      for( uint32_t i = 0; i < lane_right_points_length; i++){
      offset += this->st_lane_right_points.deserialize(inbuffer + offset);
        memcpy( &(this->lane_right_points[i]), &(this->st_lane_right_points), sizeof(geometry_msgs::Point32));
      }
     return offset;
    }

    const char * getType(){ return "pixhwk_ctrl_node/Lanes"; };
    const char * getMD5(){ return "1c83d511d158b95dd22c4a5f998f865d"; };

  };

}
#endif