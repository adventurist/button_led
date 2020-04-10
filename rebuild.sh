#!/usr/bin/env bash

avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o button_led.o button_led.c && \
avr-gcc -mmcu=atmega328p button_led.o -o button_led && \
avr-objcopy -O ihex -R .eeprom button_led button_led.hex && \
avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:button_led.hex
