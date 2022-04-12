#include "lista.h"

tLista *listaCria(int quantMax,int ehClassif,int ehComRep){
  tLista *lista = (tLista *)malloc(sizeof(tLista));
  listaSetClassif(lista,ehClassif);
  listaSetRep(lista,ehComRep);
  listaSetQuantMax(lista,quantMax);
  listaSetQuantOcupado(lista,0);
  listaSetVetorVazio(lista);
  return lista;
}
void listaSetClassif(tLista *l,int classif){
  l->ehClassif = classif;
}
void listaSetRep(tLista *l,int rep){
  l->ehComRep = rep;
}
void listaSetQuantMax(tLista *l,int quant){
  l->quantMax = quant;
}
void listaSetQuantOcupadoMais1(tLista *l){
  l->quantOcup += 1;
}
void listaSetQuantOcupado(tLista *l,int quant){
  l->quantOcup = quant;
}
void listaSetVetorVazio(tLista *l){
  l->vetor = (int *)malloc(sizeof(int) * listaGetQuantMax(l));
}
int listaGetQuantOcupado(tLista *l){
  return l->quantOcup;
}
int listaGetQuantMax(tLista *l){
  return l->quantMax;
}
void listaExibi(tLista *l){
  printf("\nlista:");
  printf("\nquantidade ocupada do vet:%d",listaGetQuantOcupado(l));
  printf(" quantidade maxima:%d", listaGetQuantMax(l));
  listaExibiVet(l);
  switch(listaGetClassif(l)){
    case 0:
    printf("\nnao eh classificada");  
    break;
    case 1:
    printf("\neh classificada");
    break;
  }
  switch(listaGetRep(l)){
    case 0:
    printf("\nnao possui repeticao");
    break;
    case 1:
    printf("\npossui repeticao");
    break;
  }
}
int listaGetNumVet(tLista *l,int pos){
  return l->vetor[pos];
}
int listaGetClassif(tLista *l){
  return l->ehClassif;
}
int listaGetRep(tLista *l){
  return l->ehComRep;
}

void listaExibiVet(tLista *l){//ainda não concluido
  int i;
  printf("\nvetor:");
  for(i=0;i<listaGetQuantOcupado(l);i++){
    printf("%d ",listaGetNumVet(l,i));
  }
}
void listaInclui(tLista *l,int n){
  
}