#include <stdio.h>
#include <stdlib.h>
#define N 50

struct estacionamento
{
    int placa[N];
    int hora[N];
    int num;
};

int main()
{

    int n, x,r;
    int i, k,vet[N],vet2[N],aux;
    int escolha;
    int pl, h;
    int acu=0,confirma;




    printf("\nDIGITE O NUMERO DE PILHAS :");
    scanf("%i",&n);

    struct estacionamento fila[n];

    printf("\nDIGITE O NUMERO DE CARROS QUE CADA PILHA PODERA ALOCAR :");
    scanf("%i",&x);

    printf("\nDIGITE QUANTOS CARROS PODERÃO SER ALOCADOS NA RUA :");
    scanf("%i",&r);


    fila[0].num = 1; //primeira vaga da rua
    for(i=1; i<=r+1; i++)//fila[0] é a rua
    {
        fila[0].placa[fila[0].num] = 0;
        fila[0].hora[fila[0].num] = 0;
        fila[0].num++;
    }//inserindo todas as vagas zeradas

    for(i=1; i<=n+1; i++)
    {
        fila[i].num = 1;
    }

    for(i=1; i<=n; i++)
    {

        for(k=1; k<=x+1; k++)
        {
            fila[i].placa[k] = 0; // estacionamento
            fila[i].hora[k] = 0;
        }
    }// todas as vagas do estacionamento recebem 0


menu :
    acu=0;
    printf("\n ----------------- SITUACAO DO ESTACIONAMENTO ----------------- \n");
    for(i=1; i<=n; i++)
    {
        printf("\n pilha %i --> ",i);
        for(k=1; k<=x; k++)
        {
            printf("[placa %i / hora %i]   ",fila[i].placa[k],fila[i].hora[k]);
        }
        printf("\n");
    }
    printf("\n rua --> ");
    for(i=1; i<=r; i++)
    {
        printf("[placa %i / hora %i]    ",fila[0].placa[i],fila[0].hora[i]);
    }
    printf("\n <------------------------------------------------------------> \n");
    printf("\n O QUE DESEJA?\n 1 - ADICIONAR VEICULO\n 2 - RETIRAR VEICULO\n 3 - REORGANIZAR ESTACIONAMENTO\n 4 - FIM\n");

    scanf("%i",&escolha);

    switch ( escolha )
    {
    case 1 :

        printf("\n DIGITE A PLACA E A HORA DE PERMANENCIA NO ESTACIONAMENTO SEPARADAMENTE\n\n");
        scanf("%i %i", &pl, &h);

nova :
        acu=0;
        for(i=1; i<=x; i++)
        {

            for(k=1; k<=n; k++)
            {
                if(fila[k].hora[i]==0)
                {
                    if(fila[k].hora[i-1]<h && (i-1!=0)&&fila[k].hora[i-1]!=-1) {} //fica quietinho kkkk
                    else
                    {
                        fila[k].hora[i] = h;
                        fila[k].placa[i] = pl;
                        goto conf;
                    }
                }//procura a melhor posicao ou vai para rua
            }

        }

        for(i=1; i<=r; i++)
        {
            if(fila[0].hora[i]==0)
            {
                fila[0].hora[i] = h;    //aloca na rua
                fila[0].placa[i] = pl;
                acu++;
                goto conf;
            }
        }// a rua funciona como uma fila
        if(acu==0)//enfia em qualquer lugar disponivel
        {
            for(i=1; i<=x; i++)
            {

                for(k=1; k<=n; k++)
                {
                    if(fila[k].hora[i]==0)
                    {
                        fila[k].hora[i] = h;
                        fila[k].placa[i] = pl;
                        acu++;
                        goto conf;
                    }
                }

            }
            if(acu==0)
            {
                printf("\n\n\n ESTACIONAMENTO LOTADO!!!\nVEICULO NAO FOI ADICIONADO!\n");
            }
        }
conf :
        printf("\n ||||||||||||| POSSIVEL SITUACAO DO ESTACIONAMENTO ||||||||||||| \n");
        for(i=1; i<=n; i++)
        {
            printf("\n pilha %i --> ",i);
            for(k=1; k<=x; k++)
            {
                printf("[placa %i / hora %i]   ",fila[i].placa[k],fila[i].hora[k]);
            }
            printf("\n");
        }
        printf("\n rua --> ");
        for(i=1; i<=r; i++)
        {
            printf("[placa %i / hora %i]    ",fila[0].placa[i],fila[0].hora[i]);
        }
        printf("\n <--|||||||||||||||||||||||||||||||||||||||||||||||||||||--> \n");
        printf("\n DIGITE 0 CASO QUEIRA MUDAR A LOCALIZAÇAO DO VEICULO\n\nDIGITE 1 PARA CONFIRMAR\n");
        scanf("%i",&confirma);
        if(confirma == 0)
        {
            for(i=1; i<=x; i++)
            {

                for(k=0; k<=n; k++)
                {
                    if(fila[k].placa[i]==pl)
                    {
                        fila[k].hora[i] = -1;
                        fila[k].placa[i] = -1;
                    }
                }

            }

            goto nova ;

        }
        else
        {
            for(i=1; i<=x; i++)
            {

                for(k=0; k<=n; k++)
                {
                    if(fila[k].placa[i]==-1)
                    {
                        fila[k].hora[i] = 0;
                        fila[k].placa[i] = 0;
                    }
                }

            }
            goto menu ;
        }




        goto menu;
    case 2 :
        printf("\n DIGITE A PLACA DO VEICULO\n\n");
        scanf("%i", &pl);
        for(i=1; i<=x; i++)
        {

            for(k=0; k<=n; k++)
            {
                if(fila[k].placa[i]==pl)
                {
                    vet[fila[k].hora[i]]=0;
                    fila[k].hora[i] = 0;
                    fila[k].placa[i] = 0;
                }
            }

        }

        for(i=1; i<=x; i++)
        {

            for(k=0; k<=n; k++)
            {
                if(fila[k].placa[i-1]==0 && i-1!=0)
                {
                    fila[k].hora[i-1] = fila[k].hora[i];
                    fila[k].placa[i-1] = fila[k].placa[i];
                    fila[k].placa[i] = 0;
                    fila[k].hora[i] = 0;
                }
            }
        }

        for(i=1; i<=x; i++)
        {

            for(k=0; k<=n; k++)
            {
                if(fila[k].placa[i]== 0 ||fila[k].hora[i]==0)
                {
                    fila[k].hora[i] = 0;
                    fila[k].placa[i] = 0;
                }
            }

        }
        goto menu ;




        goto menu;
    case 3 :







        goto menu;
    case 4 :

      break;
    }



    return 0;
}
