
#include "modall.h"
#include "led.h"
#include "beep.h"
int main(void){
    clk_enable();

    led_init();
    beep_init();

    led_switch(LED0, ON);
    beep_switch(OFF);
    delay(1000);

    while(1){
        led_switch(LED0, ON);
        beep_switch(ON);
        delay(500);

        led_switch(LED0, OFF);
        beep_switch(OFF);
        delay(500);
    }
    return 0;
}