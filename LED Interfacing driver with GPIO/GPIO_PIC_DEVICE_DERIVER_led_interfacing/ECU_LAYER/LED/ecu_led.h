/* 
 * File:   ecu_led.h
 * Author: Hadeer.Shrif
 *
 * Created on March 29, 2024, 5:34 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H
/*section : includes*/
#include "../../MCAL_LAYER/GPIO/hal_gpio.h"
#include "ecu_led_config.h"
/*section : Macro declarations*/

/*section : Macro function declarations*/

/*section : Data type declarations*/
typedef enum{
    LED_ON,
    LED_OFF
}led_status_t;

typedef struct{
    uint8 port_name:4;
    uint8 pin:3;
    uint8 led_status:1 ;    
}led_t;


/*section : Function declarations*/
Std_ReturnType led_initialize(const led_t *led);
Std_ReturnType led_turn_on(const led_t *led);
Std_ReturnType led_turn_off(const led_t *led);
Std_ReturnType led_toggle(const led_t *led);

#endif	/* ECU_LED_H */

