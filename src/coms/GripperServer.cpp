/**
 * RBE3001 - Nucleo Firmware
 * See header file for more detail on this class.
 * GripperServer.cpp
 */
#include "GripperServer.h"
#include "mbed.h"
#include "Servo.h"


/**
 *  @brief This function handles incoming HID packets from MATLAB.
 *
 *  @description If it receives a 1, close the gripper, if it receives a 0, open the gripper
 */
void GripperServer::event(float * packet){


	uint8_t * buff = (uint8_t *) packet;


	// re-initialize the packet to all zeros
	//for(int i = 4; i < 64;i++)
	//	buff[i]=0;

	if(packet[0]==0){
		myServo -> position(100);
	}
	else if(packet[0]==1){
		myServo -> position(-100);
	}
	packet[0] = myServo->read();


}




