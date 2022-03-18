
/*a. Faça a função horario que receba um parâmetro (inteiro por valor) com o total de
minutos de um evento e receba também dois parâmetros (inteiros por referência) no
qual deve preencher a quantidade de hora e de minutos equivalente. Por exemplo:
145 minutos equivale a 2 h e 25 min. Esta função deverá OBRIGATORIAMENTE chamar
a função DivisaoInteira

b. Faça um programa que leia o tempo de treino (em minutos) de 10 atletas, mostrando
a cada um, o tempo de treino no formato hh:mm. (utilize a função do item a).
No final deve ser exibido o maior tempo de treino e quantos atletas o fizeram*/
#include <stdio.h>
#include <stdlib.h>
void horario(int minT, int *hora, int *min);
int divisaoInteira(int a, int b);
int main(){
	int i, hora, min, minT;	
	printf("digite os minutos:");
	scanf("%d", &minT);
	horario(minT, &hora, &min);	
	printf("\n%d horas e %d minutos", hora, min);
	return 0;
}
void horario(int minT, int *hora, int *min){
	int i;
	
	*hora = (minT/60);
	*min = divisaoInteira(minT, 60);
	
}

int divisaoInteira(int a, int b){
	return(a % 60);
}
