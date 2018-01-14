#ifndef _ATENDIMENTOS_H
#define _ATENDIMENTOS_H

#include <stdbool.h>
#define MAX 100

// Definição do TAD atendimento
typedef struct
{
    char medicos[MAX];
    char paciente[MAX];
    int tolerancia[MAX];
    int espera[MAX];
} atendimento;

void iniciasperaAtendimento(atendimento *, int m);
#endif
