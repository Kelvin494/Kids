#ifndef __MAIN_H
#define __MAIN_H

//1.时钟寄存器
#define CCM_CCGR0 *((volatile unsigned int *)0x020c4068)
#define CCM_CCGR1 *((volatile unsigned int *)0x020c406c)
#define CCM_CCGR2 *((volatile unsigned int *)0x020c4070)
#define CCM_CCGR3 *((volatile unsigned int *)0x020c4074)
#define CCM_CCGR4 *((volatile unsigned int *)0x020c4078)
#define CCM_CCGR5 *((volatile unsigned int *)0x020c407c)
#define CCM_CCGR6 *((volatile unsigned int *)0x020c4080)

//2.复用功能
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03 *((volatile unsigned int *)0x020e0068)
//3.电气属性
#define IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03 *((volatile unsigned int *)0x020e02f4)
//4.GPIO引脚设置
#define GPIO1_DR *((volatile unsigned int *)0x209c000)
#define GPIO1_GDIR *((volatile unsigned int *)0x209c004)

#endif