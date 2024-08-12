
/* 
 * File:   ecu_button_conf.h
 * Author: Hadeer Shrif
 *
 * Created on August 11, 2024, 11:09 PM
 */

#include "ecu_button.h"

/**
 * 
 * @param btn 
 * @return status of the function
 *         [E_OK]:the function done successfully 
 *         [E_NOT_OK]:the function has issue to perform this action
 */

Std_ReturnType button_initialize(const button_t *btn){
    Std_ReturnType ret=E_OK;
    
    if(btn==NULL){
        ret=E_NOT_OK;        
    }
    else{
        ret=gpio_pin_direction_intialize(&(btn->button_pin));
    
    }
    return ret;
}

/**
 * 
 * @param btn
 * @param btn_state
 * @return status of the function
 *         [E_OK]:the function done successfully 
 *         [E_NOT_OK]:the function has issue to perform this action
 */
Std_ReturnType button_read_state(const button_t *btn,button_state_t *btn_state){
    Std_ReturnType ret=E_OK;
    logic_t pin_logic_status=LOW;
    if(btn==NULL||btn_state==NULL ){
        ret=E_NOT_OK;        
    }
    else{
        gpio_pin_read_logic(&(btn->button_pin),&pin_logic_status);
        
        if(btn->button_connection==BUTTON_ACTIVE_HIGH){
            if(pin_logic_status==HIGH){
               *btn_state=BUTTON_PRESSED;
            }
            else{
               *btn_state=BUTTON_RELEASED;
            }
        }
        else if(btn->button_connection==BUTTON_ACTIVE_LOW){
            if(pin_logic_status==HIGH){
                *btn_state=BUTTON_RELEASED;
            }
            else{
                *btn_state=BUTTON_PRESSED;
            }
        }
        else{/*nothing*/}
        ret=E_OK;
    }
    return ret;

}