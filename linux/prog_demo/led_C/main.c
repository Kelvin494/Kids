#include "main.h"

void click_enabled(void){
    CCM_CCGR0 = 0xffffffff;
    CCM_CCGR1 = 0xffffffff;
    CCM_CCGR2 = 0xffffffff;
    CCM_CCGR3 = 0xffffffff;
    CCM_CCGR4 = 0xffffffff;
    CCM_CCGR5 = 0xffffffff;
    CCM_CCGR6 = 0xffffffff;
}

void ledinit(){
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03 = 0x5;
    IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03 = 0x10b0;
    GPIO1_GDIR =0x8;
    GPIO1_DR = 0x0;

}
void delay_short(volatile unsigned int n){
    while(n--);
}
void delay(volatile unsigned int n){
    while(n--){
        delay_short(0x7ff);
    }
}
void led_on(void){
    GPIO1_DR&=~(1<<3);
}
void led_off(void){
    GPIO1_DR|=(1<<3);
}
int main(void){
    //³õÊ¼»¯led
    click_enabled();
    //ÉèÖÃÉÁË¸
    ledinit();
    
    while(1){
        led_on();
        delay(500);
        led_off();
        delay(500);
    }

return 0;
}