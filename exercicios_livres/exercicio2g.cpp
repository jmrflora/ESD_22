/*2. Construa as fun??es a seguir que recebem uma matriz ( criada com dados aleat?rios)
e uma fun??o main para test?-las:
a. Tamb?m recebe um vetor vazio e preenche-o com a soma dos valores de cada
linha da matriz
b. Tamb?m recebe um vetor vazio e preenche-o com a soma dos valores de cada
coluna da matriz
c. Mostra os elementos da diagonal principal da matriz
d. Mostra os elementos da diagonal secund?ria
e. Mostra tudo, exceto a diagonal principal
f. Multiplica uma matriz por um n?mero inteiro recebido
g. Mostra o resultado da soma entre duas matrizes recebidas.
h. Altera para 0 todos os valores da matriz que s?o m?ltiplos de sua posi??o( de
se sua linha ou coluna)
i. Verifica se uma matriz ? sim?trica: retorna 1 se TRUE e 0 se FALSE:
j. Calcula a transposta de uma matriz:*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define L 3
#define C 3
void preencheAl(int mat[L][C]);
void print(int mat[L][C]);
void funcG(int mat[L][C], int mat2[L][C]);
int main(){
	int mat[L][C], mat2[L][C];
	
	preencheAl(mat);
	preencheAl(mat2);
	print(mat);
	print(mat2);
	
	funcG(mat, mat2);
	return 0;
}

void funcG(int mat[L][C],int mat2[L][C]){
	int i,j, soma;
	printf("\n");
	for(i=0;i<L;i++){
        for(j=0;j<C;j++){
        printf(" %d  ",soma=(mat[i][j]+ mat2[i][j]));
        }
        printf("\n");
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
	printf("\n");
	for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            printf(" %d  ",mat[i][j]);
        }
        printf("\n");
    }
}
