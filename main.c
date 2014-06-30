#include <stdio.h>
#include <stdlib.h>

int ultimoID=0;

typedef struct proc 
{
	int ID;
	float ValorCheque;
	char DataCheque [9];
	char NomeMercado [31];
	char NomeCliente [31];
	char EnderecoCliente [51];
	char RGCliente [11];
	char TelefoneCliente [12];
	struct proc * prox;
} Processo;

void Inicializar(Processo *p);
void CriarProcesso(Processo *p);
void Empilhar(Processo *p);

int main()
{
	Processo *p = NULL;
	Inicializar(p);
	Empilhar(p);
  	system("PAUSE");	
  	return 0;
}

/*
COPIA:

void insereListaOrdenada(struct item **p0, int x)
{
	struct item *p, *pa = NULL, *corr = *p0;
	int cont = TRUE;
	p = (struct item *)malloc(sizeof(struct item));
	p->info = x;
	p->prox = NULL;
	while (corr != NULL && cont)
	{
		if (x < corr->info) cont = FALSE;
		else
		{
			pa = corr;
			corr = corr->prox;
		}
	}
	p->prox = corr;
	if (pa == NULL) *p0 = p;
	else pa->prox = p;
}*/


void Inicializar(Processo *p)
{
	p->prox = NULL;
} 

void CriarProcesso(Processo *p) 
{
	printf("Insira o nome do Estabelecimento: ");
	gets(p->NomeMercado);
	printf("Insira o valor do cheque: ");
	scanf("%d", &p->ValorCheque);
	printf("Insira a data do cheque: ");
	gets(p->DataCheque);
	printf("Insira o nome do Cliente: ");
	gets(p->NomeCliente);
	printf("Insira o RG do Cliente: ");
	gets(p->RGCliente);
	printf("Insira o endereço do Cliente: ");
	gets(p->EnderecoCliente);
	printf("Insira o telefone do Cliente: ");
	gets(p->TelefoneCliente);
	p->prox = NULL;
	p->ID = ultimoID++; 
}  


void Empilhar(Processo *p){

	Processo *pAnterior = NULL, *pPosterior = p;
	int AchaPosicao = 1; // 1 = Verdadeiro e 0 = Falso
	Processo *novo=(Processo*) malloc(sizeof(Processo));


/*	if(novo == NULL)
	{
		printf("Memoria insuficiente!\n");
		exit(1);
	}
	else
	{*/
		CriarProcesso(novo);
	
		while ((pPosterior != NULL) && (AchaPosicao == 1))
		{
			if (p->ValorCheque < pPosterior->ValorCheque) AchaPosicao = 0; //VOLTAR p ou Processo
			else
			{
				pAnterior = pPosterior;
				pPosterior = pPosterior->prox;
			}
		}
	//}      
}
