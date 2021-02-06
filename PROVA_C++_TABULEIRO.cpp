#include <iostream>
//#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <locale.h>
#include <windows.h>

#define PLAY1 1 /*REPRESENTAÇÃO DOS PLAYERS*/
#define PLAY2 2

using namespace std;

/*------------------------------------------*/ //FUNÇÕES
int tabuleiro_0(int *vet);
int tabuleiro_armadilhas(int *pet);
int dado_D6();
void moverNoTabuleiro1(int &posicao1, int &dado1_f, int &dado2_f, int &play1_aux, int *tabuleiro);
void tomarAntidoto1(int &contadorAntidoto, int &antidoto1, int &play1_aux);
void moverNoTabuleiro2(int &posicao2, int &dado1_f, int &dado2_f, int &play2_aux, int *tabuleiro);
void tomarAntidoto2(int &contadorAntidoto2, int &antidoto2, int &play2_aux);
/**/void SetColor(int ForgC);/**/
/*------------------------------------------*/ //FUNÇÕES

/**=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*/ //INICIO DO MAIN
main()
{
    srand(time(NULL));
    setlocale(LC_ALL,"");

    /*------------------------------------------*/ //VARIÁVEIS
    /*FILE *arqVarMover1;  /* guarda o valor de varMover1 se o contador já não for o inicial */
    /*FILE *arqVarMover2;  /* guarda o valor de varMover2 se o contador já não for o inicial */
    int tabuleiro[30];
    int i, contadorAntidoto1 = 0, contadorAntidoto2 = 0, contadorArmadilhasTeste = 0;
    string player1, player2; //NICKS DOS JOGADORES
    int antidoto1 = 3, antidoto2 = 3;
    int selec;
    int dado1_m, dado2_m;
    int play1_aux = 0, play2_aux = 0; //ESTADO DOS JOGADORES
    int posicao1 = 0, posicao2 = 0; //sem zero pegou (até agora)
    //int temp = 0;
    /*arqVarMover1 = fopen("varMover1.txt","r");
    arqVarMover2 = fopen("varMover2.txt","r");*/
    /*------------------------------------------*/ //VARIÁVEIS

    /*------------------------------------------*/ //TESTE: Tabuleiro: 0
    cout << "TESTE: Tabuleiro: 0" << endl;
    for(i = 0; i < 30; i++)
    {
        cout << tabuleiro_0(tabuleiro) << "\t";
    }
    /*------------------------------------------*/ //TESTE: Tabuleiro: 0
    cout << endl;
    /*------------------------------------------*/ //TESTE: Imprimindo tabuleiro
    cout << "TESTE: Imprimindo tabuleiro" << endl;
    for(i = 0; i < 30; i++)
    {
        cout << tabuleiro[i] << "\t";
    }
    /*------------------------------------------*/ //TESTE: Imprimindo tabuleiro
    cout << endl;
    /*------------------------------------------*/ //TESTE: GERANDO TABULEIRO
    cout << "TESTE: GERANDO TABULEIRO: " << endl;
    for(i = 0; i < 30; i++)
    {
        tabuleiro_armadilhas(tabuleiro);
    }
    /*------------------------------------------*/ //TESTE: GERANDO TABULEIRO
    cout << endl;
    /*------------------------------------------*/ //TESTE: Imprimindo tabuleiro (-1)
    cout << "TESTE: Imprimindo tabuleiro (-1)" << endl;
    for(i = 0; i < 30; i++)
    {
        cout << tabuleiro[i] << "\t";
        if (tabuleiro[i] == -1)
        {
            contadorArmadilhasTeste++;
        }
    }
    /*------------------------------------------*/ //TESTE: Imprimindo tabuleiro (-1)
    cout << endl;
    cout << "Nº de armadilhas: " << contadorArmadilhasTeste << endl; //TESTE: Verificando qtd de armadilhas
    cout << endl;

    cout << "Iniciando jogo";
    i = 0;
    while (i < 3)
    {
        Sleep(500);
        cout << " .";
        i++;
    }

    /*==============================================================*/
    /*                      INÍCIO DO JOGO                          */

    system("color 6F"); //8 //5 //70 +trabalho //6 mudar -1 //

    /*------------------------------------------*/
    //Possível tela inicial c/ system("pause")
    system("cls");
    /*------------------------------------------*/

    /*------------------------------------------*/ //ENTRADA DE NICKS
	cout << "Jogador 1, digite seu nick: ";
	SetColor(11); //0 //11
	cin >> player1;
	cout << endl;
	cout << player1;
	SetColor(15);
	cout << ", bem vindo ao jogo" << endl;
    cout << endl;

	cout << "----------------------------" << endl;

	cout << "Jogador 2, digite seu nick: ";
	SetColor(11); //0 //11
	cin >> player2;
	cout << endl;
	cout << player2;
	SetColor(15);
	cout << ", bem vindo ao jogo" << endl;
    cout << endl;

	cout << "----------------------------" << endl;

    cout << endl;
    SetColor(4);
	cout << player1 << " é o Jogador 1" << endl;
	cout << player2 << " é o Jogador 2" << endl;
	cout << endl << endl;
    /*------------------------------------------*/ //ENTRADA DE NICKS
    SetColor(12); //TESTE
	cout << "LET'S START THE GAME!!" << endl;
	SetColor(15);

	system("pause");
    system("cls");

    //while (((tabuleiro[29] != 1) && (tabuleiro[29] != 2)) || ((posicao1 < 30) || (posicao2 < 30)))
    //while ((posicao1 <= 30) || (posicao2 <= 30))
    while (1)
    {
        retorno_invalida1: //TESTE = OK!!!!!
        /*------------------------------------------*/ //Impressão do tabuleiro
        cout << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "TABULEIRO: " << endl;
        for(i = 0; i < 30; i++)
        {
            if (tabuleiro[i] == -1)
            {
                SetColor(4); //5 //4 //
                cout << "["<<tabuleiro[i] << "]"<< "\t";
                SetColor(15);
            }
            else if((tabuleiro[i] == PLAY1) || (tabuleiro[i] == PLAY2))
            {
                SetColor(9); //TESTE
                cout << "["<<tabuleiro[i] << "]"<< "\t";
                SetColor(15);
            }
            else
            {
                SetColor(15);
                cout << "["<<tabuleiro[i] << "]"<< "\t";
            }

        }
        cout << "-----------------------------------------------" << endl;
        cout << endl;
        /*------------------------------------------*/  //Impressão do tabuleiro

        /*------------------------------------------*/ //TURNO PLAYER1
        cout << player1 << ", sua vez" << endl << endl;
        cout << "•STATUS: " << endl;
        cout << "- Nº de Antidotos: " << antidoto1 << endl;
        if (play1_aux == 0)
        {
            SetColor(10);
            cout << "- Normal (não envenenado)" << endl;
            SetColor(15);
        }
        else if (play1_aux == -1)
        {
            SetColor(5);
            cout << "- ENVENENADO" << endl;
            SetColor(15);
        }
        cout << "- Sua posição: " << posicao1 << endl;

        cout << endl;

        cout << "1) Rolar dados\n"
             << "2) Tomar antídoto\n"
             << "3) Desistir"            << endl;
        cin >> selec;

        system("cls");

        if (selec == 3) //desistência
        {
            system("cls");
            cout << player1 << " desistiu!!!!!" << endl;
            cout << player2 << " venceu!!!!!!" << endl;
            break;
        }

        switch (selec)
        {
        case 1:
            dado1_m = dado_D6();
            dado2_m = dado_D6();

            cout << "Você rolou os dados e obteve: " << endl;
            cout << dado1_m << " " << dado2_m << endl << endl;

            /*if (play1_aux == -1) //ENVENENADO
            {
                moverNoTabuleiro1(posicao1, dado1_m, dado2_m, play1_aux, tabuleiro);
                if (dado1_m == dado2_m)
                {
                    cout << "VC FOI CURADO!!!!!" <<endl;
                }
                else if (dado1_m != dado2_m)
                {
                    cout << "Você volta: " << posicao1 << " casas." << endl;
                }
            }*/
            /*else if (play1_aux == 0) //NORMAL
            {
                cout << "Você anda: " << dado1_m + dado2_m << " casas." << endl;
                moverNoTabuleiro1(posicao1, dado1_m, dado2_m, play1_aux, tabuleiro);
            }*/

            /*posicao1 = moverNoTabuleiro1(posicao1, dado1_m, dado2_m, play1_aux, tabuleiro);
            play1_aux = moverNoTabuleiro1(posicao1, dado1_m, dado2_m, play1_aux, tabuleiro);*/
            moverNoTabuleiro1(posicao1, dado1_m, dado2_m, play1_aux, tabuleiro);
            //cout << "TESTE: imprimindo tabuleiro: " << endl;
            /*for(i = 0; i < 30; i++)
            {
                cout << tabuleiro[i] << "\t";
            }*/
            //cout << "dado1_m: " << dado1_m << endl;
            //cout << "dado2_m: " << dado2_m << endl;
            //cout << "play1_aux: " << play1_aux << endl; //TIRAR DEPOIS
            if (play1_aux == -1)
            {
                SetColor(5);
                cout << "VC ESTÁ ENVENENADO!!!!" << endl;
                SetColor(15);
            }
            else if (play1_aux == 0)
            {
                SetColor(10);
                cout << "SAFE!!!!" << endl;
                SetColor(15);
            }
            cout << "posicao1: " << posicao1 << endl;
            /*------------------------------------------*/

            /*------------------------------------------*/ //Impressão do tabuleiro
        cout << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "TABULEIRO: " << endl;
        for(i = 0; i < 30; i++)
        {
            if (tabuleiro[i] == -1)
            {
                SetColor(4); //5 //4 //
                cout << "["<<tabuleiro[i] << "]"<< "\t";
                SetColor(15);
            }
            else if((tabuleiro[i] == PLAY1) || (tabuleiro[i] == PLAY2))
            {
                SetColor(9); //TESTE
                cout << "["<<tabuleiro[i] << "]"<< "\t";
                SetColor(15);
            }
            else
            {
                SetColor(15);
                cout << "["<<tabuleiro[i] << "]"<< "\t";
            }

        }
        cout << "-----------------------------------------------" << endl;
        cout << endl;
        /*------------------------------------------*/  //Impressão do tabuleiro

            break;
        case 2:
            tomarAntidoto1(contadorAntidoto1, antidoto1, play1_aux); //OK!

            /*------------------------------------------*/ //Impressão do tabuleiro
        cout << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "TABULEIRO: " << endl;
        for(i = 0; i < 30; i++)
        {
            if (tabuleiro[i] == -1)
            {
                SetColor(4); //5 //4 //
                cout << "["<<tabuleiro[i] << "]"<< "\t";
                SetColor(15);
            }
            else if((tabuleiro[i] == PLAY1) || (tabuleiro[i] == PLAY2))
            {
                SetColor(9); //TESTE
                cout << "["<<tabuleiro[i] << "]"<< "\t";
                SetColor(15);
            }
            else
            {
                SetColor(15);
                cout << "["<<tabuleiro[i] << "]"<< "\t";
            }

        }
        cout << "-----------------------------------------------" << endl;
        cout << endl;
        /*------------------------------------------*/  //Impressão do tabuleiro
            break; //ISSO FICA AQUI
        default:
            cout << "Jogada inválida" << endl;
            system("pause");
            system("cls");
            goto retorno_invalida1;
        }

        /*------------------------------------------*/ //VERIFICAÇÃO DE VITÓRIA PLAYER1 (OK!!!!!!!!!!!)
        if (posicao1 >= 30)
        {
            tabuleiro[29] = PLAY1;
            system("cls");
            cout << player1 << " é o vencedor!!!!!" << endl;
            /*------------------------------------------*/ //Impressão do tabuleiro
        cout << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "TABULEIRO: " << endl;
        for(i = 0; i < 30; i++)
        {
            if (tabuleiro[i] == -1)
            {
                SetColor(4); //5 //4 //
                cout << "["<<tabuleiro[i] << "]"<< "\t";
                SetColor(15);
            }
            else if((tabuleiro[i] == PLAY1) || (tabuleiro[i] == PLAY2))
            {
                SetColor(9); //TESTE
                cout << "["<<tabuleiro[i] << "]"<< "\t";
                SetColor(15);
            }
            else
            {
                SetColor(15);
                cout << "["<<tabuleiro[i] << "]"<< "\t";
            }

        }
        cout << "-----------------------------------------------" << endl;
        cout << endl;
        /*------------------------------------------*/  //Impressão do tabuleiro
            break;

        }
        /*------------------------------------------*/ //VERIFICAÇÃO DE VITÓRIA PLAYER1 (OK!!!!!!!!!!!)

        /*------------------------------------------*/ //TURNO PLAYER1

        /*------------------------------------------*/ //INTER-JOGADOR
        cout << "Continuar...";
        system("pause>>NULL");
        system("cls");
        /*------------------------------------------*/ //INTER-JOGADOR

        /*------------------------------------------*/ //TURNO PLAYER2

        retorno_invalida2:
        /*------------------------------------------*/ //Impressão do tabuleiro
        cout << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "TABULEIRO: " << endl;
        for(i = 0; i < 30; i++)
        {
            if (tabuleiro[i] == -1)
            {
                SetColor(4); //5 //4 //
                cout << "["<<tabuleiro[i] << "]"<< "\t";
                SetColor(15);
            }
            else if((tabuleiro[i] == PLAY1) || (tabuleiro[i] == PLAY2))
            {
                SetColor(9); //TESTE
                cout << "["<<tabuleiro[i] << "]"<< "\t";
                SetColor(15);
            }
            else
            {
                SetColor(15);
                cout << "["<<tabuleiro[i] << "]"<< "\t";
            }

        }
        cout << "-----------------------------------------------" << endl;
        cout << endl;
        /*------------------------------------------*/  //Impressão do tabuleiro

        cout << player2 << ", sua vez" << endl << endl;
        cout << "•STATUS: " << endl;
        cout << "- Nº de Antidotos: " << antidoto2 << endl;
        if (play2_aux == 0)
        {
            SetColor(10);
            cout << "- Normal (não envenenado)" << endl;
            SetColor(15);
        }
        else if (play2_aux == -1)
        {
            SetColor(5);
            cout << "- ENVENENADO" << endl;
            SetColor(15);
        }
        cout << "- Sua posição: " << posicao2 << endl;

        cout << endl;

        cout << "1) Rolar dados\n"
             << "2) Tomar antídoto\n"
             << "3) Desistir"            << endl;
        cin >> selec;

        system("cls");

        if (selec == 3) //desistência
        {
            system("cls");
            cout << player2 << " desistiu!!!!!" << endl;
            cout << player1 << " venceu!!!!!!" << endl;
            break;
        }

        switch (selec)
        {
        case 1:
            dado1_m = dado_D6();
            dado2_m = dado_D6();

            cout << "Você rolou os dados e obteve: " << endl;
            cout << dado1_m << " " << dado2_m << endl << endl;

            /*if (play1_aux == -1) //ENVENENADO
            {
                moverNoTabuleiro1(posicao1, dado1_m, dado2_m, play1_aux, tabuleiro);
                if (dado1_m == dado2_m)
                {
                    cout << "VC FOI CURADO!!!!!" <<endl;
                }
                else if (dado1_m != dado2_m)
                {
                    cout << "Você volta: " << posicao1 << " casas." << endl;
                }
            }*/
            /*else if (play1_aux == 0) //NORMAL
            {
                cout << "Você anda: " << dado1_m + dado2_m << " casas." << endl;
                moverNoTabuleiro1(posicao1, dado1_m, dado2_m, play1_aux, tabuleiro);
            }*/

            /*posicao1 = moverNoTabuleiro1(posicao1, dado1_m, dado2_m, play1_aux, tabuleiro);
            play1_aux = moverNoTabuleiro1(posicao1, dado1_m, dado2_m, play1_aux, tabuleiro);*/
            moverNoTabuleiro2(posicao2, dado1_m, dado2_m, play2_aux, tabuleiro);
            //cout << "TESTE: imprimindo tabuleiro: " << endl;
            /*for(i = 0; i < 30; i++)
            {
                cout << tabuleiro[i] << "\t";
            }*/
            //cout << "dado1_m: " << dado1_m << endl;
            //cout << "dado2_m: " << dado2_m << endl;
            //cout << "play2_aux: " << play2_aux << endl;
            if (play2_aux == -1)
            {
                SetColor(5);
                cout << "VC ESTÁ ENVENENADO!!!!" << endl;
                SetColor(15);
            }
            else if (play2_aux == 0)
            {
                SetColor(10);
                cout << "SAFE!!!!" << endl;
                SetColor(15);
            }
            cout << "posicao2: " << posicao2 << endl;
            /*------------------------------------------*/

            /*------------------------------------------*/ //Impressão do tabuleiro
        cout << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "TABULEIRO: " << endl;
        for(i = 0; i < 30; i++)
        {
            if (tabuleiro[i] == -1)
            {
                SetColor(4); //5 //4 //
                cout << "["<<tabuleiro[i] << "]"<< "\t";
                SetColor(15);
            }
            else if((tabuleiro[i] == PLAY1) || (tabuleiro[i] == PLAY2))
            {
                SetColor(9); //TESTE
                cout << "["<<tabuleiro[i] << "]"<< "\t";
                SetColor(15);
            }
            else
            {
                SetColor(15);
                cout << "["<<tabuleiro[i] << "]"<< "\t";
            }

        }
        cout << "-----------------------------------------------" << endl;
        cout << endl;
        /*------------------------------------------*/  //Impressão do tabuleiro

            break;
        case 2:
            tomarAntidoto2(contadorAntidoto2, antidoto2, play2_aux); //OK!

            /*------------------------------------------*/ //Impressão do tabuleiro
        cout << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "TABULEIRO: " << endl;
        for(i = 0; i < 30; i++)
        {
            if (tabuleiro[i] == -1)
            {
                SetColor(4); //5 //4 //
                cout << "["<<tabuleiro[i] << "]"<< "\t";
                SetColor(15);
            }
            else if((tabuleiro[i] == PLAY1) || (tabuleiro[i] == PLAY2))
            {
                SetColor(9); //TESTE
                cout << "["<<tabuleiro[i] << "]"<< "\t";
                SetColor(15);
            }
            else
            {
                SetColor(15);
                cout << "["<<tabuleiro[i] << "]"<< "\t";
            }

        }
        cout << "-----------------------------------------------" << endl;
        cout << endl;
        /*------------------------------------------*/  //Impressão do tabuleiro

            break; //ISSO FICA AQUI
        default:
            cout << "Jogada inválida" << endl;
            system("pause");
            system("cls");
            goto retorno_invalida2;
        }

        /*------------------------------------------*/ //VERIFICAÇÃO DE VITÓRIA PLAYER2 (OK!!!!!!!!!!!)
        if (posicao2 >= 30)
        {
            tabuleiro[29] = PLAY2;
            system("cls");
            cout << player2 << " é o vencedor!!!!!" << endl;
            /*------------------------------------------*/ //Impressão do tabuleiro
        cout << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "TABULEIRO: " << endl;
        for(i = 0; i < 30; i++)
        {
            if (tabuleiro[i] == -1)
            {
                SetColor(4); //5 //4 //
                cout << "["<<tabuleiro[i] << "]"<< "\t";
                SetColor(15);
            }
            else if((tabuleiro[i] == PLAY1) || (tabuleiro[i] == PLAY2))
            {
                SetColor(9); //TESTE
                cout << "["<<tabuleiro[i] << "]"<< "\t";
                SetColor(15);
            }
            else
            {
                SetColor(15);
                cout << "["<<tabuleiro[i] << "]"<< "\t";
            }

        }
        cout << "-----------------------------------------------" << endl;
        cout << endl;
        /*------------------------------------------*/  //Impressão do tabuleiro
        break;

        }
        /*------------------------------------------*/ //VERIFICAÇÃO DE VITÓRIA PLAYER2 (OK!!!!!!!!!!!)

        /*------------------------------------------*/ //TURNO PLAYER2

        /*------------------------------------------*/ //INTER-JOGADOR
        cout << "Continuar...";
        system("pause>>NULL");
        system("cls");
        /*------------------------------------------*/ //INTER-JOGADOR
    }

    /*------------------------------------------*/ //CRÉDITOS
    cout << endl << endl;
    SetColor(4);
    cout << "by: André Severino e Felipe Garcia" << endl;
    cout << "EC2MA 2017" << endl;
    SetColor(15);
    cout << endl;
    /*------------------------------------------*/ //CRÉDITOS
    system("pause");
}
/**=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*/ //FIM DO MAIN

