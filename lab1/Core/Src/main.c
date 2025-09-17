#include "main.h"

#define LED_ON 0
#define LED_OFF 1
#define RED_TIME 5
#define YELLOW_TIME 2
#define GREEN_TIME 3

typedef enum {
	RED,
	YELLOW,
	GREEN
} trafficLightState;

void display7SEG(int num) {
	if (num == 0) {
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, LED_ON);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, LED_ON);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, LED_ON);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, LED_ON);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, LED_ON);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, LED_ON);
		HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, LED_OFF);
	}
	else if (num == 1) {
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, LED_OFF);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, LED_ON);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, LED_ON);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, LED_OFF);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, LED_OFF);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, LED_OFF);
		HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, LED_OFF);
	}
	else if (num == 2) {
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, LED_ON);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, LED_ON);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, LED_OFF);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, LED_ON);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, LED_ON);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, LED_OFF);
		HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, LED_ON);
	}
	else if (num == 3) {
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, LED_ON);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, LED_ON);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, LED_ON);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, LED_ON);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, LED_OFF);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, LED_OFF);
		HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, LED_ON);
	}
	else if (num == 4) {
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, LED_OFF);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, LED_ON);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, LED_ON);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, LED_OFF);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, LED_OFF);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, LED_ON);
		HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, LED_ON);
	}
	else if (num == 5) {
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, LED_ON);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, LED_OFF);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, LED_ON);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, LED_ON);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, LED_OFF);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, LED_ON);
		HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, LED_ON);
	}
	else {
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, LED_OFF);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, LED_OFF);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, LED_OFF);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, LED_OFF);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, LED_OFF);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, LED_OFF);
		HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, LED_OFF);
	}
}
void SystemClock_Config(void);
static void MX_GPIO_Init(void);

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  trafficLightState status1 = RED; int counter1 = RED_TIME;
  trafficLightState status2 = GREEN; int counter2 = GREEN_TIME;

  while (1){
	  display7SEG(counter1); // Display countdown value of Way1

	  if (status1 == RED) {
		  HAL_GPIO_WritePin(LED_RED_WAY1_GPIO_Port, LED_RED_WAY1_Pin, LED_ON);
    	  HAL_GPIO_WritePin(LED_YELLOW_WAY1_GPIO_Port, LED_YELLOW_WAY1_Pin, LED_OFF);
	  	  HAL_GPIO_WritePin(LED_GREEN_WAY1_GPIO_Port, LED_GREEN_WAY1_Pin, LED_OFF);
	      counter1--;
	      if (counter1 <= 0) {
	  		  status1 = GREEN;
	    	  counter1 = GREEN_TIME;
	      }
	  }
	  else if (status1 == GREEN) {
	      HAL_GPIO_WritePin(LED_RED_WAY1_GPIO_Port, LED_RED_WAY1_Pin, LED_OFF);
	      HAL_GPIO_WritePin(LED_YELLOW_WAY1_GPIO_Port, LED_YELLOW_WAY1_Pin, LED_OFF);
	      HAL_GPIO_WritePin(LED_GREEN_WAY1_GPIO_Port, LED_GREEN_WAY1_Pin, LED_ON);
	      counter1--;
	  	  if (counter1 <= 0) {
	    	  status1 = YELLOW;
	          counter1 = YELLOW_TIME;
	      }
	  }
	  else if (status1 == YELLOW) {
	      HAL_GPIO_WritePin(LED_RED_WAY1_GPIO_Port, LED_RED_WAY1_Pin, LED_OFF);
	      HAL_GPIO_WritePin(LED_YELLOW_WAY1_GPIO_Port, LED_YELLOW_WAY1_Pin, LED_ON);
	      HAL_GPIO_WritePin(LED_GREEN_WAY1_GPIO_Port, LED_GREEN_WAY1_Pin, LED_OFF);
	      counter1--;
	      if (counter1 <= 0) {
	          status1 = RED;
	          counter1 = RED_TIME;
	      }
	  }
	  if (status2 == RED) {
	      HAL_GPIO_WritePin(LED_RED_WAY2_GPIO_Port, LED_RED_WAY2_Pin, LED_ON);
	      HAL_GPIO_WritePin(LED_YELLOW_WAY2_GPIO_Port, LED_YELLOW_WAY2_Pin, LED_OFF);
	      HAL_GPIO_WritePin(LED_GREEN_WAY2_GPIO_Port, LED_GREEN_WAY2_Pin, LED_OFF);
	      counter2--;
	      if (counter2 <= 0) {
	    	  status2 = GREEN;
	    	  counter2 = GREEN_TIME;
	      }
	  }
	  else if (status2 == GREEN) {
	      HAL_GPIO_WritePin(LED_RED_WAY2_GPIO_Port, LED_RED_WAY2_Pin, LED_OFF);
	      HAL_GPIO_WritePin(LED_YELLOW_WAY2_GPIO_Port, LED_YELLOW_WAY2_Pin, LED_OFF);
	      HAL_GPIO_WritePin(LED_GREEN_WAY2_GPIO_Port, LED_GREEN_WAY2_Pin, LED_ON);
	      counter2--;
	      if (counter2 <= 0) {
	    	  status2 = YELLOW;
	    	  counter2 = YELLOW_TIME;
	      }
	  }
	  else if (status2 == YELLOW) {
	      HAL_GPIO_WritePin(LED_RED_WAY2_GPIO_Port, LED_RED_WAY2_Pin, LED_OFF);
	      HAL_GPIO_WritePin(LED_YELLOW_WAY2_GPIO_Port, LED_YELLOW_WAY2_Pin, LED_ON);
	   	  HAL_GPIO_WritePin(LED_GREEN_WAY2_GPIO_Port, LED_GREEN_WAY2_Pin, LED_OFF);
	      counter2--;
	      if (counter2 <= 0) {
	    	  status2 = RED;
	    	  counter2 = RED_TIME;
	      }
	  }
 	  HAL_Delay(1000);
  }
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED_WAY1_Pin|LED_YELLOW_WAY1_Pin|LED_GREEN_WAY1_Pin|LED_RED_WAY2_Pin
                          |LED_YELLOW_WAY2_Pin|LED_GREEN_WAY2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, S1_Pin|S2_Pin|S3_Pin|S4_Pin
                          |S5_Pin|S6_Pin|S7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED_WAY1_Pin LED_YELLOW_WAY1_Pin LED_GREEN_WAY1_Pin LED_RED_WAY2_Pin
                           LED_YELLOW_WAY2_Pin LED_GREEN_WAY2_Pin */
  GPIO_InitStruct.Pin = LED_RED_WAY1_Pin|LED_YELLOW_WAY1_Pin|LED_GREEN_WAY1_Pin|LED_RED_WAY2_Pin
                          |LED_YELLOW_WAY2_Pin|LED_GREEN_WAY2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : S1_Pin S2_Pin S3_Pin S4_Pin
                           S5_Pin S6_Pin S7_Pin */
  GPIO_InitStruct.Pin = S1_Pin|S2_Pin|S3_Pin|S4_Pin
                          |S5_Pin|S6_Pin|S7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
