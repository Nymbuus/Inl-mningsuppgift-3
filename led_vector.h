#ifndef LED_VECTOR_H_
#define LED_VECTOR_H_

#include "header.h"

// Vektor som innehåller alla leds.
struct led_vector
{
	struct led* leds; // Pekare till fält innehållande lysdioder.
	size_t size; // Vektorns storlek, dvs. antalet lysdioder.
};

// Deklarerar funktioner.
void led_vector_init(struct led_vector* self);
void led_vector_clear(struct led_vector* self);
int led_vector_push(struct led_vector* self, struct led* new_led);
int led_vector_pop(struct led_vector* self);
void led_vector_leds_on(struct led_vector* self);
void led_vector_leds_off(struct led_vector* self);
void led_vector_blink_sequentially(struct led_vector* self, uint16_t delay);
void led_vector_blink_collectively(struct led_vector* self, uint16_t delay);

#endif /* LED_VECTOR_H_ */