int tabuleiro_0(int *vet)
{
    int i;
    int varAux; //variável Auxiliar

    for(i = 0; i < 30; i++)
    {
        vet[i] = 0;
    }

    for(i = 0; i < 30; i++)
    {
        return vet[i];
    }
}

int tabuleiro_armadilhas(int *pet)
{
    int vetor_Aleatorio[10]; //vetor que recebe as casa aleatórias a receber -1
    int i = 0, j = 0;
    int varAux; //variável auxiliar

    for(i = 0; i < 30; i++)
    {
        pet[i] = 0;
    }

    for(i = 0; i < 10; i++) //ZERAR O VETOR PARA FZER A COMPARAÇÃO
    {
        vetor_Aleatorio[i] = 0;
    }
    /*--------------------------------*/
    for(i = 0; i < 10; i++)
    {
        vetor_Aleatorio[i] = 1 + (rand() % 29);
        for(j = 0; j < 10; j++)
        {
             if (i != j)
             {
                while (vetor_Aleatorio[i] == vetor_Aleatorio[j])
                {
                   vetor_Aleatorio[i] =  1 + (rand() % 29);
                }
             }
        }
        varAux = vetor_Aleatorio[i];
        pet[varAux] = -1;
        //cout << varAux << "\t" << vetor_Aleatorio[i]  << "\t" << i << "\t"<< pet[varAux] << endl;
    }

    /*------------------------------------------*/
    /*cout << "TESTE: vetor aleatório " << endl; //ESTÁ FUNCIONANDO
    for(i = 0; i < 10; i++)
    {
        cout << vetor_Aleatorio[i] << "\t";
    }*/
    /*------------------------------------------*/

    for(i = 0; i < 30; i++)
    {
        return pet[i];
    }
}

