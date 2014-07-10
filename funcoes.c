#include "funcoes.h"
int GeraID = 0; // A cada Processo novo ser� acrescido um valor, assim o processo ter� um ID �nico;
float Clock_Insere=0, Clock_Apaga=0, Clock_ApagaID=0, Clock_ExibeTudo=0,Clock_ExibeID=0, Clock_ExibeProximo=0, Clock_ExibeUltimo=0, Clock_ExibeTamanho=0, Clock_LimpaTudo=0, Clock_OrganizaPorNome=0;
int QuantidadeProcessos;

void Inicializar(Processo *Pilha)	                    //Inicia a pilha
{
	Pilha->prox = NULL;
	QuantidadeProcessos=0;
}

void Menu(Processo *Pilha)                              //Menu e chamada para as fun��es
{

	clock_t inicio, fim;
	int op;

	while(1)
	{
        system("cls");
        printf("    Selecione a operacao desejada:   \n\n");
        printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c MENU %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c ANALISE %c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
        printf(" %c                                  %c                             %c\n",186,186,186);
        printf(" %c 0 - Inserir novo Processo        %c %c Tempo Execucao: %f %c\n",186,186,26, ((double)(Clock_Insere)/CLOCKS_PER_SEC),186);
        printf(" %c 1 - Apagar ultimo Processo       %c %c Tempo Execucao: %f %c\n",186,186,26, ((double)(Clock_Apaga)/CLOCKS_PER_SEC),186);
        printf(" %c 2 - Apagar um Processo pelo ID   %c %c Tempo Execucao: %f %c\n",186,186,26, ((double)(Clock_ApagaID)/CLOCKS_PER_SEC),186);
        printf(" %c 3 - Exibir Pilha de Processos    %c %c Tempo Execucao: %f %c\n",186,186,26, ((double)(Clock_ExibeTudo)/CLOCKS_PER_SEC),186);
        printf(" %c 4 - Exibir por ID                %c %c Tempo Execucao: %f %c\n",186,186,26, ((double)(Clock_ExibeID)/CLOCKS_PER_SEC),186);
        printf(" %c 5 - Exibir proximo Processo      %c %c Tempo Execucao: %f %c\n",186,186,26, ((double)(Clock_ExibeProximo)/CLOCKS_PER_SEC),186);
        printf(" %c 6 - Exibir ultimo Processo       %c %c Tempo Execucao: %f %c\n",186,186,26, ((double)(Clock_ExibeUltimo)/CLOCKS_PER_SEC),186);
        printf(" %c 7 - Tamanho da Pilha             %c %c Tempo Execucao: %f %c\n",186,186,26, ((double)(Clock_ExibeTamanho)/CLOCKS_PER_SEC),186);
        printf(" %c 8 - Limpar Pilha                 %c %c Tempo Execucao: %f %c\n",186,186,26, ((double)(Clock_LimpaTudo)/CLOCKS_PER_SEC),186);
        printf(" %c 9 - Organiza por Nome de Mercado %c %c Tempo Execucao: %f %c\n",186,186,26, ((double)(Clock_OrganizaPorNome)/CLOCKS_PER_SEC),186);
        printf(" %c                                  %c                             %c\n",186,186,186);
        printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
        printf("\n\tOpcao: ");
        fflush(stdin);
        scanf("%d", &op);
        switch(op)
        {
            case 0: // Inserir novo Processo
                {
                    EmpilharProcesso(Pilha);
                    system("Pause");
                    break;
                }
            case 1: // Inserir novo Processo
                {
                    Apagar(Pilha);
                    system("Pause");
                    break;
                }
                case 2: // Apagar Ultimo Processo
                {
                    ApagarID(Pilha);
                    system("Pause");
                    break;
                }
            case 3: // Excluir um Processo pelo ID
                {
                    ExibirProcessos(Pilha);
                    system("Pause");
                    break;
                }
            case 4: // Exibir Pilha um ID selecionado
                {
                    ExibirID(Pilha);
                    system("Pause");
                    break;
                }
            case 5: // Exibir proximo Processo
                {
                    ExibirProximoProcesso(Pilha);
                    system("Pause");
                    break;
                }
            case 6: // Exibir ultimo processo
                {
                    ExibirUltimoProcesso(Pilha);
                    system("Pause");
                    break;
                }
            case 7: // Tamanho da Pilha
                {
                    Clock_ExibeTamanho=clock();
                    printf("A pilha possui %d elementos. \n", QuantidadeProcessos);
                    Clock_ExibeTamanho = clock() - Clock_ExibeTamanho;
                    system("Pause");
                    break;
                }
            case 8: // Zerar Pilha
                {
                    libera(Pilha);
                    Inicializar(Pilha);
                    system("Pause");
                    break;
                }
            case 9: // Organiza por Nome de Mercado
                {
                    OrganizaProcessoPorNomeMercado(Pilha);
                    system("Pause");
                    break;
                }
            default:
                printf("\nComando invalido, por favor escolha uma opcao.\n\n");
                fflush(stdin);
        }
	}
}

