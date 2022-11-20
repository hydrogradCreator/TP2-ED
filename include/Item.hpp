#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <random>
#include <string>
#include <unistd.h>
#include <ctime>
#include "memlog.h"



class Item
{
    public:
        int chave;
        std::string caracter[15]; 
        int numeros[10];
        std::string gen_random();
        int getChave(){return chave;};
        void setChave(int _chave){ this->chave = _chave;};
        void inicializa();
        void imprime(Item *A, int n);
        void preenche_vetor(int tam);
};

void Item::inicializa(){

    for(int i=0; i < 15; i++){
            this->caracter[i] = gen_random();
    }   

    //o srand é colocado no main
    //srand(n) n = seed;
    this->chave = rand()%1000;

    for(int i=0 ; i < 10 ; i++){
        this->numeros[i] = rand()%100;
    }
}

void Item::preenche_vetor(int tam){
    for(int i=0; i < tam; i++){
        this[i].inicializa();
    }
}

std::string Item::gen_random() {
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(200);

    for (int i = 0; i < 200; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}


void Item::imprime(Item *A, int n){
    for(int i=0; i < n; i++){
        std::cout << "\nregistro n:" << i << "\nchave:" << A[i].chave << "\n";
        LEMEMLOG((long int)(&(A[i].chave)), sizeof(double),0);
    }
}


#endif