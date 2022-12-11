/********************************************************************************
* led.c: Innehåller funktioner relaterade till lamporna.
********************************************************************************/
#include "led.h"

/********************************************************************************
* led.init: Initierar angiven pin till utport och registrerar vilket pin-nummer
*           och I/O-port som lysdioden är ansluten till.
*
*           - self: Pekare till lysdioden.
*           - pin : Pin-nummer på Arduino Uno som lysdioden är ansluten till.
********************************************************************************/
void led_init(struct led* self, const uint8_t pin)
{
	self->io_port = IO_PORTB;
	self->pin = pin - 8;
	DDRB |= (1 << self->pin);
	
	self->enabled = false; // Lysdioden är släckt.
	
	return;
}

/********************************************************************************
* led_clear: Resetar pin, IO-port och sätter togglen till false
*
*            - self: Pekare till lysdioden.
********************************************************************************/
void led_clear(struct led* self)
{
	led_off(self);
	
	DDRB &= ~(1 << self->io_port);
	
	self->pin = 0;
	self->io_port = IO_PORT_NONE;
	self->enabled = false;
	
	return;
}

/********************************************************************************
* led_on: Tänder angiven lysdiod.
*
*         - self: Pekare till lysdioden.
********************************************************************************/
void led_on(struct led* self)
{
	PORTB |= (1 << self->pin);
	
	self->enabled = true; // Betyder att lysdioden är tänd.
	return;
}

/********************************************************************************
* led_off: Tänder angiven lysdiod.
*
*         - self: Pekare till lysdioden.
********************************************************************************/
void led_off(struct led* self)
{
	PORTB &= ~(1 << self->pin);
	
	self->enabled = false; // Lysdioden är släckt.
	return;
}

/********************************************************************************
* led_toggle: Togglar mellan av och på för lysdioden.
*
*             - self: Pekare till lysdioden.
********************************************************************************/
void led_toggle(struct led* self)
{
	if (self->enabled)
	{
		led_off(self);
	}
	else
	{
		led_on(self);
	}
	
	return;
}