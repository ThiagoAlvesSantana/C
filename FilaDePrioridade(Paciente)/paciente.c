#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "paciente.h"

/*Metodo para saber se o tempo de espera do paciente*/
void iniciaTempoEspera(pacientes * p, int n)
{
    int i = 0;
    for(i = 0; i < n; i++)
    {
        p->espera[i] = 0;
    }
}

