/*
 * API_uart.c
 *
 *  Created on: Apr 4, 2022
 *      Author: Lucas
 */

#include "API_uart.h"

#define DEFAULT_TIMEOUT		30
#define DEFAULT_BAUDRATE 	9600

static const char * BAUDRATE = "Baudrate: 9600\r\n";
static const char * WORD_LENGTH = "Word length: 8 bits\r\n";
static const char * STOP_BITS = "Stop bits: 1 bit\r\n";
static const char * PARITY = "Parity: Odd\r\n";
static const char * HW_CTRL = "Hardware control: None\r\n";
static const char * MODE = "Mode: TX/RX\r\n";
static const char * OVERSAMPLING = "Oversampling: 16\r\n";

static UART_HandleTypeDef myUARTHandler;			// Handler del puerto UART
static bool_t UART_Init_OK = false;					// Flag que indica si se pudo inicializar el UART

static void UART_Error_Handler(void);

// Funcion: inicializa el puerto UART con los parametros especificados
// Entrada: Ninguna
// Salida: True si se pudo abrir el puerto sin errores, false en caso contrario
bool_t uartinit(void)
{
	// Configuracion del UART
	myUARTHandler.Instance			= USART3;
	myUARTHandler.Init.BaudRate		= DEFAULT_BAUDRATE;
	myUARTHandler.Init.WordLength	= UART_WORDLENGTH_8B;
	myUARTHandler.Init.StopBits		= UART_STOPBITS_1;
	myUARTHandler.Init.Parity		= UART_PARITY_ODD;
	myUARTHandler.Init.HwFlowCtl	= UART_HWCONTROL_NONE;
	myUARTHandler.Init.Mode			= UART_MODE_TX_RX;
	myUARTHandler.Init.OverSampling	= UART_OVERSAMPLING_16;

	if(HAL_UART_Init(&myUARTHandler) != HAL_OK)
	{
		// Error de inicializacion
		UART_Error_Handler();
		UART_Init_OK = false;
	}
	else
	{
		UART_Init_OK = true;
		// Debug de configuracion del puerto
		uartSendString((uint8_t *)BAUDRATE);
		uartSendString((uint8_t *)WORD_LENGTH);
		uartSendString((uint8_t *)STOP_BITS);
		uartSendString((uint8_t *)PARITY);
		uartSendString((uint8_t *)HW_CTRL);
		uartSendString((uint8_t *)MODE);
		uartSendString((uint8_t *)OVERSAMPLING);
	}

	return UART_Init_OK;
}

// Funcion: Envia por UART el string pasado como argumento, usando el handler
// Entrada: Puntero al string a enviar
// Salida: Ninguna
void uartSendString(uint8_t * pstring)
{
	if((pstring != NULL) && UART_Init_OK)						// Chequea que el puntero y el handler esten inicializados
		HAL_UART_Transmit(&myUARTHandler, pstring, strlen((const char *)pstring), DEFAULT_TIMEOUT);
}

// Funcion: Envia por UART el string pasado como argumento, usando el handler
// Entrada: Puntero y largo del string (en bytes) a enviar
// Salida: Ninguna
void uartSendStringSize(uint8_t * pstring, uint16_t size)
{
	if((pstring != NULL) && (size > 0) && UART_Init_OK)			// Chequea que la cantidad de bytes a enviar sea positiva y que el puntero y el handler esten inicializados
		HAL_UART_Transmit(&myUARTHandler, pstring, size, DEFAULT_TIMEOUT);
}

// Funcion: Recibe por UART la cantidad de bytes pasada por argumento, copiandolos en el buffer
// Entrada: Puntero y largo del string a enviar
// Salida: Ninguna
void uartReceiveStringSize(uint8_t * pstring, uint16_t size)
{
	if((pstring != NULL) && (size > 0) && UART_Init_OK)			// Chequea que la cantidad de bytes a recibir sea positiva y que el puntero y el handler esten inicializados
		HAL_UART_Receive(&myUARTHandler, pstring, size, DEFAULT_TIMEOUT);
}

static void UART_Error_Handler(void)
{

}

