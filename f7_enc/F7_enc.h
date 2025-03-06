//
// Created by Kota Kobayashi on 2019-05-08.
//
/**TIM1 GPIO Configuration
     PE9     ------> TIM1_CH1
     PE11     ------> TIM1_CH2
     */

/**TIM3 GPIO Configuration
     PA6     ------> TIM3_CH1
     PB5     ------> TIM3_CH2
     */

/**TIM4 GPIO Configuration
     PD12     ------> TIM4_CH1
     PD13     ------> TIM4_CH2
     */

/**TIM8 GPIO Configuration
     PC6     ------> TIM8_CH1
     PC7     ------> TIM8_CH2
     */

#ifndef F7_ENC_H_
#define F7_ENC_H_

#include "mbed.h"
TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;
TIM_HandleTypeDef htim8;

void HAL_TIM_Encoder_MspInit(TIM_HandleTypeDef* htim_encoder)
{

	GPIO_InitTypeDef GPIO_InitStruct;
	if(htim_encoder->Instance==TIM1)
	{
		/* USER CODE BEGIN TIM1_MspInit 0 */

		/* USER CODE END TIM1_MspInit 0 */
		/* Peripheral clock enable */
		__HAL_RCC_TIM1_CLK_ENABLE();

		__HAL_RCC_GPIOE_CLK_ENABLE();
		/**TIM1 GPIO Configuration
		PE9     ------> TIM1_CH1
		PE11     ------> TIM1_CH2
		*/
		GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_11;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
		HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

		/* USER CODE BEGIN TIM1_MspInit 1 */

		/* USER CODE END TIM1_MspInit 1 */
	}
	else if(htim_encoder->Instance==TIM3)
	{
		/* USER CODE BEGIN TIM3_MspInit 0 */

		/* USER CODE END TIM3_MspInit 0 */
		/* Peripheral clock enable */
		__HAL_RCC_TIM3_CLK_ENABLE();

		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_GPIOB_CLK_ENABLE();
		/**TIM3 GPIO Configuration
		PA6     ------> TIM3_CH1
		PB5     ------> TIM3_CH2
		*/
		GPIO_InitStruct.Pin = GPIO_PIN_6;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_5;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

		/* USER CODE BEGIN TIM3_MspInit 1 */

		/* USER CODE END TIM3_MspInit 1 */
	}
	else if(htim_encoder->Instance==TIM4)
	{
		/* USER CODE BEGIN TIM4_MspInit 0 */

		/* USER CODE END TIM4_MspInit 0 */
		/* Peripheral clock enable */
		__HAL_RCC_TIM4_CLK_ENABLE();

		__HAL_RCC_GPIOD_CLK_ENABLE();
		/**TIM4 GPIO Configuration
		PD12     ------> TIM4_CH1
		PD13     ------> TIM4_CH2
		*/
		GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF2_TIM4;
		HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

		/* USER CODE BEGIN TIM4_MspInit 1 */

		/* USER CODE END TIM4_MspInit 1 */
	}
	else if(htim_encoder->Instance==TIM8)
	{
		/* USER CODE BEGIN TIM8_MspInit 0 */

		/* USER CODE END TIM8_MspInit 0 */
		/* Peripheral clock enable */
		__HAL_RCC_TIM8_CLK_ENABLE();

		__HAL_RCC_GPIOC_CLK_ENABLE();
		/**TIM8 GPIO Configuration
		PC6     ------> TIM8_CH1
		PC7     ------> TIM8_CH2
		*/
		GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		GPIO_InitStruct.Alternate = GPIO_AF3_TIM8;
		HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

		/* USER CODE BEGIN TIM8_MspInit 1 */

		/* USER CODE END TIM8_MspInit 1 */
	}

}

