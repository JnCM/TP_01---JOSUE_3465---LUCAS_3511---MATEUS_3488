#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADITEMMATRIZ.h"

void IniciaItemMatriz(ItemMatriz *DadoMatriz){//Inicializa um bloco da matriz (item matriz)
    InicializaLista(&(DadoMatriz -> lista));
    DadoMatriz -> NumVoos = 0;
    strcpy(DadoMatriz -> HoraAtualizacao, "00:00");
}
TipoLista GetLista(ItemMatriz *DadoMatriz){//Recebe a lista para ser parte do item
    TipoLista listgen;
    listgen = DadoMatriz -> lista;
    return listgen;
}
char *GetHoraAtua(ItemMatriz *DadoMatriz){//Hora de atualização do sistema em um elemento da matriz
    return DadoMatriz -> HoraAtualizacao;
}
int GetNumVoos(ItemMatriz *DadoMatriz){//Para saber o número de voos de cada elemento
    int NumberFly;
    NumberFly = DadoMatriz -> NumVoos;
    return NumberFly;
}
void SetLista(ItemMatriz *DadoMatriz, TipoVoo voo){//Utilizada para inserir um voo a lista do item matriz
    Insere(&(DadoMatriz -> lista), voo);
}
void SetHoraAtua(ItemMatriz *DadoMatriz, char *HourAtua){//Altera o horário de atualização de um elemento da matriz
    strcpy(DadoMatriz -> HoraAtualizacao, HourAtua);
}
void SetNumVoos(ItemMatriz *DadoMatriz){//Altera o número de voos de um elemento da matriz
    DadoMatriz -> NumVoos = DadoMatriz -> lista.ContaVoo;
}
void ImprimeItemMatriz(ItemMatriz DadoMatriz){//Utilizado para imprimir elementos da matriz
    TipoLista lista2;
    lista2 = GetLista(&DadoMatriz);
    ImprimeLista(lista2);
    printf("Hora de Atualizacao: %s\n", GetHoraAtua(&DadoMatriz));
    printf("Num de Voos: %d\n", GetNumVoos(&DadoMatriz));
}
