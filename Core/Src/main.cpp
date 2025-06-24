/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <PID.h>
#include <CircularBuffer.h>
#include <cmath>
#include <Eigen>

//#include "../../Drivers/CMSIS/CMSIS_DSP/Include/arm_math.h"
//#include "../../Drivers/CMSIS/CMSIS_DSP/Include/dsp/transform_functions_f16.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define SPR 				128
#define AZIMUTH_MOTOR 		0
#define ELEVATION_MOTOR 	1

#define SPEEDOFSOUND 		343.0 // meters/s
#define MICSPACING 			0.1016 // in meters
#define DIR_CCW				0
#define DIR_CW				1

#define CLK_PRD				12.5e-9
#define DEBUG 				0
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */
GPIO_PinState outputSeq[8][4] = {
			{GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET},
			{GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET},
			{GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_RESET},
			{GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET},
			{GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET},
			{GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET},
			{GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET},
			{GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET}
	};


int steps = 0;

bool timer2BreakFlag = 1;

volatile uint32_t mic1TimerCapture = 0;
volatile uint32_t mic2TimerCapture = 0;
volatile uint32_t mic3TimerCapture = 0;

volatile bool mic1Triggered = 0;
volatile bool mic2Triggered = 0;
volatile bool mic3Triggered = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM1_Init(void);
//static void MX_TIM2_Init(void);
static void MX_USART3_UART_Init(void);
/* USER CODE BEGIN PFP */
void rectangular2Spherical(float*, float*);
void moveMotor(bool, bool, float);
void useMotor(bool, uint16_t*);
void moveMotor(bool, float);
void calculateTrilateration(float*, float*);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
	{
		mic1Triggered = 1;
		mic1TimerCapture = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
	}

	if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
	{
		mic2Triggered = 1;
		mic2TimerCapture = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
	}

	if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3)
	{
		mic3Triggered = 1;
		mic3TimerCapture = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3);
	}
}
//
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
//	timer2BreakFlag = 1;
//}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
	//arm_mfcc_instance_q15 mfcc_instance;
	/*
	 * mfcc init
	 * (instance, fft_len, num_mel_filters, num_DCT_out,
	 * 		DCT_coeff_array, filterPos, filterLen,
	 * 		filter_coeff, window_coeff)
	 *
	 * 		The matrix of Mel filter coefficients is sparse.
	 * 		Most of the coefficients are zero. To avoid multiplying
	 * 		the spectrogram by those zeros, the filter is applied
	 * 		only to a given position in the spectrogram and on a
	 * 		given number of FFT bins (the filter length). It is
	 * 		the reason for the arrays filterPos and filterLengths.
	 */
	//arm_mfcc_init_32_q15(&mfcc_instance, 2048, 20, 13);
//	PID controlAzimuthMotor(0.5, 0.1, 0.0);
//	PID controlElevationMotor(0.5, 0.1, 0.0);

	// Init Buffer
	CircularBuffer frame;
	uint8_t tx_buff[4];
	// Signal Processing Variables
	float times[3];
//	float distance2Source = 0.0;

	// Coordinate Variables
	float rectangular[3];
//	float xCoord = 0.0;
//	float yCoord = 0.0;
//	float zCoord = 0.0;

	float spherical[2];
//	bool AziDirection = 0;
//	bool AltiDirection = 0;
//	float AziDeg = 0.0;
//	float AltiDeg = 0.0;
//
//	// Control Variables
//	float errorA = 0.0;
//	float targetDegA = 0.0;
//	float currentDegA = 0.0;
//	float newTargetA = 0.0;
//
//	float errorB = 0.0;
//	float targetDegB = 0.0;
//	float currentDegB = 0.0;
//	float newTargetB = 0.0;

	//HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);


  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
//  MX_TIM2_Init();
  MX_ADC1_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_1);
  HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_2);
  HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_3);
