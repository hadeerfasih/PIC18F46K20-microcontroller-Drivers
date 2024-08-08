/* 
 * File:   hal_gpio.c
 * Author: Hadeer.Shrif
 *
 * Created on March 29, 2024, 12:15 AM
 */

#include "hal_gpio.h"
//reference to the data direction control register
volatile uint8 *tris_register[]={&TRISA,&TRISB,&TRISC,&TRISD};
//reference to the data latch register (read and write to data latch)
volatile uint8 *lat_register[]={&LATA,&LATB,&LATC,&LATD};
//reference to the port status register
volatile uint8 *port_register[]={&PORTA,&PORTB,&PORTC,&PORTD};

/**
 * @brief initialize the direction of specific pin @ref direction_t
 * @param pin_config pointer to the configrations  @ref pin_config_t
 * @return status of the function
 *         [E_OK]:the function done successfully 
 *         [E_NOT_OK]:the function has issue to perform this action
 */

#if PORT_PIN_CONFIGRATIONS== ENABLE
Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *pin_config){
    Std_ReturnType ret=E_OK;
    
    if(NULL==pin_config || pin_config->pin>PORT_PIN_MAX_NUMBER-1){
        ret=E_NOT_OK
    }
    else{
        switch(pin_config->direction){
            case OUTPUT:
                CLEAR_BIT(*tris_register[pin_config->port],pin_config->pin);
                break;
            case INPUT:
                SET_BIT(*tris_register[pin_config->port],pin_config->pin);
                break;

            default:ret=E_NOT_OK ;
        }
    }

    return ret;
}
#endif
/**
 * 
 * @param pin_config pointer to the configrations @ref pin_config_t
 * @param direction_status
 * @return status of the function
 *         [E_OK]:the function done successfully 
 *         [E_NOT_OK]:the function has issue to perform this action
 */
#if PORT_PIN_CONFIGRATIONS== ENABLE
Std_ReturnType gpio_get_pin_direction_status(const pin_config_t *pin_config, direction_t *direction_status){
    Std_ReturnType ret=E_OK;
    
    if(NULL==pin_config ||NULL==direction_status ||pin_config->pin>PORT_PIN_MAX_NUMBER-1){
        ret=E_NOT_OK
    }
    else{
        *direction_status= READ_BIT(*tris_register[pin_config->port],pin_config->pin);
    }
    
    return ret;
}
#endif
/**
 * 
 * @param pin_config pointer to the configrations @ref pin_config_t
 * @param logic
 * @return status of the function
 *         [E_OK]:the function done successfully 
 *         [E_NOT_OK]:the function has issue to perform this action 
 */
#if PORT_PIN_CONFIGRATIONS== ENABLE
Std_ReturnType gpio_pin_write_logic(const pin_config_t *pin_config, logic_t logic){
    Std_ReturnType ret=E_OK;
    
    if(NULL==pin_config||pin_config->pin>PORT_PIN_MAX_NUMBER-1){
        ret=E_NOT_OK
    }
    else{
        switch(logic){
            case LOW:
                CLEAR_BIT(*lat_register[pin_config->port],pin_config->pin);
                break;
            case  HIGH:
                SET_BIT(*lat_register[pin_config->port],pin_config->pin);
                break;
            default : ret=E_NOT_OK;     
        } 
    }
    
    return ret;

}
#endif
/**
 * 
 * @param pin_config pointer to the configrations @ref pin_config_t
 * @param logic
 * @return status of the function
 *         [E_OK]:the function done successfully 
 *         [E_NOT_OK]:the function has issue to perform this action
 */
#if PORT_PIN_CONFIGRATIONS== ENABLE
Std_ReturnType gpio_pin_read_logic(const pin_config_t *pin_config, logic_t *logic){
    Std_ReturnType ret=E_OK;
    
    if(NULL==pin_config ||NULL==logic||pin_config->pin>PORT_PIN_MAX_NUMBER-1){
        ret=E_NOT_OK
    }
    else{
        *logic= READ_BIT(*port_register[pin_config->port],pin_config->pin);
    }
    
    return ret;

}
#endif
/**
 * 
 * @param pin_config pointer to the configrations @ref pin_config_t
 * @return status of the function
 *         [E_OK]:the function done successfully 
 *         [E_NOT_OK]:the function has issue to perform this action
 */
