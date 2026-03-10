# UART-TX-RX-ATmega328P
## Bare-Metal UART Communication between Two ATmega328P Microcontrollers ##
*Bare-metal UART communication between two ATmega328P microcontrollers without using Arduino libraries. One MCU transmits characters, and the other receives them and controls LEDs based on the received data.*
## Working / Features ##
- Transmit and receive data between two ATmega328P MCUs using hardware UART.
- Implemented using **register-level programming** (no Arduino libraries like Serial).
- Demonstrates use of **interrupts (RX complete ISR)** for receiving data.
- Controls multiple LEDs on the receiver based on received characters.
- Fully portable to any ATmega328P-based board (Arduino Uno, Nano, etc.).
## Hardware used ##
- 2 × ATmega328P microcontrollers (Arduino Uno or Nano can be used)
- LEDs for output (connected to PB3, PB4, PB5)
- Jumper wires
- Common GND connection between both MCUs
