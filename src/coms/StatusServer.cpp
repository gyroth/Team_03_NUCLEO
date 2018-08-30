/*
 * StatusServer.cpp
 *
 *  Created on: Aug 30, 2018
 *      Author: ocsmith
 */
#include "StatusServer.h"


void StatusServer::event(float * packet){
	/*
	   * ======= Generate a response to be sent back to MATLAB =============
	   */

	  // we will be using the same memory area in which the incoming packet was stored,
	  // however, a we need to perform a type cast first (for convenience).
	  uint8_t * buff = (uint8_t *) packet;

	  // re-initialize the packet to all zeros
	  for(int i = 4; i < 64;i++)
	      buff[i]=0;

	  /**
	   * The following loop reads sensor data (encoders ticks, joint velocities and
	   * force readings) and writes it in the response packet.
	   */
	  for(int i = 0; i < myNumJoints; i++)
	    {
	      float position = myJointData[i]->GetPIDPosition();
	      float velocity = myJointData[i]->getVelocity();
	      float torque   = myJointData[i]->loadCell->read();

	      packet[(i*3)+0] = position;
	      packet[(i*3)+1] = velocity;
	      packet[(i*3)+2] = torque;
	    }
}




