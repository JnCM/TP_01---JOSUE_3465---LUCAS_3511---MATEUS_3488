#ifndef TADITEMMATRIZ_H_INCLUDED
#define TADITEMMATRIZ_H_INCLUDED

#include "TADLISTAVOOS.h"

typedef struct{//No item da  matriz estarão presentes estes elementos
    TipoLista lista;
    char HoraAtualizacao[6];
    int NumVoos;
}ItemMatriz;

//Cabeçalhos das funções que serão utilizadas
void IniciaItemMatriz(ItemMatriz *DadoMatriz);
TipoLista GetLista(ItemMatriz *DadoMatriz);
char *GetHoraAtua(ItemMatriz *DadoMatriz);
int GetNumVoos(ItemMatriz *DadoMatriz);
void SetLista(ItemMatriz *DadoMatriz, TipoVoo voo);
void SetHoraAtua(ItemMatriz *DadoMatriz, char *HourAtua);
void SetNumVoos(ItemMatriz *DadoMatriz);
void ImprimeItemMatriz(ItemMatriz DadoMatriz);
#endif // TADITEMMATRIZ_H_INCLUDED
