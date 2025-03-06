/*!
 * @file    function.h
 * @brief   Write a function here.
 * @author  Cooperative Robotics Lab, Tokyo Denki University
 * @date    2020/06/14
 */

#ifndef MCOM_FUNCTION_H
#define MCOM_FUNCTION_H

/*!
 * @brief   Function of UDP sending
 * @details This function is called by the ticker of UDP send (see main.cpp).
 */
void send(){
	/* Substitute them to the structure for UDP sending */
    udp.topc.ch1 = udp.tombed.ch1;
    udp.topc.ch2 = udp.tombed.ch2;
    udp.topc.ch3 = udp.tombed.ch3;
    udp.topc.ch4 = udp.tombed.ch4;

    /* Get counter values and substitute them to the structure for UDP sending */
	udp.topc.tim1_pulse = get_counter_tim1();
    udp.topc.tim8_pulse = get_counter_tim8();
    udp.topc.tim3_pulse = get_counter_tim3();
    udp.topc.tim4_pulse = get_counter_tim4();

	/* Call the udp send function */
    udp.send();
}

/*!
 * @brief   Function of control
 * @details This is called by the ticker of control (see main.cpp).
 */
void control(){
	/* Set the value of PWM output */
	double u[4] = {0.0};
    u[0] = udp.tombed.ch1;
    u[1] = udp.tombed.ch2;
    u[2] = udp.tombed.ch3;
    u[3] = udp.tombed.ch4;

	for (int i = 0; i < 4; ++i) {
		u[i] = (u[i] * 0.4) + 0.5;
		if (u[i] > 0.9) u[i] = 0.9;
		if (u[i] < 0.1) u[i] = 0.1;

		pwm[i] = u[i];
	}

	/* Set the value of enable output */
	enable[0] = udp.tombed.servo1;
	enable[1] = udp.tombed.servo2;
	enable[2] = udp.tombed.servo3;
	enable[3] = udp.tombed.servo4;

	/* Green LED turns on and off corresponding to UDP receive */
    mbed_gled = udp.get_recv_check_state();

	/* Blue LED turns on and off corresponding to UDP receive */
    mbed_bled = udp.get_send_check_state();

	/* Red LED turns on when initialization finished */
	mbed_gled = udp.get_initialized_state();

	if (udp.get_auto_stop_state()) {
		mbed_bled = 0;
		mbed_rled = 0;
		for (int i = 0; i < 4; ++i) {
			enable[i] = 0;
		}
	} else {
		mbed_bled = udp.get_recv_check_state();
		mbed_rled = udp.get_send_check_state();
	}
}

#endif //MCOM_FUNCTION_H

//Copyright (c) 2021, Cooperative Robotics Lab, Tokyo Denki University
//All rights reserved.