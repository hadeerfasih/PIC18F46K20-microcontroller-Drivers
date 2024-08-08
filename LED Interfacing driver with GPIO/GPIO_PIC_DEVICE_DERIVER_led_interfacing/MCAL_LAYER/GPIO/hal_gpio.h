 /* 
 * File:   hal_gpio.h
 * Author: hadeer.shrif
 *
 * Created on March 29, 2024, 4:44 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/////////section : Includes /////////////////////////////
#include "../proc/pic18f4620.h"
//#include <pic18f4620.h> 
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "hal_gpio_config.h"

/////////section : Macro declarations ////////////////////
#define BITMASK   0x01
#define PORT_PIN_MAX_NUMBER  8
#define PORT_MAX_NUMBER  5
#define PORTC_TOGGLE_MASK 0xFF

#define PORT_PIN_CONFIGRATIONS ENABLE    //if it is disable the functions "that checked by this macro" will be locked
#define PORT_CONFIGRATIONS ENABLE
/////////section : Macro function declarations ///////////
#define HWREG8(x)                      (*((volatile uont8 *)x))
#define SET_BIT(REG_ADDR,BIT_BOS)      (REG_ADDR |=(BITMASK<<BIT_BOS))
#define CLEAR_BIT(REG_ADDR,BIT_BOS)    (REG_ADDR &=~(BITMASK<<BIT_BOS))
#define TOGGLE_BIT(REG_ADDR,BIT_BOS)   (REG_ADDR ^=(BITMASK<<BIT_BOS))
#define READ_BIT(REG_ADDR,BIT_BOS)      (REG_ADDR>>BIT_BOS)&BITMASK
/////////section : Data type declarations ///////////////
typedef enum{
    LOW=0,
    HIGH        
}logic_t;

typedef enum{
    OUTPUT=0,
    INPUT        
}direction_t;

typedef enum{
    PIN0=0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7          
}pin_index_t;

typedef enum{
    PORTA_INDEX=0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX
}port_index_t;

typedef struct{
    uint8 port:3;  //the max num it might has is 4 which needs 3bits so make it take 3 bits instead uint8 which is 4bits     @ref port_index_t
    uint8 pin:3;  //max num is 7 need 3bits                     @ref pin_index_t
    uint8 direction:1; // max num is 1                          @ref direction_t
    uint8 logic:1;    // max num is 1                           @ref logic_t
}pin_config_t;
/////////section : Function declarations ///////////////
Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *pin_config);
Std_ReturnType gpio_get_pin_direction_status(const pin_config_t *pin_config, direction_t *direction_status);

Std_ReturnType gpio_pin_write_logic(const pin_config_t *pin_config, logic_t logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t *pin_config, logic_t *logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *pin_config);

Std_ReturnType gpio_pin_intialize(const pin_config_t *pin_config);

Std_ReturnType gpio_port_direction_intialize(port_index_t  port,uint8 direction);
Std_ReturnType gpio_port_get_direction_status(port_index_t  port,uint8 *direction_status);
Std_ReturnType gpio_port_write_logic(port_index_t  port,uint8 logic);
Std_ReturnType gpio_port_read_logic(port_index_t  port,uint8 *logic);
Std_ReturnType gpio_port_toggle_logic(port_index_t  port);
#endif	/* HAL_GPIO_H */

