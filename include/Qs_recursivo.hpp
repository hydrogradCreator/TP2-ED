#ifndef QS_RECURSIVO_H
#define QS_RECURSIVO_H
#include <iostream>
#include <stdlib.h>
#include "Item.hpp"
#include "memlog.h"


class qs_recursivo{

public:
    void Particao(int Esq, int Dir, int *i, int *j, Item *A);
    void Quicksort(Item *A, int n);
    void Ordena(int Esq, int Dir, Item *A);
};

void Particao(int Esq, int Dir, int *i, int *j, Item *A)
{
    Item x,w;
        *i = Esq; *j = Dir;
        x = A[(*i + *j)/2]; /* obtem o pivo x */
    do
    {
        while (x.getChave() > A[*i].getChave()) (*i)++;
        while (x.getChave() < A[*j].getChave()) (*j)--;
        if (*i <= *j)
    {
        w = A[*i]; 
        //ESCREVEMEMLOG((long int)(&(w)),sizeof(double),0);
        A[*i] = A[*j]; 
        ESCREVEMEMLOG((long int)(&(A[*i])),sizeof(double),0);
        A[*j] = w;
        ESCREVEMEMLOG((long int)(&(A[*j])),sizeof(double),0);
        (*i)++; 
        (*j)--;
        }
    } while (*i <= *j);
}


void Ordena(int Esq, int Dir, Item *A)
{ int i,j;
    Particao(Esq, Dir, &i, &j, A);
    if (Esq < j) Ordena(Esq, j, A);
    if (i < Dir) Ordena(i, Dir, A);
}

void QuickSort(Item *A, int n){
    Ordena(0, n-1, A);
}

#endif