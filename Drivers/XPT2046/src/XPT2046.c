/*
 * XPT2046.c
 *
 *  Created on: May 28, 2022
 *      Author: Lucas
 */

#include "XPT2046.h"

void getXValue(void)
{
	XPT2046_chipEnable();
	XPT2046_startConversion(CTRL_BYTE_TEMP);




	XPT2046_chipDisable();
}
