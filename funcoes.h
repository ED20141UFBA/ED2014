#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>




typedef struct proc
{
	int ID;				// Cada nó só terá 1 único valor de ID, será gerado pela incrementação do inteiro GeraID
	char NomeCliente [50];
	char EnderecoCliente [50];
	char RGCliente [12];
	char TelefoneCliente [15];
	float ValorCheque;
	char DataCheque[11];
	char NomeMercado [31];
	struct proc *prox;		// Ponteiro para o próximo nó
} Processo;	



void Menu(Processo *Pilha);				// Menu
void Inicializar(Processo *Pilha);			// Inicializa a Pilha
int teste_vazia(Processo *Pilha);			// Verifica se a pilha está vazia
void ExibirProcessos(Processo *Pilha);			// Exibe todos os processos
void libera(Processo *Pilha);				// Limpa a pilha
void EmpilharProcesso(Processo *Pilha);			// Empilha
void Apagar(Processo *Pilha);				// Desempilha
void OrganizarUltimoProcesso(Processo *Pilha);		// A função EmpilharProcesso insere um processo sempre no topo da pilha, essa função remaneja para a posição correta.
void OrganizaProcessoPorNomeMercado(Processo *Pilha);	// Ordena todos os processos com o nome pesquisado para o topo da pilha
void ApagarID(Processo *Pilha);				// Apaga um processo
void ExibirID(Processo *Pilha);				// Imprime o ID pesquisado
void ExibirProximoProcesso(Processo *Pilha);		// Imprime o processo no topo.
void ExibirUltimoProcesso(Processo *Pilha);		// Imprime somente o processo na base da pilha
void ExibeNo(Processo *No);				// Imprime o processo passado.
