/*
 * numeros.c
 *
 *  Created on: 14/05/2014
 *      Author: cuki
 */

/*
 * numeros.c
 *
 *  Created on: 07/05/2012
 *      Author: cuki
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int primo(int nr) {

	int aux;

	for (aux = nr - 1; aux > 1; aux--) {
		if (!(nr % aux))
			return 0;
	}
	return 1;
}

int _feliz(double nr, double *ptr) {

	double qtdAlgarismos = 0;
	double proximo = 0;
	int aux = 0;
	int aux2 = 0;

	for (qtdAlgarismos = 0;
			(nr > exp10(qtdAlgarismos)) && (qtdAlgarismos <= 10);
			qtdAlgarismos++)
		if (qtdAlgarismos == 10)
			return 0;

	for (; qtdAlgarismos; qtdAlgarismos--) {
		if (qtdAlgarismos > 1 || nr <= 99) {
			aux = sqrt(aux);
			aux *= exp10(qtdAlgarismos);
			aux = nr - aux;
			aux /= (int) exp10(qtdAlgarismos - 1);
			aux = pow(aux, 2);
			proximo += aux;
			aux2 += sqrt(aux) * exp10(qtdAlgarismos - 1);
		} else {
			aux = nr - aux2;
			aux = pow(aux, 2);
			proximo += aux;
		}
	}

	if (proximo == 1 || proximo == 10 || nr == 1)
		return 1;
	else
		return feliz(proximo);

}

void printUsage() {
	printf("Uso: numeros.exe numero");
}

int main(int argc, char **argv) {

	int nr = 0;

	if (argc > 1) {
		nr = atoi(argv[1]);
		if (feliz(nr))
			printf("%d eh um nr Feliz", nr);
		else
			printf("%d não eh um nr Feliz", nr);
	} else {
		printUsage();
		return 1;
	}

	return 0;

}
