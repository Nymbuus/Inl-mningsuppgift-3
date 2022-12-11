#include "header.h"

ISR (PCINT0_vect)
{
	if (BUTTON1_IS_PRESSED)
	{
		leds_enabled = !leds_enabled;
	}
}