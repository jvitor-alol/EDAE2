#include "pilhaDinamica.c"

void inserir(PILHA *l)
{
  TIPOCHAVE ch;
  scanf("%f", &ch);
  REGISTRO reg;
  reg.chave = ch;
  if (push(l, reg))
    printf("Elemento %f inserido corretamente.\n", ch);
  else
    printf("Nao foi possivel inserir elemento %f.\n", ch);
}

void exibirTopo(PILHA *l)
{
  TIPOCHAVE ch;
  PONT posicao = retornarTopo(l, &ch);
  if (posicao != NULL)
    printf("Elemento %f encontrado no endereco %p.\n", ch, posicao);
  else
    printf("Nao foi possivel encontrar nenhum elemento (pilha vazia).\n");
}

void excluir(PILHA *l)
{
  REGISTRO temp;
  if (excluirElemPilha(l, &temp))
    printf("Elemento %f excluido corretamente.\n", temp.chave);
  else
    printf("Nao foi possivel excluir elemento (pilha vazia).\n");
}

void exibir(PILHA *l)
{
  exibirPilha(l);
}

void meuLog(PILHA *l)
{
  printf("Numero de elementos na pilha: %i.\n", tamanho(l));
  printf("Tamanho da pilha (em bytes): %i.\n", tamanhoEmBytes(l));
}

void help()
{
  printf("Comandos validos: \n");
  printf("   i <chave1>: inserir elemento com chave=chave1\n");
  printf("   e : excluir topo da pilha\n");
  printf("   p : imprimir pilha\n");
  printf("   d : destruir (zerar) pilha\n");
  printf("   l : exibir log de utilizacao da pilha\n");
  printf("   c : modo calculadora\n");
  printf("   h : exibir esta mensagem de ajuda\n");
  printf("   0 : exibir a chave e o endereco do primeiro elemento\n");
  printf("   q : sair\n");
}

void destruir(PILHA *l)
{
  reinicializarPilha(l);
  printf("Pilha zerada.\n");
}

void calculadora() {
	system("cls");
	printf("**Modo calculadora**\n\nInstrucoes/Operadores:\n+ Adicao || - Subtracao || x Multiplicacao || / Divisao\nc Limpar memoria\np Mostrar memoria\nh Limpar tela\nq Sair do modo calculadora\n\n");
	PILHA m;
	inicializarPilha(&m);
	REGISTRO reg;
	char entrada [10];
	scanf("%s", entrada);
	while (entrada[0] != 'q'){	
	    switch (entrada[0] + entrada [1])
	    {
	    case '+' + '\0':
	      if (estaVazia(&m)) {printf("Memoria vazia\n");	break;}
	      if (m.topo->prox == NULL) printf("Resultado = %.4f\n", m.topo->reg.chave);
	      else{
	      	m.topo->prox->reg.chave += m.topo->reg.chave;
	      	pop(&m);
	     	printf("Resultado = %.4f\n", m.topo->reg.chave);
		  }
	      break;
	
	    case '-' + '\0':
	      if (estaVazia(&m)) {printf("Memoria vazia\n");	break;}
	      if (m.topo->prox == NULL) printf("Resultado = %.4f\n", m.topo->reg.chave);
	      else{
	      	m.topo->prox->reg.chave -= m.topo->reg.chave;
	      	pop(&m);
	     	printf("Resultado = %.4f\n", m.topo->reg.chave);
		  }
	      break;
	
	    case 'x' + '\0':
	      if (estaVazia(&m)) {printf("Memoria vazia\n");	break;}
	      if (m.topo->prox == NULL) printf("Resultado = %.4f\n", m.topo->reg.chave);
	      else{
	      	m.topo->prox->reg.chave *= m.topo->reg.chave;
	      	pop(&m);
	     	printf("Resultado = %.4f\n", m.topo->reg.chave);
		  }
	      break;
	
	    case '/' + '\0':
	      if (estaVazia(&m)) {printf("Memoria vazia\n");	break;}
	      if (m.topo->prox == NULL) printf("Resultado = %.4f\n", m.topo->reg.chave);
	      else{
	      if(m.topo->reg.chave == 0) {
	        printf("Divisao por zero nao permitida\n");
	        break;
	      }
	      m.topo->prox->reg.chave /= m.topo->reg.chave;
	      pop(&m);
	      printf("Resultado = %.4f\n", m.topo->reg.chave);
		  }
	      break;
		
		case 'h' + '\0':
			system("cls");
			printf("**Modo calculadora**\n\nInstrucoes/Operadores:\n+ Adicao || - Subtracao || x Multiplicacao || / Divisao\nc Limpar memoria\np Mostrar memoria\nh Limpar tela\nq Sair do modo calculadora\n\n");
			break;
			
		case 'c' + '\0': 
			reinicializarPilha(&m);
			printf("Memoria limpa\n");
			break;
			
		case 'p' + '\0':
			exibirPilha(&m);
			break;
				
		default: 
			reg.chave = atof (entrada);
			push (&m, reg);
			break;
	    }
	    
	scanf("%s", entrada);
	}	
	printf("Saindo do modo calculadora...\n");
	getch();
}

int main()
{
  PILHA pilha;
  inicializarPilha(&pilha);
  help();
  char comando = ' ';
  scanf("%c", &comando);
  while (comando != 'q')
  {
    switch (comando)
    {
    case 'i':
      inserir(&pilha);
      break;
    case 'e':
      excluir(&pilha);
      break;
    case 'p':
      exibir(&pilha);
      break;
    case 'd':
      destruir(&pilha);
      break;
    case 'l':
      meuLog(&pilha);
      break;
    case 'c':
      calculadora();
      system("cls");
      help();
      break;
    case 'h':
      help();
      break;
    case '0':
      exibirTopo(&pilha);
      break;

    default:
    {
      while (comando != '\n')
        scanf("%c", &comando);
    };
    }
    scanf("%c", &comando);
  }

  return 0;
}
