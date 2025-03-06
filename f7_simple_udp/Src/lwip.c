/**
 ******************************************************************************
  * File Name          : LWIP.c
  * Description        : This file provides initialization code for LWIP
  *                      middleWare.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <Third_Party/LwIP/src/include/lwip/inet.h>
#include <memory.h>
#include "lwip.h"
#include "lwip/init.h"
#include "lwip/netif.h"
#if defined ( __CC_ARM )  /* MDK ARM Compiler */
#include "lwip/sio.h"
#endif /* MDK ARM Compiler */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/* Private function prototypes -----------------------------------------------*/
/* ETH Variables initialization ----------------------------------------------*/
void Error_Handler(void);

/* DHCP Variables initialization ---------------------------------------------*/
uint32_t DHCPfineTimer = 0;
uint32_t DHCPcoarseTimer = 0;
/* USER CODE BEGIN 1 */
int set_addr = 0;
/* USER CODE END 1 */

/* Variables Initialization */
struct netif gnetif;
ip4_addr_t ipaddr;
ip4_addr_t netmask;
ip4_addr_t gw;
uint8_t IP_ADDRESS[4];
uint8_t NETMASK_ADDRESS[4];
uint8_t GATEWAY_ADDRESS[4];

/* USER CODE BEGIN 2 */

uint32_t prefix2mask(int prefix){
    struct in_addr mask;
    memset(&mask, 0, sizeof(mask));
    if (prefix) {
        return htonl(~((1 << (32 - prefix)) - 1));
    } else {
        return htonl(0);
    }
}

void MX_LWIP_Setaddres(char *ipaddr_CIDR, char *gataway){
    /* divided to ip address and prefix  */
    int count = 0;
	int num = 0;
	int prefix = 0;
    char buf[15] = {'\0'};
    /* address part */
    while(1) {
        if (ipaddr_CIDR[count] == '/') break;
        buf[num] = ipaddr_CIDR[count];
        num++;
        count++;
    };
    ip4addr_aton(buf, &ipaddr); //set the ip address
//    printf("%s\n\r", ip4addr_ntoa(&ipaddr)); //check the adress

    /* netmask part */
    count++;
    memset(buf, '\0', sizeof(buf));
    num = 0;
    while (1){
        if (ipaddr_CIDR[count] == '\0') break;
        buf[num] = ipaddr_CIDR[count];
        num++;
        count++;
    }

    netmask.addr = prefix2mask(atoi(buf)); //set the netmask
//    printf("%s\n\r", ip4addr_ntoa(&netmask)); //check the netmask

    ip4addr_aton(gataway, &gw); //set the gateway
    set_addr = 1; //address set flag
}

/*
void MX_LWIP_Setaddres(char *address){
    int count = 0;
    for (int i = 0; i < 4; ++i) {
        int num = 0;
        char buf[3] = {'\0'};
        while(1) {
            if (address[count] == '/') break;
            if (address[count] == '.') break;
            buf[num] = address[count];
            num++;
            count++;
        };
//        printf("buf:%s\n\r", buf);
        IP_ADDRESS[i] = atoi(buf);
        count++;
    }

    int num = 0;
    char buf[2] = {'\0'};
    while(!address[count] == '\0') {
        buf[num] = address[count];
        num++;
        count++;
    }
    int prefix = atoi(buf);
//    printf("prefix: %d\n\r", prefix);

    struct in_addr netmask;
    netmask.s_addr = prefix2mask(prefix);
    char *mask = inet_ntoa(netmask);

//    printf("mask:%s\n\r", mask);
    count = 0;
    for (int i = 0; i < 4; ++i) {
        int num = 0;
        char buf[3] = {'\0'};
        while(!mask[count] == '\0') {
            if (mask[count] == '.') break;
            buf[num] = mask[count];
            num++;
            count++;
        }
//        printf("buf:%s\n\r", buf);
        NETMASK_ADDRESS[i] = atoi(buf);
        count++;
    }

    set_addr = 1;
}*/

void MX_LWIP_Readaddress(){
    if (!set_addr) {
        printf("Does not set the IP address\n\rPlease call MX_LWIP_Setaddres(char *address)\n\r");
        IP_ADDRESS[0] = 1;
        IP_ADDRESS[1] = 1;
        IP_ADDRESS[2] = 1;
        IP_ADDRESS[3] = 1;
        NETMASK_ADDRESS[0] = 255;
        NETMASK_ADDRESS[1] = 255;
        NETMASK_ADDRESS[2] = 255;
        NETMASK_ADDRESS[3] = 0;
        GATEWAY_ADDRESS[0] = 10;
        GATEWAY_ADDRESS[1] = 0;
        GATEWAY_ADDRESS[2] = 1;
        GATEWAY_ADDRESS[3] = 1;
    }
}

/* USER CODE END 2 */

/**
  * LwIP initialization function
  */
