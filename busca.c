/* * * * * * * * * * * * * * * * * * * * * * * * *
 *                                               *
 * Nome : Rafael Escaleira Ferreira dos Santos.  *
 * Universidade Federal do Mato Grosso do Sul    *
 *                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include "busca.h"

int busca_sequencial (tipo_vetor * v, void * elemento) {

	int posicao;

	for (posicao = 0; posicao < v -> n; posicao ++) {

		if (v -> compara (v -> v [posicao], elemento) == 0) {

			return posicao;

		}

	}

	return - 1;

}

int busca_sequencial_recursiva (tipo_vetor * v, void * elemento, int n) {

	if (n == 0) {

		return - 1;

	}

	else {

		if (v -> compara (v -> v [n - 1], elemento) == 0) {

			return n - 1;

		}

		else {

			return busca_sequencial_recursiva (v, elemento, n - 1);

		}

	}

}

int busca_ordenada (tipo_vetor * v, void * elemento) {

	int posicao;

	for (posicao = 0; posicao < v -> n; posicao ++) {

		if (v -> compara (v -> v [posicao], elemento) == 0) {

			return posicao;

		}

	}

	return - 1;

}

int busca_binaria (tipo_vetor * v, void * elemento) {

	int inicio, meio, fim;

	inicio = - 1;
	fim = v -> n;

	while (inicio < fim - 1) {

		meio = (inicio + fim) / 2;

		if (v -> compara (v -> v [meio], elemento) < 0) {

			inicio = meio;

		}

		else if (v -> compara (v -> v [meio], elemento) == 0) {

			return meio;

		}

		else {

			fim = meio;

		}

	}

	return - 1;

}

int busca_binaria_recursiva (int inicio, int fim, tipo_vetor * v, void * elemento) {

	int meio;

	if (inicio == fim - 1) {

		return - 1;

	}

	else {

		meio = (inicio + fim) / 2;

		if (v -> compara (v -> v [meio], elemento) < 0) {

			return busca_binaria_recursiva (meio, fim, v, elemento);

		}

		else if (v -> compara (v -> v [meio], elemento) == 0) {

			return meio;

		}

		else {

			return busca_binaria_recursiva (inicio, meio, v, elemento);

		}

	}

}

void destroi_vetor (tipo_vetor * v) {

	free (v -> v);
	free (v);

}
