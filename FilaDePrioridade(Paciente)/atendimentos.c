#include <stdio.h>
#include <stdlib.h>
#include "atendimentos.h"

void iniciasperaAtendimento(atendimento * aten, int m)
{
    int i = 0;
    for(i = 0; i < m; i++)
    {
        aten->espera[i] = 0;
    }
}
