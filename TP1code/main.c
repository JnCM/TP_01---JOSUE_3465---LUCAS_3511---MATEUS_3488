/*
CABEÇALHO TRABALHO PRÁTICO 1

NOMES-MATRÍCULAS:

Josué Nunes - 3465
Lucas Barros - 3511
Mateus Coelho - 3488
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADMATRIZVOOS.h"

int main(){
    char Caracter, Hora_Decolagem[6], Hora_Pouso[6], Aero_Decolagem[4], Aero_Pouso[4], Arquivo[100], VID[5], str[25];
    int Num_Pista, ID, Verifica_Entrada, j, i, var, tam;
    TipoVoo voo;
    TipoListaVID listaID;
    TipoMatriz Dados;
    FListaVID(&listaID);

    //MENU PARA SELEÇÃO DA FUNÇÃO QUE SERÁ EXECUTADA
    printf(" ********************************* // MENU \\ *****************************************\n");
	printf(" *                                                                                   *\n");
	printf(" * 1 - Entrada do Teclado                                                            *\n");
	printf(" * 2 - Entrada por Arquivo                                                           *\n");
	printf(" * a - Iniciar Nova Lista de Voos                                                    *\n");
	printf(" * b - Inserir Voo                                                                   *\n");
	printf(" * c - Remover Voo                                                                   *\n");
	printf(" * d - Procurar Voo                                                                  *\n");
	printf(" * e - Imprimir Voos - <De acordo com Horario de Decolagem e de Pouso>               *\n");
	printf(" * f - Imprimir Voos - <De acordo com Horario de Decolagem>                          *\n");
	printf(" * g - Imprimir Voos - <De acordo com Horario de Pouso>                              *\n");
	printf(" * h - Imprimir Todos os Voos                                                        *\n");
	printf(" * i - Encontrar Faixa de Horario de Decolagem e Pouso com Mais Voos Cadastrados     *\n");
	printf(" * j - Encontrar Faixa de Horario de Decolagem e Pouso com Menos Voos Cadastrados    *\n");
	printf(" * k - Encontrar Ultima Atualizacao do Sistema                                       *\n");
	printf(" * l - Encontrar Atualizacao Mais Antiga                                             *\n");
	printf(" * m - Verificar se a Matriz e Esparca                                               *\n");
    printf(" * 0 - Termina o Programa                                                            *\n");
	printf(" *                                                                                   *\n");
	printf(" *************************************************************************************\n");
	printf("Digite o Tipo de Entrada:\n");//VERIFICANDO SE A ENTRADA SERÁ POR ARQUIVO, OU SE SERÁ MANUAL
	scanf("%d", &Verifica_Entrada);
	printf("--------------------------------------------------------------------------------\n");
	if(Verifica_Entrada == 1){
        do{//ENTRA AQUI SE A ENTRADA FOR MANUAL
            printf("Digite a Operacao a ser Realizada:\n");
            fflush(stdin);
            scanf("%c", &Caracter);//RECEBENDO O COMANDO PARA FAZER UMA FUNÇÃO LISTADA NO MENU
            if(Caracter == 'a'){
                InicializaMatriz(&Dados);//CHAMA FUNÇÃO PARA INICIALIZAR A MATRIZ
                printf("Matriz de Voos Inicializada com Sucesso!\n");
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'b'){
                printf("Digite os Dados do Voo:\n");
                scanf("%s %s %s %s %d", Hora_Decolagem, Hora_Pouso, Aero_Decolagem, Aero_Pouso, &Num_Pista);
                ID = rand()%10000;
// FUNÇÃO RAND SERÁ UTILIZADA PARA QUE UM NÚMERO ALEATÓRIO SEJA GERADO PARA SER O IDENTIFICADOR DO VOO
                var = ComparaVID(&listaID, ID);
                if(var == 1){
                    ID = rand()%10000;
                    var = ComparaVID(&listaID, ID);
                }
//AS FUNÇÕES A SEGUIR SÃO CHAMADOS PARA SALVAR E INSERIR OS DADOS DO VOO NO VOO, E O VOO NA LISTA DE VOOS
                SetVID(&voo, ID);
                SetHoraDeco(&voo, Hora_Decolagem);
                SetHoraPouso(&voo, Hora_Pouso);
                SetAeroDeco(&voo, Aero_Decolagem);
                SetAeroPouso(&voo, Aero_Pouso);
                SetNpista(&voo, Num_Pista);
                InserirVoo(&Dados, voo);
                printf("VID do Voo Inserido: %d\n", ID);
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'c'){
                printf("Digite o VID do Voo a ser Removido:\n");
                scanf("%d", &ID);
//ESSA FUNÇÃO É CHAMADA PARA REMOVER A CÉLULA EM QUE O IDENTIFICADOR DE VOO FOR O DIGITADO
                RemoveVoo(&Dados, ID);
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'd'){
                printf("Digite o VID do Voo a ser Procurado:\n");
                scanf("%d", &ID);
//ESTA FUNÇÃO IRÁ PROCURAR UMA CÉLULA DA LISTA DE ACORDO COM O IDENTIFICADOR DE VOO DE TAL VOO
                Procura(&Dados, ID);
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'e'){
                printf("Digite a Faixa de Horario de Decolagem e Pouso que deseja Imprimir:\n");
                scanf("%s %s", Hora_Decolagem, Hora_Pouso);
//A FUNÇÃO A SEGUIR IMPRIME TODOS OS VOOS QUE ESTÃO DENTRO DA FAIXA DE HORÁRIO DE DECOLAGEM E DE POUSO DIGITADOS PELO USUÁRIO
                ImprimeVooEspecifico(Dados, Hora_Decolagem, Hora_Pouso);
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'f'){
                printf("Digite a Faixa de Horario de Decolagem que deseja Imprimir:\n");
                scanf("%s", Hora_Decolagem);
//ESTA FUNÇÃO IRÁ IMPRIMIR TODOS OS VOOS QUE POSSUEM O HORÁRIO DE DECOLAGEM IGUAL AO DIGITADO PELO USUÁRIO
                ImprimeVooHoraD(Dados, Hora_Decolagem);
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'g'){
                printf("Digite a Faixa de Horario de Pouso que deseja Imprimir:\n");
                scanf("%s", Hora_Pouso);
//ESTA FUNÇÃO IRÁ IMPRIMIR TODOS OS VOOS QUE POSSUEM O HORÁRIO DE POUSO IGUAL AO DIGITADO PELO USUÁRIO
                ImprimeVooHoraP(Dados, Hora_Pouso);
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'h'){
                printf("Imprimindo Toda a Matriz de Voos:\n");
                ImprimeMatriz(Dados);//A MATRIZ SERÁ IMPRESSA POR COMPLETO
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'i'){
//ENCONTRA QUAL HORÁRIO DE DECOLAGEM E DE POUSO QUE POSSUI O MAIOR NÚMERO DE VOOS CADASTRADOS
                EncontraMaiorNumVoos(Dados);
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'j'){
//ENCONTRA QUAL HORÁRIO DE DECOLAGEM E DE POUSO QUE POSSUI O MENOR NÚMERO DE VOOS CADASTRADOS
                EncontraMenorNumVoos(Dados);
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'k'){
//ESTA FUNÇÃO ENCONTRA A ATUALIZAÇÃO MAIS RECENTE DA LISTA
                EncontraMaiorHoraA(Dados);
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'l'){
//ESTA FUNÇÃO ENCONTRA A ATUALIZAÇÃO MAIS ANTIGA DA LISTA
                EncontraMenorHoraA(Dados);
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'm'){
//ESTA FUNÇÃO VERIFICA SE A MATRIZ É ESPARÇA
                MatrizEsparca(Dados);
                printf("--------------------------------------------------------------------------------\n");
            }
        //O PROGRAMA IRÁ PARAR SE O USUÁRIO DIGITAR "0" NA HORA DE ESCOLHER UMA FUNÇÃO
        }while(Caracter != '0');
	}
	else if(Verifica_Entrada == 2){
    //AS FUNÇÕES QUE SERÃO EXECUTADAS UTILIZAM O MESMO PRINCÍPIO DAS DIGITADAS
        printf("Digite o nome do Arquivo com a Extensao:\n");
        scanf("%s", Arquivo);
        printf("--------------------------------------------------------------------------------\n");
        FILE *Arq;
        Arq = fopen(Arquivo, "r");//ABRINDO ARQUIVO DIGITADO PARA LEITURA DE DADOS
        while(!feof(Arq)){
            fgets(str, 24, Arq);//A VARIAVEL "str" IRÁ RECEBER A LINHA DO ARQUIVO
            printf("%s\n", str);
            Caracter = str[0];//"Caracter" REPRESENTA A ESCOLHA DA FUNÇÃO A SER EXECUTADA
            if(Caracter == 'a'){
                InicializaMatriz(&Dados);
                printf("Matriz de Voos Inicializada com Sucesso!\n");
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'b'){
                j = 0;
                for(i=2; i<=6; i++){//A HORA DE DECOLAGEM É CORRESPONDENTE NO ARQUIVO DA POSIÇÃO 2 ATÉ A POSIÇÃO 6
                    Hora_Decolagem[j] = str[i];
                    j++;
                }
                Hora_Decolagem[5] = '\0';
                SetHoraDeco(&voo, Hora_Decolagem);
                j = 0;
                for(i=8; i<=12; i++){//A HORA DE POUSO É CORRESPONDENTE NO ARQUIVO DA POSIÇÃO 8 ATÉ A POSIÇÃO 12
                    Hora_Pouso[j] = str[i];
                    j++;
                }
                Hora_Pouso[5] = '\0';
                SetHoraPouso(&voo, Hora_Pouso);
                j = 0;
                for(i=14; i<=16; i++){//O AEROPORTO DE DECOLAGEM É CORRESPONDENTE NO ARQUIVO DA POSIÇÃO 14 ATÉ A POSIÇÃO 16
                    Aero_Decolagem[j] = str[i];
                    j++;
                }
                Aero_Decolagem[j] = '\0';
                SetAeroDeco(&voo, Aero_Decolagem);
                j = 0;
                for(i=18; i<=20; i++){//O AEROPORTO DE POUSO É CORRESPONDENTE NO ARQUIVO DA POSIÇÃO 18 ATÉ A POSIÇÃO 20
                    Aero_Pouso[j] = str[i];
                    j++;
                }
                Aero_Pouso[j] = '\0';
                SetAeroPouso(&voo, Aero_Pouso);
                Num_Pista = ((int)str[22])-48;//O NÚMERO DA PISTA É CORRESPONDENTE NO ARQUIVO A POSIÇÃO 22
                /*FOI FEITA A CONVERSÃO DO CARACTERE PARA INTEIRO
                MAS DESTA FORMA, FOI UTILIZADA A TABELA ASCII, E NELA, UM DÍGITO É O PRÓPRIO NÚMERO MAIS 48*/
                SetNpista(&voo, Num_Pista);
                ID = rand()%10000;
                //UTILIZAMOS A FUNÇÃO "rand" PARA GERAR NÚMEROS ALEATÓRIOS PARA SEREM OS VALORES DO IDENTIFICADOR
                var = ComparaVID(&listaID, ID);
                if(var == 1){
                    ID = rand()%10000;
                    var = ComparaVID(&listaID, ID);
                }
                SetVID(&voo, ID);
                InserirVoo(&Dados, voo);
                printf("VID do Voo Inserido: %d\n", ID);
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'c'){
            //UM VOO SERÁ REMOVIDO DA LISTA PELO SEU IDENTIFICADOR, QUE ESTÁ NA COLUNA 2 E 3 DA LINHA DO ARQUIVO
                j=0;
				for(i=2; i<=5; i++){
                    if(str[i] == '\n'){
                        break;
                    }
                    VID[j] = str[i];
                    j++;
				}
				tam = j;
				VID[tam] = '\0';
				if(VID[1] == '\0'){
                    ID = (((int)VID[0])-48);
				}
				else if(VID[2] == '\0'){
                    ID = ((((int)VID[0])-48)*10)+(((int)VID[1])-48);
				}
				else if(VID[3] == '\0'){
                    ID = ((((int)VID[0])-48)*100)+((((int)VID[1])-48)*10)+(((int)VID[2])-48);
				}
				else{
                    ID = ((((int)VID[0])-48)*1000)+((((int)VID[1])-48)*100)+((((int)VID[2])-48)*10)+(((int)VID[3])-48);
				}
//SERÁ FEITA A CONVERSÃO DOS NÚMEROS, QUE ESTÃO COMO CHAR, PARA O TIPO INT
//O NÚMERO DA TABELA ASCII É OBTIDO, SUBTRI-SE 48 DELE, PARA ACHAR O DÍGITO, E ENTÃO MULTIPLICA ESSE DIGITO POR 10, POIS ELE REPRESENTA A CASA DECIMAL DO IDENTIFICADOR
//O SEGUNDO NÚMERO TAMBÉM É CONVERTIDO, E SOMADO AO DIGITO ENCONTRADO, FICANDO ASSIM COMO A UNIDADE DO IDENTIFICADOR DO VOO
                RemoveVoo(&Dados, ID);
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'd'){
//É FEITO O MESMO PROCESSO DA FUNÇÃO REMOVE, MAS A FINALIDADE É OUTRA
//ESTA FUNÇÃO DEVE PROCURAR UM ITEM DA LISTA PELO SEU IDENTIFICADOR DE VOO
                j=0;
				for(i=2; i<=5; i++){
                    if(str[i] == '\n'){
                        break;
                    }
                    VID[j] = str[i];
                    j++;
				}
				tam = j;
				VID[tam] = '\0';
				if(VID[1] == '\0'){
                    ID = (((int)VID[0])-48);
				}
				else if(VID[2] == '\0'){
                    ID = ((((int)VID[0])-48)*10)+(((int)VID[1])-48);
				}
				else if(VID[3] == '\0'){
                    ID = ((((int)VID[0])-48)*100)+((((int)VID[1])-48)*10)+(((int)VID[2])-48);
				}
				else{
                    ID = ((((int)VID[0])-48)*1000)+((((int)VID[1])-48)*100)+((((int)VID[2])-48)*10)+(((int)VID[3])-48);
				}
                Procura(&Dados, ID);
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'e'){
//ESTA FUNÇÃO IMPRIME TODOS OS VOOS QUE POSSUEM HORÁRIO DE POUSO E DE DECOLAGEM IGUAIS AOS RECEBIDOS DO ARQUIVO
                j = 0;
				for(i=2; i<=6; i++){//"Hora_Decolagem" RECEBE O HORÁRIO DE DECOLAGEM DO VOO PELO ARQUIVO
					Hora_Decolagem[j] = str[i];
					j++;
				}
				Hora_Decolagem[5] = '\0';
				j = 0;
				for(i=8; i<=12; i++){//"Hora_Pouso" RECEBE O HORÁRIO DE POUSO DO VOO PELO ARQUIVO
					Hora_Pouso[j] = str[i];
					j++;
				}
				Hora_Pouso[5] = '\0';
                ImprimeVooEspecifico(Dados, Hora_Decolagem, Hora_Pouso);//CHAMA-SE A FUNÇÃO PARA IMPRIMIR VOOS
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'f'){
//ESTA FUNÇÃO IMPRIME TODOS OS VOOS QUE POSSUEM HORÁRIO DE DECOLAGEM IGUAIS AOS RECEBIDOS DO ARQUIVO
                j = 0;
				for(i=2; i<=6; i++){
					Hora_Decolagem[j] = str[i];
					j++;
				}
				Hora_Decolagem[5] = '\0';
                ImprimeVooHoraD(Dados, Hora_Decolagem);//CHAMA-SE A FUNÇÃO PARA IMPRIMIR VOOS
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'g'){
//ESTA FUNÇÃO IMPRIME TODOS OS VOOS QUE POSSUEM HORÁRIO DE POUSO IGUAIS AOS RECEBIDOS DO ARQUIVO
                j = 0;
				for(i=2; i<=6; i++){
					Hora_Pouso[j] = str[i];
					j++;
				}
				Hora_Pouso[5] = '\0';
                ImprimeVooHoraP(Dados, Hora_Pouso);//CHAMA-SE A FUNÇÃO PARA IMPRIMIR VOOS
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'h'){
                printf("Imprimindo Toda a Matriz de Voos:\n");
                ImprimeMatriz(Dados);//CHAMA-SE A FUNÇÃO PARA IMPRIMIR TODA A MATRIZ DE VOOS
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'i'){
//ESTA FUNÇÃO ENCONTRA QUAL HORÁRIO DE DECOLAGEM E DE POUSO QUE POSSUI O MAIOR NÚMERO DE VOOS CADASTRADOS
                EncontraMaiorNumVoos(Dados);
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'j'){
//ESTA FUNÇÃO ENCONTRA QUAL HORÁRIO DE DECOLAGEM E DE POUSO QUE POSSUI O MENOR NÚMERO DE VOOS CADASTRADOS
                EncontraMenorNumVoos(Dados);
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'k'){
//ESTA FUNÇÃO ENCONTRA A ATUALIZAÇÃO MAIS RECENTE DA LISTA
                EncontraMaiorHoraA(Dados);
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'l'){
//ESTA FUNÇÃO ENCONTRA A ATUALIZAÇÃO MAIS ANTIGA DA LISTA
                EncontraMenorHoraA(Dados);
                printf("--------------------------------------------------------------------------------\n");
            }
            else if(Caracter == 'm'){
                MatrizEsparca(Dados);//ESTA FUNÇÃO VERIFICA SE A MATRIZ É ESPARÇA
                printf("--------------------------------------------------------------------------------\n");
            }
        }
        fclose(Arq);//FECHANDO O ARQUIVO APÓS LEITURA
	}
    return 0;
}
