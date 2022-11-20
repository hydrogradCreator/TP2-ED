#include <iostream>
#include "Item.hpp"
#include "memlog.h"

class qs_selecao{
public:
    void selection(int Esq, int Dir, int *i, int *j, Item *A);
    void Particao_selection(int Esq, int Dir, int *i, int *j, Item *A);
    void QuicksortSelection(Item *A, int n);
    void Troca(int *A, int i, int j);
    void Ordena_selection(int Esq, int Dir, Item *A);
};

void Troca(Item *A, Item *B){
    int temp = A->getChave();
    //ESCREVEMEMLOG((long int)(&(temp)),sizeof(double),0);
    A->setChave(B->getChave());
    //ESCREVEMEMLOG((long int)(&(A)),sizeof(double),0);
    B->setChave(temp);
    //ESCREVEMEMLOG((long int)(&(B)),sizeof(double),0);
}


void selection(Item *v, int n){
    int i, j, Min;
    for (i = 0; i < n-1 ; i++){
        Min = i;
    for (j = i + 1 ; j < n; j++){
        if (v[j].getChave() < v[Min].getChave())
            Min = j;
    }
        Troca(&v[i], &v[Min]);
    }
}


void Particao_selection(int Esq, int Dir, int *i, int *j, Item *A)
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
        (*i)++; (*j)--;
        }
    } while (*i <= *j);
}

 
void Ordena_selection(int Esq, int Dir, Item *A, int m){
    int i,j;
    Particao(Esq, Dir, &i, &j, A);
    if(Dir - Esq + 1 <= m){
        selection(A,m);
    }
    if (Esq < j) Ordena(Esq, j, A);
    if (i < Dir) Ordena(i, Dir, A);


}

void QuickSortSelection(Item *A, int n, int m){
    Ordena_selection(0, n-1, A,m);
}
