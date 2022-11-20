#ifndef QS_ITERATIVO_H
#define QS_ITERATIVO_H
#include <iostream>
#include "memlog.h"
#include "Item.hpp"

void troca(Item *A, Item* b)
{
    int t = A->getChave();
    //ESCREVEMEMLOG((long int)(&(t)),sizeof(double),0);

    A->setChave(b->getChave());
    ESCREVEMEMLOG((long int)(&(A)),sizeof(double),0);

    b->setChave(t);
    ESCREVEMEMLOG((long int)(&(b)),sizeof(double),0);

}
 
/* Função Partição*/
int Particao(Item *vetor, int inicio, int final)
{
    Item x = vetor[final];
    int i = (inicio - 1);
 
    for (int j = inicio; j <= final - 1; j++) {
        if (vetor[j].getChave() <= x.getChave()) {
            i++;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[final]);
    return (i + 1);
}
 

void quickSortIterativo(Item *vetor, int inicio, int final)
{
    
    int pilha[final - inicio + 1];
 
    int topo = -1;
 
    pilha[++topo] = inicio;
    pilha[++topo] = final;
 
    while (topo >= 0) {

        final = pilha[topo--];
        inicio = pilha[topo--];
 
        int pivo = Particao(vetor, inicio, final);
 
        if (pivo - 1 > inicio) {
            pilha[++topo] = inicio;
            pilha[++topo] = pivo - 1;
        }
        if (pivo + 1 < final) {
            pilha[++topo] = pivo + 1;
            pilha[++topo] = final;
        }
    }
}

#endif