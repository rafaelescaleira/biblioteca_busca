/* * * * * * * * * * * * * * * * * * * * * * * * *
 *                                               *
 * Nome : Rafael Escaleira Ferreira dos Santos.  *
 * Universidade Federal do Mato Grosso do Sul    *
 *                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
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

/* * * * * * * * * Declaração de Funções (Teste) * * * * * * * * */

void teste_busca_sequencial (void);

void teste_busca_sequencial_recursiva (void);

void teste_busca_ordenada (void);

void teste_busca_binaria (void);

void teste_busca_binaria_recursiva (void);

/* * * * * * * * * * * * Função Principal * * * * * * * * * * * */

int main (void) {

	cor_texto (ciano);
    printf ("\n\t* * * * * * * * ");
    estilo_texto (resetar);

    cor_texto (amarelo);
    printf ("CONFERE FUNCIONAMENTO");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf (" * * * * * * * *\n\t*                                                   *\n");
    estilo_texto (resetar);

	teste_busca_sequencial ();
	teste_busca_sequencial_recursiva ();
	teste_busca_ordenada ();
	teste_busca_binaria ();

	cor_texto (ciano);
    printf ("\t*                                                   *\n\t* * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
    estilo_texto (resetar);

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

/* * * * * * * * * * * * * * Funções Teste * * * * * * * * * * * * * */

void teste_busca_sequencial (void) {

	tipo_vetor * v;
	int elemento, posicao, i;

	v = (tipo_vetor *) malloc (sizeof (tipo_vetor));
	v -> compara = &compara;

	v -> n = 5;
	v -> v = (void * *) malloc (v -> n * sizeof (void *));

	for (i = 0; i < v -> n; i ++) {

		v -> v [i] = aloca_registro (i + 1);

	}

	elemento = - 3;
	posicao = busca_sequencial (v, aloca_registro (elemento));
	assert (posicao == - 1);

	elemento = 4;
	posicao = busca_sequencial (v, aloca_registro (elemento));
	assert (posicao == 3);

	elemento = 7;
	posicao = busca_sequencial (v, aloca_registro (elemento));
	assert (posicao == - 1);

	destroi_vetor (v);

	cor_texto (ciano);
    printf("\t*");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Busca Sequêncial ");
    cor_texto (verde);
    printf("              OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

}

void teste_busca_sequencial_recursiva (void) {

	tipo_vetor * v;
	int elemento, posicao, i;

	v = (tipo_vetor *) malloc (sizeof (tipo_vetor));
	v -> compara = &compara;

	v -> n = 5;
	v -> v = (void * *) malloc (v -> n * sizeof (void *));

	for (i = 0; i < v -> n; i ++) {

		v -> v [i] = aloca_registro (i + 1);

	}

	elemento = - 3;
	posicao = busca_sequencial_recursiva (v, aloca_registro (elemento), v -> n);
	assert (posicao == - 1);

	elemento = 4;
	posicao = busca_sequencial_recursiva  (v, aloca_registro (elemento), v -> n);
	assert (posicao == 3);

	elemento = 7;
	posicao = busca_sequencial_recursiva  (v, aloca_registro (elemento), v -> n);
	assert (posicao == - 1);

	destroi_vetor (v);

	cor_texto (ciano);
    printf("\t*");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Busca Sequêncial Recursiva ");
    cor_texto (verde);
    printf("    OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

}

void teste_busca_ordenada (void) {

	tipo_vetor * v;
	int elemento, posicao, i;

	v = (tipo_vetor *) malloc (sizeof (tipo_vetor));
	v -> compara = &compara;

	v -> n = 5;
	v -> v = (void * *) malloc (v -> n * sizeof (void *));

	for (i = 0; i < v -> n; i ++) {

		v -> v [i] = aloca_registro (i + 1);

	}

	elemento = - 3;
	posicao = busca_ordenada (v, aloca_registro (elemento));
	assert (posicao == - 1);

	elemento = 4;
	posicao = busca_ordenada  (v, aloca_registro (elemento));
	assert (posicao == 3);

	elemento = 7;
	posicao = busca_ordenada  (v, aloca_registro (elemento));
	assert (posicao == - 1);

	destroi_vetor (v);

	cor_texto (ciano);
    printf("\t*");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Busca Ordenada ");
    cor_texto (verde);
    printf("                OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

}

void teste_busca_binaria (void) {

	tipo_vetor * v;
	int elemento, posicao, i;

	v = (tipo_vetor *) malloc (sizeof (tipo_vetor));
	v -> compara = &compara;

	v -> n = 5;
	v -> v = (void * *) malloc (v -> n * sizeof (void *));

	for (i = 0; i < v -> n; i ++) {

		v -> v [i] = aloca_registro (i + 1);

	}

	elemento = - 3;
	posicao = busca_binaria (v, aloca_registro (elemento));
	assert (posicao == - 1);

	elemento = 4;
	posicao = busca_binaria  (v, aloca_registro (elemento));
	assert (posicao == 3);

	elemento = 7;
	posicao = busca_binaria  (v, aloca_registro (elemento));
	assert (posicao == - 1);

	destroi_vetor (v);

	cor_texto (ciano);
    printf("\t*");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Busca Binária ");
    cor_texto (verde);
    printf("                 OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

}

void teste_busca_binaria_recursiva (void) {

	tipo_vetor * v;
	int elemento, posicao, i;

	v = (tipo_vetor *) malloc (sizeof (tipo_vetor));
	v -> compara = &compara;

	v -> n = 5;
	v -> v = (void * *) malloc (v -> n * sizeof (void *));

	for (i = 0; i < v -> n; i ++) {

		v -> v [i] = aloca_registro (i + 1);

	}

	elemento = - 3;
	posicao = busca_binaria_recursiva (- 1, v -> n, v, aloca_registro (elemento));
	assert (posicao == - 1);

	elemento = 4;
	posicao = busca_binaria_recursiva  (- 1, v -> n, v, aloca_registro (elemento));
	assert (posicao == 3);

	elemento = 7;
	posicao = busca_binaria_recursiva  (- 1, v -> n, v, aloca_registro (elemento));
	assert (posicao == - 1);

	destroi_vetor (v);

	cor_texto (ciano);
    printf("\t*");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Busca Binária Recursiva ");
    cor_texto (verde);
    printf("       OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

}
