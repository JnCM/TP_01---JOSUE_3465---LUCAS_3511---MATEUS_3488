#ifndef TADDADOSVOO_H_INCLUDED
#define TADDADOSVOO_H_INCLUDED

//Define o Tipo Abstrato de Dados - Voo;
typedef struct{
    int VID;//Identificador de Voo;
    char HoraDecolagem[6];//Hora de Decolagem do Voo;
    char HoraPouso[6];//Hora de Pouso do Voo;
    char AeroDecolagem[100];//Aeroporto de onde irá sair o voo;
    char AeroPouso[100];//Destino do voo;
    int Npista;//Numero da pista de decolagem e pouso;
}TipoVoo; //Estrutura de Dados Voo;

/* Hora de decolagem e pouso tem como característica, um vetor de 6 posições, pois o horário é dado no formato
     HH:MM (Horas:Minutos); */

//Cabeçalhos das operações do TAD Voo;
void InicializaVoo(TipoVoo *Voo);//Inicia os parâmetros do TAD_Voo com valor nulo;
int GetVID(TipoVoo Voo);//acessar Identificador para leitura;
void SetVID(TipoVoo *Voo, int NewID);//Cadastro ou alteração de um Identificador;
char *GetHoraDeco(TipoVoo *Voo);//acessar Horario de decolagem para leitura;
void SetHoraDeco(TipoVoo *Voo, char *NewHour);//Cadastro ou alteração de um Horario de decolagem;
char *GetHoraPouso(TipoVoo *Voo);//acessar Horario de pouso para leitura;
void SetHoraPouso(TipoVoo *Voo, char *NewHour2);//Cadastro ou alteração de um Horario de pouso;
char *GetAeroDeco(TipoVoo *Voo);//acessar Aeroporto de decolagem para leitura;
void SetAeroDeco(TipoVoo *Voo, char *NewAero);//Cadastro ou alteração de um Aeroporto de decolagem;
char *GetAeroPouso(TipoVoo *Voo);//acessar Aeroporto de chegada para leitura;
void SetAeroPouso(TipoVoo *Voo, char *NewAero2);//Cadastro ou alteração de um Aeroporto de chegada;
int GetNpista(TipoVoo Voo);//acessar Número da Pista para leitura;
void SetNpista(TipoVoo *Voo, int newNpista);//Cadastro ou alteração de um Número de Pista;
void ImprimeVoo(TipoVoo Voo);//Imprime um Voo cadastrado com todos os seus elementos;

#endif // TADDADOSVOO_H_INCLUDED
