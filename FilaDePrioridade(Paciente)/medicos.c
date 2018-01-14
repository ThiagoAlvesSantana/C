#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "medicos.h"

/*Metodo para saber se o medico esta em atendimento ou não*/
void iniciaTempoMedico(medicos * med, int m)
{
    int i = 0;
    for(i = 0; i < m; i++)
    {
        med->in_atendimento[i] = 0;
    }
}
