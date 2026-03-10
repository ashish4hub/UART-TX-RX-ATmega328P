// TX code
// Uplaod on transmitter IC


#define F_CPU 16000000
#include<avr/io.h>
#include<avr/interrupt.h>
#include<stdint.h>
#include<util/delay.h>
#define BAUD 9600
#define BRC ((F_CPU / (16 * BAUD)) - 1)
void uart_tx_ini(){
  UBRR0H = (BRC >> 8);
  UBRR0L = BRC;
  UCSR0B = (1 << TXEN0);
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}
void uart_send(uint8_t data){
  while(!(UCSR0A & (1 << UDRE0))){
    
  }
        UDR0 = data;

}
        int main(void){
          uart_tx_ini();
          sei();
          while(1){
          uart_send('R');
          _delay_ms(1000);
          uart_send('B');
          _delay_ms(1000);
          uart_send('O');
          _delay_ms(1000);
          }
          _delay_ms(500);
          
          
        }

