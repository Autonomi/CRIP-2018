#ifndef _ROS_pixhwk_ctrl_node_PixHawk_SteeringControl_h
#define _ROS_pixhwk_ctrl_node_PixHawk_SteeringControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pixhwk_ctrl_node
{

  class PixHawk_SteeringControl : public ros::Msg
  {
    public:
      typedef float _steering_type;
      _steering_type steering;

    PixHawk_SteeringControl():
      steering(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->steering);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->steering));
     return offset;
    }

    const char * getType(){ return "pixhwk_ctrl_node/PixHawk_SteeringControl"; };
    const char * getMD5(){ return "13be5889908f58ce029441890e49203c"; };

  };

}
#endif