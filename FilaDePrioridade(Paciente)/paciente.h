#ifndef _PACIENTE_H
#define _PACIENTE_H
#define MAX 100

// Definição do TAD paciente
typedef struct
{
    char pacientes[MAX];//Nome do paciente.
    int prioridade[MAX];//Prioridade do paciente.
    bool in_espera[MAX];//Guarda true se o paciente esta em atendimento
    int espera[MAX];//Tempo de espera.
} pacientes;

//Inicaliza o tempo de espera dos pacientes com 0;
void iniciaTempoEspera(pacientes *, int);
#endif
