
#include "list.h"
//任务一栈空间
#define TASK1_STACK_SIZE 128
StackType_t Task1Stack[TASK1_STACK_SIZE];
//任务二栈空间
#define TASK2_STACK_SIZE 128
StackType_t Task2Stack[TASK2_STACK_SIZE];

//#include "list.c"
/* 定义链表根节点 */
struct xLIST List_Test;

/* 定义节点 */
struct xLIST_ITEM List_Item1;
struct xLIST_ITEM List_Item2;
struct xLIST_ITEM List_Item3;

int main (void)
{

/* 链表根节点初始化 */
vListInitialise( &List_Test );

/* 节点1初始化 */
vListInitialiseItem( &List_Item1 );
List_Item1.xItemValue = 1;

/* 节点2初始化 */
vListInitialiseItem( &List_Item2 );
List_Item2.xItemValue = 2;

/* 节点3初始化 */
vListInitialiseItem( &List_Item3 );
List_Item3.xItemValue = 3;

/* 将节点插入链表，按照升序排列 */
vListInsert( &List_Test, &List_Item2 );
vListInsert( &List_Test, &List_Item1 );
vListInsert( &List_Test, &List_Item3 );








return 0;
}