void ExibeNo(Processo *No)                              //Chamada so para exibir um No
{
    printf("\n%c ID: %d\n",16, No->ID);
    printf("%cCheque:\n",204);
    printf("%c\tValor do Cheque: R$ %.2f\n",186, No->ValorCheque);
    printf("%c\tData do Cheque:.... %s\n",186, No->DataCheque);
    printf("%c\tNome do Mercado:... %s\n",186, No->NomeMercado);
    printf("%cCliente:\n",204);
    printf("%c\tNome:.............. %s\n",186, No->NomeCliente);
    printf("%c\tRG:................ %s\n",186, No->RGCliente);
    printf("%c\tEndere�o:.......... %s\n",186, No->EnderecoCliente);
    printf("%c\tTelefone:.......... %s\n",186, No->TelefoneCliente);
}

int teste_vazia(Processo *Pilha)                        // Testa se a pilha est� vazia. Se o primeiro elemento aponta para NULL quer dizer que a pilha n�o tem elementos
{

	if(Pilha->prox == NULL)
		return 1;
	else
		return 0;
}

void ExibirProcessos(Processo *Pilha)                   // Fun��o de impress�o da pilha
{
    Clock_ExibeTudo=0;
    Clock_ExibeTudo = clock();
	Processo *aux= Pilha->prox;

	if(teste_vazia(Pilha))
    {
		printf("A pilha esta vazia. \n");
	}
	else
    {
		while( aux != NULL)
        {
            ExibeNo(aux);
			aux = aux->prox;
		}
	}
	Clock_ExibeTudo = clock() - Clock_ExibeTudo;
}

void ExibirID(Processo *Pilha)                          // Exibe somente o processo com a ID selecionada
{
    Clock_ExibeID=0;
    float Clock_Pause =0;
    Clock_Pause = clock();

	Processo *Pos = Pilha->prox;
	Processo *Ant = Pilha;
    int LocalizarEsteID;

    printf("Informe o ID do Processo que deseja ver: ");
    Clock_Pause = clock() - Clock_Pause;    // Pausa a contagem do tempo para esperar o scanf.
    scanf("%d", &LocalizarEsteID);
    Clock_ExibeID = clock();
    if(Pilha->prox != NULL)
    {
        while(Pos->prox != NULL)            //Percorre a Pilha Principal at� o ultimo elemento apontar para NULL.
        {
            if(LocalizarEsteID != Pos->ID)      // Se entrar aqui � pq � diferente, ent�o avan�a os n�s da Pilha principal.
            {
                Ant = Ant->prox;
                Pos = Pos->prox;
            }
            else
            {
                ExibeNo(Pos);
                Clock_ExibeID = clock() - Clock_ExibeID + Clock_Pause;
                return;
            }
        }
        if(LocalizarEsteID == Pos->ID)
        {
            ExibeNo(Pos);
            Clock_ExibeID = clock() - Clock_ExibeID + Clock_Pause;
            return;
        }
    }
    printf("O Processo solicitado nao foi encontrado.\n");
    Clock_ExibeID = clock() -  Clock_ExibeID + Clock_Pause;
}

