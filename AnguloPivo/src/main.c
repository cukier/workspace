/*
 * main.c
 *
 *  Created on: 12/11/2014
 *      Author: cuki
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define maxSetores		6

typedef struct setor_str {
	int angulo;
} setor_type;

typedef struct pivo_str {
	setor_type setor[maxSetores];
	int nrSetores;
	int anguloOperacao;
} pivo_type;

bool mudouAngulo(int *angulo, int *anguloAux);
int trataAngulo(int *angulo, int *anguloAux);
int trataNrSetores(pivo_type *pivo);
int somatorio(pivo_type *pivo);
int corrigeAngulos(pivo_type *pivo);
int mostraPivo(pivo_type *pivo);
int setAngulo(pivo_type *pivo, int setor, int angulo);
int testaPivo(bool result, pivo_type *pivo);

int main(int argc, char **argv) {

	pivo_type pivo;

	pivo.nrSetores = 4;
	pivo.anguloOperacao = 100;

	trataNrSetores(&pivo);

	mostraPivo(&pivo);

	setAngulo(&pivo, 1, 10);

	testaPivo(corrigeAngulos(&pivo), &pivo);

	setAngulo(&pivo, 2, 700);

	testaPivo(corrigeAngulos(&pivo), &pivo);

	return 0;

}

bool mudouAngulo(int *angulo, int *anguloAux) {
	int i = 0;
	bool ret = false;

	for (i = 0; i < maxSetores; ++i)
		ret |= angulo[i] != anguloAux[i];

	return ret;
}

int trataAngulo(int *angulo, int *anguloAux) {
	if (mudouAngulo(angulo, anguloAux)) {
		int i;
		for (i = 0; i < maxSetores; ++i) {
			anguloAux[i] = angulo[i];
		}
	}

	return 0;
}

int trataNrSetores(pivo_type *pivo) {
	int i;
	for (i = 0; i < maxSetores; ++i) {
		if (i < pivo->nrSetores)
			pivo->setor[i].angulo = (int) pivo->anguloOperacao
					/ pivo->nrSetores;
		else
			pivo->setor[i].angulo = 360;
	}
	return pivo->nrSetores;
}

int somatorio(pivo_type *pivo) {
	int i;
	int sum = 0;
	for (i = 0; i < pivo->nrSetores; ++i)
		sum += pivo->setor[i].angulo;

	return sum;
}

int corrigeAngulos(pivo_type *pivo) {
	int sum = somatorio(pivo);
	int i = pivo->nrSetores - 1;
	int delta = 0;
	while (sum != pivo->anguloOperacao) {
		if (sum > pivo->anguloOperacao) {
			delta = sum - pivo->anguloOperacao;
			if (delta >= pivo->setor[i].angulo) {
				delta -= pivo->setor[i].angulo - 1;
				pivo->setor[i].angulo = 1;
				--i;
				if (i < 0)
					trataNrSetores(pivo);
			} else
				pivo->setor[i].angulo -= delta;
		} else {
			delta = pivo->anguloOperacao - sum;
			pivo->setor[i].angulo += delta;
		}
		sum = somatorio(pivo);
	}
	printf("Corrigido...\n");
	return 0;
}

int mostraPivo(pivo_type *pivo) {
	printf("Nr de Setores: %d\n", pivo->nrSetores);
	printf("Angulo de Operacao: %d\n", pivo->anguloOperacao);
	printf("Angulos dos setores...\n");
	int i;
	for (i = 0; i < maxSetores; ++i)
		printf("[%d] ", pivo->setor[i].angulo);
	printf("\n\n");
	return 0;
}

int setAngulo(pivo_type *pivo, int setor, int angulo) {
	if (pivo->setor[setor].angulo != angulo) {
		if (pivo->setor[setor].angulo > angulo)
			printf("Diminuindo o setor %d para %d graus.\n", setor + 1, angulo);
		else
			printf("Aumentando o setor %d para %d graus.\n", setor + 1, angulo);
		pivo->setor[setor].angulo = angulo;
	} else
		printf(
				"Pedido de alteracao igual ao angulo do setor, deixando como esta.\n");

	return 0;
}

int testaPivo(bool result, pivo_type *pivo) {
	if (result)
		exit(result);
	else
		mostraPivo(pivo);

	return 0;
}
