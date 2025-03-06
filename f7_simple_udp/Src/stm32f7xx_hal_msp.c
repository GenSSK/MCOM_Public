/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : stm32f7xx_hal_msp.c
  * Description        : This file provides code for the MSP Initialization 
  *                      and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */
 
/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{
  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_RCC_SYSCFG_CLK_ENABLE();

  /* System interrupt init*/

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

///**
//* @brief TIM_Encoder MSP Initialization
//* This function configures the hardware resources used in this example
//* @param htim_encoder: TIM_Encoder handle pointer
//* @retval None
//*/
//void HAL_TIM_Encoder_MspInit(TIM_HandleTypeDef* htim_encoder)
//{
//  GPIO_InitTypeDef GPIO_InitStruct = {0};
//  if(htim_encoder->Instance==TIM1)
//  {
//  /* USER CODE BEGIN TIM1_MspInit 0 */
//
//  /* USER CODE END TIM1_MspInit 0 */
//    /* Peripheral clock enable */
//    __HAL_RCC_TIM1_CLK_ENABLE();
//
//    __HAL_RCC_GPIOE_CLK_ENABLE();
//    /**TIM1 GPIO Configuration
//    PE9     ------> TIM1_CH1
//    PE11     ------> TIM1_CH2
//    */
//    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_11;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//    GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
//    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
//
//  /* USER CODE BEGIN TIM1_MspInit 1 */
//
//  /* USER CODE END TIM1_MspInit 1 */
//  }
//  else if(htim_encoder->Instance==TIM3)
//  {
//  /* USER CODE BEGIN TIM3_MspInit 0 */
//
//  /* USER CODE END TIM3_MspInit 0 */
//    /* Peripheral clock enable */
//    __HAL_RCC_TIM3_CLK_ENABLE();
//
//    __HAL_RCC_GPIOA_CLK_ENABLE();
//    __HAL_RCC_GPIOB_CLK_ENABLE();
//    /**TIM3 GPIO Configuration
//    PA6     ------> TIM3_CH1
//    PB5     ------> TIM3_CH2
//    */
//    GPIO_InitStruct.Pin = GPIO_PIN_6;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//    GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
//    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
//
//    GPIO_InitStruct.Pin = GPIO_PIN_5;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//    GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
//    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//
//  /* USER CODE BEGIN TIM3_MspInit 1 */
//
//  /* USER CODE END TIM3_MspInit 1 */
//  }
//  else if(htim_encoder->Instance==TIM4)
//  {
//  /* USER CODE BEGIN TIM4_MspInit 0 */
//
//  /* USER CODE END TIM4_MspInit 0 */
//    /* Peripheral clock enable */
//    __HAL_RCC_TIM4_CLK_ENABLE();
//
//    __HAL_RCC_GPIOD_CLK_ENABLE();
//    /**TIM4 GPIO Configuration
//    PD12     ------> TIM4_CH1
//    PD13     ------> TIM4_CH2
//    */
//    GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//    GPIO_InitStruct.Alternate = GPIO_AF2_TIM4;
//    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
//
//  /* USER CODE BEGIN TIM4_MspInit 1 */
//
//  /* USER CODE END TIM4_MspInit 1 */
//  }
//  else if(htim_encoder->Instance==TIM8)
//  {
//  /* USER CODE BEGIN TIM8_MspInit 0 */
//
//  /* USER CODE END TIM8_MspInit 0 */
//    /* Peripheral clock enable */
//    __HAL_RCC_TIM8_CLK_ENABLE();
//
//    __HAL_RCC_GPIOC_CLK_ENABLE();
//    /**TIM8 GPIO Configuration
//    PC6     ------> TIM8_CH1
//    PC7     ------> TIM8_CH2
//    */
//    GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//    GPIO_InitStruct.Alternate = GPIO_AF3_TIM8;
//    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
//
//  /* USER CODE BEGIN TIM8_MspInit 1 */
//
//  /* USER CODE END TIM8_MspInit 1 */
//  }
//
//}
//
///**
//* @brief TIM_Encoder MSP De-Initialization
//* This function freeze the hardware resources used in this example
//* @param htim_encoder: TIM_Encoder handle pointer
//* @retval None
//*/
//void HAL_TIM_Encoder_MspDeInit(TIM_HandleTypeDef* htim_encoder)
//{
//  if(htim_encoder->Instance==TIM1)
//  {
//  /* USER CODE BEGIN TIM1_MspDeInit 0 */
//
//  /* USER CODE END TIM1_MspDeInit 0 */
//    /* Peripheral clock disable */
//    __HAL_RCC_TIM1_CLK_DISABLE();
//
//    /**TIM1 GPIO Configuration
//    PE9     ------> TIM1_CH1
//    PE11     ------> TIM1_CH2
//    */
//    HAL_GPIO_DeInit(GPIOE, GPIO_PIN_9|GPIO_PIN_11);
//
//  /* USER CODE BEGIN TIM1_MspDeInit 1 */
//
//  /* USER CODE END TIM1_MspDeInit 1 */
//  }
//  else if(htim_encoder->Instance==TIM3)
//  {
//  /* USER CODE BEGIN TIM3_MspDeInit 0 */
//
//  /* USER CODE END TIM3_MspDeInit 0 */
//    /* Peripheral clock disable */
//    __HAL_RCC_TIM3_CLK_DISABLE();
//
//    /**TIM3 GPIO Configuration
//    PA6     ------> TIM3_CH1
//    PB5     ------> TIM3_CH2
//    */
//    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_6);
//
//    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_5);
//
//  /* USER CODE BEGIN TIM3_MspDeInit 1 */
//
//  /* USER CODE END TIM3_MspDeInit 1 */
//  }
//  else if(htim_encoder->Instance==TIM4)
//  {
//  /* USER CODE BEGIN TIM4_MspDeInit 0 */
//
//  /* USER CODE END TIM4_MspDeInit 0 */
//    /* Peripheral clock disable */
//    __HAL_RCC_TIM4_CLK_DISABLE();
//
//    /**TIM4 GPIO Configuration
//    PD12     ------> TIM4_CH1
//    PD13     ------> TIM4_CH2
//    */
//    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_12|GPIO_PIN_13);
//
//  /* USER CODE BEGIN TIM4_MspDeInit 1 */
//
//  /* USER CODE END TIM4_MspDeInit 1 */
//  }
//  else if(htim_encoder->Instance==TIM8)
//  {
//  /* USER CODE BEGIN TIM8_MspDeInit 0 */
//
//  /* USER CODE END TIM8_MspDeInit 0 */
//    /* Peripheral clock disable */
//    __HAL_RCC_TIM8_CLK_DISABLE();
//
//    /**TIM8 GPIO Configuration
//    PC6     ------> TIM8_CH1
//    PC7     ------> TIM8_CH2
//    */
//    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_6|GPIO_PIN_7);
//
//  /* USER CODE BEGIN TIM8_MspDeInit 1 */
//
//  /* USER CODE END TIM8_MspDeInit 1 */
//  }
//
//}

/**
* @brief UART MSP Initialization
* This function configures the hardware resources used in this example
* @param huart: UART handle pointer
* @retval None
*/
void HAL_UART_MspInit(UART_HandleTypeDef* huart)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(huart->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspInit 0 */

  /* USER CODE END USART3_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_USART3_CLK_ENABLE();
  
    __HAL_RCC_GPIOD_CLK_ENABLE();
    /**USART3 GPIO Configuration    
    PD8     ------> USART3_TX
    PD9     ------> USART3_RX 
    */
    GPIO_InitStruct.Pin = STLK_RX_Pin|STLK_TX_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /* USER CODE BEGIN USART3_MspInit 1 */

  /* USER CODE END USART3_MspInit 1 */
  }

}

