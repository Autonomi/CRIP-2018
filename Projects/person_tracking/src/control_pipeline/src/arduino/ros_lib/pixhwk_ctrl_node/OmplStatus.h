#ifndef _ROS_pixhwk_ctrl_node_OmplStatus_h
#define _ROS_pixhwk_ctrl_node_OmplStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace pixhwk_ctrl_node
{

  class OmplStatus : public ros::Msg
  {
    public:
      typedef int8_t _OmplSolStatus_type;
      _OmplSolStatus_type OmplSolStatus;
      typedef const char* _actualmsg_type;
      _actualmsg_type actualmsg;
      typedef ros::Time _stamp_type;
      _stamp_type stamp;

    OmplStatus():
      OmplSolStatus(0),
      actualmsg(""),
      stamp()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_OmplSolStatus;
      u_OmplSolStatus.real = this->OmplSolStatus;
      *(outbuffer + offset + 0) = (u_OmplSolStatus.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->OmplSolStatus);
      uint32_t length_actualmsg = strlen(this->actualmsg);
      varToArr(outbuffer + offset, length_actualmsg);
      offset += 4;
      memcpy(outbuffer + offset, this->actualmsg, length_actualmsg);
      offset += length_actualmsg;
      *(outbuffer + offset + 0) = (this->stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.sec);
      *(outbuffer + offset + 0) = (this->stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_OmplSolStatus;
      u_OmplSolStatus.base = 0;
      u_OmplSolStatus.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->OmplSolStatus = u_OmplSolStatus.real;
      offset += sizeof(this->OmplSolStatus);
      uint32_t length_actualmsg;
      arrToVar(length_actualmsg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_actualmsg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_actualmsg-1]=0;
      this->actualmsg = (char *)(inbuffer + offset-1);
      offset += length_actualmsg;
      this->stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.sec);
      this->stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.nsec);
     return offset;
    }

    const char * getType(){ return "pixhwk_ctrl_node/OmplStatus"; };
    const char * getMD5(){ return "5e50e9584b597fecb0c7c001901c2ff9"; };

  };

}
#endif