/*Quest�o 03:
Determinada institui��o de ensino armazena,
sob a forma de vetores (de structs), as
seguintes informa��es:
? Alunos: nome, matr�cula;
? Disciplinas do curso: nome, c�digo;
? Inscri��es realizadas: matr�cula do aluno,
c�digo da disciplina, semestre da inscri��o
(semestre/ano).
Pede-se o desenvolvimento de fun��es que
realizem as seguintes opera��es:
i. Exibir, para cada aluno, o total de inscri��es
j� realizadas;
ii. Dado um semestre, informar para cada
disciplina o n�mero de alunos inscritos.

*/

#include <stdio.h>
#include <string.h>

#define TAM 5
#define TAM2 3

//defini��o de tipos
typedef struct{
	char nome;
	int matricula;
}TAlunos;

typedef struct{
	char nome;
	int codigo;

}TDisciplinas;

typedef struct{
	int semestre;
	int ano;
}TPeriodo;

typedef struct{
	int matricula;
	int codigo;
	TPeriodo semestre;
	
}TInscricoes;

void preencher1 (TInscricoes vetor[]);
void preencher2 (TAlunos vetor[]);
void preencher3 (TDisciplinas vetor[]);
int incricoesRealizadas (TInscricoes vetInscricoes[]);

int main(){
	int quant;
	TInscricoes inscricoes[TAM];
	TAlunos alunos[TAM2];
	TDisciplinas disciplinas[TAM2];
	
	//preenchendo as structs
	preencher1 (inscricoes);
	preencher2 (alunos);
	preencher3 (disciplinas);
	
	//chamando fun�ao
	quant= incricoesRealizadas(inscricoes);
	printf("%d\n", quant);
	
	return 0;
}

int incricoesRealizadas (TInscricoes vetInscricoes[]){
	int i, j, cont=0;
	
	for(i=0; i<TAM2; i++){
		for(j=0; j<TAM; j++){
			if(vetInscricoes[j].matricula == i){
				cont++;
			}
		}
		
	}
	
	
	return cont;
	
}

void preencher1 (TInscricoes vetor[]){
	vetor[0].matricula=10;
	vetor[0].codigo=3;
	vetor[0].semestre.semestre=1;
	vetor[0].semestre.ano=2020;
	
	vetor[1].matricula=15;
	vetor[1].codigo=5;
	vetor[1].semestre.semestre=2;
	vetor[1].semestre.ano=2021;
	
	vetor[2].matricula=10;
	vetor[2].codigo=6;
	vetor[2].semestre.semestre=1;
	vetor[2].semestre.ano=2020;
	
	vetor[3].matricula=25;
	vetor[3].codigo=6;
	vetor[3].semestre.semestre=1;
	vetor[3].semestre.ano=2022;
	
	vetor[4].matricula=15;
	vetor[4].codigo=3;
	vetor[4].semestre.semestre=2;
	vetor[4].semestre.ano=2021;
	
}

void preencher2 (TAlunos vetor[]){
	strcpy (vetor[0].nome, "Steve");
	vetor[0].matricula=1;
	
	strcpy (vetor[1].nome, "Vitor");
	vetor[1].matricula=2;
	
	strcpy (vetor[2].nome, "Carlos");
	vetor[2].matricula=3;
	
}

void preencher3 (TDisciplinas vetor[]){
	strcpy (vetor[0].nome, "FPR");
	vetor[0].codigo=3;
	
	strcpy (vetor[1].nome, "SOP");
	vetor[1].codigo=6;
	
	strcpy (vetor[2].nome, "CAW");
	vetor[2].codigo=5;
	
	
}
