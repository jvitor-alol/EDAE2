#include <stdio.h>
#include <malloc.h>

int *a;// = (int*) malloc(sizeof(int*));

typedef struct{
  int c1;
  int c2;
} TESTE, *PONT;

PONT copiar(TESTE t1){
	PONT x = (PONT) malloc(sizeof(PONT));
	//printf("%d %d %p %p %d %d %p %p\n", x->c1,x->c2,&x->c1,&x->c2,t1.c1,t1.c2,&t1.c1,&t1.c2);
	x = &t1;
	//printf("%d %d %p %p %d %d %p %p\n", x->c1,x->c2,&x->c1,&x->c2,t1.c1,t1.c2,&t1.c1,&t1.c2);
	return x;
}

int main(){
	//printf("%p", a);
	//*a = 10;
	TESTE y;
	y.c1 = 10;
	y.c2 = 22;
	PONT w = copiar(y);
	printf("c1: %i, c2: %i\n ", w->c1, w->c2);
	return 0;
}

/*
c1: 10, c2: 22
*/
