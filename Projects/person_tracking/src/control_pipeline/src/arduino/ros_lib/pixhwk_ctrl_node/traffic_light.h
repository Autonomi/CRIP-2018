#ifndef _ROS_pixhwk_ctrl_node_traffic_light_h
#define _ROS_pixhwk_ctrl_node_traffic_light_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pixhwk_ctrl_node
{

  class traffic_light : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _dist_light_type;
      _dist_light_type dist_light;
      typedef const char* _color_light_type;
      _color_light_type color_light;

    traffic_light():
      header(),
      dist_light(0),
      color_light("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->dist_light);
      uint32_t length_color_light = strlen(this->color_light);
      varToArr(outbuffer + offset, length_color_light);
      offset += 4;
      memcpy(outbuffer + offset, this->color_light, length_color_light);
      offset += length_color_light;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->dist_light));
      uint32_t length_color_light;
      arrToVar(length_color_light, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_color_light; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_color_light-1]=0;
      this->color_light = (char *)(inbuffer + offset-1);
      offset += length_color_light;
     return offset;
    }

    const char * getType(){ return "pixhwk_ctrl_node/traffic_light"; };
    const char * getMD5(){ return "f8df0c506b0f4a93a3c764f8dfe78ca5"; };

  };

}
#endif