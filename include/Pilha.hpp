#include <iostream>
#include "Item.hpp"


class TipoCelula{
    public:
        TipoCelula();
        Item item;
        TipoCelula *prox;
        int Esq,Dir;

    friend class PilhaEncadeada;
};

class Pilha
{
    public:
        Pilha(){tamanho = 0;};
        int GetTamanho() {return tamanho;};
        bool Vazia() {return tamanho == 0;};
    
    protected:
        int tamanho;
};

class PilhaEncadeada : public Pilha{
    public:
    void Empilha(TipoCelula item);
    TipoCelula Desempilha();
    void Limpa();

    private:
        TipoCelula* topo;
};

TipoCelula::TipoCelula()
{
    item.setChave(-1);
    prox = NULL;
}

void PilhaEncadeada::Empilha(TipoCelula item){
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->item = item.item;
    nova->Esq = item.Esq;
    nova->Dir = item.Dir;
    nova->prox = topo;
    topo = nova;
    tamanho++;
};


TipoCelula PilhaEncadeada::Desempilha(){
    TipoCelula aux; TipoCelula *p;
    
    aux.item = topo->item;
    aux.Esq = topo->Esq;
    aux.Dir = topo->Dir;
    p = topo;
    topo = topo->prox;
    delete p;
    tamanho--;
    return aux;
};
