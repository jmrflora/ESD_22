/*2. Construa as funções a seguir que recebem uma matriz ( criada com dados aleatórios)
e uma função main para testá-las:
a. Também recebe um vetor vazio e preenche-o com a soma dos valores de cada
linha da matriz
b. Também recebe um vetor vazio e preenche-o com a soma dos valores de cada
coluna da matriz
c. Mostra os elementos da diagonal principal da matriz
d. Mostra os elementos da diagonal secundária
e. Mostra tudo, exceto a diagonal principal
f. Multiplica uma matriz por um número inteiro recebido
g. Mostra o resultado da soma entre duas matrizes recebidas.
h. Altera para 0 todos os valores da matriz que são múltiplos de sua posição( de
se sua linha ou coluna)
i. Verifica se uma matriz é simétrica: retorna 1 se TRUE e 0 se FALSE:
j. Calcula a transposta de uma matriz:*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define L 3
#define C 3
void preencheAl(int mat[L][C]);
void print(int mat[L][C]);
void funcF(int mat[L][C],int n);
int main(){
	int mat[L][C], n;
	
	preencheAl(mat);
	print(mat);
	printf("digite um numero:");
	scanf("%d", &n);
	funcF(mat, n);
	print(mat);
	return 0;
}

void funcF(int mat[L][C], int n){
	int i,j;
	
	for(i=0;i<L;i++){
        for(j=0;j<C;j++){
        mat[i][j]= mat[i][j] * n;
        }
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
