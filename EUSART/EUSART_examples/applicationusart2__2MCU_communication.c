/* 
 * File:   application.c
 * Author: Hadeer.Shrif
 *
 * Created on March 29, 2024, 12:15 AM
 */

#include "application.h"

Std_ReturnType ret=E_NOT_OK;

void usart_module_init(void){
    usart_t usart_obj;
    usart_obj.baudrate=9600;
    usart_obj.baudrate_gen_config=BAUDRATE_ASYN_8BIT_LOW_SPEED;
    
    usart_obj.usart_tx_cfg.usart_tx_enable=EUSART_ASYNCHRONOUS_TX_ENABLE;
    usart_obj.usart_tx_cfg.usart_tx_interrupt_enable=EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE;
    usart_obj.usart_tx_cfg.usart_tx_9bit_enable=EUSART_ASYNCHRONOUS_9Bit_TX_DISABLE;
    
    usart_obj.usart_rx_cfg.usart_rx_enable=EUSART_ASYNCHRONOUS_RX_ENABLE;
    usart_obj.usart_rx_cfg.usart_rx_interrupt_enable=EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE;
    usart_obj.usart_rx_cfg.usart_rx_9bit_enable=EUSART_ASYNCHRONOUS_9Bit_RX_DISABLE;
    
    usart_obj.EUSART_TXDefaultInterruptHandler=NULL;
    usart_obj.EUSART_RXDefaultInterruptHandler=NULL;
    usart_obj.EUSART_FramingErrorHandler=NULL;
    usart_obj.EUSART_OverrunErrorHandler=NULL; 
    ret=EUSART_ASYNC_Init(&usart_obj);
}

uint8 rec_uart_data;
int main() {
    Std_ReturnType ret=E_NOT_OK;
    application_intialize();
    usart_module_init();

    while(1){
//        ret=EUSART_ASYNC_WriteByteBlocking('o');
//        __delay_ms(1000);
//        ret=EUSART_ASYNC_WriteByteBlocking('f');
//        __delay_ms(1000);
        
        
        ret=EUSART_ASYNC_ReadByteNonBlocking(&rec_uart_data);
        
        if(E_OK==ret){
           if(rec_uart_data=='o'){
                led_turn_on(&led1);
                ret=EUSART_ASYNC_WriteStringBlocking("LED ON\r",7);
           }
           else if(rec_uart_data=='f'){
                led_turn_off(&led1);
                ret=EUSART_ASYNC_WriteStringBlocking("LED OFF\r",8);
           }
           else{/*nothing*/}
        }
        else{/*nothing*/}

        

        
    }
       
    return (EXIT_SUCCESS);

}
void application_intialize(void){
    ecu_layer_initialize();

}

