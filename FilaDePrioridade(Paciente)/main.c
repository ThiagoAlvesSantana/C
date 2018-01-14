#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "filapri.h"
#include "paciente.h"
#include "medicos.h"
#include "atendimentos.h"
#define MAX 9999

//Variáveis estaticas para os valores padrões que serão usados dentro do programa.
static int VERMELHO = 0;
static int VERMELHO_MEDIA = 50;
static int VERMELHO_DESVIO_PADRAO = 10;
static int VERMELHO_TOLERANCIA = 0;
static int LARANJA = 1;
static int LARANJA_MEDIA = 20;
static int LARANJA_DESVIO_PADRAO = 5;
static int LARANJA_TOLERANCIA = 10;
static int AMARELO = 2;
static int AMARELO_MEDIA = 15;
static int AMARELO_DESVIO_PADRAO = 5;
static int AMARELO_TOLERANCIA = 20;
static int VERDE = 3;
static int VERDE_MEDIA = 8;
static int VERDE_DESVIO_PADRAO = 2;
static int VERDE_TOLERANCIA = 60;
static int AZUL = 4;
static int AZUL_MEDIA = 5;
static int AZUL_DESVIO_PADRAO = 5;
static int AZUL_TOLERANCIA = 180;

fpa f;
fpa_info x;
atendimento a[MAX];
pacientes p[MAX];
medicos med[MAX];
int qtdPacienteEspera = 0;
int qtPaciente = 0;

int main()
{
    fpa_init(&f);
    int n = 0,m = 0,t = 0, i = 0, j = 0, k = 0, l = 0;
    int cont = 0, cont1 = 0;
    char respostas [MAX];

    printf("*************************************************************************\n");
    printf("*\t\t\t\tHospital\t\t\t\t*\n");
    printf("*************************************************************************\n");

    printf("Entre com a quantidade de medicos: ");
    scanf("%d",&m);

    fflush(stdin);

    for(i = 0; i < m; i++)
    {
        printf("Entre com o nome do(s) medico(s): ");
        gets(med[i].medicos);
    }

    iniciaTempoMedico(&med, m);

    while(t != (-1))
    {
        printf("\nEntre com o tempo dos pacientes a chegar para atendimento: ");
        scanf("%d", &t);
        if(t != (-1))
        {
            printf("Entre com a quantidade de pacientes: ");
            scanf("%d",&n);

            for(i = 0; i < n; i++)
            {
                printf("QT = %d",j);
                if(p[qtPaciente].in_espera[i] != true)
                {
                    preencheFormulario(n,i,m,p);
                }
                else
                {
                    preencheFormulario(n,i,m,p);
                    qtdPacienteEspera++;
                }
                qtPaciente++;
            }

            for(i = 0; i < n; i++)
            {
                escolheTempoAtendimento(n, p,i);
            }
            //Subtrai os valores que estão no Heap referente ao instante.
            subtraiElementos(&f, m);
            //Remove do Heap o elemento quando for igual a 0.
            fpa_rem_min(&f);
        }
    }

    //Remove todos os elementos da lista, quando o sistema acabar de rodar.
    while(fpa_isempty(f) == false)
    {
        subtraiElementos(&f, m);
        fpa_rem_min(&f);
    }

    saida(n,qtdPacienteEspera, qtPaciente);
    return 0;
}

