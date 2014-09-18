/*
 * ShiftRegister.c
 *
 *  Created on: Mar 30, 2014
 *      Author: cuki
 */

#include <18F45K20.h>

#use delay(clock=4MHz)
#use rs232(xmit=PIN_C6, baud=9600)

#define clock_pin	PIN_C0
#define data_pin	PIN_C1
#define delay		10
#define clear_pin	PIN_C2

void clock() {
	output_high(clock_pin);
	delay_ms(delay);
	output_low(clock_pin);
}

void clear() {
	output_low(clear_pin);
	delay_ms(delay);
	output_high(clear_pin);
	delay_ms(delay);
}

void sendL(int data) {
	int mask = 1;

	for (mask = 0x80; mask >= 1; mask >>= 1) {
		output_bit(data_pin, data & mask);
		clock();
	}
}

void sendR(int data) {
	int mask = 1;

	for (mask = 1; mask <= 0x80; mask <<= 1) {
		output_bit(data_pin, data & mask);
		clock();
	}
}

int main(void) {

	int cont = 0;

	output_high(clear_pin);
	delay_ms(10);

	for (cont = 1; cont < 11; cont++) {
		sendR(cont);
		printf("\n\r%d", cont);
		delay_ms(750);
		clear();
	}

	return 0;
}