int dado_D6()
{
    int dado1, dado2;

    dado1 = 1 + (rand() % 5); /*PRECISA SER ALTERADO, POIS 0 E 0 BUGA O CÓDIGO*/
    dado2 = 1 + (rand() % 5);

    return dado1, dado2;
}

void moverNoTabuleiro1(int &posicao1, int &dado1_f, int &dado2_f, int &play1_aux, int *tabuleiro)
{
    int temp; //temporária
    /*temp: a posição que ele estava -1*/
    //int cont = 0; //contador

    /*------------------------------------------*/
    //if (temp == 0)
    //{

        //posicao1 = posicao1 - 1; //PARA IGUALAR COM O VETOR (TABULEIRO)
    //}
    /*else
    {
        posicao1 = posicao1 + (dado1_f + dado2_f) + 1; //+1 TÁ FORA
        //posicao1 = posicao1 - 1; //PARA IGUALAR COM O VETOR (TABULEIRO)
    }*/
    /*------------------------------------------*/

    if (posicao1 < 0)
    {
       posicao1 = 0;
       /*------------------------------------------*/ //NORMAL
    if (play1_aux == 0)
    {
        //if (posicao1 == 0)
        //{
            temp = posicao1;
        //}
        /*else
        {
            temp = posicao1 - 1;
        }*/

        posicao1 = posicao1 + (dado1_f + dado2_f); /*ORIGNAL*/

        if (tabuleiro[posicao1 - 1] == PLAY2) //só vou sabe rse estpa certo o -1 quando eu fizer turno do player2
        {
            posicao1 = posicao1 - 1;
        }
        cout << "Você anda: " << dado1_f + dado2_f << " casas." << endl;
        play1_aux = tabuleiro[posicao1 - 1];
        tabuleiro[posicao1 - 1] = PLAY1;
        cout << "Você vai pra casa " << posicao1 << "." << endl; //TESTANDO
        //if (cont != 0)
        //{
            tabuleiro[temp - 1] = 0;
            //cout << "temp: " << temp << endl; //TESTANDO
        //}
        //cont++;
    }
    /*------------------------------------------*/ //NORMAL

    /*------------------------------------------*/ //ENVENENADO
    else if (play1_aux == -1)
    {
        temp = posicao1;
        if (dado1_f == dado2_f) //DADOS DOBRADOS
        {
            play1_aux = 0;
            SetColor(10);
            cout << "VC FOI CURADO!!!" << endl;
            SetColor(15);
        }
        else if (dado1_f != dado2_f) //DADOS DIFERENTES
        {
            posicao1 = posicao1 - 2;
            if (tabuleiro[posicao1 - 1] == PLAY2)
            {
               posicao1 = posicao1 - 3;
               cout << "Você volta: 5 casas." << endl;
               tabuleiro[posicao1 - 1] = PLAY1;
            tabuleiro[temp - 1] = 0;
            cout << "Você vai pra casa " << posicao1 << "." << endl; //TESTANDO
            //cout << "temp: " << temp << endl; //TESTANDO
            }
            else
            {
                cout << "Você volta: 2 casas." << endl;
                tabuleiro[posicao1 - 1] = PLAY1;
            tabuleiro[temp - 1] = 0;
            cout << "Você vai pra casa " << posicao1 << "." << endl; //TESTANDO
            //cout << "temp: " << temp << endl; //TESTANDO
            }

            //ELE NÃO RECEBERÁ O STATUS DA CASA ATUAL, POIS ELE JÁ ESTÁ ENVENENADO

        }
    }
    /*------------------------------------------*/ //ENVENENADO
    //posicao1 = posicao1 + 1;
    }
    else
    {
    /*------------------------------------------*/ //NORMAL
    if (play1_aux == 0)
    {
        //if (posicao1 == 0)
        //{
            temp = posicao1;
        //}
        /*else
        {
            temp = posicao1 - 1;
        }*/

        posicao1 = posicao1 + (dado1_f + dado2_f); /*ORIGNAL*/

        if (tabuleiro[posicao1 - 1] == PLAY2) //só vou sabe rse estpa certo o -1 quando eu fizer turno do player2
        {
            posicao1 = posicao1 - 1;
        }
        cout << "Você anda: " << dado1_f + dado2_f << " casas." << endl;
        play1_aux = tabuleiro[posicao1 - 1];
        tabuleiro[posicao1 - 1] = PLAY1;
        cout << "Você vai pra casa " << posicao1 << "." << endl; //TESTANDO
        //if (cont != 0)
        //{
            tabuleiro[temp - 1] = 0;
            //cout << "temp: " << temp << endl; //TESTANDO
        //}
        //cont++;
    }
    /*------------------------------------------*/ //NORMAL

    /*------------------------------------------*/ //ENVENENADO
    else if (play1_aux == -1)
    {
        temp = posicao1;
        if (dado1_f == dado2_f) //DADOS DOBRADOS
        {
            play1_aux = 0;
            SetColor(10);
            cout << "VC FOI CURADO!!!" << endl;
            SetColor(15);
        }
        else if (dado1_f != dado2_f) //DADOS DIFERENTES
        {
            posicao1 = posicao1 - 2;
            if (tabuleiro[posicao1 - 1] == PLAY2)
            {
               posicao1 = posicao1 - 3;
               cout << "Você volta: 5 casas." << endl;
               tabuleiro[posicao1 - 1] = PLAY1;
            tabuleiro[temp - 1] = 0;
            cout << "Você vai pra casa " << posicao1 << "." << endl; //TESTANDO
            //cout << "temp: " << temp << endl; //TESTANDO
            }
            else
            {
                cout << "Você volta: 2 casas." << endl;
                tabuleiro[posicao1 - 1] = PLAY1;
            tabuleiro[temp - 1] = 0;
            cout << "Você vai pra casa " << posicao1 << "." << endl; //TESTANDO
            //cout << "temp: " << temp << endl; //TESTANDO
            }

            //ELE NÃO RECEBERÁ O STATUS DA CASA ATUAL, POIS ELE JÁ ESTÁ ENVENENADO

        }
    }
    /*------------------------------------------*/ //ENVENENADO
    //posicao1 = posicao1 + 1;
    }
}

