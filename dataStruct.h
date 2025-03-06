/*!
 * @file    dataStruct.h
 * @brief   This struct is for communication between the mbed and the PC.
 * @author  Cooperative Robotics Lab, Tokyo Denki University
 * @date    2020/06/14
 */

#ifndef MCOM_DATASTRUCT_H
#define MCOM_DATASTRUCT_H

/* PC to mbed */
struct toMbed{
	float ch1 = 0.0;
	float ch2 = 0.0;
	float ch3 = 0.0;
	float ch4 = 0.0;
	float led1 = 0.0;
	float led2 = 0.0;
	float led3 = 0.0;
	float led4 = 0.0;
	float led5 = 0.0;
	float led6 = 0.0;
	float led7 = 0.0;
	float rgb_r = 0.0;
	float rgb_g = 0.0;
	float rgb_b = 0.0;
	bool servo1 = false;
	bool servo2 = false;
	bool servo3 = false;
	bool servo4 = false;
	int checkCount = 0;
	int returnCount = 0;
};

/* mbed to PC */
struct toPC{
	int tim1_pulse = 0;
	int tim3_pulse = 0;
	int tim4_pulse = 0;
	int tim8_pulse = 0;
	float ch1 = 0.0;
	float ch2 = 0.0;
	float ch3 = 0.0;
	float ch4 = 0.0;
	int checkCount = 0;
	int returnCount = 0;
	int mbedCheck = 0;
	int foot = 0;
};
#endif //MCOM_DATASTRUCT_H

//Copyright (c) 2021, Cooperative Robotics Lab, Tokyo Denki University
//All rights reserved.