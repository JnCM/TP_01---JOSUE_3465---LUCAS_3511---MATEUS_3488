#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TADMATRIZVOOS.h"

void InicializaMatrizDinamica(TipoMatriz *MatrizVoos){//Inicializa a alocação dinâmica da matriz
    	int i;
        MatrizVoos -> Matriz = (ItemMatriz **)malloc(576*sizeof(ItemMatriz));
        for(i=0; i<24; i++){
            MatrizVoos -> Matriz[i] = (ItemMatriz *)malloc(24*sizeof(ItemMatriz));
        }
}
void InicializaMatriz(TipoMatriz *MatrizVoos){//A matriz será incializada e todas suas posições vão ser colocadas como 0, null ou equivalente
    int i, j;
    InicializaMatrizDinamica(MatrizVoos);
    for(i=0; i<24; i++){
        for(j=0; j<24; j++){
            IniciaItemMatriz(&(MatrizVoos -> Matriz[i][j]));
        }
    }
    strcpy(MatrizVoos -> Data, "NULL");
    MatrizVoos -> NumTotVoos = 0;
    strcpy(MatrizVoos -> HAtualizacao, "00:00");
}
void InserirVoo(TipoMatriz *MatrizVoos, TipoVoo Voo){//Será inserido um voo a lista de um elemento da matriz
    int HoraD, HoraP, i, j;
    char HA[6];
    strcpy(HA, __TIME__);//Utilização do ___TIME___ para ter a hora do sistema, para assim ter a hora de atualização
	HA[5] = '\0';
//Conversão da hora de decolagem e de pouso, de string para inteiro, para saber em qual posição da matriz o voo será enviado
    HoraD = ConverteHoraD(Voo);
    HoraP = ConverteHoraP(Voo);
    for(i=0; i<24; i++){
        for(j=0; j<24; j++){
            if(i == HoraD && j == HoraP){
                SetLista(&(MatrizVoos -> Matriz[i][j]), Voo);//A lista do elemento da matriz irá receber o voo
                SetHoraAtua(&(MatrizVoos->Matriz[i][j]), HA);//Hora de atualização irá ser alterada no elemento da matriz
                printf("Voo Inserido com Sucesso!\n");
                break;
            }
        }
    }
}
void RemoveVoo(TipoMatriz *MatrizVoos, int ID){//Um voo será removido de acordo da lista de um elemento da matriz
    TipoVoo voo;
    int i, j, aux = 0, cont = 0;
    char HA[6];
	strcpy(HA, __TIME__);
	HA[5] = '\0';
    for(i=0; i<24; i++){
        for(j=0; j<24; j++){
            aux = Remove(&(MatrizVoos -> Matriz[i][j].lista), &voo, ID);//Remoção de um voo
            SetHoraAtua(&(MatrizVoos->Matriz[i][j]), HA);
            if(aux == 1){
                cont = 1;
                printf("Voo Removido com Sucesso!\n");
                ImprimeVoo(voo);//Imprime o voo removido
                break;
            }
        }
        if(aux == 1){
            break;
        }
    }
    if(cont == 0){
        printf("Esse Identificador de Voo nao existe!\n");//Caso não exista um voo com o identificador recebido, essa mensagem irá aparecer
    }
}
void Procura(TipoMatriz *MatrizVoos, int vID){//Um voo será procurado na matriz
    int i, j, aux = 0, cont = 0;
    TipoVoo voo;
    for(i=0; i<24; i++){
        for(j=0; j<24; j++){
//O voo está sendo procurado em cada lista de cada elemento da matriz até ser encontraado, ou até a matriz chegar ao fim
            aux = ProcuraVoo(MatrizVoos->Matriz[i][j].lista, &voo, vID);
            if(aux == 1){
                cont = 1;
                printf("Voo Achado!\n");
                ImprimeVoo(voo);
                break;
            }
        }
        if(aux == 1){
            break;
        }
    }
    if(cont == 0){//Caso não haja voo com tal identificador, essa mensagem será exibida
        printf("Esse Identificador de Voo nao existe!\n");
    }
}
void ImprimeVooEspecifico(TipoMatriz MatrizVoos, char *HD, char *HP){//Imprimir voo de acordo com sua hora de decolagem e de pouso
    int horad, horap, cont = 0;
    TipoLista TempLista;
    TipoApontador x;
    horad = ConverteHora(HD);
    horap = ConverteHora(HP);
//Para acessar diretamente a lista desejada, é utilizado como índice a hora de decolagem e a hora de pouso
    TempLista = GetLista(&(MatrizVoos.Matriz[horad][horap]));
    x = TempLista.Primeiro -> Prox;
    while(x != NULL){//Lista do elemento da matriz é percorrida para encontrar o voo desejado
        if(strcmp(x -> Voo.HoraDecolagem, HD)== 0 && strcmp(x -> Voo.HoraPouso, HP)== 0){
            printf("Voo Achado:\n\n");//Caso o horário de decolagem E o horário de pouso de voos sejam iguais aos da entrada, os voos serão exibidos
            ImprimeVoo(x -> Voo);
            printf("\n");
            cont ++;
        }
        x = x -> Prox;
    }
    if(cont == 0){
        printf("Nenhum Voo nessa Faixa de Horario!\n");
    }
}
void ImprimeVooHoraD(TipoMatriz MatrizVoos, char *HD){//Imprime os voos de acordo com o horário de decolagem
    int horad, j, cont = 0;
    TipoLista TempLista;
    TipoApontador x;
    horad = ConverteHora(HD);
    for(j=0; j<24; j++){
//Utiliza-se o "horad" para acessar a linha desejada, e então um for para fazer com que todas as listas dessa linha sejam utilizadas
        TempLista = GetLista(&(MatrizVoos.Matriz[horad][j]));
        x = TempLista.Primeiro -> Prox;
        while(x != NULL){
            ImprimeVoo(x -> Voo);//Todos os voos com o horário de decolagem correspondentes ao da entrada serão exibidos
            cont ++;
            printf("\n");
            x = x -> Prox;
        }
    }
    if(cont == 0){
        printf("Nenhum Voo nesse Horario!\n");
    }
}
void ImprimeVooHoraP(TipoMatriz MatrizVoos, char *HP){//Imprime os voos de acordo com o horário de decolagem
    int horap, i, cont = 0;
    TipoLista TempLista;
    TipoApontador x;
    horap = ConverteHora(HP);
    for(i=0; i<24; i++){
//Percorrer todas as linhas da matriz, usa-se o "horap" como índice da coluna, para pegar somente os elementos com aquele horário de pouso
        TempLista = GetLista(&(MatrizVoos.Matriz[i][horap]));
        x = TempLista.Primeiro -> Prox;
        while(x != NULL){
            ImprimeVoo(x -> Voo);//Todos os voos com o horário de pouso correspondentes ao da entrada serão exibidos
            cont ++;
            printf("\n");
            x = x -> Prox;
        }
    }
    if(cont == 0){
        printf("Nenhum Voo nesse Horario!\n");
    }
}
void ImprimeMatriz(TipoMatriz MatrizVoos){//Imprime todas as listas de voos da matriz
    TipoLista TempLista;
    int i, j;
    for(i=0; i<24; i++){
        for(j=0; j<24; j++){//Percorre todos os elementos
            TempLista = GetLista(&MatrizVoos.Matriz[i][j]);
            ImprimeLista(TempLista);//Imprime a lista da posição
            printf("\n");
        }
    }
}
void EncontraMaiorNumVoos(TipoMatriz MatrizVoos){//Encontra o elemento da matriz que possui mais voos
    int i, j, NumVoos, MaiorN, MaiorI, MaiorJ;
    for(i=0; i<24; i++){
        for(j=0; j<24; j++){
            SetNumVoos(&MatrizVoos.Matriz[i][j]);
            NumVoos = GetNumVoos(&MatrizVoos.Matriz[i][j]);//Recebendo o número de voos do elemento
            if(i == 0 && j == 0){//O primeiro elemento ([0][0]) será o parâmetro inicial de comparação para saber se o número de voos é maior ou não
                MaiorN = NumVoos;
                MaiorI = i;
                MaiorJ = j;
            }
//Comparação para verificar se na posição i, j, há mais voos que o anteriormente chamado de MaiorN
            if(NumVoos > MaiorN){
                MaiorN = NumVoos;
                MaiorI = i;
                MaiorJ = j;
            }//Se a condição for verdadeira, então o maior número será substituído, e os índices da matriz guardados
        }
    }
    printf("Maior Numero de Voos: %d\nFaixa de Horario:\nDecolagem: %d Horas\nPouso: %d Horas\n", MaiorN, MaiorI, MaiorJ);
}
void EncontraMenorNumVoos(TipoMatriz MatrizVoos){//Encontra o elemento da matriz que possui menos voos
    int i, j, NumVoos, MenorN, MenorI, MenorJ;
    for(i=0; i<24; i++){
        for(j=0; j<24; j++){
            SetNumVoos(&MatrizVoos.Matriz[i][j]);
            NumVoos = GetNumVoos(&MatrizVoos.Matriz[i][j]);//Recebendo o número de voos do elemento
            if(i == 0 && j == 0){//O primeiro elemento ([0][0]) será o parâmetro inicial de comparação para saber se o número de voos é menor ou não
                MenorN = NumVoos;
                MenorI = i;
                MenorJ = j;
            }
//Comparação para verificar se na posição i, j, há menos voos que o anteriormente chamado de MenorN
            if(NumVoos < MenorN){
                MenorN = NumVoos;
                MenorI = i;
                MenorJ = j;
            }//Se a condição for verdadeira, então o menor número será substituído, e os índices da matriz guardados
        }
    }
    printf("Menor Numero de Voos: %d\nFaixa de Horario:\nDecolagem: %d Horas\nPouso: %d Horas\n", MenorN, MenorI, MenorJ);
}
void EncontraMaiorHoraA(TipoMatriz MatrizVoos){//Encontra a última atualização da matriz
    int i, j, H1 = 0, H2 = 0, M1 = 0, M2 = 0, posI = 0, posJ = 0;
    char *HA, MaiorHR[6];
    for(i=0; i<24; i++){
        for(j=0; j<24; j++){
            HA = GetHoraAtua(&(MatrizVoos.Matriz[i][j]));
            H1 = ConverteHora(HA);
            M1 = ConverteMin(HA);
            if(i==0 && j == 0){//Primeiro termo como parâmetro inicial
                H2 = H1;
                M2 = M1;
                posI = i;
                posJ = j;
                strcpy(MaiorHR, HA);
            }
            if(H1 > H2){//Comparação para ver se a hora do termo é maior que o parâmetro H2
                H2 = H1;
                M2 = M1;
                posI = i;
                posJ = j;
                strcpy(MaiorHR, HA);
            }
            if(H1 == H2){//Se a hora for igual ao parâmetro, é comparado o minuto
                if(M1 > M2 || M1 == M2){
                    H2 = H1;
                    M2 = M1;
                    posI = i;
                    posJ = j;
                    strcpy(MaiorHR, HA);
                }
            }
        }
    }
    printf("Hora de Atualizacao mais recente: %s\nFaixa de Horario:\nDecolagem: %d Horas\nPouso: %d Horas\n", MaiorHR, posI, posJ);
}
void EncontraMenorHoraA(TipoMatriz MatrizVoos){//Encontra o elemento da matriz com atualização mais antiga
    int i, j, H1, H2, M1, M2, posI, posJ;
    char *HA, MenorHR[6];
    for(i=0; i<24; i++){
        for(j=0; j<24; j++){
            HA = GetHoraAtua(&(MatrizVoos.Matriz[i][j]));
            H1 = ConverteHora(HA);
            M1 = ConverteMin(HA);
            if(i==0 && j == 0){//Primeiro termo como parâmetro inicial
                H2 = H1;
                M2 = M1;
                posI = i;
                posJ = j;
                strcpy(MenorHR, HA);
            }
            else if(H1 < H2){//Comparação para ver se a hora do termo é menor que o parâmetro H2
                H2 = H1;
                M2 = M1;
                posI = i;
                posJ = j;
                strcpy(MenorHR, HA);
            }
            else if(H1 == H2){//Se a hora for igual ao parâmetro, é comparado o minuto
                if(M1 < M2 || M1 == M2){
                    H2 = H1;
                    M2 = M1;
                    posI = i;
                    posJ = j;
                    strcpy(MenorHR, HA);
                }
            }
        }
    }
    printf("Hora de Atualizacao menos recente: %s\nFaixa de Horario:\nDecolagem: %d Horas\nPouso: %d Horas\n", MenorHR, posI, posJ);
}

//Uma matriz esparça é aquela que suas posições vazias são duas vezes ou mais o número de posições preenchidas
void MatrizEsparca(TipoMatriz MatrizVoos){
    int i, j, ContaO = 0, ContaMais1 = 0;
    for(i=0; i<24; i++){
        for(j=0; j<24; j++){
            if(MatrizVoos.Matriz[i][j].NumVoos == 0){//Verifica se a posição é vazia
                ContaO ++;//Sim
            }
            else{
                ContaMais1 ++;//Não
            }
        }
    }
    if(ContaO >= 2*ContaMais1){//A comparação do número de posições vazias com as preenchidas
        printf("A Matriz e Esparca!\n");
    }
    else{
        printf("A Matriz nao e Esparca!\n");
    }
}
