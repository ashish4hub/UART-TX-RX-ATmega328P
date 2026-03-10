// RX code 
// upload on Receiver IC


#define F_CPU 16000000
#include<avr/io.h>
#include<avr/interrupt.h>
#define BAUD 9600
#define BRC ((F_CPU / (16 * BAUD)) - 1)
volatile char rx_data;
void uart_rx_ini(){
  UBRR0H = (BRC >> 8);
  UBRR0L = BRC;
  UCSR0B = (1 << RXCIE0) | (1 << RXEN0);
  UCSR0C = ( 1 << UCSZ01) | (1 << UCSZ00);
  sei();
}
ISR(USART_RX_vect){
  rx_data = UDR0; // ISR writes the received byte
}
int main (void){
  uart_rx_ini();
  DDRB |= (1 << PB5);
  DDRB |= (1 << PB4);
  DDRB |= (1 << PB3);
  while(1){
    if(rx_data == 'B'){
      PORTB |= (1 << PB4);
      PORTB &= ~(1 << PB5);
      PORTB &= ~(1 << PB3);
    }
    else if(rx_data == 'R'){
      PORTB |= (1 << PB5);
      PORTB &= ~(1 << PB4);
      PORTB &= ~(1 << PB3);
    }
    else if(rx_data == 'O'){
      PORTB |= (1 << PB3);
      PORTB &= ~(1 << PB5);
      PORTB &= ~(1 << PB4);
    
    }
  }
}

