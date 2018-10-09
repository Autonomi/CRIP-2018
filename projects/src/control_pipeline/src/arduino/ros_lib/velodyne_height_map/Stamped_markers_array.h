#ifndef _ROS_velodyne_height_map_Stamped_markers_array_h
#define _ROS_velodyne_height_map_Stamped_markers_array_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "visualization_msgs/MarkerArray.h"

namespace velodyne_height_map
{

  class Stamped_markers_array : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef visualization_msgs::MarkerArray _message_type;
      _message_type message;

    Stamped_markers_array():
      header(),
      message()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->message.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->message.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "velodyne_height_map/Stamped_markers_array"; };
    const char * getMD5(){ return "6a89b6b306aa7ce71467b97fc77122f0"; };

  };

}
#endif