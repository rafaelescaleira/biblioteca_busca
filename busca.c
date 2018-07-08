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

void gerar_menu () {

	cor_texto (ciano);
    printf ("\n\t* * * * * * * * ");
    estilo_texto (resetar);
   
    cor_texto (amarelo);
    printf ("OPERAÇÕES");
    estilo_texto (resetar);
    
    cor_texto (ciano);
    printf (" * * * * * * * *\n\t*                                       *\n");
    estilo_texto (resetar);
    
    cor_texto (ciano);
	printf("\t*");
	estilo_texto (resetar);

	cor_texto (vermelho);
	printf("\t1) ");
	estilo_texto (resetar);

	printf ("Busca Sequêncial;");

	cor_texto (ciano);
	printf("\t\t*\n");
	estilo_texto (resetar);

	cor_texto (ciano);
	printf("\t*");
	estilo_texto (resetar);

	cor_texto (vermelho);
	printf("\t2) ");
	estilo_texto (resetar);

	printf ("Busca Sequêncial Recursiva;");

	cor_texto (ciano);
	printf("\t*\n");
	estilo_texto (resetar);

	cor_texto (ciano);
	printf("\t*");
	estilo_texto (resetar);

	cor_texto (vermelho);
	printf("\t3) ");
	estilo_texto (resetar);

	printf ("Busca Ordenada;");

	cor_texto (ciano);
	printf("\t\t*\n");
	estilo_texto (resetar);

	cor_texto (ciano);
	printf("\t*");
	estilo_texto (resetar);

	cor_texto (vermelho);
	printf("\t4) ");
	estilo_texto (resetar);

	printf ("Busca Binária;");

	cor_texto (ciano);
	printf("\t\t*\n");
	estilo_texto (resetar);

	cor_texto (ciano);
	printf("\t*");
	estilo_texto (resetar);

	cor_texto (vermelho);
	printf("\t5) ");
	estilo_texto (resetar);

	printf ("Busca Binária Recursiva;");

	cor_texto (ciano);
	printf("\t*\n");
	estilo_texto (resetar);

	cor_texto (ciano);
	printf("\t*");
	estilo_texto (resetar);

	cor_texto (vermelho);
	printf("\t6) ");
	estilo_texto (resetar);

	printf ("Sair;");

	cor_texto (ciano);
	printf("\t\t\t*\n");
	estilo_texto (resetar);
    
    cor_texto (ciano);
    printf ("\t*                                       *\n\t* * * * * * * * * * * * * * * * * * * * *\n\n");
    estilo_texto (resetar);

}
