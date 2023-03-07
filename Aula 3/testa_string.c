#include<stdio.h>
#include<conio.h>
int main(void)
{
  char nomeComEspaco[201];
  char nomeSemEspaco[201];
  
  printf("Digite seu nome (maniuplacao com espaco): ");
  gets(nomeComEspaco);
  printf("Digite seu nome (manipulacao sem espaco): ");
  scanf("%s",nomeSemEspaco);
  
  printf("\nO nome armazenado foi (manipulacao com espaco): %s", nomeComEspaco);
  printf("\nO nome armazenado foi (manipulacao sem espaco): %s", nomeSemEspaco);
  
  getch();
  return 0;
}
