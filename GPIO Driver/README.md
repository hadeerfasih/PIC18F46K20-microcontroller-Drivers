# GPIO Driver for PIC18F46K20 Microcontroller

## Overview

This project implements a GPIO driver for the PIC18F46K20 microcontroller. The driver provides functionalities to initialize, configure, and control the General Purpose Input/Output (GPIO) pins and ports of the microcontroller.

## Files

- **gpio.h**: Header file containing the macro definitions, data types, and function declarations for the GPIO driver.
- **gpio.c**: Source file containing the function definitions for the GPIO driver.

## gpio.h

This header file includes the necessary dependencies, macro declarations, data type declarations, and function declarations for the GPIO driver.

### Includes

```c
#include "../proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "hal_gpio_config.h"
```

### Macro Declarations

- `BITMASK`
- `PORT_PIN_MAX_NUMBER`
- `PORT_MAX_NUMBER`
- `PORTC_TOGGLE_MASK`
- `PORT_PIN_CONFIGRATIONS`
- `PORT_CONFIGRATIONS`

### Macro Function Declarations

- `HWREG8(x)`
- `SET_BIT(REG_ADDR,BIT_BOS)`
- `CLEAR_BIT(REG_ADDR,BIT_BOS)`
- `TOGGLE_BIT(REG_ADDR,BIT_BOS)`
- `READ_BIT(REG_ADDR,BIT_BOS)`

### Data Type Declarations

- `logic_t`
- `direction_t`
- `pin_index_t`
- `port_index_t`
- `pin_config_t`

### Function Declarations

- GPIO Pin Functions
  - `Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *pin_config);`
  - `Std_ReturnType gpio_get_pin_direction_status(const pin_config_t *pin_config, direction_t *direction_status);`
  - `Std_ReturnType gpio_pin_write_logic(const pin_config_t *pin_config, logic_t logic);`
  - `Std_ReturnType gpio_pin_read_logic(const pin_config_t *pin_config, logic_t *logic);`
  - `Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *pin_config);`
  - `Std_ReturnType gpio_pin_intialize(const pin_config_t *pin_config);`

- GPIO Port Functions
  - `Std_ReturnType gpio_port_direction_intialize(port_index_t port, uint8 direction);`
  - `Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status);`
  - `Std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic);`
  - `Std_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic);`
  - `Std_ReturnType gpio_port_toggle_logic(port_index_t port);`

## gpio.c

This source file contains the definitions for the functions declared in `gpio.h`.

### Function Definitions

- GPIO Pin Functions
  - `Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *pin_config);`
  - `Std_ReturnType gpio_get_pin_direction_status(const pin_config_t *pin_config, direction_t *direction_status);`
  - `Std_ReturnType gpio_pin_write_logic(const pin_config_t *pin_config, logic_t logic);`
  - `Std_ReturnType gpio_pin_read_logic(const pin_config_t *pin_config, logic_t *logic);`
  - `Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *pin_config);`
  - `Std_ReturnType gpio_pin_intialize(const pin_config_t *pin_config);`

- GPIO Port Functions
  - `Std_ReturnType gpio_port_direction_intialize(port_index_t port, uint8 direction);`
  - `Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status);`
  - `Std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic);`
  - `Std_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic);`
  - `Std_ReturnType gpio_port_toggle_logic(port_index_t port);`

## Usage

1. **Initialization**:
   Initialize the GPIO pin or port using the appropriate initialization function (`gpio_pin_intialize` or `gpio_port_direction_intialize`).

2. **Configuration**:
   Configure the direction and logic level of the GPIO pin or port using the direction and logic functions (`gpio_pin_direction_intialize`, `gpio_pin_write_logic`, etc.).

3. **Reading and Writing**:
   Use the read and write functions to interact with the GPIO pins or ports (`gpio_pin_read_logic`, `gpio_pin_write_logic`, etc.).

4. **Toggling**:
   Toggle the logic level of the GPIO pin or port using the toggle functions (`gpio_pin_toggle_logic`, `gpio_port_toggle_logic`).

## Example

```c
in application.c outside main function
pin_config_t led_1={
.port=PORTC_INDEX,
.pin=PIN0,
.direction=OUTPUT,
.logic=LOW
};

in application.c inside main function
application_intialize();
in application_intialize function
ret=gpio_pin_intialize(&led_1);

## Notes

- Ensure that the microcontroller is properly configured and that the necessary headers and libraries are included.
- The macro definitions and function declarations are designed to be flexible and easy to use.
- Error handling is included to ensure that invalid configurations are caught and handled appropriately.



https://github.com/user-attachments/assets/65b586be-29ab-4b9f-9b9d-bf5ea7afbe7f



