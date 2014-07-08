#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>




typedef struct proc
{
	int ID;
	char NomeCliente [50];
	char EnderecoCliente [50];
	char RGCliente [12];
	char TelefoneCliente [15];
	float ValorCheque;
	char DataCheque[11];
	char NomeMercado [31];
	struct proc *prox;
} Processo;



void Menu(Processo *Pilha);
void Inicializar(Processo *Pilha);
int teste_vazia(Processo *Pilha);
void ExibirProcessos(Processo *Pilha);
void libera(Processo *Pilha);
void EmpilharProcesso(Processo *Pilha);
void Apagar(Processo *Pilha);
void OrganizarUltimoProcesso(Processo *Pilha);
void OrganizaProcessoPorNomeMercado(Processo *Pilha);
void ApagarID(Processo *Pilha);
void ExibirID(Processo *Pilha);
void ExibirProximoProcesso(Processo *Pilha);
void ExibirUltimoProcesso(Processo *Pilha);
void ExibeNo(Processo *No);