void ExibirProximoProcesso(Processo *Pilha)             //Exibe o processo no TOPO da Pilha
{
    Clock_ExibeProximo=0;
    Clock_ExibeProximo = clock();
	if(teste_vazia(Pilha))
	{
		printf("A pilha esta vazia. \n");
	}
	else
	{
		Processo *Pos = Pilha->prox;
		while(Pos->prox != NULL)            //Percorre a Pilha Principal at� o ultimo elemento apontar para NULL.
		{
		   Pos = Pos->prox;
		}
		ExibeNo(Pos);
	}
	Clock_ExibeProximo = clock() - Clock_ExibeProximo;
}

void ExibirUltimoProcesso(Processo *Pilha)              //Exibe o processo na BASE da Pilha
{
    Clock_ExibeUltimo=0;
    Clock_ExibeUltimo = clock();
	if(teste_vazia(Pilha))
	{
		printf("A pilha esta vazia. \n");
	}
	else
	{
        ExibeNo(Pilha->prox);
	}
	Clock_ExibeUltimo = clock() - Clock_ExibeUltimo;
}

void libera(Processo *Pilha)                            //Libera todos os espa�o alocado da Pilha
{
    Clock_LimpaTudo=0;
    Clock_LimpaTudo = clock();
	Processo *proxNo,*atual;

	if(!teste_vazia(Pilha))     //Verifica se a Pilha ta vazia
    {

		atual = Pilha->prox;
		while(atual != NULL)    //Atual corre a pilha e libera cada no alocado
        {
			proxNo = atual->prox;

			free(atual);
			atual = proxNo;     //atual recebe o proximo n� e o lo�o continua se repetindo at� que a pilha seja apagada
		}
	}
    Clock_LimpaTudo = clock() - Clock_LimpaTudo;
}

