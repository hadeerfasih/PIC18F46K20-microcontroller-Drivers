/* 
 * File:   application.c
 * Author: Hadeer.Shrif
 *
 * Created on March 29, 2024, 12:15 AM
 */



#include "application.h"

led_t led_1={
.port_name=PORTC_INDEX,
.pin=PIN0,
.led_status=LOW
};

led_t led_2={
.port_name=PORTC_INDEX,
.pin=PIN1,
.led_status=LOW
};

led_t led_3={
.port_name=PORTC_INDEX,
.pin=PIN2,
.led_status=LOW
};

led_t led_4={
.port_name=PORTC_INDEX,
.pin=PIN3,
.led_status=LOW
};
int main() {

    application_intialize();
    while(1){
        /*turn on and turn off trial*/
        /*led_turn_on(&led_1);
        led_turn_on(&led_2);
        led_turn_on(&led_3);
        led_turn_on(&led_4);
        for(int i=50000;i<0;i--){
        }
        led_turn_off(&led_1);
        led_turn_off(&led_2);
        led_turn_off(&led_3);
        led_turn_off(&led_4);
        for(int i=50000;i<0;i--){
        }*/
        
        /*toggle trial*/
        led_toggle(&led_1);
        led_toggle(&led_2);
        led_toggle(&led_3);
        led_toggle(&led_4);
        for(int i=50000;i<0;i--){
        }
    }
    
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret=E_NOT_OK;
    ret=led_initialize(&led_1);
    ret=led_initialize(&led_2);
    ret=led_initialize(&led_3);
    ret=led_initialize(&led_4);
    
}