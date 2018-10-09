#ifndef _ROS_pixhwk_ctrl_node_PixHawk_Goal_h
#define _ROS_pixhwk_ctrl_node_PixHawk_Goal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pixhwk_ctrl_node
{

  class PixHawk_Goal : public ros::Msg
  {
    public:
      typedef float _Lat_type;
      _Lat_type Lat;
      typedef float _Lon_type;
      _Lon_type Lon;

    PixHawk_Goal():
      Lat(0),
      Lon(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->Lat);
      offset += serializeAvrFloat64(outbuffer + offset, this->Lon);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Lat));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Lon));
     return offset;
    }

    const char * getType(){ return "pixhwk_ctrl_node/PixHawk_Goal"; };
    const char * getMD5(){ return "6481a43b47ce4303d5bdcb88c9414b02"; };

  };

}
#endif