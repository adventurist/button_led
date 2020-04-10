#include <avr/io.h>

int main(void) {
  DDRB |= (1 << 0);   // PORTB pin 8 as output
  DDRB &= ~(1 << 1);  // PORTB pin 9 as input

  for (;;) {
    if ((PINB & (1 << 1))) {  // If 2nd pin of PORTB (pin 9)
      PORTB |= (1 << 0);      // Set pin 8 HIGH
    } else {
      PORTB &= ~(1 << 0);  // Set pin 8 LOW
    }
  }
}

