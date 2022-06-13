/*
 * XPT2046.c
 *
 *  Created on: May 28, 2022
 *      Author: Lucas
 */

#include "XPT2046.h"

#include "API_uart.h"			// Sacar esto!

uint16_t getXCoord(void)
{
	uint8_t receivedData[3];
	char str[10];
	uint16_t xCoord;

	receivedData[2] = '\0';

	XPT2046_chipEnable();

	XPT2046_startConversion(CTRL_BYTE_X);

	XPT2046_getConversionData(receivedData, 16);

	XPT2046_chipDisable();

	xCoord = XPT2046_convertReceivedData(receivedData[0], receivedData[1]);

	sprintf(str, "%d", xCoord);
	uartSendString((uint8_t *)" X: ");
	uartSendString((uint8_t *)str);

	return xCoord;
}

uint16_t getYCoord(void)
{
	uint8_t receivedData[3];
	char str[10];
	uint16_t yCoord;

	receivedData[2] = '\0';

	XPT2046_chipEnable();

	XPT2046_startConversion(CTRL_BYTE_Y);

	XPT2046_getConversionData(receivedData, 16);

	XPT2046_chipDisable();

	yCoord = XPT2046_convertReceivedData(receivedData[0], receivedData[1]);

	sprintf(str, "%d", yCoord);
	uartSendString((uint8_t *)" Y: ");
	uartSendString((uint8_t *)str);

	return yCoord;
}

static uint16_t XPT2046_convertReceivedData(uint16_t firstByte, uint16_t secondByte)
{
	uint16_t coord;

	coord = (firstByte << 5) | (secondByte >> 3);

	return coord;
}
