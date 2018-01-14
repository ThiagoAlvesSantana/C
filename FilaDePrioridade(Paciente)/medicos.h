#ifndef _MEDICOS_H
#define _MEDICOS_H
#include <stdbool.h>
#define MAX 100

// Definição do TAD medico
typedef char med_info;
typedef struct
{
    med_info medicos[MAX]; //Nome do médico.
    bool in_atendimento[MAX]; //Guarda se o médico está em atendimento.
} medicos;

//Inicaliza o tempo de atendimento dos medicos com 0;
void iniciaTempoMedico(medicos *, int);
#endif

