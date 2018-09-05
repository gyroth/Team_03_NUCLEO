/*
 * CalibrateServer.cpp
 *
 *  Created on: Sep 2, 2018
 *      Author: ocsmith
 */
#include "CalibrateServer.h"

void CalibrateServer::event(float * packet) {

	for (int i = 0; i < myNumJoints; i++) // for each joint,
			{	//setting the encoder reading in reference to new homePositions
		myJointData[i]->pidReset(myJointData[i]->GetPIDPosition() - packet[i]);

	}
}

