#include <stdio.h>
#include "lista.h"
#define true 1
#define false 0

int main(void) {
  printf("Hello World\n");
  tLista *lista1;
  lista1=listaCria(10,false,true);//quant max,classif,rep

  listaInclui(lista1,1);
  listaInclui(lista1,2);
  listaInclui(lista1,3);
  listaInclui(lista1,1);
  listaInclui(lista1,3);
  listaInclui(lista1,1);
  listaExibi(lista1);
  listaExclui(lista1,3);
  listaExibi(lista1);
  return 0;
}