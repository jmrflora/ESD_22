#include "lista.h"

tLista *listaCria(int quantMax, int ehClassif, int ehComRep) {
  tLista *lista = (tLista *)malloc(sizeof(tLista));
  listaSetClassif(lista, ehClassif);
  listaSetRep(lista, ehComRep);
  listaSetQuantMax(lista, quantMax);
  listaSetQuantOcupado(lista, 0);
  listaSetVetorVazio(lista);
  return lista;
}
void listaSetClassif(tLista *l, int classif) { l->ehClassif = classif; }
void listaSetRep(tLista *l, int rep) { l->ehComRep = rep; }
void listaSetQuantMax(tLista *l, int quant) { l->quantMax = quant; }
void listaSetQuantOcupadoMais1(tLista *l) { l->quantOcup += 1; }
void listaSetQuantOcupado(tLista *l, int quant) { l->quantOcup = quant; }
void listaSetVetorVazio(tLista *l) {
  l->vetor = (int *)malloc(sizeof(int) * listaGetQuantMax(l));
}
void listaSetVet(tLista *l, int n, int pos) { l->vetor[pos] = n; }
int listaGetQuantOcupado(tLista *l) { return l->quantOcup; }
int listaGetQuantMax(tLista *l) { return l->quantMax; }
void listaExibi(tLista *l) {
  printf("\nlista:");
  printf("\nquantidade ocupada do vet:%d", listaGetQuantOcupado(l));
  printf(" quantidade maxima:%d", listaGetQuantMax(l));
  listaExibiVet(l);
  switch (listaGetClassif(l)) {
  case 0:
    printf("\nnao eh classificada");
    break;
  case 1:
    printf("\neh classificada");
    break;
  }
  switch (listaGetRep(l)) {
  case 0:
    printf("\nnao possui repeticao");
    break;
  case 1:
    printf("\npossui repeticao");
    break;
  }
}
int listaGetNumVet(tLista *l, int pos) { return l->vetor[pos]; }
int listaGetClassif(tLista *l) { return l->ehClassif; }
int listaGetRep(tLista *l) { return l->ehComRep; }
int listaGetVetEmPos(tLista *l, int pos) { return l->vetor[pos]; }
void listaExibiVet(tLista *l) {
  int i;
  printf("\nvetor:");
  for (i = 0; i < listaGetQuantOcupado(l); i++) {
    printf("%d ", listaGetNumVet(l, i));
  }
}
int listaExclui(tLista *l, int el) {
  printf("\n\nexcluindo el:%d", el);
  int primOco, ultimOco, i;
  if (listaGetQuantOcupado(l) == 0) {
    // lista vazia
  } else {
    switch (listaGetClassif(l)) {
    case 1:                      // classif
      if (listaGetRep(l) == 1) { // com rep
        // encontar o primeiro e a ultima ocorrencia
        listaBuscaEl(l, el, &primOco);
        listaBuscaU(l, el, primOco, &ultimOco);
        listaPuxaVet(l, primOco, ultimOco);
      } else { // sem rep
        // pos1 ?? igual a pos ultima
        listaBuscaEl(l, el, &primOco);
        listaPuxaVet(l, primOco, primOco);
      }
      // desloc=posultima - pos1+1
      // fazer um for at?? final-desloc
      // l->vet[i]=l->vet[i+desloc]
      break;
    case 0:// n??o classif
      if (listaGetRep(l) == 1) { // com rep
        // enquanto nao chegar no fim
        // se o el atual==n
        // subistitui pelo ultimo,diminui quantOcup
        // senao i++
        for (i = 0; i < listaGetQuantOcupado(l); i++) {
          if (listaGetVetEmPos(l, i) == el) {
            // printf("\nquantOcupado: %d",listaGetQuantOcupado(l));
            listaSetVet(l, listaGetVetEmPos(l, listaGetQuantOcupado(l) - 1), i);
            // listaExibiVet(l);
            listaSetQuantOcupado(l, listaGetQuantOcupado(l) - 1);
            i--;
          }
        }
      } else { // sem rep
        // acha a pos do el
        // subistitui pelo ultimo
        listaBuscaEl(l, el, &primOco);
        listaSetVet(l, listaGetVetEmPos(l, listaGetQuantOcupado(l)-1), primOco);
        listaSetQuantOcupado(l, listaGetQuantOcupado(l) - 1);
      }
      break;
    }
  }
}
void listaInclui(tLista *l, int n) {
  int i, pos;
  if (listaGetQuantOcupado(l) == listaGetQuantMax(l)) {
    // cheio
  } else {
    switch (listaGetClassif(l)) {
    case 1: // classificado
      if (listaGetRep(l) == 1) {
        // com rep
        if (listaBuscaEl(l, n, &pos) == 1) { // achou
          listaEmpurraVet(l, pos);
          listaSetVet(l, n, pos);
          listaSetQuantOcupadoMais1(l);
        } else { // n??o achou
          listaEmpurraVet(l, pos);
          listaSetVet(l, n, pos);
          listaSetQuantOcupadoMais1(l);
        }

      } else {
        // sem rep
        if (listaBuscaEl(l, n, &pos) == 1) { // achou
          printf("\nelemento ja incluso");
        } else { // n??o achou
          listaEmpurraVet(l, pos);
          listaSetVet(l, n, pos);
          listaSetQuantOcupadoMais1(l);
        }
      }
      break;
    case 0: // n??o classificado
      if (listaGetRep(l) == 1) {
        // com rep
        listaSetVet(l, n, listaGetQuantOcupado(l));
        listaSetQuantOcupadoMais1(l);
      } else { // precisa de teste
        // sem rep
        if (listaBuscaEl(l, n, &pos) == 1) { // achou
          printf("\nelemento ja incluso");
        } else { // n??o achou
          listaSetVet(l, n, pos);
          listaSetQuantOcupadoMais1(l);
        }
      }
      break;
    }
  }
}
int listaBuscaEl(tLista *l, int el, int *pos) {
  int i = 0;
  int achou = 0;
  int temChance = 1;

  while (achou != 1 && temChance != 0) {

    if (listaGetNumVet(l, i) == el) {
      achou = 1;
      i--;
    } else if (listaGetClassif(l) == 1 && listaGetNumVet(l, i) > el ||
               i >= listaGetQuantOcupado(l)) {
      temChance = 0;
      i--;
    }
    i++;
  }
  (*pos) = i;
  return achou;
}
void listaEmpurraVet(tLista *l, int posI) {
  int i;
  for (i = listaGetQuantOcupado(l); i > posI; i--) {
    listaSetVet(l, listaGetVetEmPos(l, i - 1), i);
  }
}
int listaBuscaU(tLista *l, int el, int posI, int *posF) {
  int i = posI;
  int achou = 0;
  int temChance = 1;

  while (temChance != 0) {
    if (listaGetNumVet(l, i) == el) {
      achou++;
    } else if (listaGetNumVet(l, i) > el || i >= listaGetQuantOcupado(l)) {
      temChance = 0;
    }
    i++;
  }
  (*posF) = i - 2;
  return achou;
}
void listaPuxaVet(tLista *l, int posI, int ultimOco) {
  int i, j, desloc;
  desloc = ((ultimOco - posI) + 1);
  /*printf("\ndesloc %d",desloc);
  printf("\nposI: %d",posI);*/
  for (i = posI;i<listaGetQuantOcupado(l); i++) {
    listaSetVet(l, listaGetVetEmPos(l, i + desloc), i);
    /*listaExibiVet(l);
    printf("\n\n");*/
  }
  listaSetQuantOcupado(l, listaGetQuantOcupado(l) - desloc);
}