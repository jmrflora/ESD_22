#include <stdio.h>

struct conjunto{
	int tamAtual;
	int tamMaximo;
	int *elem;
};

typedef struct conjunto tConjunto;
tConjunto *criaConjunto(int tam);
//get e set
int conjuntoGetElem(tConjunto *p,int pos);
int conjuntoGetTamMaximo(tConjunto *p);
int conjuntoGetTamAtual(tConjunto *p);
void conjuntoSetElem(tConjunto *p,int pos, int x);
void conjuntoSetTamAtual(tConjunto *p,int x);

void conjuntoExibe (tConjunto *p);
void conjuntoInsere(tConjunto *p,int x);

