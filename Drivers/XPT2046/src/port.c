/*
 * port.c
 *
 *  Created on: May 28, 2022
 *      Author: Lucas
 */

#include "XPT2046.h"

static SPI_HandleTypeDef XPT2046_SPIHandle;

void XPT2046_SPIConfig(void)
{

    XPT2046_SPIHandle.Instance 					= SPI3;
    XPT2046_SPIHandle.Init.Mode 				= SPI_MODE_MASTER;
    XPT2046_SPIHandle.Init.Direction 			= SPI_DIRECTION_2LINES;
    XPT2046_SPIHandle.Init.DataSize 			= SPI_DATASIZE_8BIT;
    XPT2046_SPIHandle.Init.CLKPolarity 			= SPI_POLARITY_LOW;
    XPT2046_SPIHandle.Init.CLKPhase 			= SPI_PHASE_1EDGE;
    XPT2046_SPIHandle.Init.NSS 					= SPI_NSS_SOFT;
    XPT2046_SPIHandle.Init.BaudRatePrescaler	= SPI_BAUDRATEPRESCALER_8;
    XPT2046_SPIHandle.Init.FirstBit 			= SPI_FIRSTBIT_MSB;
    XPT2046_SPIHandle.Init.TIMode 				= SPI_TIMODE_DISABLED;
    XPT2046_SPIHandle.Init.CRCCalculation 		= SPI_CRCCALCULATION_DISABLED;
    XPT2046_SPIHandle.Init.CRCPolynomial 		= 10;

    if (HAL_SPI_Init(&XPT2046_SPIHandle) != HAL_OK)
    {
    	BSP_LED_On(LED2);
    }

}

void XPT2046_chipEnable(void)
{
	HAL_GPIO_WritePin(XPT2046_CS_PORT, XPT2046_CS_PIN, GPIO_PIN_RESET);
}

void XPT2046_chipDisable(void)
{
	HAL_GPIO_WritePin(XPT2046_CS_PORT, XPT2046_CS_PIN, GPIO_PIN_SET);
}

void XPT2046_startConversion(unsigned char data)
{

	HAL_SPI_Transmit(&XPT2046_SPIHandle, &data, 1, 10);

}

void XPT2046_getConversionData(uint8_t * dataPtr, uint16_t length)
{
	uint8_t aux[2];

	aux[0] = 0x00;
	aux[1] = 0x00;
	//HAL_SPI_Receive(&XPT2046_SPIHandle, dataPtr, length, 10);
	HAL_SPI_TransmitReceive(&XPT2046_SPIHandle, aux, dataPtr, 2, 10);
}


//HAL_StatusTypeDef HAL_SPI_Receive(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout)

