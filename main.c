#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "funcoes.h"


       
int main()	// Função principal
{
	
       int opcao;
	Processo *Pilha = (Processo *) malloc(sizeof(Processo));

	if(Pilha== NULL){
		printf("Memoria Indisponivel.\n");
		exit(1);
	}
	else{
		Inicializar(Pilha);
		Menu(Pilha);
		free(Pilha);
		return 0;
	}
}