//Preenche o formulário e verifica a prioridade do paciente.
void preencheFormulario(int n, int i, int m)
{
    printf("TAMANHO = %d",qtPaciente);
    int k = 0, l = 0, aux = 0;
    char respostas [MAX];
    iniciaTempoEspera(&p,n);
    fflush(stdin);

    printf("\nEntre com o paciente: ");
    gets(p[qtPaciente].pacientes);



    printf("QUESTIONARIO S(SIM) e N(NAO)");
    printf("\n1.Comprometimento da via aerea?");
    scanf("%s",&respostas[0]);
    printf("\n2.Respiracao ineficaz?");
    scanf("%s",&respostas[1]);
    printf("\n3.Em choque ou convulsao?");
    scanf("%s",&respostas[2]);

    if((respostas[0] == 's' )|| (respostas[1] == 's') || (respostas[2] == 's')
            || (respostas[0] == 'S' )|| (respostas[1] == 'S') || (respostas[2] == 'S'))
    {
        for(k = 0; k < m; k++)
        {
            if(med[k].in_atendimento[k] == 0 && aux < 1)
            {
                aux = k;
                p[qtPaciente].prioridade[qtPaciente] = VERMELHO;
                strcpy(a[qtPaciente].paciente,p[qtPaciente].pacientes);
                strcpy(a[qtPaciente].medicos,med[aux].medicos);
                a[qtPaciente].tolerancia[qtPaciente] = VERMELHO_TOLERANCIA;
                a[qtPaciente].espera[qtPaciente] = 0;
                med[aux].in_atendimento[k] = true;
                aux++;
                printf("+++%d",a[0].tolerancia[0]);
                printf("+++%d",a[0].espera[0]);
            }
            else
            {
                p[qtPaciente].prioridade[qtPaciente] = VERMELHO;
                p[qtPaciente].in_espera[qtPaciente] = true;
                p[qtPaciente].prioridade[qtPaciente] = VERMELHO;
            }
        }
    }
    else
    {
        printf("\n4.Dor severa?");
        scanf("%s",&respostas[3]);
        printf("\n5.Grande hemorragia?");
        scanf("%s",&respostas[4]);
        printf("\n6.Trauma craniano severo?");
        scanf("%s",&respostas[5]);

        if((respostas[3] == 's' )|| (respostas[4] == 's') || (respostas[5] == 's')
                || (respostas[3] == 'S' )|| (respostas[4] == 'S') || (respostas[5] == 'S'))
        {
            for(k = 0; k < m; k++)
            {
                if(med[k].in_atendimento[k] == 0 && aux < 1)
                {
                    aux = k;
                    p[qtPaciente].prioridade[qtPaciente] = LARANJA;
                    strcpy(a[qtPaciente].paciente,p[k].pacientes);
                    strcpy(a[qtPaciente].medicos,med[aux].medicos);
                    a[qtPaciente].tolerancia[qtPaciente] = LARANJA_TOLERANCIA;
                    a[qtPaciente].espera[qtPaciente] = 0;
                    med[aux].in_atendimento[k] = true;
                    aux++;
                }
                else
                {
                    p[qtPaciente].in_espera[i] = true;
                    p[qtPaciente].prioridade[i] = LARANJA;
                }
            }
        }
        else
        {
            printf("\n7.Dor moderada?");
            scanf("%s",&respostas[6]);
            printf("\n8.Pequena hemorragia?");
            scanf("%s",&respostas[7]);
            printf("\n9.Idoso ou gravida sintomatico?");
            scanf("%s",&respostas[8]);
            if((respostas[6] == 's' )|| (respostas[7] == 's') || (respostas[8] == 's')
                    || (respostas[6] == 'S' )|| (respostas[7] == 'S') || (respostas[8] == 'S'))
            {
                for(k = 0; k < m; k++)
                {
                    if(med[k].in_atendimento[k] == 0 && aux < 1)
                    {
                        aux = k;
                        p[qtPaciente].prioridade[qtPaciente] = AMARELO;
                        strcpy(a[qtPaciente].paciente,p[k].pacientes);
                        strcpy(a[qtPaciente].medicos,med[aux].medicos);
                        a[qtPaciente].tolerancia[qtPaciente] = AMARELO_TOLERANCIA;
                        a[qtPaciente].espera[qtPaciente] = 0;
                        med[aux].in_atendimento[k] = true;
                        aux++;
                    }
                    else
                    {
                        p[qtPaciente].in_espera[i] = true;
                        p[qtPaciente].prioridade[i] = AMARELO;
                    }
                }
            }
            else
            {
                printf("\n10.Dor leve?");
                scanf("%s",&respostas[9]);
                printf("\n11.Nauseas?");
                scanf("%s",&respostas[10]);
                printf("\n12.Febre?");
                scanf("%s",&respostas[11]);
                if((respostas[9] == 's' )|| (respostas[10] == 's') || (respostas[11] == 's')
                        || (respostas[9] == 'S' )|| (respostas[10] == 'S') || (respostas[11] == 'S'))
                {
                    for(k = 0; k < m; k++)
                    {
                        if(med[k].in_atendimento[k] == 0 && aux < 1)
                        {
                            aux = k;
                            p[qtPaciente].prioridade[qtPaciente] = VERDE;
                            strcpy(a[qtPaciente].paciente,p[k].pacientes);
                            strcpy(a[qtPaciente].medicos,med[aux].medicos);
                            a[qtPaciente].tolerancia[qtPaciente] = VERDE_TOLERANCIA;
                            a[qtPaciente].espera[qtPaciente] = 0;
                            med[aux].in_atendimento[k] = true;
                            aux++;
                        }
                        else
                        {
                            p[qtPaciente].in_espera[i] = true;
                            p[qtPaciente].prioridade[i] = VERDE;
                        }
                    }
                }
                else
                {
                    for(k = 0; k < m; k++)
                    {
                        if(med[k].in_atendimento[k] == 0 && aux < 1)
                        {
                            aux = k;
                            p[qtPaciente].prioridade[qtPaciente] = AZUL;
                            strcpy(a[qtPaciente].paciente,p[k].pacientes);
                            strcpy(a[qtPaciente].medicos,med[aux].medicos);
                            a[qtPaciente].tolerancia[qtPaciente] = AZUL_TOLERANCIA;
                            a[qtPaciente].espera[qtPaciente] = 0;
                            med[aux].in_atendimento[k] = true;
                            aux++;
                        }
                        else
                        {
                            p[qtPaciente].in_espera[i] = true;
                            p[qtPaciente].prioridade[i] = AZUL;
                        }
                    }
                }
            }
        }
    }
}