void MX_LWIP_Init(void)
{
/* IP addresses initialization */
//  IP_ADDRESS[0] = 10;
//  IP_ADDRESS[1] = 0;
//  IP_ADDRESS[2] = 1;
//  IP_ADDRESS[3] = 3;
//  NETMASK_ADDRESS[0] = 255;
//  NETMASK_ADDRESS[1] = 255;
//  NETMASK_ADDRESS[2] = 255;
//  NETMASK_ADDRESS[3] = 0;
//  GATEWAY_ADDRESS[0] = 10;
//  GATEWAY_ADDRESS[1] = 0;
//  GATEWAY_ADDRESS[2] = 1;
//  GATEWAY_ADDRESS[3] = 1;
    MX_LWIP_Readaddress();

  /* Initilialize the LwIP stack without RTOS */
//  printf("bfore init\n\r");
  lwip_init();

//  ipaddr.addr = 0;
//  netmask.addr = 0;
//  gw.addr = 0;

  /* IP addresses initialization without DHCP (IPv4) */
//  IP4_ADDR(&ipaddr, IP_ADDRESS[0], IP_ADDRESS[1], IP_ADDRESS[2], IP_ADDRESS[3]);
//  IP4_ADDR(&netmask, NETMASK_ADDRESS[0], NETMASK_ADDRESS[1] , NETMASK_ADDRESS[2], NETMASK_ADDRESS[3]);
//  IP4_ADDR(&gw, GATEWAY_ADDRESS[0], GATEWAY_ADDRESS[1], GATEWAY_ADDRESS[2], GATEWAY_ADDRESS[3]);

  /* add the network interface (IPv4/IPv6) without RTOS */
//  printf("bfore add\n\r");
  netif_add(&gnetif, &ipaddr, &netmask, &gw, NULL, &ethernetif_init, &ethernet_input);

  /* Registers the default network interface */
//  printf("bfore regist\n\r");
  netif_set_default(&gnetif);

  if (netif_is_link_up(&gnetif))
  {
    /* When the netif is fully configured this function must be called */
    netif_set_up(&gnetif);
  }
  else
  {
    /* When the netif link is down this function must be called */
    netif_set_down(&gnetif);
  }

/* USER CODE BEGIN 3 */

/* USER CODE END 3 */

//  gnetif.ip_addr.addr;

  printf("set my address: %s\n\r", ip4addr_ntoa(&gnetif.ip_addr));
  printf("set my netmask: %s\n\r", ip4addr_ntoa(&gnetif.netmask));
  printf("set my gateway: %s\n\r", ip4addr_ntoa(&gnetif.gw));

/* USER CODE BEGIN 3 */

/* USER CODE END 3 */
}

#ifdef USE_OBSOLETE_USER_CODE_SECTION_4
/* Kept to help code migration. (See new 4_1, 4_2... sections) */
/* Avoid to use this user section which will become obsolete. */
/* USER CODE BEGIN 4 */
/* USER CODE END 4 */
#endif

/**
 * ----------------------------------------------------------------------
 * Function given to help user to continue LwIP Initialization
 * Up to user to complete or change this function ...
 * Up to user to call this function in main.c in while (1) of main(void) 
 *-----------------------------------------------------------------------
 * Read a received packet from the Ethernet buffers 
 * Send it to the lwIP stack for handling
 * Handle timeouts if LWIP_TIMERS is set and without RTOS
 * Handle the llink status if LWIP_NETIF_LINK_CALLBACK is set and without RTOS 
 */
void MX_LWIP_Process(void)
{
/* USER CODE BEGIN 4_1 */
/* USER CODE END 4_1 */
  ethernetif_input(&gnetif);


/* USER CODE BEGIN 4_2 */
/* USER CODE END 4_2 */
  /* Handle timeouts */
  sys_check_timeouts();

/* USER CODE BEGIN 4_3 */
/* USER CODE END 4_3 */
}

#if defined ( __CC_ARM )  /* MDK ARM Compiler */
/**
 * Opens a serial device for communication.
 *
 * @param devnum device number
 * @return handle to serial device if successful, NULL otherwise
 */
sio_fd_t sio_open(u8_t devnum)
{
  sio_fd_t sd;

/* USER CODE BEGIN 7 */
  sd = 0; // dummy code
/* USER CODE END 7 */
	
  return sd;
}

/**
 * Sends a single character to the serial device.
 *
 * @param c character to send
 * @param fd serial device handle
 *
 * @note This function will block until the character can be sent.
 */
void sio_send(u8_t c, sio_fd_t fd)
{
/* USER CODE BEGIN 8 */
/* USER CODE END 8 */
}

/**
 * Reads from the serial device.
 *
 * @param fd serial device handle
 * @param data pointer to data buffer for receiving
 * @param len maximum length (in bytes) of data to receive
 * @return number of bytes actually received - may be 0 if aborted by sio_read_abort
 *
 * @note This function will block until data can be received. The blocking
 * can be cancelled by calling sio_read_abort().
 */
u32_t sio_read(sio_fd_t fd, u8_t *data, u32_t len)
{
  u32_t recved_bytes;

/* USER CODE BEGIN 9 */
  recved_bytes = 0; // dummy code
/* USER CODE END 9 */	
  return recved_bytes;
}

/**
 * Tries to read from the serial device. Same as sio_read but returns
 * immediately if no data is available and never blocks.
 *
 * @param fd serial device handle
 * @param data pointer to data buffer for receiving
 * @param len maximum length (in bytes) of data to receive
 * @return number of bytes actually received
 */
u32_t sio_tryread(sio_fd_t fd, u8_t *data, u32_t len)
{
  u32_t recved_bytes;

/* USER CODE BEGIN 10 */
  recved_bytes = 0; // dummy code
/* USER CODE END 10 */	
  return recved_bytes;
}
#endif /* MDK ARM Compiler */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
