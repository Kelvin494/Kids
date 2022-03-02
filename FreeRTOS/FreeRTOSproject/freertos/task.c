#include "task.h"
#include "FreeRTOSConfig.h"

/*创建任务，静态创建*/
/*
动态创建时，
任务控制块和栈的内存是创建任务时动态分配的，
任务删除时，内存可以释放。
静态创建时，任务控制块和栈的内存需要事先定义好，
是静态的内存，任务删除时，内存不能释放。
*/
#if( configSUPPORT_STATIC_ALLOCATION == 1 )  /*静态创建*/

TaskHandle_t xTaskCreateStatic(TaskFunction_t pxTaskCode,
const char * const pcName,
const uint32_t ulStackDepth,
void * const pvParameters,
StackType_t * const
puxStackBuffer,
TCB_t * const pxTaskBuffer )

{
TCB_t *pxNewTCB;
TaskHandle_t xReturn;

if ( ( pxTaskBuffer != NULL ) && ( puxStackBuffer != NULL) )
{
pxNewTCB = ( TCB_t * ) pxTaskBuffer;
pxNewTCB->pxStack = ( StackType_t * ) puxStackBuffer;

/* 创建新的任务 */
prvInitialiseNewTask(
pxTaskCode, 	/* 任务入口*/
pcName, 	/* 任务名称，字符串形式 */
ulStackDepth, 	/* 任务栈大小，单位为字 */
pvParameters,	/* 任务形参*/
&xReturn, 	/* 任务句柄*/
pxNewTCB ); 	/* 任务栈起始地址 */
}
else
{
xReturn = NULL;
 }

/* 返回任务句柄，如果任务创建成功，此时xReturn应该指向任务控制块*/
return xReturn;
}

#endif  
/* configSUPPORT_STATIC_ALLOCATION */


/********/
/*私有的初始化新任务函数*/
/********/
static void prvInitialiseNewTask(
		TaskFunction_t pxTaskCode,//任务入口
		const char * const pcName,//任务名称，字符串
		const uint32_t ulStackDepth,//任务栈大小，单位为字
		void * const pvParameters,//任务形参
		TaskHandle_t * const pxCreatedTask,//任务句柄
		TCB_t *pxNewTCB )//任务控制块指针

{
StackType_t *pxTopOfStack;
UBaseType_t x;

/* 获取栈顶地址 */
pxTopOfStack = pxNewTCB->pxStack + ( ulStackDepth - (uint32_t ) 1 );

/* 向下做8字节对齐 *///兼容64位浮点运算
pxTopOfStack = ( StackType_t * ) \
( ( ( uint32_t ) pxTopOfStack ) & ( ~( (uint32_t ) 0x0007 ) ) );

/* 将任务名存储在TCB中 */
for ( x = ( UBaseType_t ) 0; x < ( UBaseType_t ) configMAX_TASK_NAME_LEN; x++ )
{
pxNewTCB->pcTaskName[ x ] = pcName[ x ];

if ( pcName[ x ] == 0x00 )
{
break;
}
}
/* 任务名的长度不能超过configMAX_TASK_NAME_LEN */
pxNewTCB->pcTaskName[ configMAX_TASK_NAME_LEN - 1 ] ='\0';

/* 初始化TCB中的xStateListItem节点 */(
vListInitialiseItem( &( pxNewTCB->xStateListItem ) );

/* 设置xStateListItem节点的拥有者 */(
listSET_LIST_ITEM_OWNER( &( pxNewTCB->xStateListItem ),
			pxNewTCB );


/* 初始化任务栈 */(
pxNewTCB->pxTopOfStack = pxPortInitialiseStack(
		pxTopOfStack,
		pxTaskCode,
		pvParameters );


/* 让任务句柄指向任务控制块 */
if ( ( void * ) pxCreatedTask != NULL )
{
*pxCreatedTask = ( TaskHandle_t ) pxNewTCB;
}
}
