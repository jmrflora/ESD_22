
/*2. Construa as fun��es a seguir que recebem uma matriz ( criada com dados aleat�rios)
e uma fun��o main para test�-las:
a. Tamb�m recebe um vetor vazio e preenche-o com a soma dos valores de cada
linha da matriz
b. Tamb�m recebe um vetor vazio e preenche-o com a soma dos valores de cada
coluna da matriz
c. Mostra os elementos da diagonal principal da matriz
d. Mostra os elementos da diagonal secund�ria
e. Mostra tudo, exceto a diagonal principal
f. Multiplica uma matriz por um n�mero inteiro recebido
g. Mostra o resultado da soma entre duas matrizes recebidas.
h. Altera para 0 todos os valores da matriz que s�o m�ltiplos de sua posi��o( de
se sua linha ou coluna)
i. Verifica se uma matriz � sim�trica: retorna 1 se TRUE e 0 se FALSE:
j. Calcula a transposta de uma matriz:*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define L 3
#define C 3
void preencheAl(int mat[L][C]);
void print(int mat[L][C]);
void funcA(int mat[L][C], int vet[]);
int main(){
	int mat[L][C], vet[L];
	
	preencheAl(mat);
	print(mat);
	
	funcA(mat,vet);
	
	return 0;
}

void funcA(int mat[L][C], int vet[]){
	int i,j, soma;
	
	for(i=0;i<L;i++){
		for(j=0, soma=0;j<C;j++){
			soma = soma + mat[i][j];
		}
		vet[i]=soma;
	}
	//printando
	for(i=0;i<L;i++){
		printf("\nlinha %d:%d\n",i, vet[i]);
	}
}
void preencheAl(int mat[L][C]){
	int i, j;
	srand(time(NULL));
	
	for(i=0;i<L;i++){
		for(j=0;j<C;j++){
			mat[i][j]= rand () % 10;
		}
	}
}
void print(int mat[L][C]){
	int i, j;
	for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            printf(" %d  ",mat[i][j]);
        }
        printf("\n");
    }
}

