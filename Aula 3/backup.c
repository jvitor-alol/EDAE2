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
  	l->cabeca->prox = l->cabeca; 
  	PONT end = l->cabeca->prox;
  	int i = 0;
  	while (i < c){
  		end->prox = (PONT) malloc(sizeof(Pessoa));
  		end = end->prox;
  		i++;
  		end->numero = i;
  	}
  	end->prox = l->cabeca;
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

int solucaoJosefo(LISTA* l){
	int tam = tamanho(l);
	PONT end = l->cabeca->prox;
  	while (tam > 1){
		while(end != l->cabeca && end->prox != l->cabeca){
  			PONT aux = end->prox;
  			printf("%d ", end->numero);
  			end->prox = end->prox->prox;
  			printf("%d ", end->numero);
  			end = end->prox;
  			printf("%d ", end->numero);
  			free (aux);
  			tam--;
  			printf("%d \n", end->numero);
  			printf("%d ", tam);
		}
	}
	return end->numero;
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

void main(){
	LISTA l;
	int c;
	scanf("%d", &c);
	inicializarLista(&l, c);
	exibirLista(&l);
	printf("S(%d) = %d", c, solucaoJosefo(&l));
}
