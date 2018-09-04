/*
 * CalibrateServer.cpp
 *
 *  Created on: Sep 2, 2018
 *      Author: ocsmith
 */
#include "CalibrateServer.h"

void CalibrateServer::event(float * packet) {

	/*
	 myHome[0] = myHome[0] + packet[0];
	 myHome[1] = myHome[1] + packet[1];					//sets homePosition to current values
	 myHome[2] = myHome[2] + packet[2];
	 */

	for (int i = 0; i < myNumJoints; i++) // for each joint,
			{	//setting the encoder reading in reference to new homePositions
		myJointData[i]->pidReset(0);
	}
}

