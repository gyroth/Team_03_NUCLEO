/*
 * CalibrateServer.cpp
 *
 *  Created on: Sep 2, 2018
 *      Author: ocsmith
 */
#include "CalibrateServer.h"

void CalibrateServer::event(float * packet){
	printf("calibrating");
	myHome[0] = myHome[0] + packet[0];
	myHome[1] = myHome[1] + packet[1];					//sets homePosition to current values
	myHome[2] = myHome[2] + packet[2];
    printf("myHome = %d , %d , %d",myHome[0],myHome[1],myHome[2]);
	printf("reset\n");
	for (int i = 0; i < myNumJoints; i++) // for each joint,
				{	//setting the encoder reading in reference to new homePositions
		myJointData[i]->pidReset(myJointData[i]->GetPIDPosition() - myHome[i]);
				}
}


