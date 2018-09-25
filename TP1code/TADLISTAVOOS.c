#include <stdio.h>
#include <stdlib.h>
#include "TADLISTAVOOS.h"

void InicializaLista(TipoLista *Lista){//Inicializa uma nova lista encadeada;
    Lista -> Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista -> Ultimo = Lista -> Primeiro;
    InicializaVoo(&(Lista -> Ultimo -> Voo));
    Lista -> Ultimo -> Prox = NULL;
    Lista -> ContaVoo = 0;
}
int ConverteHoraD(TipoVoo Voo){//Converte a hora recebida em string para int
    int Hora;
    int HD[2];
    HD[0] = ((int)Voo.HoraDecolagem[0]);
    HD[1] = ((int)Voo.HoraDecolagem[1]);
    Hora = ((HD[0]-48)*10)+(HD[1]-48);//Conversão de char para int(ASCII), e depois para decimal e unidade da hora
    return Hora;
}
int ConverteHoraP(TipoVoo Voo){//Converte a hora recebida em string para int
    int Hora;
    int HP[2];
    HP[0] = ((int)Voo.HoraPouso[0]);
    HP[1] = ((int)Voo.HoraPouso[1]);
    Hora = ((HP[0]-48)*10)+(HP[1]-48);//Conversão de char para int(ASCII), e depois para decimal e unidade da hora
    return Hora;
}
int ConverteHora(char *hora){//Converte a hora recebida em string para int
    int Hora;
    int H[2];
    H[0] = ((int)hora[0]);
    H[1] = ((int)hora[1]);
    Hora = ((H[0]-48)*10)+(H[1]-48);//Conversão de char para int(ASCII), e depois para decimal e unidade da hora
    return Hora;
}
int ConverteMin(char *mint){ //Converte o minuto recebido em string para int
    int Min;
    int M[2];
    M[0] = ((int)mint[3]);
    M[1] = ((int)mint[4]);
    Min = ((M[0]-48)*10)+(M[1]-48);//Conversão de char para int(ASCII), e depois para decimal e unidade do minuto
    return Min;
}
int ConverteMinD(TipoVoo Voo){//Converte o minuto recebido em string para int
    int Min;
    char m[2];
    m[0] = ((int)Voo.HoraDecolagem[3]);
    m[1] = ((int)Voo.HoraDecolagem[4]);
    Min = ((m[0]-48)*10)+(m[1]-48);//Conversão de char para int(ASCII), e depois para decimal e unidade do minuto
    return Min;
}
void Insere(TipoLista *Lista, TipoVoo x){//Função para inserir uma célula na lista
    TipoApontador suc = NULL;
    TipoApontador ant = NULL;
    TipoApontador aux = NULL;
    int H1, M1, H2, M2, cont = 0;
    if(Lista -> Ultimo == Lista -> Primeiro){//Verifica se a lista é vazia
        Lista -> ContaVoo = Lista -> ContaVoo + 1;//Contando o número de voos na lista a medida que adiciona e remove da mesma
        Lista -> Ultimo -> Prox = (TipoApontador)malloc(sizeof(TipoCelula));//Alocando espaço na memória para a célula
        Lista -> Ultimo = Lista -> Ultimo -> Prox;
        Lista -> Ultimo -> Voo = x;//Aqui a célula recebe os valores da entrada
        Lista -> Ultimo -> Prox = NULL;
    }
    else{//Aqui a lista é percorrida para encontrar onde a célula deve ser colocada, de acordo com o horário de decolagem do voo
        ant = Lista -> Primeiro;
        suc = Lista -> Primeiro;
        H1 = ConverteHoraD(x);
        M1 = ConverteMinD(x);
        while(suc -> Prox != NULL){//Só vai parar quando for a última posição, ou a célula ser inserida antes
            suc = suc -> Prox;
            H2 = ConverteHoraD(suc -> Voo);//Função para que possa converter de string para int, para então comparar horários
            M2 = ConverteMinD(suc -> Voo);
            if(H2 > H1){//Compara se o horário do voo a ser inserido com um voo já existente na lista
                Lista -> ContaVoo = Lista -> ContaVoo + 1;
                aux = (TipoApontador)malloc(sizeof(TipoCelula));//Voo será adicionado a lista
                aux -> Prox = suc;
                ant -> Prox = aux;
                aux -> Voo = x;
                cont ++;
                break;
            }
            else if(H2 == H1){
                if(M2 >= M1){//Se a hora dos voo forem iguais, o minuto de cada voo será comparado, para então alocar a célula
                    Lista -> ContaVoo = Lista -> ContaVoo + 1;
                    aux = (TipoApontador)malloc(sizeof(TipoCelula));
                    aux -> Prox = suc;
                    ant -> Prox = aux;
                    aux -> Voo = x;
                     cont ++;
                    break;
                }
            }
            ant = ant -> Prox;
        }//FIM WHILE
        if(cont == 0){//Se a célula tem o maior horário de voo que todas as outras, então ela é inserida na última posição
            aux = (TipoApontador)malloc(sizeof(TipoCelula));
            aux -> Voo = x;
            suc -> Prox = aux;
            Lista -> Ultimo = aux;
            Lista -> Ultimo -> Prox = NULL;
        }
    }
}
int Remove(TipoLista *Lista, TipoVoo *y, int IdentVoo){//Esta função irá ser usada para remover uma célula da lista de acordo com o identificador de voo
    TipoApontador temp = NULL;
    TipoApontador r = NULL;
    int cont = 0;
    temp = Lista -> Primeiro;
    r = Lista -> Primeiro;
    if(Lista->Primeiro==Lista->Ultimo){//Verifica se a lista é vazia
        return cont;
    }
    else{
        while(temp -> Prox != NULL){ //A lista será percorrida procurando o voo pelo seu identificador
            temp = temp -> Prox;
            if(temp -> Voo.VID == IdentVoo){//Ao encontrar o voo, ele é removido da lista
                cont = 1;
                Lista -> ContaVoo = Lista -> ContaVoo - 1;//Retira-se um do "ContaVoo" para que seja possível saber o número de células na lista sem precisar percorrer a mesma
                *y = temp -> Voo;
                r -> Prox = temp -> Prox;
                if(r -> Prox == NULL){
                    Lista -> Ultimo = r;
                    Lista -> Ultimo -> Prox = NULL;
                }
                free(temp);
                break;
            }
            r = r -> Prox;
        }
    }
//É retornado cont para saber se a célula foi ou não retirada, se cont = 1, então foi retirada, se cont = 0, não foi
    return cont;
}
int ProcuraVoo(TipoLista Lista, TipoVoo *z, int SearchVoo){
    TipoApontador q = NULL;
    int cont = 0;
    q = Lista.Primeiro;
    if(Lista.Primeiro==Lista.Ultimo){//Verifica se a lista é vazia
        return cont;
    }
    else{
            while(q -> Prox != NULL){//Percorre-se a lista a procura do voo com o identificador de voo recebido
            q = q -> Prox;
            if(q -> Voo.VID == SearchVoo){//Ao encontrar o voo, um ponteiro é usado para guardar seu endereço, para que esse voo possa ser usado futuramente
                *z = q -> Voo;
                cont = 1;
            }
            if(q -> Prox == NULL){
                break;
            }
        }
    }
    return cont;//É retornado cont para saber se a célula foi ou não encontrada, se cont = 1, então foi encontrada, se cont = 0, não foi
}
void ImprimeLista(TipoLista Lista){//Percorre-se a lista e chama a função para que ela seja mostrada na tela
    TipoApontador x;
    x = Lista.Primeiro -> Prox;
    while(x != NULL){
        ImprimeVoo(x -> Voo);
        printf("\n");
        x = x -> Prox;
    }
}
