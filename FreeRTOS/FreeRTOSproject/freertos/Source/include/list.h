
#ifndef LIST_H
#define LIST_H

#include "portmacro.h"
/*双向循环链表*/
/*链表节点*/
struct xLIST_ITEM
{
TickType_t xItemValue; //辅助值用于帮助节点进行顺序排列
struct xLIST_ITEM * pxNext;//下一节点指针
struct xLIST_ITEM * pxPrevious; //上一节点指针
void * pvOwner; //链表拥有者，TCB
void * pvContainer;//该链表
};
typedef struct xLIST_ITEM ListItem_t;

/*链表精简节点*/
struct xMINI_LIST_ITEM
{
TickType_t xItemValue; /* 辅助值，用于帮助节点进行升序排列 */
struct xLIST_ITEM * pxNext; /* 指向链表下一个节点 */
struct xLIST_ITEM * pxPrevious; /* 指向链表上一个节点 */
};
typedef struct xMINI_LIST_ITEM MiniListItem_t; /* 精简节点数据类型重定义 */

/*链表根节点*/
typedef struct xLIST
{
UBaseType_t uxNumberOfItems; /* 链表节点计数器 */
ListItem_t * pxIndex;        /* 链表节点索引指针 */
MiniListItem_t xListEnd;     /* 链表最后一个节点 */
} List_t;

/*节点带参宏函数*/
/* 初始化节点的拥有者 */
#define listSET_LIST_ITEM_OWNER( pxListItem, pxOwner ) \
	( ( pxListItem )->pvOwner = ( void * ) ( pxOwner ) )

/* 获取节点拥有者 */
#define listGET_LIST_ITEM_OWNER( pxListItem ) \
	( ( pxListItem )->pvOwner )

/* 初始化节点排序辅助值 */
#define listSET_LIST_ITEM_VALUE( pxListItem, xValue ) \
	( ( pxListItem )->xItemValue = ( xValue ) )

/* 获取节点排序辅助值 */
#define listGET_LIST_ITEM_VALUE( pxListItem ) \
	( ( pxListItem )->xItemValue )

/* 获取链表根节点的节点计数器的值 */
#define listGET_ITEM_VALUE_OF_HEAD_ENTRY( pxList ) \
	( ( ( pxList )->xListEnd ).pxNext->xItemValue )

/* 获取链表的入口节点 */
#define listGET_HEAD_ENTRY( pxList ) \
	( ( ( pxList )->xListEnd ).pxNext )

/* 获取节点的下一个节点 */
#define listGET_NEXT( pxListItem ) \
	( ( pxListItem )->pxNext )
/* 获取链表的最后一个节点 */
#define listGET_END_MARKER( pxList ) \
	( ( ListItem_t const * ) ( &( ( pxList )->xListEnd )) )

/* 判断链表是否为空 */
#define listLIST_IS_EMPTY( pxList ) \
	( ( BaseType_t ) ( ( pxList )->uxNumberOfItems == (UBaseType_t ) 0 ) )

/* 获取链表的节点数 */
#define listGET_OWNER_OF_NEXT_ENTRY( pxTCB, pxList )										\
{																							\
List_t * const pxConstList = ( pxList );													\
	/* Increment the index to the next item and return the item, ensuring */				\
	/* we don't return the marker used at the end of the list.  */							\
	( pxConstList )->pxIndex = ( pxConstList )->pxIndex->pxNext;							\
	if( ( void * ) ( pxConstList )->pxIndex == ( void * ) &( ( pxConstList )->xListEnd ) )	\
	{																						\
		( pxConstList )->pxIndex = ( pxConstList )->pxIndex->pxNext;						\
	}																						\
	( pxTCB ) = ( pxConstList )->pxIndex->pvOwner;											\
}
/* 获取链表第一个节点的OWNER，即TCB */
	
//#define listGET_OWNER_OF_NEXT_ENTRY( pxTCB, pxList ) \
//	{\
//	List_t * const pxConstList = ( pxList ); \
//	/* 节点索引指向链表第一个节点 */ 

//	( pxConstList )->pxIndex = ( pxConstList )->pxIndex->pxNext;
//		\
//	/* 这个操作有什么作用 */

//	if( ( void * ) ( pxConstList )->pxIndex == ( void * ) &(( pxConstList )->xListEnd ) )
//		\
//		{
//		( pxConstList )->pxIndex = ( pxConstList )->pxIndex->pxNext;
//		}
//		\
//	/* 获取节点的OWNER，即TCB */
//	( pxTCB ) = ( pxConstList )->pxIndex->pvOwner;
//	}

/*faction*/

extern void vListInitialiseItem( ListItem_t * const pxItem );

extern void vListInitialise( List_t * const pxList );

extern void vListInsertEnd( List_t * const pxList, ListItem_t * const pxNewListItem );

extern void vListInsert( List_t * const pxList, ListItem_t * const pxNewListItem );

extern UBaseType_t uxListRemove( ListItem_t * const pxItemToRemove );


#endif
