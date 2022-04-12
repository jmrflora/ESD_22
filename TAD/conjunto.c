#include "conjunto.h"
#include <stdlib.h>
#include <stdio.h>

tConjunto *criaConjunto(int tam){
	tConjunto *p;
	p = (tConjunto *) malloc(sizeof(tConjunto));
	p->elem = (int *) malloc(sizeof(int)*tam);
	p->tamMaximo = tam;
	p->tamAtual = 0;
	return p;
}

int conjuntoGetElem(tConjunto *p,int pos){
	int result= p->elem[pos];
	return result; 
}
int conjuntoGetTamMaximo(tConjunto *p){
	int result = p->tamMaximo;
	return result;
}
int conjuntoGetTamAtual(tConjunto *p){
	int result = p->tamAtual;
	return result;
}
void conjuntoSetElem(tConjunto *p,int pos, int x){
	p->elem[pos]=x;
}
void conjuntoSetTamAtual(tConjunto *p,int x){
	p->tamAtual=x;
}


void conjuntoExibe(tConjunto *p){
	int i;
	printf("conjunto:(");
	for(i=0;i <= (conjuntoGetTamAtual(&p));i++){
		printf("%d ", conjuntoGetElem(&p,i));
	}
	printf(")\n");
}

void conjuntoInsere(tConjunto *p,int x){
	int i,quant=0;
	if(conjuntoGetTamAtual(&p) == conjuntoGetTamMaximo(&p)){
		printf("\nconjunto lotado");
	}else{
		for(i=0;i <= (conjuntoGetTamAtual(&p));i++){
			if(conjuntoGetElem(&p,i) == x){
			quant++;
			}
		}
		if(quant == 0){
			conjuntoSetElem(&p,i);
			conjuntoSetTamAtual(&p,i++);
		}else{
			printf("\nelemento ja presente");
		}
	}
}