#if PORT_PIN_CONFIGRATIONS== ENABLE
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *pin_config){
    Std_ReturnType ret=E_OK;
    
    if(NULL==pin_config ||pin_config->pin>PORT_PIN_MAX_NUMBER-1){
        ret=E_NOT_OK
    }
    else{
        TOGGLE_BIT(*lat_register[pin_config->port],pin_config->pin);
        
    }
    
    return ret;

}
#endif
/**
 * 
 * @param port
 * @param direction
 * @return status of the function
 *         [E_OK]:the function done successfully 
 *         [E_NOT_OK]:the function has issue to perform this action
 */
#if PORT_CONFIGRATIONS== ENABLE
Std_ReturnType gpio_port_direction_intialize(port_index_t  port,uint8 direction){
    Std_ReturnType ret=E_OK;
    if(port>PORT_MAX_NUMBER-1){
        ret=E_NOT_OK
    }
    else{
        *tris_register[port]=direction;
    }
    
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param direction_status
 * @return status of the function
 *         [E_OK]:the function done successfully 
 *         [E_NOT_OK]:the function has issue to perform this action
 */
#if PORT_CONFIGRATIONS== ENABLE
Std_ReturnType gpio_port_get_direction_status(port_index_t  port,uint8 *direction_status){
    Std_ReturnType ret=E_OK;
    
    if(NULL==direction_status ||port>PORT_MAX_NUMBER-1){
        ret=E_NOT_OK
    }
    else{
       *direction_status=*tris_register[port]; 
    }
    
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param logic
 * @return status of the function
 *         [E_OK]:the function done successfully 
 *         [E_NOT_OK]:the function has issue to perform this action
 */
#if PORT_CONFIGRATIONS== ENABLE
Std_ReturnType gpio_port_write_logic(port_index_t  port,uint8 logic){
    Std_ReturnType ret=E_OK;
    if(port>PORT_MAX_NUMBER-1){
        ret=E_NOT_OK
    }
    else{
        *lat_register[port]=logic;
    }
    
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param logic
 * @return status of the function
 *         [E_OK]:the function done successfully 
 *         [E_NOT_OK]:the function has issue to perform this action
 */
#if PORT_CONFIGRATIONS== ENABLE
Std_ReturnType gpio_port_read_logic(port_index_t  port,uint8 *logic){
    Std_ReturnType ret=E_OK;
    
    if(NULL==logic||port>PORT_MAX_NUMBER-1){
        ret=E_NOT_OK
    }
    else{
        *logic=*port_register[port];
    }
    
    return ret;
}
#endif
/**
 * 
 * @param port
 * @return status of the function
 *         [E_OK]:the function done successfully 
 *         [E_NOT_OK]:the function has issue to perform this action
 */
#if PORT_CONFIGRATIONS== ENABLE
Std_ReturnType gpio_port_toggle_logic(port_index_t  port){
    Std_ReturnType ret=E_OK;
    if(port>PORT_MAX_NUMBER-1){
        ret=E_NOT_OK
    }
    else{
        *lat_register[port]^=PORTC_TOGGLE_MASK;
    }
    
    return ret;
}
#endif
/**
 * 
 * @param pin_config pointer to the configrations @ref pin_config_t
 * @return status of the function
 *         [E_OK]:the function done successfully 
 *         [E_NOT_OK]:the function has issue to perform this action
 */
#if PORT_PIN_CONFIGRATIONS== ENABLE
Std_ReturnType gpio_pin_intialize(const pin_config_t *pin_config){
    Std_ReturnType ret=E_OK;
    
    if(NULL==pin_config || pin_config->pin>PORT_PIN_MAX_NUMBER-1){
        ret=E_NOT_OK
    }
    else{
        ret=gpio_pin_direction_intialize(pin_config);
        ret=gpio_pin_write_logic(pin_config,  pin_config->logic);
    }
    return ret;
}
#endif