/*!
 * @file    f7eth.h
 * @brief   This is the header file for f7eth class.
 * @author  Cooperative Robotics Lab, Tokyo Denki University
 * @date    2020/06/14
 */

#ifndef F7ETH_H
#define F7ETH_H

#include <inet.h>
#include "mbed.h"
#include "dataStruct.h"

/*! @brief The class that uses UDP communication on F767/F746
 * */
class f7eth{
	uint16_t dst_port_;
    ip_addr_t ip4_dst_addr;
    struct udp_pcb *ptel_pcb;
    struct pbuf *p_send;
    inline static int recv_count;
    inline static int send_count;
    inline static int check_count;
    inline static int send_time;
    inline static int send_old_time;
    inline static int recv_time;
    inline static int recv_old_time;
    inline static int send_trg;

	inline static bool recv_flag = false;         /// flag to check the state of receiving data
	inline static bool recv_check_flag = false;   /// flag to check if the data is received (divided into 1/n)
	inline static bool send_flag = false;         /// flag to check the state of sending data
	inline static bool send_check_flag = false;   /// flag to check if the data is sent (divided into 1/n)
	inline static bool initialized_flag = false;  /// flag to check if the class is initialized
	inline static bool auto_stop_flag = true;     /// flag to auto stop

	void bind();

 public:
    void init(
			bool auto_stop = true,
			char *src_addr = "10.0.4.3/24",
			char *src_gateway = "10.0.0.1",
			uint16_t src_port = 1235,
			char *dst_addr = "10.0.4.4",
			uint16_t dst_port = 12345
					);

    void release();
    void send();
    static void recv(void *arg, struct udp_pcb *pcb, struct pbuf *p, struct ip_addr *addr, u16_t port);
	static bool get_recv_state();
	static bool get_recv_check_state();
	static bool get_send_state();
	static bool get_send_check_state();
	static bool get_initialized_state();
	static bool get_auto_stop_state();

	inline static bool auto_stop_state = false;

    inline static toMbed tombed;
    inline static toPC topc;

	inline static int send_trg_initial_value = 1000;        // index to rest send function
	inline static int division_counts_for_check = 100000;   // division counts for checking the state of sending/receiving data

};

#endif //F7ETH_H

//Copyright (c) 2022, Cooperative Robotics Lab, Tokyo Denki University
//All rights reserved.