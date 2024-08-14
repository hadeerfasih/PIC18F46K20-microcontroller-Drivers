# GPIO and DC Motor Driver Integration

## Overview

This project demonstrates the integration of a DC motor driver with a GPIO driver. The project involves controlling two DC motors, allowing them to move left, right, or stop, using simple GPIO-based logic.

## Project Structure

- **ecu_dc_motor.h**: Header file for the DC motor driver, containing necessary includes, macros, data type declarations, and function prototypes.

- **ecu_dc_motor.c**: Implementation file for the DC motor driver, containing the logic to initialize, move, and stop the DC motors.

- **application.c**: Example application demonstrating the use of the DC motor driver. This file initializes two DC motors and controls their movement in a loop.

## Files Description

### 1. `ecu_dc_motor.h`

This header file defines the following:
- **Macros**: 
  - `DC_MOTOR_ON_STATUS`: Status indicating the motor is on.
  - `DC_MOTOR_OFF_STATUS`: Status indicating the motor is off.
- **Data Types**:
  - `dc_motor_t`: Structure containing an array of `pin_config_t` for the two pins controlling the motor.
- **Function Prototypes**:
  - `dc_motor_initialize(const dc_motor_t *dc_motor)`: Initializes the motor.
  - `dc_motor_move_right(const dc_motor_t *dc_motor)`: Moves the motor to the right.
  - `dc_motor_move_left(const dc_motor_t *dc_motor)`: Moves the motor to the left.
  - `dc_motor_stop(const dc_motor_t *dc_motor)`: Stops the motor.

### 2. `ecu_dc_motor.c`

This C file provides the implementation of the DC motor driver functions:
- **Initialization**: Sets up the GPIO pins for the motor.
- **Movement**:
  - `dc_motor_move_right()`: Sets the motor to move in the right direction.
  - `dc_motor_move_left()`: Sets the motor to move in the left direction.
  - `dc_motor_stop()`: Stops the motor by setting both control pins low.

### 3. `application.c`

The application demonstrates the usage of the DC motor driver:
- Two DC motors are initialized and controlled in a loop.
- The motors are made to move right, left, stop, and then one motor moves right while the other moves left.

## How to Use

1. **Initialization**: 
   - The motors are configured by defining their control pins and ports in the `dc_motor_t` structure.
   - The `application_intialize()` function initializes the motors.

2. **Motor Control**: 
   - Use the following functions to control the motors:
     - `dc_motor_move_right(&dc_motor)`: Moves the motor right.
     - `dc_motor_move_left(&dc_motor)`: Moves the motor left.
     - `dc_motor_stop(&dc_motor)`: Stops the motor.
   - The `main()` function contains a loop that continuously controls the motors with delays.

## Notes
- Ensure the GPIO driver is correctly implemented and included in the project, as the DC motor driver relies on it for controlling the pins.
- The code assumes that the `gpio_pin_initialize` and `gpio_pin_write_logic` functions are available from the GPIO driver.

## Dependencies
- GPIO Driver: Required for setting pin direction and writing logic levels to the pins.

https://github.com/user-attachments/assets/f2123542-dbf0-44b0-ac06-57179bdd2cda

