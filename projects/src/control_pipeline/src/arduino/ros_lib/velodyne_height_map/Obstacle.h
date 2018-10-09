#ifndef _ROS_velodyne_height_map_Obstacle_h
#define _ROS_velodyne_height_map_Obstacle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace velodyne_height_map
{

  class Obstacle : public ros::Msg
  {
    public:
      typedef uint8_t _obstacleID_type;
      _obstacleID_type obstacleID;
      typedef uint8_t _obstacle_class_type;
      _obstacle_class_type obstacle_class;
      typedef float _min_x_type;
      _min_x_type min_x;
      typedef float _max_x_type;
      _max_x_type max_x;
      typedef float _min_y_type;
      _min_y_type min_y;
      typedef float _max_y_type;
      _max_y_type max_y;
      typedef float _min_z_type;
      _min_z_type min_z;
      typedef float _max_z_type;
      _max_z_type max_z;

    Obstacle():
      obstacleID(0),
      obstacle_class(0),
      min_x(0),
      max_x(0),
      min_y(0),
      max_y(0),
      min_z(0),
      max_z(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->obstacleID >> (8 * 0)) & 0xFF;
      offset += sizeof(this->obstacleID);
      *(outbuffer + offset + 0) = (this->obstacle_class >> (8 * 0)) & 0xFF;
      offset += sizeof(this->obstacle_class);
      offset += serializeAvrFloat64(outbuffer + offset, this->min_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->min_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->min_z);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_z);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->obstacleID =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->obstacleID);
      this->obstacle_class =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->obstacle_class);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->min_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->min_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->min_z));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_z));
     return offset;
    }

    const char * getType(){ return "velodyne_height_map/Obstacle"; };
    const char * getMD5(){ return "50a1d547135fad026457c679116d391b"; };

  };

}
#endif