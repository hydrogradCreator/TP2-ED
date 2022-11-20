#include <iostream>
#include "Item.hpp"


class HeapSort{

    public:
        void Refaz(int Esq, int Dir, Item *A);
        void Constroi(Item *A, int n);
};

void Refaz(int Esq, int Dir, Item *A){
    int i, j;
    Item x;
    i = Esq;
    j = i * 2;
    x = A[i];

    while (j <= Dir){
        if (j < Dir)
            if (A[j].getChave() < A[j+1].getChave()) j++;
            if (x.getChave() >= A[j].getChave()) break;
            A[i] = A[j];
            i = j;
            j = i *2;
    }
        A[i] = x;
}

void Constroi(Item *A, int n) {
    int Esq;
    Esq = n / 2 + 1;

    while (Esq > 0) {
        Esq--;
        Refaz(Esq, n, A);
    }
}



void Heapsort(Item *A, int n) {
    int Esq, Dir;
    Item x;
    Constroi(A, n); /* constroi o heap */
    Esq = 0; 
    Dir = n;
    while (Dir > 0)
    { /* ordena o vetor */
        x = A[0];
        A[0] = A[Dir];
        A[Dir] = x;
        Dir--;
        Refaz(Esq, Dir, A);
    }
}

int main(){

    int n, seed;
    std::cin >> n >> seed;
    srand(seed);
    Item *novoItem = new Item[n];

    
    for(int i=0; i < n; i++){
        novoItem[i].preenche(seed);
        //std::cout << "registro n:" << i << "\nchave:" << novoItem[i].getChave() << "\n" ;
    }
    Heapsort(novoItem,n-1);

    for(int i=0; i < n; i++){
        std::cout << "\nregistro n:" << i << "\nchave:" << novoItem[i].getChave() << "\n";
    }
}