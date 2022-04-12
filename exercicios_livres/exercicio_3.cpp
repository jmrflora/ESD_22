#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define L 6
#define C 6
/*3. Faça um programa que construa uma matriz 6x6 onde os índices da matriz
representarão as cidades e os valores da matriz, criados randomicamente,
representarão as distâncias entre as cidades. Somente os valores da diagonal inferior
da matriz devem ser aleatoriamente gerados (pois a matriz será simétrica e sua
diagonal principal é 0).*/
void preencheD(int mat[L][C]);
void preencheI (int mat[L][C]);
void print(int mat[L][C]);
int distancia(int mat[L][C], int vet[]);
void preencheVet(int vet[]);
int main(){
	int i, mat[L][C], vet[L];
	
	preencheD(mat);
	preencheI(mat);
	print(mat);
	
	/*printf("digite os numeros do vetor: ");
	for(i=0;i<L;i++){
		scanf("%d", &vet[i]);
	}*/
  preencheVet(vet);
	printf("\ndistancia:%d", distancia(mat,vet));
	return 0;
}

void preencheD(int mat[L][C]){
	int i,j;
	/*
	for(i=0;i<L;i++){
		for(j=0;j<C;j++){
			if(i==j){
				mat[i][j]=0;
			}
		}
	}*/
  for(i=0;i<L;i++){
    mat[i][i] = 0;
  }
}
void preencheI (int mat[L][C]){
	int i,j,quant;
	srand(time(NULL));
	
	for(i=0;i<L;i++){
		quant=0;
		for(j=0;j<C;j++){
			if(i == j){
				quant++;
			}else if(quant > 0){
				mat[i][j] = ((rand () % 10) + 10);
				mat[j][i] = mat[i][j];
			}
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
int distancia(int mat[L][C], int vet[]){
	int i, disT=0;
	
	for(i=0;i<4;i++){
		printf("\nmat:%d", mat[(vet[i]-1)][(vet[i+1]-1)]);
		printf("\ndist:%d", disT);
		disT=disT + mat[(vet[i]-1)][(vet[i+1]-1)];
		printf("\ndist apos calculo:%d", disT);
	}
	
	return disT;
}void preenche(){
  
}
void preencheVet(int vet[]){
  int i,j, vet2[L]={1,2,3,4,5,6},quantP=0,quantT=6;
  while(quantT > 1){
    j=rand()%quantT;//gerando indice
    vet[quantP]= vet2[j];//pega o valor do indice

    vet2[j] = vet2[quantT - 1];//joagndo o ultimo na posição do j
    quantT--;//excluindo a ultmia casa aka diminuindo o vetor
    printf("\nvet[]:%d", vet[quantP]);
    quantP++;//novo tamanho do vetor principal
  }
  vet[quantP] = vet2[0];//ultimo
  printf("\nvet[]:%d", vet[quantP]);
  
}
