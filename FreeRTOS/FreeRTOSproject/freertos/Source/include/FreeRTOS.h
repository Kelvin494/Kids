#ifndef FREERTOS_H
#define FREERTOS_H


#include "portmacro.h"
#include "list.h"
#include "FreeRTOSConfig.h"

/****************/
/*任务控制块结构*/
/****************/
typedef struct tskTaskControlBlock
{
volatile StackType_t *pxTopOfStack; /*栈顶*/

ListItem_t xStateListItem;	/*任务节点，用于*/

StackType_t *pxStack;		/*任务栈起始地址*/

char pcTaskName[ 16 ];/*任务名称，字符串形式*/
} tskTCB;
typedef tskTCB TCB_t;



#endif
