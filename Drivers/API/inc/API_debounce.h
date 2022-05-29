/*
 * API_debounce.h
 *
 *  Created on: Mar 27, 2022
 *      Author: Lucas
 */

#ifndef API_INC_API_DEBOUNCE_H_
#define API_INC_API_DEBOUNCE_H_

#include "stm32f4xx_nucleo_144.h" 	/* <- BSP include */
#include "API_delay.h"
#include "API_uart.h"

#define DEBOUNCE_DELAY	40

void debounceFSM_init();
void debounceFSM_update();
bool_t readKey();

#endif /* API_INC_API_DEBOUNCE_H_ */