static void MX_TIM1_Init(void)
{

	/* USER CODE BEGIN TIM1_Init 0 */

	/* USER CODE END TIM1_Init 0 */

	TIM_Encoder_InitTypeDef sConfig = {0};
	TIM_MasterConfigTypeDef sMasterConfig = {0};

	/* USER CODE BEGIN TIM1_Init 1 */

	/* USER CODE END TIM1_Init 1 */
	htim1.Instance = TIM1;
	htim1.Init.Prescaler = 0;
	htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim1.Init.Period = 0xFFFF;
	htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	sConfig.EncoderMode = TIM_ENCODERMODE_TI12;;
	sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
	sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
	sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
	sConfig.IC1Filter = 0x5;
	sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
	sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
	sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
	sConfig.IC2Filter = 0x5;
	if (HAL_TIM_Encoder_Init(&htim1, &sConfig) != HAL_OK)
	{
//    Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
	{
//    Error_Handler();
	}
	/* USER CODE BEGIN TIM1_Init 2 */

	/* USER CODE END TIM1_Init 2 */

}

static void MX_TIM3_Init(void)
{
	TIM_Encoder_InitTypeDef sConfig = {0};
	TIM_MasterConfigTypeDef sMasterConfig = {0};

	htim3.Instance = TIM3;
	htim3.Init.Prescaler = 0;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim3.Init.Period = 0xFFFF;
	htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
	sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
	sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
	sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
	sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
	sConfig.IC1Filter = 0x5;
	sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
	sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
	sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
	sConfig.IC2Filter = 0x5;
	if (HAL_TIM_Encoder_Init(&htim3, &sConfig) != HAL_OK)
	{
//    Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
	{
//    Error_Handler();
	}
}

static void MX_TIM4_Init(void)
{
	TIM_Encoder_InitTypeDef sConfig;
	TIM_MasterConfigTypeDef sMasterConfig;

	htim4.Instance = TIM4;
	htim4.Init.Prescaler = 0;
	htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim4.Init.Period = 0xFFFF;
	htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
	sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
	sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
	sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
	sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
	sConfig.IC1Filter = 0x5;
	sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
	sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
	sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
	sConfig.IC2Filter = 0x5;
	if (HAL_TIM_Encoder_Init(&htim4, &sConfig) != HAL_OK)
	{
		//_Error_Handler(__FILE__, __LINE__);
	}

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
	{
		//_Error_Handler(__FILE__, __LINE__);
	}
}

static void MX_TIM8_Init(void)
{

	/* USER CODE BEGIN TIM8_Init 0 */

	/* USER CODE END TIM8_Init 0 */

	TIM_Encoder_InitTypeDef sConfig = {0};
	TIM_MasterConfigTypeDef sMasterConfig = {0};

	/* USER CODE BEGIN TIM8_Init 1 */

	/* USER CODE END TIM8_Init 1 */
	htim8.Instance = TIM8;
	htim8.Init.Prescaler = 0;
	htim8.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim8.Init.Period = 0xFFFF;
	htim8.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim8.Init.RepetitionCounter = 0;
	htim8.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
	sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
	sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
	sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
	sConfig.IC1Filter = 0x5;
	sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
	sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
	sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
	sConfig.IC2Filter = 0x5;
	if (HAL_TIM_Encoder_Init(&htim8, &sConfig) != HAL_OK)
	{
//    Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim8, &sMasterConfig) != HAL_OK)
	{
//    Error_Handler();
	}
	/* USER CODE BEGIN TIM8_Init 2 */

	/* USER CODE END TIM8_Init 2 */

}

/*!
 * @brief  Get the counter value of the tim1 counter
 * @param init True to reset the encoder, False to nothing (default = False)
 * @return
 */
int get_counter_tim1(bool init = false){
	static int counts;
	static int countsbefore = 0;
	uint16_t temp;
	if (init) counts = 0;

	temp = TIM1->CNT;
	counts += (int16_t)(temp - countsbefore);
	countsbefore = temp;

	return counts;
}

/*!
 * @brief  Get the counter value of the tim3 counter
 * @param  init True to reset the encoder, False to nothing (default = False)
 * @return counter value
 */
int get_counter_tim3(bool init = false){
	static int counts;
	static int countsbefore = 0;
	uint16_t temp;

	if (init) counts = 0;

	temp = TIM3->CNT;
	counts += (int16_t)(temp - countsbefore);
	countsbefore = temp;

	return counts;
}

/*!
 * @brief  Get the counter value of the tim4 counter
 * @param  init True to reset the encoder, False to nothing (default = False)
 * @return counter value
 */
int get_counter_tim4(bool init = false){
	static int counts;
	static int countsbefore = 0;
	uint16_t temp;

	if (init) counts = 0;

	temp = TIM4->CNT;
	counts += (int16_t)(temp - countsbefore);
	countsbefore = temp;

	return counts;
}

/*!
 * @brief  Get the counter value of the tim8 counter
 * @param  init True to reset the encoder, False to nothing (default = False)
 * @return counter value
 */
int get_counter_tim8(bool init = false){
	static int counts;
	static int countsbefore = 0;
	uint16_t temp;

	if (init) counts = 0;

	temp = TIM8->CNT;
	counts += (int16_t)(temp - countsbefore);
	countsbefore = temp;

	return counts;
}

/*!
 * @brief  Initialize the tim1 counter
 */
void tim1_init(){
	__HAL_RCC_GPIOE_CLK_ENABLE();
	HAL_TIM_Encoder_MspInit(&htim1);
	MX_TIM1_Init();
	HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
}

/*!
 * @brief  Initialize the tim3 counter
 */
void tim3_init(){
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	HAL_TIM_Encoder_MspInit(&htim3);
	MX_TIM3_Init();
	HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
}

/*!
 * @brief  Initialize the tim4 counter
 */
void tim4_init(){
	__HAL_RCC_GPIOD_CLK_ENABLE();
	HAL_TIM_Encoder_MspInit(&htim4);
	MX_TIM4_Init();
	HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
}

/*!
 * @brief  Initialize the tim8 counter
 */
void tim8_init(){
	__HAL_RCC_GPIOC_CLK_ENABLE();
	HAL_TIM_Encoder_MspInit(&htim8);
	MX_TIM8_Init();
	HAL_TIM_Encoder_Start(&htim8, TIM_CHANNEL_ALL);
}

#endif //F7_ENC_H_
