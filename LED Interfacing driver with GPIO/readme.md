
# LED Interfacing Driver

This project provides an LED interfacing driver for controlling LEDs using GPIO pins. The driver allows for initializing LEDs, turning them on, turning them off, and toggling their state.

## API Functions

### Initialization

```c
Std_ReturnType led_initialize(const led_t *led);
```
Initializes the assigned pin as an output and turns the LED off.

- **Parameters**: 
  - `led`: Pointer to the LED module configuration.
- **Returns**: 
  - `E_OK`: Function executed successfully.
  - `E_NOT_OK`: Function encountered an issue.

### Turn On

```c
Std_ReturnType led_turn_on(const led_t *led);
```
Turns the LED on.

- **Parameters**: 
  - `led`: Pointer to the LED module configuration.
- **Returns**: 
  - `E_OK`: Function executed successfully.
  - `E_NOT_OK`: Function encountered an issue.

### Turn Off

```c
Std_ReturnType led_turn_off(const led_t *led);
```
Turns the LED off.

- **Parameters**: 
  - `led`: Pointer to the LED module configuration.
- **Returns**: 
  - `E_OK`: Function executed successfully.
  - `E_NOT_OK`: Function encountered an issue.

### Toggle

```c
Std_ReturnType led_toggle(const led_t *led);
```
Toggles the state of the LED.

- **Parameters**: 
  - `led`: Pointer to the LED module configuration.
- **Returns**: 
  - `E_OK`: Function executed successfully.
  - `E_NOT_OK`: Function encountered an issue.

## Data Structures

### LED Status

```c
typedef enum{
    LED_ON,
    LED_OFF
} led_status_t;
```

Defines the status of the LED, either `LED_ON` or `LED_OFF`.

### LED Configuration Structure

```c
typedef struct{
    uint8 port_name:4;
    uint8 pin:3;
    uint8 led_status:1;    
} led_t;
```

Defines the configuration structure for an LED, including the port name, pin number, and initial status.

## Usage

1. Include the `led.h` header file in your project.
2. Define and initialize an `led_t` structure with the appropriate configuration.
3. Use the provided functions to control the LED.

### Example

see the examples in application.c file


https://github.com/user-attachments/assets/4224108e-c219-40e3-99c5-5fd79e568a96




Feel free to adjust any parts to better fit your specific project requirements or preferences!
