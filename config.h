/*!
 * @file    config.h
 * @brief   Write a configuration here.
 * @author  Cooperative Robotics Lab, Tokyo Denki University
 * @date    2020/06/14
 */

#ifndef MCOM_CONFIG_H
#define MCOM_CONFIG_H

DigitalOut mbed_gled(LED1);   // Green LED is defined in mbed.h
DigitalOut mbed_bled(LED2);   // Blue LED is defined in mbed.h
DigitalOut mbed_rled(LED3);   // Red LED is defined in mbed.h

f7eth udp{};     		  // f7eth is defined in f7eth.h

int state = 0;
float float_value = 0.0;
float value[3] = {0.0f};
float sinValue[3] = {0.0f};
uint16_t rawValue = 0x8000;
int val = 0;
int count = 0;

bool recv_flag = false;
bool recv_led_flag = false;
bool send_flag = false;
bool send_led_flag = false;
bool initial_flag = false;

PwmOut pwm[4] = {PE_5, PE_6, PF_8, PF_7};
DigitalOut enable[4] = {PE_0, PE_15, PE_2, PD_11};

#endif //MCOM_CONFIG_H
