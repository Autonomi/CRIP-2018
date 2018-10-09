#ifndef _ROS_velodyne_height_map_Obstacles_h
#define _ROS_velodyne_height_map_Obstacles_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "velodyne_height_map/Obstacle.h"

namespace velodyne_height_map
{

  class Obstacles : public ros::Msg
  {
    public:
      typedef int32_t _numberOfDetections_type;
      _numberOfDetections_type numberOfDetections;
      uint32_t obstacles_length;
      typedef velodyne_height_map::Obstacle _obstacles_type;
      _obstacles_type st_obstacles;
      _obstacles_type * obstacles;

    Obstacles():
      numberOfDetections(0),
      obstacles_length(0), obstacles(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_numberOfDetections;
      u_numberOfDetections.real = this->numberOfDetections;
      *(outbuffer + offset + 0) = (u_numberOfDetections.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_numberOfDetections.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_numberOfDetections.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_numberOfDetections.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->numberOfDetections);
      *(outbuffer + offset + 0) = (this->obstacles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->obstacles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->obstacles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->obstacles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obstacles_length);
      for( uint32_t i = 0; i < obstacles_length; i++){
      offset += this->obstacles[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_numberOfDetections;
      u_numberOfDetections.base = 0;
      u_numberOfDetections.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_numberOfDetections.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_numberOfDetections.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_numberOfDetections.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->numberOfDetections = u_numberOfDetections.real;
      offset += sizeof(this->numberOfDetections);
      uint32_t obstacles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->obstacles_length);
      if(obstacles_lengthT > obstacles_length)
        this->obstacles = (velodyne_height_map::Obstacle*)realloc(this->obstacles, obstacles_lengthT * sizeof(velodyne_height_map::Obstacle));
      obstacles_length = obstacles_lengthT;
      for( uint32_t i = 0; i < obstacles_length; i++){
      offset += this->st_obstacles.deserialize(inbuffer + offset);
        memcpy( &(this->obstacles[i]), &(this->st_obstacles), sizeof(velodyne_height_map::Obstacle));
      }
     return offset;
    }

    const char * getType(){ return "velodyne_height_map/Obstacles"; };
    const char * getMD5(){ return "9136baf9e9626933b6743acf5183b6ea"; };

  };

}
#endif