//Sorteia o numero aleatorio que vai para o heap.
int sorteioAleatorio(int media, int desvioPadrao)
{
    int tempo = media+(rand()% (2 * desvioPadrao + 1) - desvioPadrao);
    return tempo;
}

//Qualcula a porcentagem de pacientes que ficaram esperando além da tolerancia.
float calculaTempoAtendimento(int n, int qtdPacienteEspera)
{
    return (qtdPacienteEspera * 100)/ n;
}

//Saída do programa.
void saida(int n, int qtdPacienteEspera, int qtPaciente)
{
    int i = 0, j = 0, k = 0, l = 0, aux = 0;
    char porcentagem = '%';
    for(aux = 0; aux < qtPaciente; aux++)
    {
        for(i = 0; i < strlen(a[aux].medicos); i++)
        {
            printf("%c",a[aux].medicos[i]);
        }
        printf(" ");
        for(j = 0; j < strlen(a[aux].paciente); j++)
        {
            printf("%c",a[aux].paciente[j]);
        }
        printf(" ");
        for(k = 0; k < qtPaciente; k++)
        {
            printf("%d", a[aux].tolerancia[k]);
        }
        printf(" ");
        for(l = 0; l < qtPaciente; l++)
        {
            printf("%d",a[qtPaciente].espera[l]);
        }
        printf("\n");
    }
    printf("%.1f ",calculaTempoAtendimento(n,qtdPacienteEspera));
    printf("%c",porcentagem);
}

//Sorteia os tempos de atendimento e coloca no heap.
void escolheTempoAtendimento(int n, pacientes p, int i)
{
    if(p.prioridade[i] == VERMELHO)
    {
        x = sorteioAleatorio(VERMELHO_MEDIA, VERMELHO_DESVIO_PADRAO);
        fpa_ins(&f, x);
    }
    else if(p.prioridade[i] == LARANJA)
    {
        x = sorteioAleatorio(LARANJA_MEDIA, LARANJA_DESVIO_PADRAO);
        fpa_ins(&f, x);
    }
    else if(p.prioridade[i] == AMARELO)
    {
        x = sorteioAleatorio(AMARELO_MEDIA, AMARELO_DESVIO_PADRAO);
        fpa_ins(&f, x);
    }
    else if(p.prioridade[i] == VERDE)
    {
        x = sorteioAleatorio(VERDE_MEDIA, VERDE_DESVIO_PADRAO);
        fpa_ins(&f, x);
    }
    else if(p.prioridade[i] == AZUL)
    {
        x = sorteioAleatorio(AZUL_MEDIA, AZUL_DESVIO_PADRAO);
        fpa_ins(&f, x);
    }
}
