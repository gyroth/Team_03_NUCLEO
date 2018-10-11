/*
 * GripperServer.h
*/
#ifndef GRIPPERSERVER_H_
#define GRIPPERSERVER_H_
#include <PID_Bowler.h>
#include <PacketEvent.h>
#include "../drivers/MyPid.h"
#include <cmath>        // std::abs

#define GRIPPER_SERVER_ID 2
class GripperServer: public PacketEventAbstract{

private:
	Servo * myServo;

public:
  // Packet ID needs to be set
   GripperServer (Servo * servo)
   : PacketEventAbstract(GRIPPER_SERVER_ID){
	   myServo = servo;
  }

  //User function to be called when a packet comes in
  // Buffer contains data from the packet coming in at the start of the function
  // User data is written into the buffer to send it back
  void event(float * packet);
};


#endif /* SRC_COMS_GRIPPERSERVER_H_ */
