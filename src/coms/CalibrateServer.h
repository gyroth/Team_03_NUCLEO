/*
 * CalibrateServer.h
 *
 *  Created on: Sep 3, 2018
 *      Author: ocsmith
 */

#ifndef CALIBRATESERVER_H_
#define CALIBRATESERVER_H_

#include <PID_Bowler.h>
#include <PacketEvent.h>
#include "../drivers/MyPid.h"
#include <cmath>        // std::abs

#define CALIBRATE_SERVER_ID 25
class CalibrateServer: public PacketEventAbstract{

private:
	PIDimp ** myJointData;
	int myNumJoints;

public:
  // Packet ID needs to be set
   CalibrateServer (PIDimp ** jointData, int numJoints)
   : PacketEventAbstract(CALIBRATE_SERVER_ID){

	   myJointData = jointData;
	   myNumJoints = numJoints;

  }

  //User function to be called when a packet comes in
  // Buffer contains data from the packet coming in at the start of the function
  // User data is written into the buffer to send it back
  void event(float * packet);
};





#endif /* CALIBRATESERVER_H_ */
