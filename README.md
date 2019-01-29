Biblioteca Genérica de Busca
============================

![Build](https://img.shields.io/gitlab/pipeline/rafaelescaleira/busca.svg)
![Size](https://img.shields.io/github/repo-size/rafaelescaleira/busca.svg)

Esse repositório possui diversas funções de busca implementadas em linguagem C.
Segue a lista das funções :

* Busca Sequêncial;
* Busca Sequêncial Recursiva;
* Busca Ordenada;
* Busca Binária;
* Busca Binária Recursiva;

Instruções para Compilação
--------------------------
Para compilar `` busca.c `` com `` teste_busca.c `` , ou seja, caso deseja testar o código de `` busca.c `` :

* `` ~$ gcc busca.c teste_busca.c -Wall -std=c99 -pedantic ``

Para compilar `` busca.c `` com `` main.c `` , ou seja, caso deseja executar o código e realizar seus próprios testes :

* `` ~$ gcc busca.c main.c -Wall -std=c99 -pedantic ``

Instruções para Execução
------------------------
Para executar o arquivo já compilado com `` teste_busca.c `` :

* `` ~$ ./a.out ``

Para executar o arquivo já compilado com `` main.c `` :

* `` ~$ ./a.out ``
* `` ~$ ./a.out < arquivo_entrada.txt ``

Tempo de Execução
------------------

|    Funções       |   Velocidade  |
| ---------------  |:-------------:|
| Busca Sequêncial | O(n) |
| Busca Sequêncial Recursiva | O(n) |
| Busca Ordenada | O(n) |
| Busca Binária | O(log n) |
| Busca Binária Recursiva | O(log n) |

Execução do Programa (Teste)
----------------------------
![grab-landing-page](https://j.gifs.com/OynL5r.gif)

Execução do Programa (Principal)
--------------------------------
![grab-landing-page](https://j.gifs.com/ZVBvm5.gif)
