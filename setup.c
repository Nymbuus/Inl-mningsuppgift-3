#include "header.h"
#include "misc.h"

static inline void init_interupts();

struct led l1, l2, l3; // Deklarerar 3 led objekt.
struct led_vector v1; // Deklarerar en tom led vector.

// Sätter leds till false.
volatile bool leds_enabled = false;

void setup()
{
	// Initierar leds.
	led_init(&l1, 8);
	led_init(&l2, 9);
	led_init(&l3, 10);
	
	led_vector_init(&v1);
	
	led_vector_push(&v1, &l1); // Lägger till leds i vektorn.
	led_vector_push(&v1, &l2);
	led_vector_push(&v1, &l3);
	
	// Initierar knappen.
	PORTB |= (1 << BUTTON1);
	
	// Initierar avbrott på knappen.
	init_interupts();
}

static inline void init_interupts()
{
	asm("SEI");
	
	PCICR |= (1 << PCIE0);
	PCMSK0 |= (1 << BUTTON1);
	
	return;
}