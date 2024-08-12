/* 
 * File:   ecu_button.h
 * Author: Hadeer Shrif
 *
 * Created on August 11, 2024, 11:08 PM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/*section : includes*/
#include "ecu_button_conf.h"
/*section : Macro declarations*/

/*section : Macro function declarations*/

/*section : Data type declarations*/
typedef enum{
    BUTTON_PRESSED,
    BUTTON_RELEASED
}button_state_t;

typedef enum{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW
}button_active_t;

typedef struct{
    pin_config_t button_pin;
    button_state_t button_state;
    button_active_t button_connection;
}button_t;

/*section : Function declarations*/
Std_ReturnType button_initialize(const button_t *btn);
Std_ReturnType button_read_state(const button_t *btn,button_state_t *btn_state);
#endif	/* ECU_BUTTON_H */

