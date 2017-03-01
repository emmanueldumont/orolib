/*** include/pkg_common/utility.hpp ***/

#ifndef OROLIB_HPP
#define OROLIB_HPP


//#include <string>

/*
 * \enum enCommand : Enum command -> Enum for the different implemented commands
 */
enum enCommand
{
    CMD_ADD_INST = 1,
    CMD_ADD_PROP,
    CMD_FIND,
    CMD_REMOVE,
    CMD_CLEAR,
    CMD_REQUEST,
    LAST_CMD
};

/*
 * \def DELIMITER "#" : Delimiter used in the parsing of a command from a client
 * \brief //!!!\\ Care : Do not forget the quotation mark before and after the symbol DELIMITER MUST BE A UNIQUE CHAR
 */
#define DELIMITER "#"

// Chatter able to communicate with oroclient
ros::Publisher gOroChatter_pub;

void init_oroChatter();

void sayMyName(char * name, std::string sensorType);
void sayMyRoom(char * name, std::string room);

void oroChatterSender(std_msgs::String msg);



#include "orolib.cpp"

#endif
