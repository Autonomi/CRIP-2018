#ifndef _ROS_can_e2o_status_h
#define _ROS_can_e2o_status_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace can
{

  class e2o_status : public ros::Msg
  {
    public:
      typedef int32_t _velocity_type;
      _velocity_type velocity;
      typedef int32_t _throttle_type;
      _throttle_type throttle;
      typedef int32_t _brake_type;
      _brake_type brake;
      typedef int32_t _steering_type;
      _steering_type steering;
      typedef int32_t _steering_direc_type;
      _steering_direc_type steering_direc;
      typedef std_msgs::Header _header_type;
      _header_type header;

    e2o_status():
      velocity(0),
      throttle(0),
      brake(0),
      steering(0),
      steering_direc(0),
      header()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_velocity;
      u_velocity.real = this->velocity;
      *(outbuffer + offset + 0) = (u_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity);
      union {
        int32_t real;
        uint32_t base;
      } u_throttle;
      u_throttle.real = this->throttle;
      *(outbuffer + offset + 0) = (u_throttle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_throttle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_throttle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_throttle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->throttle);
      union {
        int32_t real;
        uint32_t base;
      } u_brake;
      u_brake.real = this->brake;
      *(outbuffer + offset + 0) = (u_brake.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_brake.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_brake.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_brake.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->brake);
      union {
        int32_t real;
        uint32_t base;
      } u_steering;
      u_steering.real = this->steering;
      *(outbuffer + offset + 0) = (u_steering.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steering.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steering.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steering.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steering);
      union {
        int32_t real;
        uint32_t base;
      } u_steering_direc;
      u_steering_direc.real = this->steering_direc;
      *(outbuffer + offset + 0) = (u_steering_direc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steering_direc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steering_direc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steering_direc.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steering_direc);
      offset += this->header.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_velocity;
      u_velocity.base = 0;
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity = u_velocity.real;
      offset += sizeof(this->velocity);
      union {
        int32_t real;
        uint32_t base;
      } u_throttle;
      u_throttle.base = 0;
      u_throttle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_throttle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_throttle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_throttle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->throttle = u_throttle.real;
      offset += sizeof(this->throttle);
      union {
        int32_t real;
        uint32_t base;
      } u_brake;
      u_brake.base = 0;
      u_brake.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_brake.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_brake.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_brake.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->brake = u_brake.real;
      offset += sizeof(this->brake);
      union {
        int32_t real;
        uint32_t base;
      } u_steering;
      u_steering.base = 0;
      u_steering.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steering.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steering.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steering.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steering = u_steering.real;
      offset += sizeof(this->steering);
      union {
        int32_t real;
        uint32_t base;
      } u_steering_direc;
      u_steering_direc.base = 0;
      u_steering_direc.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steering_direc.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steering_direc.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steering_direc.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steering_direc = u_steering_direc.real;
      offset += sizeof(this->steering_direc);
      offset += this->header.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "can/e2o_status"; };
    const char * getMD5(){ return "94b6373a082ac03fa17612f6941ccfa8"; };

  };

}
#endif