void tomarAntidoto1(int &contadorAntidoto1, int &antidoto1, int &play1_aux) //OK!
{
    if (play1_aux == 0)
    {
        if (contadorAntidoto1 < 3)
            {
                antidoto1 = antidoto1 - 1;
                contadorAntidoto1++;
                play1_aux = 0;
                cout << "VC FOI CURADO!!!! (DE NADA)" << endl;
            }

                /*if (antidoto1 >= 0)
                {

                }*/
        else //if (antidoto1 < 0)
        {
                cout << "VC NÃO POSSUI MAIS ANTÍDOTOS!!!!" << endl;
        }
        //break;
    }
    else if (play1_aux == -1)
    {
        if (contadorAntidoto1 < 3)
            {
                antidoto1 = antidoto1 - 1;
                contadorAntidoto1++;
                play1_aux = 0;
                SetColor(10);
                cout << "VC FOI CURADO PELO ANTÍDOTO!!!!" << endl;
                SetColor(15);
            }

                /*if (antidoto1 >= 0)
                {

                }*/
        else //if (antidoto1 < 0)
        {
                cout << "VC NÃO POSSUI MAIS ANTÍDOTOS!!!!" << endl;
        }
        //break;
    }
}

void moverNoTabuleiro2(int &posicao2, int &dado1_f, int &dado2_f, int &play2_aux, int *tabuleiro)
{
    int temp; //temporária
    /*temp: a posição que ele estava -1*/
    //int cont = 0; //contador

    /*------------------------------------------*/
    //if (temp == 0)
    //{

        //posicao1 = posicao1 - 1; //PARA IGUALAR COM O VETOR (TABULEIRO)
    //}
    /*else
    {
        posicao1 = posicao1 + (dado1_f + dado2_f) + 1; //+1 TÁ FORA
        //posicao1 = posicao1 - 1; //PARA IGUALAR COM O VETOR (TABULEIRO)
    }*/
    /*------------------------------------------*/


    if (posicao2 < 0)
    {
       posicao2 = 1;
       /*------------------------------------------*/ //NORMAL
        if (play2_aux == 0)
        {
            //if (posicao1 == 0)
            //{
                temp = posicao2;
            //}
            /*else
            {
                temp = posicao1 - 1;
            }*/

            posicao2 = posicao2 + (dado1_f + dado2_f); /*ORIGNAL*/

            if (tabuleiro[posicao2 - 1] == PLAY1) //só vou sabe rse estpa certo o -1 quando eu fizer turno do player2
            {
                posicao2 = posicao2 - 1;
            }
            cout << "Você anda: " << dado1_f + dado2_f << " casas." << endl;
            play2_aux = tabuleiro[posicao2 - 1];
            tabuleiro[posicao2 - 1] = PLAY2;
            cout << "Você vai pra casa " << posicao2 << "." << endl; //TESTANDO
            //if (cont != 0)
            //{
                tabuleiro[temp - 1] = 0;
                //cout << "temp: " << temp << endl; //TESTANDO
            //}
            //cont++;
        }
        /*------------------------------------------*/ //NORMAL

        /*------------------------------------------*/ //ENVENENADO
        else if (play2_aux == -1)
        {
            temp = posicao2;
            if (dado1_f == dado2_f) //DADOS DOBRADOS
            {
                play2_aux = 0;
                SetColor(10);
                cout << "VC FOI CURADO!!!" << endl;
                SetColor(15);
            }
            else if (dado1_f != dado2_f) //DADOS DIFERENTES
            {
                posicao2 = posicao2 - 2;
                if (tabuleiro[posicao2 - 1] == PLAY1)
                {
                   posicao2 = posicao2 - 3;
                   cout << "Você volta: 5 casas." << endl;
                   tabuleiro[posicao2 - 1] = PLAY2;
                tabuleiro[temp - 1] = 0;
                cout << "Você vai pra casa " << posicao2 << "." << endl; //TESTANDO
                //cout << "temp: " << temp << endl; //TESTANDO
                }
                else
                {
                    cout << "Você volta: 2 casas." << endl;
                    tabuleiro[posicao2 - 1] = PLAY2;
                tabuleiro[temp - 1] = 0;
                cout << "Você vai pra casa " << posicao2 << "." << endl; //TESTANDO
                //cout << "temp: " << temp << endl; //TESTANDO
                }

                //ELE NÃO RECEBERÁ O STATUS DA CASA ATUAL, POIS ELE JÁ ESTÁ ENVENENADO

            }
        }
        /*------------------------------------------*/ //ENVENENADO
        //posicao1 = posicao1 + 1;
    }
    else
    {
        /*------------------------------------------*/ //NORMAL
        if (play2_aux == 0)
        {
            //if (posicao1 == 0)
            //{
                temp = posicao2;
            //}
            /*else
            {
                temp = posicao1 - 1;
            }*/

            posicao2 = posicao2 + (dado1_f + dado2_f); /*ORIGNAL*/

            if (tabuleiro[posicao2 - 1] == PLAY1) //só vou sabe rse estpa certo o -1 quando eu fizer turno do player2
            {
                posicao2 = posicao2 - 1;
            }
            cout << "Você anda: " << dado1_f + dado2_f << " casas." << endl;
            play2_aux = tabuleiro[posicao2 - 1];
            tabuleiro[posicao2 - 1] = PLAY2;
            cout << "Você vai pra casa " << posicao2 << "." << endl; //TESTANDO
            //if (cont != 0)
            //{
                tabuleiro[temp - 1] = 0;
                //cout << "temp: " << temp << endl; //TESTANDO
            //}
            //cont++;
        }
        /*------------------------------------------*/ //NORMAL

        /*------------------------------------------*/ //ENVENENADO
        else if (play2_aux == -1)
        {
            temp = posicao2;
            if (dado1_f == dado2_f) //DADOS DOBRADOS
            {
                play2_aux = 0;
                SetColor(10);
                cout << "VC FOI CURADO!!!" << endl;
                SetColor(15);
            }
            else if (dado1_f != dado2_f) //DADOS DIFERENTES
            {
                posicao2 = posicao2 - 2;
                if (tabuleiro[posicao2 - 1] == PLAY1)
                {
                   posicao2 = posicao2 - 3;
                   cout << "Você volta: 5 casas." << endl;
                   tabuleiro[posicao2 - 1] = PLAY2;
                tabuleiro[temp - 1] = 0;
                cout << "Você vai pra casa " << posicao2 << "." << endl; //TESTANDO
                //cout << "temp: " << temp << endl; //TESTANDO
                }
                else
                {
                    cout << "Você volta: 2 casas." << endl;
                    tabuleiro[posicao2 - 1] = PLAY2;
                tabuleiro[temp - 1] = 0;
                cout << "Você vai pra casa " << posicao2 << "." << endl; //TESTANDO
                //cout << "temp: " << temp << endl; //TESTANDO
                }

                //ELE NÃO RECEBERÁ O STATUS DA CASA ATUAL, POIS ELE JÁ ESTÁ ENVENENADO

            }
        }
        /*------------------------------------------*/ //ENVENENADO
        //posicao1 = posicao1 + 1;
    }
}

