#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

int main(void) {
  DDRB |= (1 << 0);  // PORTD input
  //  PORTD = 0xff;  // PORTD internall pullup//  DDRB = 0xFF;        // set all
  // pins on PORTB to output
  DDRB &= ~(1 << 1);  // set pin 2 on PORTD to input

  for (;;) {
    if ((PINB & (1 << 1))) {  // if 2nd bit set on PIND
      PORTB |= (1 << 0);      // turn on LED
    } else {
      PORTB &= ~(1 << 0);  // turn off LED
    }
  }
}
