
.global _start

_start:
    //1.使能全部时钟
    ldr r0, =0x020c4068     @ccgr0寄存器
    ldr r1, =0xffffffff     @数据
    str r1, [r0]            @将数据写入寄存器

    ldr r0, =0x020c406c     @ccgr1寄存器
    str r1, [r0]

    ldr r0, =0x020c4070     @ccgr2寄存器
    str r1, [r0]

    ldr r0, =0x020c4074     @ccgr3寄存器
    str r1, [r0]

    ldr r0, =0x020c4078     @ccgr4寄存器
    str r1, [r0]

    ldr r0, =0x020c407c     @ccgr5寄存器
    str r1, [r0]

    ldr r0, =0x020c4080     @ccgr6寄存器
    str r1, [r0]

    //2.设定为GPIO功能
    ldr r0, =0x020e0068     @IOMUXC_SW_MUX_CTL_PAD_GPIO03寄存器
    ldr r1, =0x5            @数据
    str r1, [r0]            @将数据写入寄存器

    //3.设定电气属性
    ldr r0, =0x020e02f4          @IOMUXC_SW_PAD_CTL_PAD_GPIO03寄存器
    ldr r1, =0x10b0              
    @数据 位域从低到高 低速压摆率（高低电平转换速率） R0/6驱动能力 100mhz速度 关闭开漏输出 使能pull/keeper keeper
    @（在cpu非工作时保持原状态，pull上下拉方式在cpu非工作时上/下拉） 100kohm下拉 关闭迟滞（硬件防抖_[]-）
    str r1, [r0]                 @将数据写入存储器

    //4.写入输出
    //设置引脚是输入还是输出
    ldr r0, =0x209c004      @GPIO1_GDIR寄存器209_C004
    ldr r1, =0x8            @GPIO1_IO03 1端口3引脚设为输出
    str r1, [r0]
    //设置引脚输出状态
    ldr r0, =0x209c000      @209_C000 GPIO data register (GPIO1_DR) 
    ldr r1, =0x0            @设置输出为低电平
    str r1, [r0]

//程序主体完毕，暂停程序
loop:
    b loop




