/* 
 * File:   application.c
 * Author: Hadeer.Shrif
 *
 * Created on March 29, 2024, 12:15 AM
 */

#include "application.h"


Std_ReturnType ret=E_OK;
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
int main() {
    
    application_intialize();
    usart_module_init();

    while(1){
        ret=EUSART_ASYNC_WriteByteBlocking('a');
        __delay_ms(500);
        ret=EUSART_ASYNC_WriteByteBlocking('b');
        __delay_ms(500);
        ret = EUSART_ASYNC_WriteStringBlocking("Hadeer ", 7);
        __delay_ms(500);
        ret = EUSART_ASYNC_WriteStringBlocking("Shrif ", 6);
        __delay_ms(500);
    }
       
    return (EXIT_SUCCESS);

}
void application_intialize(void){
    ecu_layer_initialize();

}

