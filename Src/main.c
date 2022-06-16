/**
 ******************************************************************************
 * @file    UART/UART_Printf/Src/main.c
 * @author  MCD Application Team
 * @brief   This example shows how to retarget the C library printf function
 *          to the UART.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "API_uart.h"
#include "API_LCD.h"
#include "API_FSM.h"
#include "API_GPIO.h"
#include "XPT2046.h"

/** @addtogroup STM32F4xx_HAL_Examples
 * @{
 */

/** @addtogroup UART_Printf
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

FSMEvent_t newEvent;
unsigned char mybuffer[10];

/* Private function prototypes -----------------------------------------------*/

static void SystemClock_Config(void);
static void Error_Handler(void);

/* Public functions prototypes -----------------------------------------------*/

void eventGenerator(void);

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main(void)
{
	/* STM32F4xx HAL library initialization:
       - Configure the Flash prefetch
       - Systick timer is configured by default as source of time base, but user 
         can eventually implement his proper time base source (a general purpose 
         timer for example or other time source), keeping in mind that Time base 
         duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and 
         handled in milliseconds basis.
       - Set NVIC Group Priority to 4
       - Low Level Initialization
	 */
	char str[10], str2[10];
	uint16_t xcoord, ycoord, pressure;

	HAL_Init();

	/* Configure the system clock to 180 MHz */
	SystemClock_Config();

	// Debug LEDs
	BSP_LED_Init(LED1);						// Inicializacion de los LED
	BSP_LED_Init(LED2);
	BSP_LED_Init(LED3);

	GPIO_Config();
	XPT2046_SPIConfig();
	LCD_Config();


	LCD_Init();
	uartinit();
	mybuffer[0] = '\0';

	XPT2046_setControllerConfig(RES_12BITS, MODE_DIFF, PD_LOWPOWER, 346);

	/* Infinite loop */
	while (1)
	{
		HAL_Delay(500);

		xcoord = XPT2046_getCoord(COORD_X);
		ycoord = XPT2046_getCoord(COORD_Y);
		pressure = XPT2046_getPressure();

		LCD_Fill_Screen(CYAN);

		sprintf(str, "%d", xcoord);
		str2[0] = 'X';
		str2[1] = ':';
		str2[2] = '\0';
		LCD_Draw_Text(strcat(str2, str), 20, 20, PURPLE, 4, CYAN);

		//uartSendString((uint8_t *)" X: ");
		//uartSendString((uint8_t *)str);

		sprintf(str, "%d", ycoord);
		str2[0] = 'Y';
		str2[1] = ':';
		str2[2] = '\0';
		LCD_Draw_Text(strcat(str2, str), 20, 50, PURPLE, 4, CYAN);

		//uartSendString((uint8_t *)" Y: ");
		//uartSendString((uint8_t *)str);

		sprintf(str, "%d", pressure);
		str2[0] = 'P';
		str2[1] = ':';
		str2[2] = '\0';
		LCD_Draw_Text(strcat(str2, str), 20, 80, PURPLE, 4, CYAN);

		str2[0] = 'P';
		str2[1] = 'E';
		str2[2] = 'N';
		str2[3] = ':';
		str2[4] = '\0';
		if(XPT2046_isPressed())
			LCD_Draw_Text(strcat(str2, "SI"), 20, 110, PURPLE, 4, CYAN);
		else
			LCD_Draw_Text(strcat(str2, "NO"), 20, 110, PURPLE, 4, CYAN);

		//uartSendString((uint8_t *)" P: ");
		//uartSendString((uint8_t *)str);

		//uartSendString((uint8_t *)"\r\n");

	}
}

/* Public functions --------------------------------------------------------*/
void eventGenerator(void)
{
	newEvent = NO_EVENT;

	uartReceiveStringSize((uint8_t *)mybuffer, 10);

	if(mybuffer[0] != 0)
	{

		mybuffer[strlen((const char *)mybuffer) - 1] = '\0';

		if(!strcmp((const char *)mybuffer, "next"))
		{
			newEvent = UART_NEXT;
		}
		else
			if(!strcmp((const char *)mybuffer, "prev"))
			{
				newEvent = UART_PREV;
			}

		mybuffer[0] = 0;
	}
}

/**
 * @brief  System Clock Configuration
 *         The system Clock is configured as follow :
 *            System Clock source            = PLL (HSE)
 *            SYSCLK(Hz)                     = 180000000
 *            HCLK(Hz)                       = 180000000
 *            AHB Prescaler                  = 1
 *            APB1 Prescaler                 = 4
 *            APB2 Prescaler                 = 2
 *            HSE Frequency(Hz)              = 8000000
 *            PLL_M                          = 8
 *            PLL_N                          = 360
 *            PLL_P                          = 2
 *            PLL_Q                          = 7
 *            PLL_R                          = 2
 *            VDD(V)                         = 3.3
 *            Main regulator output voltage  = Scale1 mode
 *            Flash Latency(WS)              = 5
 * @param  None
 * @retval None
 */
static void SystemClock_Config(void)
{
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;

	/* Enable Power Control clock */
	__HAL_RCC_PWR_CLK_ENABLE();

	/* The voltage scaling allows optimizing the power consumption when the device is
     clocked below the maximum system frequency, to update the voltage scaling value 
     regarding system frequency refer to product datasheet.  */
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/* Enable HSE Oscillator and activate PLL with HSE as source */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 360;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 7;
	if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		/* Initialization Error */
		Error_Handler();
	}

	if(HAL_PWREx_EnableOverDrive() != HAL_OK)
	{
		/* Initialization Error */
		Error_Handler();
	}

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
	if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
	{
		/* Initialization Error */
		Error_Handler();
	}
}
/**
 * @brief  This function is executed in case of error occurrence.
 * @param  None
 * @retval None
 */
static void Error_Handler(void)
{
	/* Turn LED2 on */
	BSP_LED_On(LED2);
	while (1)
	{
	}
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
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}
#endif

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