//  HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_2);
//  HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_3);
//
//  HAL_TIM_Base_Start_IT(&htim1);

  uint16_t val = 0;

  /* USER CODE END 2 */

  /* Initialize leds */
  BSP_LED_Init(LED_GREEN);
  BSP_LED_Init(LED_BLUE);
  BSP_LED_Init(LED_RED);

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  /*
	   * Calculate position
	   */

	  if ( mic1Triggered && mic2Triggered && mic3Triggered)
	  {

//		  if (timer2BreakFlag)
//		  {
			  times[0] = CLK_PRD*mic1TimerCapture;
			  times[1] = CLK_PRD*mic2TimerCapture;
			  times[2] = CLK_PRD*mic3TimerCapture;

			  mic1Triggered = 0;
			  mic2Triggered = 0;
			  mic3Triggered = 0;
//
//			  TIM1->CNT = 0;
//			  timer2BreakFlag = 0;

//		  }
			  calculateTrilateration(rectangular, times);
			  rectangular2Spherical(rectangular, spherical);

			  if (DEBUG)
			  {
				  moveMotor(AZIMUTH_MOTOR, spherical[0]); // spherical[0]
				  HAL_Delay(1000);
				  moveMotor(ELEVATION_MOTOR, spherical[1]); // spherical[1]
				  HAL_Delay(1000);
			  }

	  }
//
//	  /*
//	   * Take data from ADC
//	   */
//
//	  HAL_ADC_Start(&hadc1);
//	  HAL_ADC_PollForConversion(&hadc1, 1);
//
//	  //val = HAL_ADC_GetValue(&hadc1);
//
//	  //HAL_Delay(1);
//
//	  val = 60;
//
//	  tx_buff[0] = (val >> 8) & 0xFF;
//	  tx_buff[1] = val & 0x00FF;
//	  tx_buff[2] = 0x0D;
//	  tx_buff[3] = 0x0A;
//
//	  HAL_UART_Transmit(&huart3, tx_buff, sizeof(tx_buff), 1000);
//
//	  HAL_Delay(100);
//
//	  val++;

	  /*
	   * Do KWS
	   */


	  /*
	   * Move Motors
	   */

	  // coordinates are converted to azimuth-altitude

	  // PIDs are given degrees
	  /*
	   * errorA = targetDegA - currentDegA;
	   * controlMotorA.setError(errorA);
	   * newTargetA = controlMotorA.getSignal()
	   *
	   * errorB = targetDegB - currentDegB;
	   * controlMotorB.setError(errorB);
	   * newTargetB = controlMotorB.getSignal()
	   */

