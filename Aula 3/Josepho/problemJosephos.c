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

void exibirLista(LISTA* l){
  	PONT end = l->cabeca->prox;
  	printf("Lista: \" ");
  	while (end != l->cabeca){
    	printf("%d ", end->numero);
    	end = end->prox;
  	}
  	printf("\"\n");
}

void solucaoJosefo(LISTA* l, int c){
	PONT end = l->cabeca->prox;
	PONT aux;
  	while (tamanho(l) > 1){
		if(end == l->cabeca) end = end->prox;
		if(end->prox != l->cabeca){
			aux = end->prox;
			end->prox = end->prox->prox;
  			end = end->prox;
		}
		else {
			aux = l->cabeca->prox;
			l->cabeca->prox = l->cabeca->prox->prox;
			end = l->cabeca->prox;
		}
		free (aux);
  		exibirLista(l);
	}
	printf("\n**S(%d) = %d**\n", c, l->cabeca->prox->numero);
}

void main(){
	LISTA l;
	int c;
	printf("Tamanho da roda: ");
	scanf("%d", &c);
	inicializarLista(&l, c);
	exibirLista(&l);
	solucaoJosefo(&l, c);
	getch();
}
