/*!
 * @file    main.cpp
 * @author  Cooperative Robotics Lab, Tokyo Denki University
 * @date    2020/06/14
 */

#include "mbed.h"
#include "lwip.h"
#define __STDC_FORMAT_MACROS
#include "f7eth.h"
#include "DAC_HAT.h"
#include "F7_enc.h"
#include "config.h"
#include "function.h"

int main() {
    printf("\n\r--------MCOM ST@RT--------\n\r");

	/* Set up tickers */
    Ticker recv_tick;   // For UDP receiving
    Ticker send_tick;   // For UDP sending
    Ticker cont_tick;   // For control

    /* Initialize counters */
    tim1_init();
    tim8_init();
    tim3_init();
    tim4_init();

	/* Initialize UDP */
    udp.init(
		    true,
		    "10.0.1.1/24",
		    "10.0.0.1",
		    1235,
		    "10.0.1.2",
		    50000
			);     // No call this function, no life

	/* Interval settings */
	float recv_time = 10 * 1e-6;    // receive interval [s],
									// Receiving interval has no problem with setting too fast interval time,
									// We recommend to set 10us (10 * 1e-6).

	float send_time = 500 * 1e-6;    // send interval [s],
									// Sending interval is set more slowly than receiving interval,
									// We recommend sending intervals synchronous with your system's cycle time.

	float cont_time = 100 * 1e-6;   // control interval [s]

	/* set specifications of UDP */
	udp.division_counts_for_check = (int)(0.5 / send_time); // set the interval of division count
	udp.send_trg_initial_value = (int)(1.0 / send_time);    // set the auto-stop-time of sending

	/* Start tickers */
    recv_tick.attach(MX_LWIP_Process, recv_time);   // For UDP receiving
    send_tick.attach(send, send_time);              // For UDP sending
    cont_tick.attach(control, cont_time);           // For control

    while (1) {
        wait_us(1);
    }

    return 0;
}

//Copyright (c) 2022, Cooperative Robotics Lab, Tokyo Denki University
//All rights reserved.