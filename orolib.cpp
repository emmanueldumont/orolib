#include "ros/ros.h"
#include "std_msgs/String.h"

#include <iostream>
#include <stdio.h>
#include <string>

#include "orolib.hpp"

using namespace std;

void init_oroChatter()
{
  
  ros::NodeHandle nOroCl;  // Communicate wit oroclient
  
  gOroChatter_pub = nOroCl.advertise<std_msgs::String>("oroChatter", 10);
  
}

// Explain who am i
void sayMyName(char * name, std::string sensorType)
{
  ros::Rate loop_rate(10); // Communicate slow rate

  std::stringstream ss;
  char enumCmd = (char)CMD_ADD_INST;
  
  ss << "BigBrother"<< DELIMITER << enumCmd << DELIMITER <<name<< DELIMITER << sensorType;
  
  std_msgs::String msg;
  msg.data = ss.str();
  oroChatterSender(msg);
}

void sayMyRoom(char * name, std::string room)
{
  ros::Rate loop_rate(10); // Communicate slow rate

  std::stringstream ss;
  char enumCmd = (char)CMD_ADD_PROP;
  
  ss << "BigBrother"<< DELIMITER << enumCmd << DELIMITER <<name<< DELIMITER << "isIn" << DELIMITER<< room;
  
  std_msgs::String msg;
  msg.data = ss.str();
  oroChatterSender(msg);
}

// Send data to oroclient
void oroChatterSender(std_msgs::String msg)
{ 
  gOroChatter_pub.publish(msg);
  ros::spinOnce();
}
