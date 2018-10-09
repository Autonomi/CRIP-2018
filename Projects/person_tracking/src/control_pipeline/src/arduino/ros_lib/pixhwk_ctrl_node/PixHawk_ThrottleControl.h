#ifndef _ROS_pixhwk_ctrl_node_PixHawk_ThrottleControl_h
#define _ROS_pixhwk_ctrl_node_PixHawk_ThrottleControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pixhwk_ctrl_node
{

  class PixHawk_ThrottleControl : public ros::Msg
  {
    public:
      typedef float _throttle_type;
      _throttle_type throttle;

    PixHawk_ThrottleControl():
      throttle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->throttle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->throttle));
     return offset;
    }

    const char * getType(){ return "pixhwk_ctrl_node/PixHawk_ThrottleControl"; };
    const char * getMD5(){ return "a0e4c91f838bf9ac9a81509ea028ea0b"; };

  };

}
#endif