/* filapri.h
 * Definicao do tipo fpa (Fila de Prioridade Ascendente) e do pr�tipo de suas opera��es
 */

#ifndef _FILAPRI_H
#define _FILAPRI_H

#include <stdbool.h>

#define MAX_FPA 100
typedef int fpa_info;
typedef struct
{
    fpa_info itens[MAX_FPA];
    int n;
} fpa;

// inicizaliza a fila de prioridade ascendente
void fpa_init(fpa *);

// verifica se a fila est� cheia
bool fpa_isempty(fpa);

// verifica se a fila est� cheia
bool fpa_isfull(fpa);

// insere um valor na fila de prioridade ascendente
void fpa_ins(fpa *, fpa_info);

// remove e devolve o valor de menor prioridade na fila
fpa_info fpa_rem_min(fpa *);

// subtrai os tempos com o tempo que sair� primeiro.
fpa_info subtraiElementos(fpa *, int);

int vazia(fpa *);

#endif // _FILAPRI_H
