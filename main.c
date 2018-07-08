/* * * * * * * * * * * * * * * * * * * * * * * * *
 *                                               *
 * Nome : Rafael Escaleira Ferreira dos Santos.  *
 * Universidade Federal do Mato Grosso do Sul    *
 *                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "busca.h"

/* * * * * * * * * * * * * * Registro * * * * * * * * * * * * * */

typedef struct _registro {

	int valor;

} tipo_registro;

/* * * * * * * * * * * Declaração de Funções * * * * * * * * * * */

tipo_vetor * constroi_vetor (int (* cmp) (const void * a, const void * b));

tipo_registro * aloca_registro (int valor);

int compara (const void * a, const void * b);

void le_vetor (tipo_vetor * v);

void imprime_vetor (tipo_vetor * v);

void aloca_vetor (tipo_vetor * v);

/* * * * * * * * * * * * Função Principal * * * * * * * * * * * */

int main (void) {

	tipo_vetor * v;
	int elemento, posicao, operacao;
	clock_t inicio, fim;

	printf("\n");

	srand (time (NULL));

	do {

		gerar_menu ();

		printf("\tInforme a operação desejada : ");
		scanf("%d", &operacao);

		switch (operacao) {

			case 1:

			v = constroi_vetor (&compara);

			printf("\tInforme o elemento que deseja buscar : ");

			cor_texto (verde);
			scanf("%d", &elemento);
			estilo_texto (resetar);

			inicio = clock ();
			posicao = busca_sequencial (v, aloca_registro (elemento));
			fim = clock ();

			if (posicao == - 1) {

				printf("\tO elemento ");

				cor_texto (vermelho);
				printf("(");
				estilo_texto (resetar);

				cor_texto (verde);
				printf("%d", elemento);
				estilo_texto (resetar);

				cor_texto (vermelho);
				printf(")");
				estilo_texto (resetar);

				printf(" não se encontra no vetor.\n\n");

			}

			else {

				printf("\tO elemento ");

				cor_texto (vermelho);
				printf("(");
				estilo_texto (resetar);

				cor_texto (verde);
				printf("%d", elemento);
				estilo_texto (resetar);

				cor_texto (vermelho);
				printf(")");
				estilo_texto (resetar);

				printf(" se encontra na posição ");

				cor_texto (magenta);
				printf("%d", posicao);
				estilo_texto (resetar);

				printf(".\n\n");

			}

			cor_texto (vermelho);
			printf("\t* ");
			estilo_texto (resetar);

			cor_texto (ciano);
			printf("Tempo de Execução");
			estilo_texto (resetar);

			printf(" : %.5lf segundos.\n\n", ( (double) (fim - inicio) ) / CLOCKS_PER_SEC);

			destroi_vetor (v);

			break;

			case 2:

			v = constroi_vetor (&compara);

			printf("\tInforme o elemento que deseja buscar : ");

			cor_texto (verde);
			scanf("%d", &elemento);
			estilo_texto (resetar);

			inicio = clock ();
			posicao = busca_sequencial_recursiva (v, aloca_registro (elemento), v -> n);
			fim = clock ();

			if (posicao == - 1) {

				printf("\tO elemento ");

				cor_texto (vermelho);
				printf("(");
				estilo_texto (resetar);

				cor_texto (verde);
				printf("%d", elemento);
				estilo_texto (resetar);

				cor_texto (vermelho);
				printf(")");
				estilo_texto (resetar);

				printf(" não se encontra no vetor.\n\n");

			}

			else {

				printf("\tO elemento ");

				cor_texto (vermelho);
				printf("(");
				estilo_texto (resetar);

				cor_texto (verde);
				printf("%d", elemento);
				estilo_texto (resetar);

				cor_texto (vermelho);
				printf(")");
				estilo_texto (resetar);

				printf(" se encontra na posição ");

				cor_texto (magenta);
				printf("%d", posicao);
				estilo_texto (resetar);

				printf(".\n\n");

			}

			cor_texto (vermelho);
			printf("\t* ");
			estilo_texto (resetar);

			cor_texto (ciano);
			printf("Tempo de Execução");
			estilo_texto (resetar);

			printf(" : %.5lf segundos.\n\n", ( (double) (fim - inicio) ) / CLOCKS_PER_SEC);

			destroi_vetor (v);

			break;

			case 3:

			v = constroi_vetor (&compara);

			printf("\tInforme o elemento que deseja buscar : ");

			cor_texto (verde);
			scanf("%d", &elemento);
			estilo_texto (resetar);

			inicio = clock ();
			posicao = busca_ordenada (v, aloca_registro (elemento));
			fim = clock ();

			if (posicao == - 1) {

				printf("\tO elemento ");

				cor_texto (vermelho);
				printf("(");
				estilo_texto (resetar);

				cor_texto (verde);
				printf("%d", elemento);
				estilo_texto (resetar);

				cor_texto (vermelho);
				printf(")");
				estilo_texto (resetar);

				printf(" não se encontra no vetor.\n\n");

			}

			else {

				printf("\tO elemento ");

				cor_texto (vermelho);
				printf("(");
				estilo_texto (resetar);

				cor_texto (verde);
				printf("%d", elemento);
				estilo_texto (resetar);

				cor_texto (vermelho);
				printf(")");
				estilo_texto (resetar);

				printf(" se encontra na posição ");

				cor_texto (magenta);
				printf("%d", posicao);
				estilo_texto (resetar);

				printf(".\n\n");

			}

			cor_texto (vermelho);
			printf("\t* ");
			estilo_texto (resetar);

			cor_texto (ciano);
			printf("Tempo de Execução");
			estilo_texto (resetar);

			printf(" : %.5lf segundos.\n\n", ( (double) (fim - inicio) ) / CLOCKS_PER_SEC);

			destroi_vetor (v);

			break;

			case 4:

			v = constroi_vetor (&compara);

			printf("\tInforme o elemento que deseja buscar : ");

			cor_texto (verde);
			scanf("%d", &elemento);
			estilo_texto (resetar);

			inicio = clock ();
			posicao = busca_binaria (v, aloca_registro (elemento));
			fim = clock ();

			if (posicao == - 1) {

				printf("\tO elemento ");

				cor_texto (vermelho);
				printf("(");
				estilo_texto (resetar);

				cor_texto (verde);
				printf("%d", elemento);
				estilo_texto (resetar);

				cor_texto (vermelho);
				printf(")");
				estilo_texto (resetar);

				printf(" não se encontra no vetor.\n\n");

			}

			else {

				printf("\tO elemento ");

				cor_texto (vermelho);
				printf("(");
				estilo_texto (resetar);

				cor_texto (verde);
				printf("%d", elemento);
				estilo_texto (resetar);

				cor_texto (vermelho);
				printf(")");
				estilo_texto (resetar);

				printf(" se encontra na posição ");

				cor_texto (magenta);
				printf("%d", posicao);
				estilo_texto (resetar);

				printf(".\n\n");

			}

			cor_texto (vermelho);
			printf("\t* ");
			estilo_texto (resetar);

			cor_texto (ciano);
			printf("Tempo de Execução");
			estilo_texto (resetar);

			printf(" : %.5lf segundos.\n\n", ( (double) (fim - inicio) ) / CLOCKS_PER_SEC);

			destroi_vetor (v);

			break;

			case 5:

			v = constroi_vetor (&compara);

			printf("\tInforme o elemento que deseja buscar : ");

			cor_texto (verde);
			scanf("%d", &elemento);
			estilo_texto (resetar);

			inicio = clock ();
			posicao = busca_binaria_recursiva (- 1, v -> n, v, aloca_registro (elemento));
			fim = clock ();

			if (posicao == - 1) {

				printf("\tO elemento ");

				cor_texto (vermelho);
				printf("(");
				estilo_texto (resetar);

				cor_texto (verde);
				printf("%d", elemento);
				estilo_texto (resetar);

				cor_texto (vermelho);
				printf(")");
				estilo_texto (resetar);

				printf(" não se encontra no vetor.\n\n");

			}

			else {

				printf("\tO elemento ");

				cor_texto (vermelho);
				printf("(");
				estilo_texto (resetar);

				cor_texto (verde);
				printf("%d", elemento);
				estilo_texto (resetar);

				cor_texto (vermelho);
				printf(")");
				estilo_texto (resetar);

				printf(" se encontra na posição ");

				cor_texto (magenta);
				printf("%d", posicao);
				estilo_texto (resetar);

				printf(".\n\n");

			}

			cor_texto (vermelho);
			printf("\t* ");
			estilo_texto (resetar);

			cor_texto (ciano);
			printf("Tempo de Execução");
			estilo_texto (resetar);

			printf(" : %.5lf segundos.\n\n", ( (double) (fim - inicio) ) / CLOCKS_PER_SEC);

			destroi_vetor (v);

			break;

			case 6:

			break;

		}

	} while (operacao > 0 && operacao < 6);

	printf("\n\n");

	return 0;

}

