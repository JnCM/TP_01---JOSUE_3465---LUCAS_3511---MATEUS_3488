#include <stdio.h>
#include <stdlib.h>
#include "LISTAVIDS.h"//Inclusão do cabeçalho Lista_VIDs;

//Detalhamento das Operações da Lista_VID;
void FListaVID(TipoListaVID *vIDs){//Inicializa uma nova lista de VID;
	vIDs->primeiro = (TAponta)malloc(sizeof(TCelula));//Cria uma nova célula na lista;
	vIDs->ultimo = vIDs->primeiro;//Faz o ponteiro Último apontar para a mesma célula que Primeiro aponta;
	vIDs->ultimo->prox = NULL;//Faz o Ponteiro prox da Célula criada apontar para nulo;
}

void InsereVID(TipoListaVID *vIDs, int id){//Insere um novo elemento ao final da lista;
	vIDs->ultimo->prox = (TAponta)malloc(sizeof(TCelula));//Cria uma nova célula na lista;
	vIDs->ultimo = vIDs->ultimo->prox;//Faz o Ponteiro Último apontar para a nova última célula;
	vIDs->ultimo->ID = id;//Faz a atribuição do novo VID;
	vIDs->ultimo->prox = NULL;//Faz o Ponteiro prox da Célula criada apontar para nulo;
}

int ComparaVID(TipoListaVID *vIDs, int ID){//Compara um novo VID com cada VID existente na lista;
	int cont = 0;
	TAponta aux;//Criação do Ponteiro auxiliar para percorrer a lista;
	aux = vIDs->primeiro->prox;
	if(vIDs->primeiro==vIDs->ultimo){//Verificando se a lista é vazia;
		InsereVID(vIDs, ID);
	}
	else{
		while(aux != NULL){//Percorrendo a lista até o final;
			if(aux->ID == ID){//Caso o novo VID for igual a um já existente;
				cont ++;
				break;//Encerra o while;
			}
			aux = aux->prox;//Percorrendo a lista;
		}
		if(cont != 0){//Caso já haja esse VID na lista;
			return 1;//Retorna 1;
		}
		else{//Caso não haja esse VID na lista;
			InsereVID(vIDs, ID);
		}
	}
	return 0;//Retorna 0;
}
