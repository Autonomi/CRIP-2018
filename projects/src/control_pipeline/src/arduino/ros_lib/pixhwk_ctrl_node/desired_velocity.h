#ifndef _ROS_pixhwk_ctrl_node_desired_velocity_h
#define _ROS_pixhwk_ctrl_node_desired_velocity_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pixhwk_ctrl_node
{

  class desired_velocity : public ros::Msg
  {
    public:
      typedef float _velocity_type;
      _velocity_type velocity;
      typedef int8_t _priority_type;
      _priority_type priority;
      typedef int8_t _node_id_type;
      _node_id_type node_id;

    desired_velocity():
      velocity(0),
      priority(0),
      node_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity);
      union {
        int8_t real;
        uint8_t base;
      } u_priority;
      u_priority.real = this->priority;
      *(outbuffer + offset + 0) = (u_priority.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->priority);
      union {
        int8_t real;
        uint8_t base;
      } u_node_id;
      u_node_id.real = this->node_id;
      *(outbuffer + offset + 0) = (u_node_id.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->node_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velocity));
      union {
        int8_t real;
        uint8_t base;
      } u_priority;
      u_priority.base = 0;
      u_priority.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->priority = u_priority.real;
      offset += sizeof(this->priority);
      union {
        int8_t real;
        uint8_t base;
      } u_node_id;
      u_node_id.base = 0;
      u_node_id.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->node_id = u_node_id.real;
      offset += sizeof(this->node_id);
     return offset;
    }

    const char * getType(){ return "pixhwk_ctrl_node/desired_velocity"; };
    const char * getMD5(){ return "e42d3ef493b1319a15d2180a4aa66278"; };

  };

}
#endif