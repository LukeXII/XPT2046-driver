/*
 * API_GPIO.h
 *
 *  Created on: Apr 21, 2022
 *      Author: Lucas
 */

#ifndef API_INC_API_GPIO_H_
#define API_INC_API_GPIO_H_

#include "API_LCD.h"
#include "stm32f4xx_hal.h"  		/* <- HAL include */
#include "stm32f4xx_nucleo_144.h"

// EDFA input signals
//#define	EDFA_RSTuC_PORT		GPIO
//#define	EDFA_RSTuC_PIN		GPIO_PIN_

//#define	EDFA__PORT		GPIO
//#define	EDFA__PIN		GPIO_PIN_

//#define	EDFA__PORT		GPIO
//#define	EDFA__PIN		GPIO_PIN_

// EDFA output signals
//#define	EDFA__PORT		GPIO
//#define	EDFA__PIN		GPIO_PIN_

//#define	EDFA__PORT		GPIO
//#define	EDFA__PIN		GPIO_PIN_

//#define	EDFA__PORT		GPIO
//#define	EDFA__PIN		GPIO_PIN_

void GPIO_Config(void);

#endif /* API_INC_API_GPIO_H_ */
