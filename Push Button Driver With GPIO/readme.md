Here is a README for your push button driver:

---

# Push Button Driver with Debouncing

This repository contains a simple yet effective push button driver designed for embedded systems. The driver is implemented in C and is part of a larger GPIO (General Purpose Input/Output) driver module that includes an LED driver. The push button driver provides an interface to initialize a button, read its state, and handle debouncing in the application layer.

## Files

- **ecu_button.h**: Header file that contains the data types, macro declarations, and function prototypes for the push button driver.
- **ecu_button.c**: Source file that implements the functions declared in `ecu_button.h`.
- **application.c**: Example application file demonstrating the usage of the push button driver, along with LED control and debouncing logic.

## Data Structures

### `button_t`
This structure defines the configuration of a button, including its pin configuration, state, and connection type (active high or active low).

```c
typedef struct{
    pin_config_t button_pin;
    button_state_t button_state;
    button_active_t button_connection;
} button_t;
```

### `button_state_t`
Enumeration to represent the state of the button:
- `BUTTON_PRESSED`
- `BUTTON_RELEASED`

### `button_active_t`
Enumeration to define the button's connection type:
- `BUTTON_ACTIVE_HIGH`
- `BUTTON_ACTIVE_LOW`

## Functions

### `Std_ReturnType button_initialize(const button_t *btn)`
Initializes the button by setting up the pin configuration. Returns `E_OK` on success or `E_NOT_OK` if an error occurs.

### `Std_ReturnType button_read_state(const button_t *btn, button_state_t *btn_state)`
Reads the current state of the button (pressed or released) and stores it in `btn_state`. It also handles the button's connection type (active high or low). Returns `E_OK` on success or `E_NOT_OK` if an error occurs.

## Example Usage

An example application (`application.c`) demonstrates how to use the button driver with an LED and handle button debouncing. The example includes three programs, each triggered by pressing a button, with the button press being debounced to prevent false triggers.

### Example Initialization

```c
button_t button_high = {
    .button_pin.port = PORTC_INDEX,
    .button_pin.pin = PIN2,
    .button_pin.direction = INPUT,
    .button_pin.logic = LOW,
    .button_connection = BUTTON_ACTIVE_HIGH,
    .button_state = BUTTON_RELEASED
};

button_t button_low = {
    .button_pin.port = PORTD_INDEX,
    .button_pin.pin = PIN0,
    .button_pin.direction = INPUT,
    .button_pin.logic = HIGH,
    .button_connection = BUTTON_ACTIVE_LOW,
    .button_state = BUTTON_RELEASED
};

led_t led_1 = {
    .port_name = PORTC_INDEX,
    .pin = PIN0,
    .led_status = LOW
};

led_t led_2 = {
    .port_name = PORTC_INDEX,
    .pin = PIN1,
    .led_status = LOW
};
```

### Example Main Loop with Debouncing

```c
int main() {
    application_intialize();
    while(1){
        // Reading button states
        ret = button_read_state(&button_high, &button_high_status);
        ret = button_read_state(&button_low, &button_low_status);

        // Debouncing logic
        if(button_high_status == BUTTON_PRESSED){
            btn_high_valid++;
            if(btn_high_valid > 500){
                button_high_valid_status = BUTTON_PRESSED;
            }
        } else {
            btn_high_valid = 0;
            button_high_valid_status = BUTTON_RELEASED;
        }

        // Handling button press actions
        if(button_high_valid_status != button_high_last_valid_status){
            button_high_last_valid_status = button_high_valid_status;
            if(button_high_valid_status == BUTTON_PRESSED){
                program_sellected = (program_sellected % 3) + 1;
                switch(program_sellected){
                    case 1: program_1(); break;
                    case 2: program_2(); break;
                    case 3: program_3(); break;
                    default: break;
                }
            }
        }
    }
    return (EXIT_SUCCESS);
}
```

### Debouncing Solution

The example includes a simple debouncing solution that counts the number of consecutive reads where the button is pressed. If the button remains pressed for more than 500 iterations, the press is considered valid.

https://github.com/user-attachments/assets/731b6dc8-d1bf-4dde-8d44-aeb65a27e109

Feel free to adjust this README according to your specific project details!

