#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

typedef struct nomeTemp{
	int numero;
	struct nomeTemp* prox;
}Pessoa, *PONT;

typedef struct{
	PONT cabeca;
}LISTA;

void inicializarLista(LISTA* l, int c){
  l->cabeca = (PONT) malloc(sizeof(Pessoa));
  PONT end = (PONT) malloc(sizeof(Pessoa));
  l->cabeca->prox = l->cabeca; 
  end = l->cabeca->prox;
  int i;
  for (i = 0; i < c; i++){
  	end->prox = (PONT) malloc(sizeof(Pessoa));
  	end->numero = i+1;
  	end = end->prox;
  	printf("%d ", end->numero);
  }
}

int tamanho(LISTA* l) {
  PONT end = l->cabeca->prox;
  int tam = 0;
 while (end != l->cabeca){
    tam++;
    end = end->prox;
  }
  return tam;
}

void exibirLista(LISTA* l){
  PONT end = l->cabeca->prox;
  printf("Lista: \" ");
  while (end != l->cabeca){
    printf("%d ", end->numero);
    end = end->prox;
  }
  printf("\"\n");
}

int main(){
	LISTA l;
	int c;
	scanf("%d", &c);
	inicializarLista(&l, c);
	exibirLista(&l);
}
