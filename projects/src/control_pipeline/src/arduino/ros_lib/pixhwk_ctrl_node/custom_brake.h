#ifndef _ROS_pixhwk_ctrl_node_custom_brake_h
#define _ROS_pixhwk_ctrl_node_custom_brake_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pixhwk_ctrl_node
{

  class custom_brake : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _brake_value_type;
      _brake_value_type brake_value;
      typedef float _time_brake_applied_in_sec_type;
      _time_brake_applied_in_sec_type time_brake_applied_in_sec;

    custom_brake():
      header(),
      brake_value(0),
      time_brake_applied_in_sec(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->brake_value);
      offset += serializeAvrFloat64(outbuffer + offset, this->time_brake_applied_in_sec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->brake_value));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->time_brake_applied_in_sec));
     return offset;
    }

    const char * getType(){ return "pixhwk_ctrl_node/custom_brake"; };
    const char * getMD5(){ return "bce3bd1c0e31e5eb8f063c9e5f716e53"; };

  };

}
#endif