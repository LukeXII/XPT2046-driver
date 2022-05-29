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

#define CTRL_BYTE_TEMP	0b10000000

void XPT2046_SPIConfig(void);
void XPT2046_chipEnable(void);
void XPT2046_chipDisable(void);
void XPT2046_startConversion(uint8_t ctrlByte);

void getXValue(void);

#endif /* XPT2046_INC_XPT2046_H_ */