void EmpilharProcesso(Processo *Pilha)                  //Iser��o de n�s na pilha
{
    Clock_Insere=0;
    float Clock_Pause=0;
    Clock_Pause = clock();

	Processo *novo=(Processo*) malloc(sizeof(Processo));
	Processo *UltimoElemento= NULL;

	if(novo == NULL){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	else
	{
		novo->ID = ++GeraID;
        Clock_Pause = clock() - Clock_Pause;    // Pausa a contagem do tempo para esperar o scanf.
        fflush(stdin);
        printf("Valor do Cheque: ");
        scanf("%f", &novo->ValorCheque);
        printf("Data do Cheque: ");
        fflush(stdin);
        scanf("\n\r%[^\n]", &novo->DataCheque);
        printf("Nome do Estabelecimento: ");
        scanf("\n\r%[^\n]", &novo->NomeMercado);
        printf("Nome do Cliente: ");
        scanf("\n\r%[^\n]", &novo->NomeCliente);
        printf("RG do Cliente: ");
        scanf("\n\r%[^\n]", &novo->RGCliente);
        printf("Endereco do Cliente: ");
        scanf("\n\r%[^\n]", &novo->EnderecoCliente);
        printf("Telefone do Cliente: ");
        scanf("\n\r%[^\n]", &novo->TelefoneCliente);

        Clock_Insere = clock();
		novo->prox = NULL;

		if(teste_vazia(Pilha))
			Pilha->prox= novo;//Se a pilha estiver vazia novo ser� o primeiro n� da pilha
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
	Clock_Insere = clock() - Clock_Insere + Clock_Pause;
}

void OrganizarUltimoProcesso(Processo *Pilha)           //Funcao que pega o ultimo No da Pilha e organiza no meio da Pilha de acordo ao valor do Cheque
{
	Processo *UltimoElemento = Pilha;		//Guardar o ultimo Elemento para verificar se ele � menor que os anteriores
	Processo *PenultimoElemento = Pilha;	//Se UltimoElemento for menor, PenultimoElemento vai apontar para NULL, j� que UltimoElemento n�o estar� mais no topo da pilha
	Processo *Ant = Pilha->prox;			//Se ultimoElemento estiver entre Ant e Pos, Ant vai apontar pra UltimoElemento
	Processo *Pos = Pilha->prox;			//Se ultimoElemento estiver entre Ant e Pos, UltimoElemento vai apontar pra Pos;
	int ComecaAnt =0;				        //Serve para for�ar PenultimoElemento ficar um n� atr�s de UltimoElemento, tem a mesma rela��o com Ant e Pos;

	while(UltimoElemento->prox != NULL) //achar o ultimo elemento da pilha e Penultimo Elemento e guarda esses valores;
	{
		UltimoElemento = UltimoElemento->prox;
		if(ComecaAnt>0) // Forca Ant ficar um no atras de Pos
		{
			PenultimoElemento = PenultimoElemento->prox;
		}
		ComecaAnt++;
	}
	if(Pilha->prox->ValorCheque > UltimoElemento->ValorCheque)	// Verifica se o UltimoElemento � menor que o primeiro da Pilha
	{

		UltimoElemento->prox = Pilha->prox;
		Pilha->prox = UltimoElemento;
		PenultimoElemento->prox = NULL; //Transforma PenultimoElemento em Ultimo Elemento da Pilha;
	}
	else
	{
		ComecaAnt =0;
		Ant = Pilha->prox;
		while((Pos->prox != NULL) && (Pos->ValorCheque <= UltimoElemento->ValorCheque) )	// Enquanto n�o chegar no final da pilha e o valor do novo cheque for maior entra aqui;
		{
			Pos = Pos->prox;
			if(ComecaAnt>0) // Forca Ant ficar um no atras de Pos
			{

				Ant = Ant->prox;
			}
			ComecaAnt++;
		}
		if(Pos->ValorCheque > UltimoElemento->ValorCheque)		//Se saiu do while anterior por causa da tamanho do cheque, ent�o ele ir� inserir o valor no intervalo correto e transformar o PenultimoElemento em UltimoElemento da pilha;
		{
			PenultimoElemento->prox = NULL;

			UltimoElemento->prox = Pos;
			Ant->prox = UltimoElemento;
		}
	}
}

void OrganizaProcessoPorNomeMercado(Processo *Pilha)    //Verifica os processos de um mercado para organizar no TOPO da Pilha
{
    Clock_OrganizaPorNome=0;
    float Clock_Pause=0;
    Clock_Pause = clock();

    char Mercado [31];
	Processo *PilhaAux=(Processo*) malloc(sizeof(Processo));
	if(PilhaAux == NULL)
    {
		printf("Sem memoria disponivel!\n");
		exit(1);
	}

	PilhaAux->prox = NULL;
    int ComecaAnt = 0;
	Processo *Pos = Pilha->prox;
	Processo *Ant = Pilha;
	Processo *CorrePilhaAux = PilhaAux;
    Processo *NovoElementoAux = NULL;

    printf("Informe o nome do Estabelecimento para reordenar no topo: ");
    Clock_Pause = clock() - Clock_Pause;    // Pausa a contagem do tempo para esperar o scanf.
    scanf("%s",&Mercado);
    Clock_OrganizaPorNome = clock();

    if(!teste_vazia(Pilha))
    {
        while(Pos->prox != NULL)            //Percorre a Pilha Principal at� o ultimo elemento apontar para NULL.
        {
            if(stricmp(Mercado,Pos->NomeMercado) != 0)      // Se entrar aqui � pq � diferente, ent�o avan�a os n�s da Pilha principal.
            {
                Ant = Ant->prox;
                Pos = Pos->prox;
            }
            else                            //Entrando aqui � pq � Igual, ent�o ele ir� passar o novo elemento para a pilhaaux e retirar da Pilha Principal.
            {
                NovoElementoAux = Pos;
                if(Pos->prox != NULL)           //Verifica se o pr�ximo aponta para NULL para avan�a com Pos e Ant;
                {
                    Pos = Pos->prox;
                    Ant->prox = Pos;
                }
                CorrePilhaAux = PilhaAux;
                while(CorrePilhaAux->prox != NULL)
                    CorrePilhaAux = CorrePilhaAux->prox;
                CorrePilhaAux->prox = NovoElementoAux;
                NovoElementoAux->prox = NULL;
            }
        }

        if(stricmp(Mercado,Pos->NomeMercado) == 0)      //Resolve o ultimo n�;
        {
            while(CorrePilhaAux->prox != NULL)
                CorrePilhaAux = CorrePilhaAux->prox;
            CorrePilhaAux->prox = Pos;
            Ant->prox = PilhaAux->prox;         //Junta as Pilhas;
        }
        else
        {
            Pos->prox = PilhaAux->prox;         //Junta as Pilhas;
        }
    }
    else
        printf("Pilha de Processos vazia!\n");
    Clock_OrganizaPorNome = clock() - Clock_OrganizaPorNome + Clock_Pause;
}

void ApagarID(Processo *Pilha)                          //Apaga um processo com o ID informado.
{
    Clock_ApagaID=0;
    float Clock_Pause=0;
    Clock_Pause = clock();

	Processo *Pos = Pilha->prox;
	Processo *Ant = Pilha;
	Processo *LiberaNo = Pilha;
    int ApagarEsteID;

    printf("Informe o ID do Processo que deseja excluir da Pilha: ");
    Clock_Pause = clock() - Clock_Pause;    // Pausa a contagem do tempo para esperar o scanf.
    scanf("%d", &ApagarEsteID);
    Clock_ApagaID = clock();
    if(Pilha->prox != NULL)
    {
        while(Pos->prox != NULL)            //Percorre a Pilha Principal at� o ultimo elemento apontar para NULL. Ou seja, ele compara at� o penultimo �tem,
        {
            if(ApagarEsteID != Pos->ID)      // Se entrar aqui � pq � diferente, ent�o avan�a os n�s da Pilha principal.
            {
                Ant = Ant->prox;
                Pos = Pos->prox;
            }
            else                            //Entrando aqui � pq � Igual, ent�o ele ir� passar o novo elemento para a pilhaaux e retirar da Pilha Principal.
            {
                Pos = Pos->prox;
                LiberaNo = Ant->prox;
                Ant->prox = Pos;
                free(LiberaNo);
                QuantidadeProcessos--;
                printf("Processo '%d' excluido com sucesso!\n",ApagarEsteID);
                Clock_ApagaID = clock() - Clock_ApagaID + Clock_Pause;
                return;
            }
        }
        if(ApagarEsteID == Pos->ID)     // Verifica se o No procurado � o ultimo
        {
            LiberaNo = Pos;
            Ant->prox = NULL;
            free(LiberaNo);
            Pos = Ant;
            QuantidadeProcessos--;
            printf("Processo '%d' excluido com sucesso!\n",ApagarEsteID);
            Clock_ApagaID = clock() - Clock_ApagaID + Clock_Pause;
            return;
        }
    }
    printf("O Processo solicitado nao existe.\n");
    Clock_ApagaID = clock() - Clock_ApagaID + Clock_Pause;
}

void Apagar(Processo *Pilha)                            //Apaga um n� da pilha. O ultimo elemento inserido.
{
    Clock_Apaga = 0;
    Clock_Apaga = clock();
	Processo *ult=NULL, *pnult=NULL;

	if(Pilha->prox == NULL)
	{
		printf("Pilha vazia\n\n");
        Clock_Apaga = clock() - Clock_Apaga;
		return;
	}
	else
	{
		ult = Pilha->prox;
	    pnult = Pilha;

		while(ult->prox != NULL)
		{
			pnult = ult;
			ult = ult->prox;
		}

		pnult->prox = NULL;
		QuantidadeProcessos--;
		printf("Processo ID: %d retirado. \n\n", ult->ID);
		free(ult);
	}
	Clock_Apaga = clock() - Clock_Apaga;
}