/**
* @brief UART MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param huart: UART handle pointer
* @retval None
*/
void HAL_UART_MspDeInit(UART_HandleTypeDef* huart)
{
  if(huart->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspDeInit 0 */

  /* USER CODE END USART3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART3_CLK_DISABLE();
  
    /**USART3 GPIO Configuration    
    PD8     ------> USART3_TX
    PD9     ------> USART3_RX 
    */
    HAL_GPIO_DeInit(GPIOD, STLK_RX_Pin|STLK_TX_Pin);

  /* USER CODE BEGIN USART3_MspDeInit 1 */

  /* USER CODE END USART3_MspDeInit 1 */
  }

}

/**
* @brief PCD MSP Initialization
* This function configures the hardware resources used in this example
* @param hpcd: PCD handle pointer
* @retval None
*/
void HAL_PCD_MspInit(PCD_HandleTypeDef* hpcd)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(hpcd->Instance==USB_OTG_FS)
  {
  /* USER CODE BEGIN USB_OTG_FS_MspInit 0 */

  /* USER CODE END USB_OTG_FS_MspInit 0 */
  
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USB_OTG_FS GPIO Configuration    
    PA8     ------> USB_OTG_FS_SOF
    PA9     ------> USB_OTG_FS_VBUS
    PA10     ------> USB_OTG_FS_ID
    PA11     ------> USB_OTG_FS_DM
    PA12     ------> USB_OTG_FS_DP 
    */
    GPIO_InitStruct.Pin = USB_SOF_Pin|USB_ID_Pin|USB_DM_Pin|USB_DP_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = USB_VBUS_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(USB_VBUS_GPIO_Port, &GPIO_InitStruct);

    /* Peripheral clock enable */
    __HAL_RCC_USB_OTG_FS_CLK_ENABLE();
  /* USER CODE BEGIN USB_OTG_FS_MspInit 1 */

  /* USER CODE END USB_OTG_FS_MspInit 1 */
  }

}

/**
* @brief PCD MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hpcd: PCD handle pointer
* @retval None
*/
void HAL_PCD_MspDeInit(PCD_HandleTypeDef* hpcd)
{
  if(hpcd->Instance==USB_OTG_FS)
  {
  /* USER CODE BEGIN USB_OTG_FS_MspDeInit 0 */

  /* USER CODE END USB_OTG_FS_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USB_OTG_FS_CLK_DISABLE();
  
    /**USB_OTG_FS GPIO Configuration    
    PA8     ------> USB_OTG_FS_SOF
    PA9     ------> USB_OTG_FS_VBUS
    PA10     ------> USB_OTG_FS_ID
    PA11     ------> USB_OTG_FS_DM
    PA12     ------> USB_OTG_FS_DP 
    */
    HAL_GPIO_DeInit(GPIOA, USB_SOF_Pin|USB_VBUS_Pin|USB_ID_Pin|USB_DM_Pin 
                          |USB_DP_Pin);

  /* USER CODE BEGIN USB_OTG_FS_MspDeInit 1 */

  /* USER CODE END USB_OTG_FS_MspDeInit 1 */
  }

}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
