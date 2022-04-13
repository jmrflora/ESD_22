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
void listaSetVet(tLista *l,int n,int pos){
  l->vetor[pos]=n;
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
    case 0:  printf("\nnao eh classificada");  
          break;
    case 1:  printf("\neh classificada");
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
int listaGetVetEmPos(tLista *l,int pos){
  return l->vetor[pos];
}
void listaExibiVet(tLista *l){
  int i;
  printf("\nvetor:");
  for(i=0;i<listaGetQuantOcupado(l);i++){
    printf("%d ",listaGetNumVet(l,i));
  }
}
/*int listaExclui(tLista *l,int pos){

  if(//lvazia){
    
  }
  else{
    switch(listaGetClassif(l)){
      case 1:
        if(listaGetRep(l)==1){
          //encontar o primeiro e a ultima ocorrencia
        }else{
          //pos1 é igual a pos ultima
        }
        //desloc=posultima - pos1+1
        //fazer um for até final-desloc
        //l->vet[i]=l->vet[i+desloc]
        break;
      case 0;
        if(listaGetRep(l)==1){
          //enquanto na chegar no fim
          //se o el atual==n
          //subistitui pelo ultimo,diminui quantOcup
          //senao i++
        }
        else{
          //acha a pos do el
          //subistitui pelo ultimo
        }

        break;
    }
  }
}*/
void listaInclui(tLista *l,int n){
  int i,pos;
  if(listaGetQuantOcupado(l)==listaGetQuantMax(l)){
    //cheio
  }else{
    switch (listaGetClassif(l)){
      case 1://classificado
        if(listaGetRep(l)==1){
          //com rep
          if(listaBuscaEl(l,n,&pos)==1){//achou
            listaEmpurraVet(l,pos);
            listaSetVet(l,n,pos);
            listaSetQuantOcupadoMais1(l);
          }else{//não achou
            listaEmpurraVet(l,pos);
            listaSetVet(l,n,pos);
            listaSetQuantOcupadoMais1(l);
          }
          
        }else{
          //sem rep
          if(listaBuscaEl(l,n,&pos)==1){//achou
            printf("\nelemento ja incluso");
          }else{//não achou
            listaEmpurraVet(l,pos);
            listaSetVet(l,n,pos);
            listaSetQuantOcupadoMais1(l);
          }
        }
        break;
      case 0://não classificado
        if(listaGetRep(l)==1){
          //com rep
          listaSetVet(l,n,listaGetQuantOcupado(l));
          listaSetQuantOcupadoMais1(l);
        }
        else{//precisa de teste
          //sem rep
          if(listaBuscaEl(l,n,&pos)==1){//achou
            printf("\nelemento ja incluso");
          }else{//não achou
            listaSetVet(l,n,pos);
            listaSetQuantOcupadoMais1(l);
          }
        }
        break;
    }
  }
}
int listaBuscaEl(tLista *l,int el, int *pos){
  int i=0;
  int achou =0;
  int temChance = 1;

  while(achou != 1 && temChance != 0){
    
    if(listaGetNumVet(l,i) == el){
      achou = 1;
      i--;
    }
    else if(listaGetClassif(l)==1 && listaGetNumVet(l,i)>el || i>=listaGetQuantOcupado(l)){
      temChance = 0;
      i--;
    }
    i++;
  }
  (*pos)=i;
  return achou;
}
void listaEmpurraVet(tLista *l,int posI){
  int i;
  for(i=listaGetQuantOcupado(l);i>posI;i--){
    listaSetVet(l,listaGetVetEmPos(l,i-1),i);
  }
  
}