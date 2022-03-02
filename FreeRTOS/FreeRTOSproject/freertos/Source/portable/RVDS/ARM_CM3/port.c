#include "task.h"

#define portINITIAL_XPSR ( 0x01000000 )
#define portSTART_ADDRESS_MASK ( ( StackType_t ) 0xfffffffeUL )

static void prvTaskExitError( void )
{
/* 函数停止在这里 */
for (;;);
}
StackType_t *pxPortInitialiseStack( StackType_t *pxTopOfStack,
TaskFunction_t pxCode,
void *pvParameters )
{
/* 异常发生时，自动加载到CPU寄存器的内容 */
pxTopOfStack--;
*pxTopOfStack = portINITIAL_XPSR;
pxTopOfStack--;
*pxTopOfStack = ( ( StackType_t ) pxCode ) &
portSTART_ADDRESS_MASK;
pxTopOfStack--;
*pxTopOfStack = ( StackType_t ) prvTaskExitError;
pxTopOfStack -= 5 /* r12、r3、r2和r1默认初始化为0 */
*pxTopOfStack = ( StackType_t ) pvParameters;

/* 异常发生时，手动加载到CPU寄存器的内容 */
pxTopOfStack -= 8;

/* 返回栈顶指针，此时pxTopOfStack指向空闲栈 */
return pxTopOfStack;
}
