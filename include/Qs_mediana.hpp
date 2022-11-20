#ifndef QS_MEDIANA_H
#define QS_MEDIANA_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Item.hpp"
#include "memlog.h"

int k=0;

Item mediana(Item *vet, int esq, int dir, int k){
    
    Item vet_particionado[k];
    for(int i=0; i < k; i++){
        vet_particionado[i].setChave(-1);
    }

    int elemento;
    Item mediana;

    for(int i=0; i < k; ++i){
 
        elemento = (esq) + rand() % ((dir) - (esq));

        if(vet_particionado[i].getChave() != -1){
            break;
        }
        else{
            vet_particionado[i] = vet[elemento];
        }
    }
    Item temp;
    for(int i=0; i < k-1; i++){
        for(int j=1; j < k-i; j++){
            if(vet_particionado[j].getChave() < vet_particionado[j-1].getChave()){
                temp = vet_particionado[i];
                //ESCREVEMEMLOG((long int)(&(temp)),sizeof(double),0);
                vet_particionado[i] = vet_particionado[j-1];
                //ESCREVEMEMLOG((long int)(&(vet_particionado[i])),sizeof(double),0);
                vet_particionado[j-1] = temp;
                //ESCREVEMEMLOG((long int)(&(vet_particionado[j-1])),sizeof(double),0);
            }
        }
    }
    mediana = vet_particionado[k/2];
    return mediana;
}


void ParticaoMediana(int Esq, int Dir, int *i, int *j, Item *A)
{
    Item w,x;
        *i = Esq; *j = Dir;
        x = mediana(A,Esq,Dir,k); /* obtem o pivo x */
    do
    {
        while (x.getChave() > A[*i].getChave()) (*i)++;
        while (x.getChave() < A[*j].getChave()) (*j)--;
        if (*i <= *j)
    {
        w = A[*i]; 
        //ESCREVEMEMLOG((long int)(&(w)),sizeof(double),0);
        A[*i] = A[*j]; 
        //ESCREVEMEMLOG((long int)(&(A[*i])),sizeof(double),0);
        A[*j] = w;
        //ESCREVEMEMLOG((long int)(&(A[*j])),sizeof(double),0);
        (*i)++; 
        (*j)--;
        }
    } while (*i <= *j);
}


void OrdenaMediana(int Esq, int Dir, Item *A)
{ int i,j;
    ParticaoMediana(Esq, Dir, &i, &j, A);
    if (Esq < j) Ordena(Esq, j, A);
    if (i < Dir) Ordena(i, Dir, A);
}

void QuicksortMediana(Item *A, int n, int _k){
    k = _k;
    OrdenaMediana(0, n-1, A);
}

#endif

