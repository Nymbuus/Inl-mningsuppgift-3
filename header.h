/********************************************************************************
* header.h: inkluderar alla header filer i en fil.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#include "misc.h"
#include "led.h"
#include "led_vector.h"

#define BUTTON1 5
#define BUTTON1_IS_PRESSED (PINB & (1 << BUTTON1))

// Kollar om leds är aktiverade.
extern volatile bool leds_enabled;

extern struct led l1, l2, l3; // Deklarerar 3 led objekt.
extern struct led_vector v1; // Deklarerar en tom led vector.

// Typisk setup funktion.
void setup(void);

#endif /* HEADER_H_ */