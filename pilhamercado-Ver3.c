#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
typedef struct proc
{
	int ID;
	float ValorCheque;
	struct proc *prox;
	char NomeMercado [31];
} Processo;

int GeraID = 0; // A cada Processo novo será acrescido um valor, assim o processo terá um ID único;

int QuantidadeProcessos;

		void Menu(Processo *Pilha);
	void Inicializar(Processo *Pilha);
		int teste_vazia(Processo *Pilha);
	void ExibirProcessos(Processo *Pilha);
		void libera(Processo *Pilha);
	void EmpilharProcesso(Processo *Pilha, float xq, char *mer);  // APAGAR PARTE!!!!!!
		Processo *apagar(Processo *Pilha);
		void OrganizarUltimoProcesso(Processo *Pilha);
	void OrganizaProcessoPorNomeMercado(Processo *Pilha, char *Mercado);


int main()
{// Função principal

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

void Inicializar(Processo *Pilha)//Inicia a pilha
{
	Pilha->prox = NULL;
	QuantidadeProcessos=0;
}

void Menu(Processo *Pilha)
{//Função que trem o menu do programa
	clock_t inicio, fim;

	int op;
				char x1[] = "mer1"; // APAGAR
				char x2[] = "mer2"; // APAGAR
				char Mercado[31]; // APAGAR
	Processo *aux= NULL;

	while(1)
	{

			system("cls");
			printf("\t  ==== MENU ====\n\n");
			printf("\t1. Inserir novo elemento;\n");
			printf("\t2. Apagar um elemento;\n");
			printf("\t3. Exibir Pilha;\n");
			printf("\t4. Tamanho da Pilha;\n");
			printf("\t5. Zerar Pilha.\n");
			printf("\t6. Organiza por Nome de Mercado.\n");
			scanf("%d", &op);

			switch(op){
				case 1:
					inicio=clock();

					EmpilharProcesso(Pilha,5,x1);
					EmpilharProcesso(Pilha,4,x1);
					EmpilharProcesso(Pilha,7,x1);
					EmpilharProcesso(Pilha,2,x1);
					EmpilharProcesso(Pilha,1,x1);

					EmpilharProcesso(Pilha,1,x1);
					EmpilharProcesso(Pilha,4,x2);
					EmpilharProcesso(Pilha,7,x2);
					EmpilharProcesso(Pilha,2,x2);
					EmpilharProcesso(Pilha,5,x2);

					fim=clock();
                  printf("Tempo de execucao: %lf\n",((double)(fim - inicio)/CLOCKS_PER_SEC));
                  system("Pause");
                  break;



				case 2:
				    inicio=clock();
					aux= apagar(Pilha);
					if(aux != NULL)
					printf("Elemento retirado: %f\n\n", aux->ValorCheque);
					fim=clock();
                  printf("Tempo de execucao: %lf\n",((double)(fim - inicio)/CLOCKS_PER_SEC));
                  system("Pause");
                  break;




				case 3:
				    inicio=clock();
					ExibirProcessos(Pilha);
					fim=clock();
                  printf("Tempo de execucao: %lf\n",((double)(fim - inicio)/CLOCKS_PER_SEC));
                  system("Pause");
                  break;




				case 4:
				    inicio=clock();
					printf("A pilha possui %d elementos. \n", QuantidadeProcessos);
					fim=clock();
                  printf("Tempo de execucao: %lf\n",((double)(fim - inicio)/CLOCKS_PER_SEC));
                  system("Pause");
                  break;



				case 5:
				    inicio=clock();
					libera(Pilha);
					Inicializar(Pilha);
					fim=clock();
                  printf("Tempo de execucao: %lf\n",((double)(fim - inicio)/CLOCKS_PER_SEC));
                  system("Pause");
                  break;

				case 6:
					inicio=clock();
					printf("Nome do Estabelecimento: ");
					fflush(stdin); // LIMPANDO BUFFER DO TECLADO!
					scanf("%s", &Mercado);
					OrganizaProcessoPorNomeMercado(Pilha, Mercado);
					fim=clock();
                  printf("Tempo de execucao: %lf\n",((double)(fim - inicio)/CLOCKS_PER_SEC));
                  system("Pause");
                  break;

				default:
					printf("Comando invalido, por favor escolha uma opcao.\n\n");
			}
	}
}


int teste_vazia(Processo *Pilha){// Testa se a pilha está vazia. Se o primeiro elemento aponta para NULL quer dizer que a pilha não tem elementos

	if(Pilha->prox == NULL)
		return 1;
	else
		return 0;
}

void ExibirProcessos(Processo *Pilha){// Função de impressão da pilha

	Processo *aux= Pilha->prox;

	if(teste_vazia(Pilha)){
		printf("A pilha esta vazia. \n");
	}
	else{
		printf("\nPilha:\n");

		while( aux != NULL){
			printf("%d\n", aux->ID);
			printf("   %s\n", aux->NomeMercado);
			printf("   %f\n", aux->ValorCheque);
			aux = aux->prox;
		}
	}
}

void libera(Processo *Pilha){//Libera o espaço alocado da Pilha

	Processo *proxNo,*atual;

	if(!teste_vazia(Pilha)){//Ou seja, se a pilha não está vazia a função irá esvaziá-la

		atual = Pilha->prox;//O ponteiro atual recebe o primeiro elemento da pilha

		while(atual != NULL){
			proxNo = atual->prox;//Uma ligação para que não se perca quem é o primeiro nó

			free(atual);
			atual = proxNo;//atual recebe o proximo nó e o loço continua se repetindo até que a pilha seja apagada
		}
	}
}

void EmpilharProcesso(Processo *Pilha, float xq, char *mer)//Iserção de nós na pilha
{

	Processo *novo=(Processo*) malloc(sizeof(Processo));
	Processo *UltimoElemento= NULL;

	if(novo == NULL){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	else
	{
		novo->ID = ++GeraID;
		novo->ValorCheque = xq;
		strcpy (novo->NomeMercado,mer);
	//	printf("Valor do Cheque: ");
	//	fflush(stdin); // LIMPANDO BUFFER DO TECLADO!
	//	scanf("%f", &novo->ValorCheque);
	//	printf("Nome do Estabelecimento: ");
	//	fflush(stdin); // LIMPANDO BUFFER DO TECLADO!
	//	scanf("%s", &novo->NomeMercado);

		novo->prox = NULL;

		if(teste_vazia(Pilha))
			Pilha->prox= novo;//Se a pilha estiver vazia novo será o primeiro nó da pilha
		else
		{

		   UltimoElemento= Pilha->prox;		// aponta pro primeiro elemento

			while(UltimoElemento->prox != NULL)
			{
				UltimoElemento = UltimoElemento->prox;
			}

			UltimoElemento->prox = novo;

			OrganizarUltimoProcesso(Pilha);
		}

		QuantidadeProcessos++;
	}
}

void OrganizarUltimoProcesso(Processo *Pilha)
{
	Processo *UltimoElemento = Pilha;		//Guardar o ultimo Elemento para verificar se ele é menor que os anteriores
	Processo *PenultimoElemento = Pilha;	//Se UltimoElemento for menor, PenultimoElemento vai apontar para NULL, já que UltimoElemento não estará mais no topo da pilha
	Processo *Ant = Pilha->prox;			//Se ultimoElemento estiver entre Ant e Pos, Ant vai apontar pra UltimoElemento
	Processo *Pos = Pilha->prox;			//Se ultimoElemento estiver entre Ant e Pos, UltimoElemento vai apontar pra Pos;
	int ComecaAnt =0;				//Serve para forçar PenultimoElemento ficar um nó atrás de UltimoElemento, tem a mesma relação com Ant e Pos;

	while(UltimoElemento->prox != NULL) //achar o ultimo elemento da pilha e Penultimo Elemento e guarda esses valores;
	{
		UltimoElemento = UltimoElemento->prox;
		if(ComecaAnt>0) // Forca Ant ficar um no atras de Pos
		{
			PenultimoElemento = PenultimoElemento->prox;
		}
		ComecaAnt++;
	}
	if(Pilha->prox->ValorCheque > UltimoElemento->ValorCheque)	// Verifica se o UltimoElemento é menor que o primeiro da Pilha
	{

		UltimoElemento->prox = Pilha->prox;
		Pilha->prox = UltimoElemento;
		PenultimoElemento->prox = NULL; //Transforma PenultimoElemento em Ultimo Elemento da Pilha;
	}
	else
	{
		ComecaAnt =0;
		Ant = Pilha->prox;
		while((Pos->prox != NULL) && (Pos->ValorCheque <= UltimoElemento->ValorCheque) )	// Enquanto não chegar no final da pilha e o valor do novo cheque for maior entra aqui;
		{
			Pos = Pos->prox;
			if(ComecaAnt>0) // Forca Ant ficar um no atras de Pos
			{

				Ant = Ant->prox;
			}
			ComecaAnt++;
		}
		if(Pos->ValorCheque > UltimoElemento->ValorCheque)		//Se saiu do while anterior por causa da tamanho do cheque, então ele irá inserir o valor no intervalo correto e transformar o PenultimoElemento em UltimoElemento da pilha;
		{
			PenultimoElemento->prox = NULL;

			UltimoElemento->prox = Pos;
			Ant->prox = UltimoElemento;
		}
	}
}

void OrganizaProcessoPorNomeMercado(Processo *Pilha, char *Mercado)
{

	Processo *PilhaAux=(Processo*) malloc(sizeof(Processo));
	if(PilhaAux == NULL){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}

	PilhaAux->prox = NULL;
    int ComecaAnt = 0;
	Processo *Pos = Pilha->prox;
	Processo *Ant = Pilha;
	Processo *CorrePilhaAux = PilhaAux;
    Processo *NovoElementoAux = NULL;

	while(Pos->prox != NULL)
	{
		if(stricmp(Mercado,Pos->NomeMercado) != 0)
		{
			Ant = Ant->prox;
			Pos = Pos->prox;ExibirProcessos(Pilha);
		}
		else
		{
            NovoElementoAux = Pos;
			if(Pos->prox != NULL)
			{
                Pos = Pos->prox;
                Ant->prox = Pos;
			}
			CorrePilhaAux = PilhaAux;
            while(CorrePilhaAux->prox != NULL)
                CorrePilhaAux = CorrePilhaAux->prox;
			CorrePilhaAux->prox = NovoElementoAux;
            NovoElementoAux->prox = NULL;
			OrganizarUltimoProcesso(PilhaAux);
		}
	}
printf("\n\n Pos:::xqP %f , idP %d ||||||| Ant:::xqA %f , idA %d", Pos->ValorCheque, Pos->ID, Ant->ValorCheque, Ant->ID);
system("pause");
	if(stricmp(Mercado,Pos->NomeMercado) == 0)
    {
        while(CorrePilhaAux->prox != NULL)
            CorrePilhaAux = CorrePilhaAux->prox;
        CorrePilhaAux->prox = Pos;

        Ant->prox = PilhaAux->prox; //PilhaAux->prox->prox ????
    }

printf("\n\n Pilha:::xqP %f , idP %d ||||||| Ant:::xqA %f , idA %d", Pos->ValorCheque, Pos->ID, Ant->ValorCheque, Ant->ID);
system("pause");

ExibirProcessos(Pilha);
printf("\n\n AUX");
ExibirProcessos(PilhaAux);
}

Processo *apagar(Processo *Pilha){//Apaga um nó da pilha. O ultimo elemento inserido.

	Processo *ult=NULL, *pnult=NULL;

	if(Pilha->prox == NULL){
		printf("Pilha vazia\n\n");
		return NULL;
	}else{
		ult = Pilha->prox;
	    pnult = Pilha;

		while(ult->prox != NULL){
			pnult = ult;
			ult = ult->prox;
		}

		pnult->prox = NULL;
		QuantidadeProcessos--;
		return ult;
	}
}
