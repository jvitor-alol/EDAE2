﻿#include <stdio.h>
#define alturaMaxima 225

typedef struct
{
  int peso;   // peso em quilogramas
  int altura; // altura em centimetros
} PesoAltura;

int main() {
  int x;
  PesoAltura pessoa1;
  pessoa1.peso = 80;
  pessoa1.altura = 185;

  printf("Peso: %i, Altura %i. ", pessoa1.peso, pessoa1.altura);
  if (pessoa1.altura>alturaMaxima) {
    printf("Altura acima da maxima.\n");
  }
  else printf("Altura abaixo da maxima.\n");

  printf("%p %p %p %p\n", &x, &pessoa1, &(pessoa1.altura), &(pessoa1.peso));
 
  return 0;
}

/*
Peso: 80, Altura 185. Altura abaixo da maxima.
000000000062FE1C 000000000062FE10 000000000062FE14 000000000062FE10
*/

/*
 __                                                    
|  \                                                   
| ▓▓____   ______   _______  _______ __    __ _______  
| ▓▓    \ /      \ /       \/       \  \  |  \       \ 
| ▓▓▓▓▓▓▓\  ▓▓▓▓▓▓\  ▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓ ▓▓  | ▓▓ ▓▓▓▓▓▓▓\
| ▓▓  | ▓▓ ▓▓  | ▓▓\▓▓    \ \▓▓    \| ▓▓  | ▓▓ ▓▓  | ▓▓
| ▓▓__/ ▓▓ ▓▓__/ ▓▓_\▓▓▓▓▓▓\_\▓▓▓▓▓▓\ ▓▓__/ ▓▓ ▓▓  | ▓▓
| ▓▓    ▓▓\▓▓    ▓▓       ▓▓       ▓▓\▓▓    ▓▓ ▓▓  | ▓▓
 \▓▓▓▓▓▓▓  \▓▓▓▓▓▓ \▓▓▓▓▓▓▓ \▓▓▓▓▓▓▓  \▓▓▓▓▓▓ \▓▓   \▓▓
                                                       
*/
