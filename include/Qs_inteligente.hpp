#ifndef QS_INTELIGENTE_H
#define QS_INTELIGENTE_H
#include <iostream>
#include "memlog.h"
#include "Item.hpp"
#include "Pilha.hpp"

void Particao_recursivo(int Esq, int Dir, int *i, int *j, Item *A)
{
    Item x,w;
        *i = Esq; *j = Dir;
        x = A[(*i + *j)/2]; /* obtem o pivo x */
    do
    {
        while (x.getChave() > A[*i].getChave()) (*i)++;
        while (x.getChave() < A[*j].getChave()) (*j)--;
    if (*i <= *j){
        w = A[*i]; 
                //ESCREVEMEMLOG((long int)(&(w)),sizeof(double),0);

        A[*i] = A[*j]; 
                ESCREVEMEMLOG((long int)(&(A[*i])),sizeof(double),0);

        A[*j] = w;
                ESCREVEMEMLOG((long int)(&(A[*j])),sizeof(double),0);

        (*i)++; (*j)--;
    }
    } while (*i <= *j);
}

void QuickSortNaoRec(Item *A, int n){
    PilhaEncadeada pilha;
    TipoCelula aux; // campos esq e dir
    int esq, dir, i, j;
    pilha.Vazia();
    esq = 0;
    dir = n-1;
    aux.Dir = dir;
    aux.Esq = esq;
    
    pilha.Empilha(aux);
    do
    if (dir > esq) {
        Particao(esq,dir,&i, &j,A);
        if ((j-esq)>(dir-i)) {
            
            aux.Dir = j;
            aux.Esq = esq;
            pilha.Empilha(aux);
            esq = i;
        }
        else {
            aux.Esq = i;
            aux.Dir = dir;
            pilha.Empilha(aux);
            dir = j;
        }
    }
    else {
        aux = pilha.Desempilha();
        dir = aux.Dir;
        esq = aux.Esq;
    } while (!(pilha.Vazia()));
}

#endif