/* * * * * * * * * * * * * * Funções * * * * * * * * * * * * * */

int compara (const void * a, const void * b) {
    
    return (* (tipo_registro *)a).valor - (* (tipo_registro *)b).valor;
    
}

tipo_registro * aloca_registro (int valor) {
    
    tipo_registro * aux;

    aux = (tipo_registro *) malloc (sizeof (tipo_registro));
    aux -> valor = valor;
    
    return aux;
    
}

void le_vetor (tipo_vetor * v) {

	int i, aux;

	printf("\tVetor : ");

	for (i = 0; i < v -> n; i ++) {

		scanf ("%d", &aux);

		v -> v [i] = aloca_registro (aux);

	}

	printf("\n");

}

void imprime_vetor (tipo_vetor * v) {

	int contador;

	printf ("V = ");

	for (contador = 0; contador < v -> n; contador ++) {

		printf ("%d ", (* (tipo_registro *) (v -> v [contador])).valor);

	}

	printf ("\n");

}

void aloca_vetor (tipo_vetor * v) {

	v -> v = (void * *) malloc (v -> n * sizeof (void *));

}

tipo_vetor * constroi_vetor (int (* cmp) (const void * a, const void * b)) {

	tipo_vetor * v;

	v = (tipo_vetor *) malloc (sizeof (tipo_vetor));
	v -> compara = cmp;

	printf("\n\tQuantidade de Elementos : ");

	scanf ("%d", &v -> n);

	aloca_vetor (v);
	le_vetor (v);

	return v;

}
