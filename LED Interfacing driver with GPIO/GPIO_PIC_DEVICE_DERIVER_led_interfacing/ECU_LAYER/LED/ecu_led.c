/* 
 * File:   ecu_led.c
 * Author: Hadeer.Shrif
 *
 * Created on March 29, 2024, 5:34 PM
 */

#include "ecu_led.h"
/**
 * @brief Initialize the assigned pin to be OUTPUT and turn the led off
 * @param led : pointer to the led module configuration
 * @return status of the function
 *         [E_OK]:the function done successfully 
 *         [E_NOT_OK]:the function has issue to perform this action
 */
Std_ReturnType led_initialize(const led_t *led){
    Std_ReturnType ret=E_OK;
    
    if(led==NULL){
        ret=E_NOT_OK;        
    }
    else{
        pin_config_t pin_obj={
        .port=led->port_name,
        .pin=led->pin,
        .direction=OUTPUT,
        .logic=led->led_status};
        gpio_pin_intialize(&pin_obj);
    }
    return ret;
}
/**
 * @brief Turn the led on
 * @param led : pointer to the led module configuration
 * @return status of the function
 *         [E_OK]:the function done successfully 
 *         [E_NOT_OK]:the function has issue to perform this action
 */
Std_ReturnType led_turn_on(const led_t *led){
    Std_ReturnType ret=E_OK;
    
    if(led==NULL){
        ret=E_NOT_OK;        
    }
    else{
        pin_config_t pin_obj={
        .port=led->port_name,
        .pin=led->pin,
        .direction=OUTPUT,
        .logic=led->led_status};
        //turn on
        gpio_pin_write_logic(&pin_obj,HIGH);
    }
    return ret;
}
/**
 * @brief Turn the led off
 * @param led : pointer to the led module configuration
 * @return status of the function
 *         [E_OK]:the function done successfully 
 *         [E_NOT_OK]:the function has issue to perform this action
 */
Std_ReturnType led_turn_off(const led_t *led){
    Std_ReturnType ret=E_OK;
 
    if(led==NULL){
        ret=E_NOT_OK;        
    }
    else{
        pin_config_t pin_obj={
        .port=led->port_name,
        .pin=led->pin,
        .direction=OUTPUT,
        .logic=led->led_status};
        gpio_pin_write_logic(&pin_obj,LOW);
    }
    return ret;
}
/**
 * @brief Toggle the led
 * @param led : pointer to the led module configuration
 * @return status of the function
 *         [E_OK]:the function done successfully 
 *         [E_NOT_OK]:the function has issue to perform this action
 */
Std_ReturnType led_toggle(const led_t *led){
    Std_ReturnType ret=E_OK;
    
    if(led==NULL){
        ret=E_NOT_OK;        
    }
    else{
        pin_config_t pin_obj={
        .port=led->port_name,
        .pin=led->pin,
        .direction=OUTPUT,
        .logic=led->led_status};
        gpio_pin_toggle_logic(&pin_obj);
    }
    return ret;
}