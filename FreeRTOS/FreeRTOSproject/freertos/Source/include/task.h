#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "projdefs.h"


/* 任务句柄 */
typedef void * TaskHandle_t;


extern TaskHandle_t xTaskCreateStatic( 
TaskFunction_t pxTaskCode,
const char * const pcName,
const uint32_t ulStackDepth,

void * const pvParameters,
StackType_t * const
puxStackBuffer,
TCB_t * const pxTaskBuffer );


static void prvTaskExitError( void );

StackType_t *pxPortInitialiseStack( 
					StackType_t *pxTopOfStack,
					TaskFunction_t pxCode,
					void *pvParameters );
#endif
