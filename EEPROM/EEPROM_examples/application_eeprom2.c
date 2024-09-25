/* 
 * File:   application.c
 * Author: Hadeer.Shrif
 *
 * Created on March 29, 2024, 12:15 AM
 */

#include "application.h"

volatile uint8 program_selected=0;
Std_ReturnType ret=E_OK;
void program1(void){
    led_turn_on(&led1); 
    __delay_ms(250);
    led_turn_off(&led1); 
    __delay_ms(250);
}
void program2(void){
    led_turn_on(&led2); 
    __delay_ms(250);
    led_turn_off(&led2); 
    __delay_ms(250);
    

}
void Int0_APP_ISR(void){
    program_selected++;
    if(program_selected>2){
        program_selected=0;
    }
    ret=Data_EEPROM_WriteByte(0x3ff,program_selected);
}
interrupt_INTx_t int0_obj={
.EXT_InterruptHandler=Int0_APP_ISR,
.edge=INTERRUPT_RISING_EDGE,
.priority=INTERRUPT_HIGH_PRIORITY,
.source=INTERRUPT_EXTERNAL_INT0,
.mcu_pin.port=PORTB_INDEX,
.mcu_pin.pin=PIN0,
.mcu_pin.direction=INPUT,
.mcu_pin.logic=LOW
};

uint8 eeprom_val=0;
uint8 eeprom_read=0;



int main() {
    
    application_intialize();
    ret=Interrupt_INTx_Init(&int0_obj);
    ret=Data_EEPROM_ReadByte(0x3ff,&program_selected);

    while(1){

        if(1==program_selected){
            program1();  
        }
        else if(2==program_selected){
            program2(); 
        }
        else{
            led_turn_off(&led1);
            led_turn_off(&led2);
        } 
    }
       
    return (EXIT_SUCCESS);

}
void application_intialize(void){
    ecu_layer_initialize();

}

