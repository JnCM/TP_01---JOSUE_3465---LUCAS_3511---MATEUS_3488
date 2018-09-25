#ifndef TADMATRIZVOOS_H_INCLUDED
#define TADMATRIZVOOS_H_INCLUDED

#include "TADITEMMATRIZ.h"
#include "LISTAVIDS.h"

typedef struct{
    ItemMatriz **Matriz;//Notação para utilizar a alocação dinâmica de matrizes (ponteiro para ponteiro)
    char Data[100];
    int NumTotVoos;
    char HAtualizacao[6];
}TipoMatriz;

//Cabeçalho das funções que serão utilizadas
void InicializaMatrizDinamica(TipoMatriz *MatrizVoos);
void InicializaMatriz(TipoMatriz *MatrizVoos);
void InserirVoo(TipoMatriz *MatrizVoos, TipoVoo Voo);
void RemoveVoo(TipoMatriz *MatrizVoos, int ID);
void Procura(TipoMatriz *MatrizVoos, int vID);
void ImprimeVooEspecifico(TipoMatriz MatrizVoos, char *HD, char *HP);
void ImprimeVooHoraD(TipoMatriz MatrizVoos, char *HD);
void ImprimeVooHoraP(TipoMatriz MatrizVoos, char *HP);
void ImprimeMatriz(TipoMatriz MatrizVoos);
void EncontraMaiorNumVoos(TipoMatriz MatrizVoos);
void EncontraMenorNumVoos(TipoMatriz MatrizVoos);
void EncontraMaiorHoraA(TipoMatriz MatrizVoos);
void EncontraMenorHoraA(TipoMatriz MatrizVoos);
void MatrizEsparca(TipoMatriz MatrizVoos);
#endif // TADMATRIZVOOS_H_INCLUDED
