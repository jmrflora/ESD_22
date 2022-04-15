#include <stdio.h>
#include <stdlib.h>

struct lista{
  //informado pelo cliente
  int *vetor;
  int quantMax;
  int quantOcup;
  int ehClassif;
  int ehComRep;
};

typedef struct lista tLista;

tLista *listaCria(int quantMax,int ehClassif,int ehComRep);
void listaSetClassif(tLista *l,int classif);
void listaSetRep(tLista *l,int rep);
void listaSetQuantMax(tLista *l,int quant);
void listaSetQuantOcupado(tLista *l,int quant);
void listaSetQuantOcupadoMais1(tLista *l);
void listaSetVetorVazio(tLista *l);
void listaExibiVet(tLista *l);
void listaExibi(tLista *l);
void listaSetVet(tLista *l,int n,int pos);
void listaEmpurraVet(tLista *l,int posI);
void listaInclui(tLista *l,int n);
int listaExclui(tLista *l, int el);
void listaPuxaVet(tLista *l,int posI,int ultimOco);
int listaGetQuantOcupado(tLista *l);
int listaGetQuantMax(tLista *l);
int listaGetNumVet(tLista *l,int pos);
int listaGetClassif(tLista *l);
int listaGetClassif(tLista *l);
int listaGetRep(tLista *l);
int listaExclui(tLista *l,int el);
int listaGetVetEmPos(tLista *l,int pos);
int listaBuscaEl(tLista *l,int el, int *pos);
int listaBuscaU(tLista *l, int el, int posI, int *posF);

/*
listaIncluiElm();
listaExcluiElm();
listaConsultaElm();
listaPercorre();
*/