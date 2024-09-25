/* 
 * File:   application.c
 * Author: Hadeer.Shrif
 *
 * Created on March 29, 2024, 12:15 AM
 */

#include "application.h"
#include "MCAL_LAYER/EEPROM/eeprom.h"


Std_ReturnType ret=E_OK;
uint8 eeprom_val=0;
uint8 eeprom_read=0;
int main() {
    
    application_intialize();
    ret=Data_EEPROM_WriteByte(0x3ff,0);
    
    while(1){
      ret=Data_EEPROM_WriteByte(0x3ff,eeprom_val++);  
      __delay_ms(1000);
      ret=Data_EEPROM_ReadByte(0x3ff,&eeprom_read);
      if(eeprom_read==5){
          led_turn_on(&led1);  
      }
      else{
          led_turn_off(&led1);
      }
    }
        
       
    return (EXIT_SUCCESS);
}


void application_intialize(void){
    ecu_layer_initialize();

}