//	  times[0] = CLK_PRD*1000;
//	  times[1] = CLK_PRD*1000;
//	  times[0] = CLK_PRD*1010;
//	  calculateTrilateration(rectangular, times);
//	  rectangular2Spherical(rectangular, spherical);
//
//	  if (DEBUG)
//	  {
//		  moveMotor(AZIMUTH_MOTOR, spherical[0]); // spherical[0]
//		  HAL_Delay(1000);
//		  moveMotor(ELEVATION_MOTOR, spherical[1]); // spherical[1]
//		  HAL_Delay(1000);
//	  }





  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_CSI|RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.CSIState = RCC_CSI_ON;
  RCC_OscInitStruct.CSICalibrationValue = RCC_CSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOMEDIUM;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV1;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart3.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart3, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart3, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_MultiModeTypeDef multimode = {0};
  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV2;
  hadc1.Init.Resolution = ADC_RESOLUTION_16B;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ConversionDataManagement = ADC_CONVERSIONDATA_DR;
  hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  hadc1.Init.LeftBitShift = ADC_LEFTBITSHIFT_NONE;
  hadc1.Init.OversamplingMode = DISABLE;
  hadc1.Init.Oversampling.Ratio = 1;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure the ADC multi-mode
  */
  multimode.Mode = ADC_MODE_INDEPENDENT;
  if (HAL_ADCEx_MultiModeConfigChannel(&hadc1, &multimode) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_2;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  sConfig.OffsetSignedSaturation = DISABLE;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_IC_InitTypeDef sConfigIC = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 60000-1;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 65535;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_IC_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
  sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
  sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
  sConfigIC.ICFilter = 0;
  if (HAL_TIM_IC_ConfigChannel(&htim1, &sConfigIC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_IC_ConfigChannel(&htim1, &sConfigIC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_IC_ConfigChannel(&htim1, &sConfigIC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_IC_InitTypeDef sConfigIC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 4294967295;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_IC_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
  sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
  sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
  sConfigIC.ICFilter = 0;
  if (HAL_TIM_IC_ConfigChannel(&htim2, &sConfigIC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_IC_ConfigChannel(&htim2, &sConfigIC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_IC_ConfigChannel(&htim2, &sConfigIC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2|LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pins : PE2 LD2_Pin */
  GPIO_InitStruct.Pin = GPIO_PIN_2|LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PF0 PF1 PF2 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : PF4 PF5 PF6 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : PD11 PD12 PD13 */
  GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : PG6 */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void rectangular2Spherical(float rect[], float sph[])
{
	float r = sqrt(rect[0]*rect[0] + rect[1]*rect[1]);
	float dist = sqrt(rect[0]*rect[0] + rect[1]*rect[1] + rect[2]*rect[2]);
	sph[0] = std::atan(rect[1]/rect[0])*180/3.14;
	sph[1] = std::acos(r/dist)*180/3.14;
}

Eigen::Matrix3d jacobianGuess(float g[3], float mp[3][2])
{
	// J is 3x3
	Eigen::Matrix3d J;
	J << 2*g[0], 2*(g[1] - mp[0][1]), 2*g[2],
			2*(g[0] - mp[1][0]), 2*(g[1] - mp[1][1]), 2*g[2],
			2*(g[0] - mp[2][0]), 2*(g[1] - mp[2][1]), 2*g[2];

//	float J = {
//			{2*g[0], 2*(g[1] - mp[0][1]), 2*g[2]},
//			{2*(g[0] - mp[1][0]), 2*(g[1] - mp[1][1]), 2*g[2]},
//			{2*(g[0] - mp[2][0]), 2*(g[1] - mp[2][1]), 2*g[2]}
//	};

	return J.inverse();
}

Eigen::Vector3d functionGuess(float g[3], float mp[3][2], float d[3])
{
	// M is just 1x3 numbers
	Eigen::Vector3d M;
	M << (((g[0] - mp[0][0]) * (g[0] - mp[0][0])) + ((g[1] - mp[0][1]) * (g[1] - mp[0][1])) + (g[2] * g[2]) - (d[0] * d[0])),
			(((g[0] - mp[1][0]) * (g[0] - mp[1][0])) + ((g[1] - mp[1][1]) * (g[1] - mp[1][1])) + (g[2] * g[2]) - (d[1] * d[1])),
			(((g[0] - mp[2][0]) * (g[0] - mp[2][0])) + ((g[1] - mp[2][1]) * (g[1] - mp[2][1])) + (g[2] * g[2]) - (d[2] * d[2]));
//	float M = {
//			((g[0] - mp[0][0]) * (g[0] - mp[0][0])) + ((g[1] - mp[0][1]) * (g[1] - mp[0][1])) + (g[2] * g[2]) - (d[0] * d[0]),
//			((g[0] - mp[1][0]) * (g[0] - mp[1][0])) + ((g[1] - mp[1][1]) * (g[1] - mp[1][1])) + (g[2] * g[2]) - (d[1] * d[1]),
//			((g[0] - mp[2][0]) * (g[0] - mp[2][0])) + ((g[1] - mp[2][1]) * (g[1] - mp[2][1])) + (g[2] * g[2]) - (d[2] * d[2])
//	};

	return M;

	// might have to make a separate container since it has to return this list
}

void calculateTrilateration(float answer[], float time[])
{
	float micPos[3][2] = {{0, .043}, {.05, -.0449}, {-.05, -.0449}};
	float guesses[] = {0.1, 0.1, 0.1};
	float distances[] = {time[0]*SPEEDOFSOUND, time[1]*SPEEDOFSOUND, time[2]*SPEEDOFSOUND};


	Eigen::Vector3d change;

	for (int i=0; i < 10; i++)
	{
		Eigen::Matrix3d Jinv = jacobianGuess(guesses, micPos);				// 3x3
		Eigen::Vector3d MF = functionGuess(guesses, micPos, distances);		// 3x1

		change = Jinv*MF;													// 3x1
		guesses[0] = guesses[0] - change[0];
		guesses[1] = guesses[1] - change[1];
		guesses[2] = guesses[2] - change[2];
	}

	answer[0] = guesses[0];
	answer[1] = guesses[1];
	answer[2] = guesses[2];

}

void useMotor(bool mtr, uint16_t* pins)
{
	if (!mtr)
	{
		pins[0] = GPIO_PIN_4;
		pins[1] = GPIO_PIN_5;
		pins[2] = GPIO_PIN_6;
		pins[3] = GPIO_PIN_6;
	}

	else
	{
		pins[0] = GPIO_PIN_13;
		pins[1] = GPIO_PIN_12;
		pins[2] = GPIO_PIN_11;
		pins[3] = GPIO_PIN_2;
	}
}

void moveMotor(bool motor, float degrees)
{
	//convert degrees to steps where spr is steps per revolution
	int steps = (int)std::abs(((degrees * SPR) / 360));
	uint16_t motorPins[4];
	useMotor(motor, motorPins);
	bool dir;

	/*
	 * Check which direction to turn
	 */

	if (degrees > 0.0)
	{
		dir = DIR_CCW;
	}
	else
	{
		dir = DIR_CW;
	}

	if (!motor)
	{
		if (!dir)
		{
			// set azimuth motor direction (0 - left, 1 - right)

			for (int i=0; i < steps; i++)
			{
				for (int k=0; k < 8; k++)
				{
					// write motorPin to outputSeq
					HAL_GPIO_WritePin(GPIOF, motorPins[0], outputSeq[k][0]); // assign to specific GPIO for IN1
					HAL_GPIO_WritePin(GPIOF, motorPins[1], outputSeq[k][1]); // assign to specific GPIO for IN2
					HAL_GPIO_WritePin(GPIOF, motorPins[2], outputSeq[k][2]); // assign to specific GPIO for IN3
					HAL_GPIO_WritePin(GPIOG, motorPins[3], outputSeq[k][3]); // assign to specific GPIO for IN4
					HAL_Delay(50); // try 25 and 10 for faster movement
				}
			}
		}
		else
		{
			// set altitude motor direction (0 - left, 1 - right)

			for (int i=0; i < steps; i++)
			{
				for (int k=8; k > 0; k--)
				{
					// write motorPin to outputSeq
					HAL_GPIO_WritePin(GPIOF, motorPins[0], outputSeq[k][0]); // assign to specific GPIO for IN1
					HAL_GPIO_WritePin(GPIOF, motorPins[1], outputSeq[k][1]); // assign to specific GPIO for IN2
					HAL_GPIO_WritePin(GPIOF, motorPins[2], outputSeq[k][2]); // assign to specific GPIO for IN3
					HAL_GPIO_WritePin(GPIOG, motorPins[3], outputSeq[k][3]); // assign to specific GPIO for IN4
					HAL_Delay(50);
				}
			}
		}
	}

	else
	{
		if (dir)
		{
			// set elevation motor direction (0 - left, 1 - right)

			for (int i=0; i < steps; i++)
			{
				for (int k=0; k < 8; k++)
				{
					// write motorPin to outputSeq
					HAL_GPIO_WritePin(GPIOD, motorPins[0], outputSeq[k][0]); // assign to specific GPIO for IN1
					HAL_GPIO_WritePin(GPIOD, motorPins[1], outputSeq[k][1]); // assign to specific GPIO for IN2
					HAL_GPIO_WritePin(GPIOD, motorPins[2], outputSeq[k][2]); // assign to specific GPIO for IN3
					HAL_GPIO_WritePin(GPIOE, motorPins[3], outputSeq[k][3]); // assign to specific GPIO for IN4
					HAL_Delay(50); // try 25 and 10 for faster movement
				}
			}
		}
		else
		{
			// set altitude motor direction (0 - left, 1 - right)

			for (int i=0; i < steps; i++)
			{
				for (int k=8; k > 0; k--)
				{
					// write motorPin to outputSeq
					HAL_GPIO_WritePin(GPIOD, motorPins[0], outputSeq[k][0]); // assign to specific GPIO for IN1
					HAL_GPIO_WritePin(GPIOD, motorPins[1], outputSeq[k][1]); // assign to specific GPIO for IN2
					HAL_GPIO_WritePin(GPIOD, motorPins[2], outputSeq[k][2]); // assign to specific GPIO for IN3
					HAL_GPIO_WritePin(GPIOE, motorPins[3], outputSeq[k][3]); // assign to specific GPIO for IN4
					HAL_Delay(50);
				}
			}
		}
	}
}


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
