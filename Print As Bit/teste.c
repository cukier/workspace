#include<stdio.h>

//enum bits { b0, b1, b2, b3, b4, b5, b6, b7 };

typedef union {
	unsigned short value;
	struct {		
		unsigned b0 : 1;
		unsigned b1 : 1;
		unsigned b2 : 1;
		unsigned b3 : 1;
		unsigned b4 : 1;
		unsigned b5 : 1;
		unsigned b6 : 1;
		unsigned b7 : 1;
	} bit;
} byte;

/* void imprime_bytes(byte *reg) {
	enum bits ultimo_bit;
	for(ultimo_bit = b0; ultimo_bit <= b7; ultimo_bit++) {
		pritnf("%u", reg->bit.ultimo_bit);
	}
} */

void imprime_em_bits(byte *reg) {
	printf("%u%u%u%u%u%u%u%u",
	reg->bit.b7, reg->bit.b6, reg->bit.b5, reg->bit.b4,
	reg->bit.b3, reg->bit.b2, reg->bit.b1, reg->bit.b0);
}

int main(void) {

	byte byte1;
	unsigned short cont = 0;
	
	for(cont = 0; cont <= 0xFF; cont++) {
		byte1.value = cont;
		imprime_em_bits(&byte1);
		printf(" %u\n", cont);
	}
	
	// imprime_bytes(&byte1);
	
	return 0;
}
