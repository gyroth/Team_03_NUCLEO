#ifndef  StatusServer_H
#define StatusServer_H
#include <PID_Bowler.h>
#include <PacketEvent.h>
#include "../drivers/MyPid.h"
#include <cmath>        // std::abs

#define STATUS_SERVER_ID 21
class StatusServer: public PacketEventAbstract{

private:
	PIDimp ** myJointData;
	int myNumJoints;

public:
  // Packet ID needs to be set
   StatusServer (PIDimp ** jointData, int numJoints)
   : PacketEventAbstract(STATUS_SERVER_ID){
	   myJointData = jointData;
	   myNumJoints = numJoints;
  }

  //User function to be called when a packet comes in
  // Buffer contains data from the packet coming in at the start of the function
  // User data is written into the buffer to send it back
  void event(float * packet);
};


#endif /* end of include guard: Pid_server */
