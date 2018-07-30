/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* USER CODE BEGIN Includes */
#include "stdio.h"
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void Error_Handler(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
static void MX_USART1_UART_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_USART1_UART_Init();

  /* USER CODE BEGIN 2 */
  uint32_t index = 0x2F;
  GPIOB->ODR = index;
  uint8_t address, data, status;
  uint8_t READ = 0x80; //MSB = 1 which is a 'read' bit
  uint8_t result[8]; //used to store the frequency data
  result[0] = 0x53;
  result[7] = 0x45;


  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);



  //Set the Strobe bit to high
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
  //Set the INH bit to low
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);

  //Start initialization of LDC1000
  //Set power mode to idle to configure stuff
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
  address = 0x0B;
  data = 0x00;
  HAL_SPI_Transmit(&hspi1,&address,1,50);
  HAL_SPI_Transmit(&hspi1,&data,1,50);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
  HAL_Delay(100);

  //Set RpMax 4.309Kohm
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
  address = 0x01;
  data = 0x19;
  HAL_SPI_Transmit(&hspi1,&address,1,50);
  HAL_SPI_Transmit(&hspi1,&data,1,50);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
  HAL_Delay(100);

  //Set RpMin 798ohm
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
  address = 0x02;
  data = 0x3F;
  HAL_SPI_Transmit(&hspi1,&address,1,50);
  HAL_SPI_Transmit(&hspi1,&data,1,50);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
  HAL_Delay(100);

  //Set Watchdog timer frequency to 300k
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
  address = 0x03;
  data = 0xA4;
  HAL_SPI_Transmit(&hspi1,&address,1,50);
  HAL_SPI_Transmit(&hspi1,&data,1,50);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
  HAL_Delay(100);


  //Set LDC configuration amplitude 4vpp
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
  address = 0x04;
  data = 0x17;
  HAL_SPI_Transmit(&hspi1,&address,1,50);
  HAL_SPI_Transmit(&hspi1,&data,1,50);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
  HAL_Delay(100);


  //Set clock input type as crystal
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
  address = 0x05;
  data = 0x02;
  HAL_SPI_Transmit(&hspi1,&address,1,50);
  HAL_SPI_Transmit(&hspi1,&data,1,50);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
  HAL_Delay(100);


  //Disable all interrupt modes
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
  address = 0x0A;
  data = 0x00;
  HAL_SPI_Transmit(&hspi1,&address,1,50);
  HAL_SPI_Transmit(&hspi1,&data,1,50);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
  HAL_Delay(100);

  //Set thresh HiLSB value
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
  address = 0x06;
  data = 0x50;
  HAL_SPI_Transmit(&hspi1,&address,1,50);
  HAL_SPI_Transmit(&hspi1,&data,1,50);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
  HAL_Delay(100);

  //Set thresh HiMSB value
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
  address = 0x07;
  data = 0x14;
  HAL_SPI_Transmit(&hspi1,&address,1,50);
  HAL_SPI_Transmit(&hspi1,&data,1,50);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
  HAL_Delay(100);

  //Set thresh LoLSB value
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
  address = 0x08;
  data = 0xC0;
  HAL_SPI_Transmit(&hspi1,&address,1,50);
  HAL_SPI_Transmit(&hspi1,&data,1,50);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
  HAL_Delay(100);

  //Set thresh LoMSB value
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
  address = 0x09;
  data = 0x12;
  HAL_SPI_Transmit(&hspi1,&address,1,50);
  HAL_SPI_Transmit(&hspi1,&data,1,50);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
  HAL_Delay(100);

  //Set power mode to active mode
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
  address = 0x0B;
  data = 0x01;
  HAL_SPI_Transmit(&hspi1,&address,1,50);
  HAL_SPI_Transmit(&hspi1,&data,1,50);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
  HAL_Delay(100);
  //End of initialization



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */


  //Read the status register

  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
  address = 0x20 + READ;
  HAL_SPI_Transmit(&hspi1,&address,1,50);
  HAL_SPI_Receive(&hspi1,&result[1],1,50);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
  HAL_Delay(100);

  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
  address = 0x21 + READ;
  HAL_SPI_Transmit(&hspi1,&address,1,50);
  HAL_SPI_Receive(&hspi1,&result[3],1,50);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
  HAL_Delay(100);

  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
  address = 0x22 + READ;
  HAL_SPI_Transmit(&hspi1,&address,1,50);
  HAL_SPI_Receive(&hspi1,&result[2],1,50);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
  HAL_Delay(100);

  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
  address = 0x23 + READ;
  HAL_SPI_Transmit(&hspi1,&address,1,50);
  HAL_SPI_Receive(&hspi1,&result[6],1,50);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
  HAL_Delay(100);

  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
  address = 0x24 + READ;
  HAL_SPI_Transmit(&hspi1,&address,1,50);
  HAL_SPI_Receive(&hspi1,&result[5],1,50);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
  HAL_Delay(100);

  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
  address = 0x25 + READ;
  HAL_SPI_Transmit(&hspi1,&address,1,50);
  HAL_SPI_Receive(&hspi1,&result[4],1,50);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
  HAL_Delay(100);

  HAL_UART_Transmit(&huart1,result,8,1000);
  HAL_Delay(100);
/*


  //Read proximity data MSB register
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);
  address = 0x22 + READ;
  HAL_SPI_Transmit(&hspi1,&address,1,50);
  HAL_SPI_Receive(&hspi1,&dataMSB,1,50);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);
  HAL_Delay(100);

*/

  }
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* SPI1 init function */
static void MX_SPI1_Init(void)
{

  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }

}

/* USART1 init function */
static void MX_USART1_UART_Init(void)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_8, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3 
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA1 PA8 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB3 
                           PB4 PB5 PB6 PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3 
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PA11 */
  GPIO_InitStruct.Pin = GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
