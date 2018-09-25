#ifndef TADLISTAVOOS_H_INCLUDED
#define TADLISTAVOOS_H_INCLUDED

#include "TADDADOSVOO.h"//Inclusão do cabeçalho TAD_Voo;

typedef struct TipoCelula *TipoApontador;//Renomeando um Ponteiro para o TipoCelula para TipoApontador;
//Motivo: Necessidade de usar dentro da própria struct TipoCelula;

//Criação da estrutura TipoCelula para armazenar as informações de um Voo e o Ponteiro para Próxima Célula;
typedef struct TipoCelula{
    TipoVoo Voo;//Variavel voo do tipo Voo;
    TipoApontador Prox;//Ponteiro prox do tipo Apontador;
}TipoCelula;

//Criação da estrutura TipoLista para armazenar os ponteiros para a Primeira e Última Célula;
typedef struct{
    TipoApontador Primeiro;//Ponteiro primeiro do tipo Apontador;
    TipoApontador Ultimo;//Ponteiro último do tipo Apontador;
    int ContaVoo;//variavel do tipo int para contar numero de voos em uma lista;
}TipoLista;

void InicializaLista(TipoLista *Lista);//inicializa a estrutura de dados, criando uma lista linear vazia;
int ConverteHoraD(TipoVoo Voo);//Conversão da hora de decolagem, pois a hora está no formato HH:MM de tipo char;
int ConverteMinD(TipoVoo Voo);//Conversão do minuto de decolagem, pois os minutos está no formato HH:MM de tipo char;
int ConverteHoraP(TipoVoo Voo);//Conversão da hora de pouso, pois a hora está no formato HH:MM de tipo char;
int ConverteHora(char *hora);//Conversão do horário de atualização, pois a hora está no formato HH:MM de tipo char;
int ConverteMin(char *mint);//Conversão do minuto de atualização, pois o minuto está no formato HH:MM de tipo char;
void Insere(TipoLista *Lista, TipoVoo x);//Insere um voo na lista(Antes do primeiro voo encontrado na lista com horário de decolagem maior ou igual ao dele);
int Remove(TipoLista *Lista, TipoVoo *y, int IdentVoo);//Remove um voo pelo Identficador e guardando-o para que possa ser utilizado;
int ProcuraVoo(TipoLista Lista, TipoVoo *z, int SearchVoo);//Procura um voo em específico a partir do VID e o guarda para utilização;
void ImprimeLista(TipoLista Lista);//Imprime toda a lista contendo todos os voos e suas respectivas informações;

#endif // TADLISTAVOOS_H_INCLUDED
