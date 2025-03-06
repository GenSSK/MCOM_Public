/*!
 * @file    f7eth.cpp
 * @brief   This is the cpp file for f7eth class.
 * @author  Cooperative Robotics Lab, Tokyo Denki University
 * @date    2020/06/14
 */

//#define debug

#include "mbed.h"
#include "lwip.h"
#include <inet.h>
#define __STDC_FORMAT_MACROS
#include "udp.h"
#include "dataStruct.h"
#include "f7eth.h"

Timer tim;

/*!
 * @brief   Initializer of f7eth class.
 * @details MUST BE CALLED BEFORE USING THIS CLASS.
 * @param[in]   auto_stop	If true, the class will stop sending automatically when the data is not received.
 * @param[in]   src_addr	My address, must save the CIDR type (ex. {"10.0.1.3/24"}.
 * @param[in]   src_gateway	My gatewey (ex. {"10.0.0.1"}
 * @param[in]   src_port	My port (ex. 12345
 * @param[in]   dst_addr	Send address, (ex. {"10.0.1.4"}
 * @param[in]   dst_port	Send port (ex. 12345
 */
void f7eth::init(
		bool auto_stop,
		char *src_addr,
		char *src_gateway,
		uint16_t src_port,
		char *dst_addr,
		uint16_t dst_port
) {
	printf("-----UDP settings st@rt-----\n\r");
	auto_stop_flag = auto_stop;
	dst_port_ = dst_port;

	MX_LWIP_Setaddres(src_addr, src_gateway);   // set my address
	MX_LWIP_Init();

	tim.start();

	ptel_pcb = udp_new();

	ip4addr_aton(dst_addr, &ip4_dst_addr); // set the destination address

	MX_LWIP_Process();
	udp_bind(ptel_pcb, IP_ADDR_ANY, src_port);
	udp_recv(ptel_pcb, reinterpret_cast<udp_recv_fn>(recv), NULL);
	printf("set my port: %d\n\r", src_port);
	printf("set send address: %s\n\r", ip4addr_ntoa(&ip4_dst_addr));
	printf("set send port: %d\n\r", dst_port);
	initialized_flag = true;
	printf("-----UDP settings end-----\n\r");
	printf("-----UDP connection st@rt-----\n\r");
}

/*!
 * @brief   Send function
 */
void f7eth::send() {
	if(!auto_stop_flag) send_trg = send_trg_initial_value;
	if(send_trg > 0) {
		topc.returnCount = tombed.checkCount;

		p_send = pbuf_alloc(PBUF_TRANSPORT, sizeof(topc), PBUF_RAM);
		memcpy(p_send->payload, &topc, sizeof(topc));

		udp_sendto(ptel_pcb, p_send, &ip4_dst_addr, dst_port_);
		send_flag = !send_flag;

		pbuf_free(p_send); //De-allocate packet buffer
		send_count++;
		if (send_count > division_counts_for_check) {
			send_count = 0;
#ifdef debug
			send_time = tim.read_us();
	        printf("@debug send period: %f ms\n\r", (float)(send_time - send_old_time) / 1000 / 100000);
            send_old_time = tim.read_us();
#endif
			send_check_flag = !send_check_flag;
		}
		auto_stop_state = false;
		send_trg--;
	} else {
		send_flag = false;
		auto_stop_state = true;
	}

}

/*!
 * @brief   Receive function
 */
void f7eth::recv(void *arg, struct udp_pcb *pcb, struct pbuf *p, struct ip_addr *addr, u16_t port) {
	/* execute when get recv data */
	if (p != nullptr) {
		memcpy(&tombed, p->payload, p->len);
		pbuf_free(p); //De-allocate packet buffer
		recv_count += 50;
		recv_flag = true;
		send_trg = send_trg_initial_value;
	} else {
		recv_flag = false;
	}

	if(recv_count > division_counts_for_check){
		recv_count = 0;
#ifdef debug
		recv_time = tim.read_us();
        printf("@debug recv period: %f ms\n\r", (float)(recv_time - recv_old_time) / 1000 / 10000);
        printf("@debug mbedcheck: %d\n\r", topc.mbedCheck);
        recv_old_time = tim.read_us();
#endif
		recv_check_flag = !recv_check_flag;
	}
}

/*!
 * @brief   Check state of receive data
 * @return  true if received data, false if not.
 */
bool f7eth::get_recv_state() {
	return recv_flag;
}

/*!
 * @brief   Check state of receive data (divided into 1/n)
 * @return  When the return value alternates between true and false, it indicates the receiving status.
 */
bool f7eth::get_recv_check_state() {
	return recv_check_flag;
}

/*!
 * @brief   Check state of send data
 * @return  true if sent data, false if not.
 */
bool f7eth::get_send_state() {
	return send_flag;
}

/*!
 * @brief   Check state of receive data (divided into 1/n)
 * @return  When the return value alternates between true and false, it indicates the sending status.
 */
bool f7eth::get_send_check_state() {
	return send_check_flag;
}

/*!
 * @brief   Check state of initialization
 * @return  true if initialized, false if not.
 */
bool f7eth::get_initialized_state() {
	return initialized_flag;
}

/*!
 * @brief   Check state of auto stop
 * @return  true if stopping, false if working.
 */
bool f7eth::get_auto_stop_state() {
	return auto_stop_state;
}


//Copyright (c) 2022, Cooperative Robotics Lab, Tokyo Denki University
//All rights reserved.