void tomarAntidoto2(int &contadorAntidoto2, int &antidoto2, int &play2_aux) //OK!
{
    if (play2_aux == 0)
    {
        if (contadorAntidoto2 < 3)
            {
                antidoto2 = antidoto2 - 1;
                contadorAntidoto2++;
                play2_aux = 0;
                cout << "VC FOI CURADO!!!! (DE NADA)" << endl;
            }

                /*if (antidoto1 >= 0)
                {

                }*/
        else //if (antidoto1 < 0)
        {
                cout << "VC NÃO POSSUI MAIS ANTÍDOTOS!!!!" << endl;
        }
        //break;
    }
    else if (play2_aux == -1)
    {
        if (contadorAntidoto2 < 3)
            {
                antidoto2 = antidoto2 - 1;
                contadorAntidoto2++;
                play2_aux = 0;
                SetColor(10);
                cout << "VC FOI CURADO PELO ANTÍDOTO!!!!" << endl;
                SetColor(15);
            }

                /*if (antidoto1 >= 0)
                {

                }*/
        else //if (antidoto1 < 0)
        {
                cout << "VC NÃO POSSUI MAIS ANTÍDOTOS!!!!" << endl;
        }
        //break;
    }
}
/*==============================================================================================================================================================*/
/**/void SetColor(int ForgC)
/**/ {
/**/WORD wColor;
/**/
/**/  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
/**/CONSOLE_SCREEN_BUFFER_INFO csbi;
/**/
/**/                       //We use csbi for the wAttributes word.
/**/ if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
/**/ {
/**/                 //Mask out all but the background attribute, and add in the forgournd color
/**/      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
/**/      SetConsoleTextAttribute(hStdOut, wColor);
/**/ }
/**/ return;
/**/}

/*  ***CORES***
Name         | Value
             |
Black        |   0
Blue         |   1
Green        |   2
Cyan         |   3
Red          |   4
Magenta      |   5
Brown        |   6
Light Gray   |   7
Dark Gray    |   8
Light Blue   |   9
Light Green  |   10
Light Cyan   |   11
Light Red    |   12
Light Magenta|   13
Yellow       |   14
White        |   15*/
