#include <stdio.h>
#include <stdlib.h>
/*1) Uma federação desportiva deseja manter atualizadas as informações sobre os recordes de 
algumas modalidades de provas de natação.
Para tanto, a federação possui um arquivo com os 
atuais recordes do seguinte modo: - código da modalidade, - segundos do atual recorde na modalidade.

O desempenho dos nadadores que participaram do último campeonato será informado a seguir, do 
seguinte modo: - código da modalidade, minutos, segundos.
Faça um programa que, baseado nestas informações, verifique se algum recorde foi batido. Neste 
caso, o recorde anterior deverá ser substituído. 
Ao final, o programa deve exibir as informações 
ordenadas por código da modalidade
*/

//structs
typedef struct recorde{
	int cod;
	int seg;
}Trecorde;

typedef struct nad{
	int cod;
	int min;
	int seg;
}Tnad;
//prototipos
int quantLinhaArq(char nome[]);
void preencheVet_r(Trecorde vet[], int ql);
int func(Trecorde vet[], int tam);
void escreveArq(Trecorde vet[], char nome[], int tam);

int main(){
	int i, ql=quantLinhaArq("arquivos/atuais_recordes.txt"), tam = ql/2;
	Trecorde vet[tam];
	
	preencheVet_r(vet,ql);
	if(func(vet,tam) > 0){
		escreveArq(vet,"arquivos/atuais_recordes.txt",tam);
	}
	
	return 0;
}
int quantLinhaArq(char nome[]){
	int quant=0;
	char c;
	FILE *arq_r;
	
	arq_r = fopen(nome, "r");
	if(arq_r == NULL){
		printf("\nproblemas com a leitura do arquivo 1");
	}else{
		
		for (c = getc(arq_r); c != EOF; c = getc(arq_r)){
			//printf("\nc:%c", c);
			if (c == '\n') {
				//printf("\noi");
			 	// Increment count if this character is newline
            	quant++;
            	//printf("\nquant:%d", quant);
			}
		
		}
		quant++;
		//printf("\nquant:%d", quant);
    	return quant;
	}
	fclose(arq_r);
	return 0;
}
void preencheVet_r(Trecorde vet[], int ql){
	int i;
	FILE *arq_r;
	
	arq_r = fopen("arquivos/atuais_recordes.txt", "r");
	if(arq_r == NULL){
		printf("\nproblemas com a leitura do arquivo 2");
	}else{
		
		for(i=0;i<(ql/2);i++){
			fscanf(arq_r,"%d", &vet[i].cod);
			fscanf(arq_r,"%d", &vet[i].seg);
			/*
			printf("\nvetor[%d].cod:%d",i, vet[i].cod);
			printf("  vetor[%d].seg:%d",i, vet[i].seg);
			*/
		}
	}
	fclose(arq_r);
}
int func(Trecorde vet[], int tam){
	int i,j,cod,min,seg,quant=0;
	int ql=quantLinhaArq("arquivos/desempenho.txt");
	FILE *arq_n;
	
	arq_n = fopen("arquivos/desempenho.txt", "r");
	if(arq_n == NULL){
		printf("\nproblemas com a leitura do arquivo desempenho");
	}
	else{
		
		for(i=0;i<ql;i++){
			fscanf(arq_n,"%d %d %d", &cod,&min,&seg);
			
			seg = seg + (min*60);
			printf("\nseg:%d", seg);
			for(j=0;j<tam;j++){
				//testando se forem os mesmos codigos
				if(cod == vet[j].cod){
					printf("\nvet.cod:%d", vet[j].cod);
					//testando record
					if(seg < vet[j].seg){
						printf("\noi");
						vet[j].seg = seg;
						printf("\nvet:%d", vet[j].seg = seg);
						quant++;
					}
				}
			}
		}
	}
	
	return quant;
	fclose(arq_n);	
}
void escreveArq(Trecorde vet[], char nome[], int tam){
	int i;
	FILE *arq;
	
	arq = fopen(nome,"w");
	if(arq == NULL){
		printf("\nproblemas com a abertura do arquivo");
	}else{
		for(i=0;i<tam;i++){
			fprintf(arq,"%d\n%d\n",vet[i].cod, vet[i].seg);
		}
	}
	
	fclose(arq);
}


	

