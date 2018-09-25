#ifndef LISTAVIDS_H_INCLUDED
#define LISTAVIDS_H_INCLUDED

typedef struct TCelula* TAponta;//Renomeando um Ponteiro para o TCelula para TAponta;
//Motivo: Necessidade de usar dentro da própria struct TCelula;

//Criação da estrutura TCelula para armazenar um VID e o Ponteiro para Próxima Célula;
typedef struct TCelula{
	int ID;//VID presente em uma célula;
	TAponta prox;//Ponteiro para proxima célula do tipo TAponta;
}TCelula;

//Criação da estrutura TipoListaVID para armazenar os ponteiros para a Primeira e Última Célula;
typedef struct{
	TAponta primeiro;//Ponteiro primeiro do tipo TAponta;
	TAponta ultimo;//Ponteiro último do tipo TAponta;
}TipoListaVID;

void FListaVID(TipoListaVID *vIDs);//inicializa a lista encadeada de VIDs, criando uma lista linear vazia;
void InsereVID(TipoListaVID *vIDs, int id);//Insere um VID não repetido ao final da lista encadeada;
int ComparaVID(TipoListaVID *vIDs, int ID);//Compara um VID com cada VID presente na lista para ver se é repetido ou não;

#endif // LISTAVIDS_H_INCLUDED
