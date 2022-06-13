/*
 * XPT2046.h
 *
 *  Created on: May 28, 2022
 *      Author: Lucas
 */

#ifndef XPT2046_INC_XPT2046_H_
#define XPT2046_INC_XPT2046_H_

#include "stm32f4xx_hal.h"  		/* <- HAL include */
#include "stm32f4xx_nucleo_144.h"

#define	XPT2046_CS_PORT		GPIOA
#define	XPT2046_CS_PIN		GPIO_PIN_4

/*______________________________________________________________
| Bit 7 | Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0 |
|	S	|   A2	| 	A1	| 	A0	|  MODE |SER/DFR|  PD1	|  PD2	|
*/

#define CTRL_BYTE_X	0b11010000
#define CTRL_BYTE_Y	0b10010000

// Port.c prototypes

void XPT2046_SPIConfig(void);
void XPT2046_chipEnable(void);
void XPT2046_chipDisable(void);
void XPT2046_startConversion(unsigned char ctrlByte);
void XPT2046_getConversionData(uint8_t * dataPtr, uint16_t length);

// Static prototypes

static uint16_t XPT2046_convertReceivedData(uint16_t firstByte, uint16_t secondByte);

// XPT2046.c prototypes

uint16_t getXCoord(void);
uint16_t getYCoord(void);

#endif /* XPT2046_INC_XPT2046_H_ */
