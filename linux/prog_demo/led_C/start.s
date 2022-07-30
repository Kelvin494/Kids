
.global _start


 _start:
    //1.设置SVC超级管理模式
    mrs r0, cpsr  
    bic r0, r0, #0x1f @清零bit4-0
    orr r0, r0, #0x13 @位或原cpsr数据，写入(10011)B
    msr cpsr, r0 @写入数据

    //2.设置sp（其它芯片在这里可能需要初始化DDR）
    ldr sp, =0x80200000
    
    //3.跳转C入口
    b main
