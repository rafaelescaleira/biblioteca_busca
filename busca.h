/* * * * * * * * * * * * * * * * * * * * * * * * *
 *                                               *
 * Nome : Rafael Escaleira Ferreira dos Santos.  *
 * Universidade Federal do Mato Grosso do Sul    *
 *                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _BUSCA_H_
#define _BUSCA_H_

/* * * * * * * * * * * Cores * * * * * * * * * * */

#define cor_texto(cor) cor
#define estilo_texto(estilo_texto_) estilo_texto_

/* * * * * * * * * Cor do Texto * * * * * * * * * */

#define preto printf("\033[30m") 
#define vermelho printf("\033[31m") 
#define verde printf("\033[32m") 
#define amarelo printf("\033[33m") 
#define azul printf("\033[34m") 
#define magenta printf("\033[35m") 
#define ciano printf("\033[36m") 
#define branco printf("\033[37m") 
#define normal printf("\033[39m") 

/* * * * * * * * Estilo do Texto * * * * * * * * */

#define negrito printf("\033[1m")
#define fosco printf("\033[2m")
#define estilo_normal printf("\033[22m")
#define resetar printf("\033[0m")
#define sublinhado printf("\033[4m")
#define piscar printf("\033[5m")
#define italico printf("\033[3m")
#define negativo printf("\033[7m")

/* * * * * * * * * Declaração de Registro * * * * * * * * */

typedef struct _vetor {

	void * * v;
	int n;
	int (* compara) (const void * a, const void * b);

} tipo_vetor;

/* * * * * * * * * Declaração de Funções * * * * * * * * */

int compara (const void * a, const void * b);

int busca_sequencial (tipo_vetor * v, void * elemento);

int busca_sequencial_recursiva (tipo_vetor * v, void * elemento, int n);

int busca_ordenada (tipo_vetor * v, void * elemento);

int busca_binaria (tipo_vetor * v, void * elemento);

int busca_binaria_recursiva (int inicio, int fim, tipo_vetor * v, void * elemento);

void destroi_vetor (tipo_vetor * v);

#endif
