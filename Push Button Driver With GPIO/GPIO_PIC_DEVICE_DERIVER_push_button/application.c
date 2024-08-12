/* 
 * File:   application.c
 * Author: Hadeer.Shrif
 *
 * Created on March 29, 2024, 12:15 AM
 */



#include "application.h"


button_t button_high={
.button_pin.port=PORTC_INDEX,
.button_pin.pin=PIN2,
.button_pin.direction=INPUT,
.button_pin.logic=LOW,
.button_connection=BUTTON_ACTIVE_HIGH,
.button_state=BUTTON_RELEASED
};

button_t button_low={
.button_pin.port=PORTD_INDEX,
.button_pin.pin=PIN0,
.button_pin.direction=INPUT,
.button_pin.logic=HIGH,
.button_connection=BUTTON_ACTIVE_LOW,
.button_state=BUTTON_RELEASED

};

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

button_state_t button_high_status=BUTTON_RELEASED;
button_state_t button_low_status=BUTTON_RELEASED;
Std_ReturnType ret=E_NOT_OK;

button_state_t button_high_valid_status=BUTTON_RELEASED;
button_state_t button_high_last_valid_status=BUTTON_RELEASED;

uint32 btn_high_valid=0;
uint8 program_sellected=0;

void program_1(void);
void program_2(void);
void program_3(void);

int main() {

    application_intialize();
    while(1){
        
        ret=button_read_state(&button_high,&button_high_status);
        ret=button_read_state(&button_low,&button_low_status);
        /*bouncing solution*/
        if((button_high_status==BUTTON_PRESSED)){
            btn_high_valid++;
            if(btn_high_valid>500){
                button_high_valid_status=BUTTON_PRESSED;
            }
        }
        else{
            btn_high_valid=0;
            button_high_valid_status=BUTTON_RELEASED;
        }
        /*take action for button press*/
        if(button_high_valid_status != button_high_last_valid_status){
            button_high_last_valid_status=button_high_valid_status;
            if(button_high_valid_status==BUTTON_PRESSED){
                if(3==program_sellected){
                    program_sellected=0;
                }
               program_sellected++;
               
               switch(program_sellected){
                case 1:
                    program_1();
                    break;
                case 2:
                   program_2();
                    break; 
                case 3:
                    program_3();
                    break;
                default:break;
               }
                
            }
        }
        
        
    }
    return (EXIT_SUCCESS);
}

void program_1(void){
    led_turn_on(&led_1);
    __delay_ms(50);
    led_turn_off(&led_1);
    __delay_ms(50);
}
void program_2(void){
    uint8 counter=0;
    for(counter=0;counter<2;counter++){
        led_turn_on(&led_1);
        __delay_ms(50);
        led_turn_off(&led_1);
        __delay_ms(50);
    }
}
void program_3(void){
    uint8 counter=0;
    for(counter=0;counter<3;counter++){
        led_turn_on(&led_1);
        __delay_ms(50);
        led_turn_off(&led_1);
        __delay_ms(50);
    }
}

void application_intialize(void){
    ret=button_initialize(&button_high);
    ret=button_initialize(&button_low);
    
    ret=led_initialize(&led_1);
    ret=led_initialize(&led_2);
    
}


/* 
     ///solve bouncing problem & click turn on another click on the same button turn off application///////
 
 button_t button_high={
.button_pin.port=PORTC_INDEX,
.button_pin.pin=PIN2,
.button_pin.direction=INPUT,
.button_pin.logic=LOW,
.button_connection=BUTTON_ACTIVE_HIGH,
.button_state=BUTTON_RELEASED
};

button_t button_low={
.button_pin.port=PORTD_INDEX,
.button_pin.pin=PIN0,
.button_pin.direction=INPUT,
.button_pin.logic=HIGH,
.button_connection=BUTTON_ACTIVE_LOW,
.button_state=BUTTON_RELEASED

};

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

button_state_t button_high_status=BUTTON_RELEASED;
button_state_t button_low_status=BUTTON_RELEASED;
Std_ReturnType ret=E_NOT_OK;

button_state_t button_high_valid_status=BUTTON_RELEASED;
button_state_t button_high_last_valid_status=BUTTON_RELEASED;

led_status_t led_1_status=LED_OFF;
uint32 btn_high_valid=0;


int main() {

    application_intialize();
    
    while(1){
        
        ret=button_read_state(&button_high,&button_high_status);
        ret=button_read_state(&button_low,&button_low_status);
        
        if((button_high_status==BUTTON_PRESSED)){
            btn_high_valid++;
            if(btn_high_valid>500){
                button_high_valid_status=BUTTON_PRESSED;
            }
        }
        else{
            btn_high_valid=0;
            button_high_valid_status=BUTTON_RELEASED;
        }
        
        if(button_high_valid_status != button_high_last_valid_status){
            button_high_last_valid_status=button_high_valid_status;
            if(button_high_valid_status==BUTTON_PRESSED){
                if(led_1_status==LED_OFF){
                    ret=led_turn_on(&led_1);
                    led_1_status=LED_ON;
                }
                else{
                    ret=led_turn_off(&led_1);
                    led_1_status=LED_OFF;
                }
            }
        }
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    ret=button_initialize(&button_high);
    ret=button_initialize(&button_low);
    
    ret=led_initialize(&led_1);
    ret=led_initialize(&led_2);
    
}
 
 
 
 */