#ifndef F_CPU
#define F_CPU 16000000UL // Define CPU frequency as 16MHz (unsigned long)
#endif

#define DELAY 700

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

int main(void) {
    // Set Data Direction Register D (DDRD) for pin PD0 as output (this is Arduino pin 13)
    
    DDRD = 0b00000001; // Set PD0 as output, all other pins on Port D as input
    // DDRD |= (1 << DDRD0); // Equivalent to this syntax

    while (1) {
        // Turn on the LED (set PD0 high)
        PORTD |= (1 << PORTD0);
        _delay_ms(DELAY); // Wait for 500 milliseconds

        // Turn off the LED (set PD0 low)
        PORTD &= ~(1 << PORTD0);
        _delay_ms(DELAY); // Wait for 500 milliseconds
    }

    return 0;
}

