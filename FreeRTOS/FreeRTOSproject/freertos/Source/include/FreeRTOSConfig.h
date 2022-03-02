#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H


#define configUSE_16_BIT_TICKS 0//TickType_t 位数，16位为1，32位为0

#define configMAX_TASK_NAME_LEN  16//任务名称字符串形式 长度

#define configSUPPORT_STATIC_ALLOCATION 1//任务创建方式，静态创建为1，动态为0


#endif
