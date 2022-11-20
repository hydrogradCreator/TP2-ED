#include <ctime>
#include <iostream>
#include <unistd.h>
#include "Item.hpp"


// class Qs_mediana{
//     public:
//         int Particao(int Esq, int Dir, int *i, int *j, Item *A, int k);
//         void Troca(Item *A, Item *B);
//         void Quicksort(Item *A, int n);
//         void Ordena(int Esq, int Dir, Item *A);
//         Item mediana(Item *vet, int tam, int k);
// };


void Ordenar_vetor(Item *vetor, int n_elementos)
{
  int aux;

  for (int i = 0; i < n_elementos; i++)
  {
    for (int j = i; j < n_elementos; j++)
    {
      if (vetor[i].getChave() >= vetor[j].getChave())
      {
        aux = vetor[i].getChave();
        vetor[i].setChave(vetor[j].getChave());
        vetor[j].setChave(aux);
      }
    }
  } 
}

//   Ordenar_vetor(vetor_amostras, k);
  
//   int meio = (0+k) / 2;
//   return vetor_amostras[meio].getChave();
int mediana(Item *vet, int tam, int k){
    //k = numero de elementos para selecionar do vetor
    Item vet_particionado[k];
    for(int i=0; i < k; i++){
        vet_particionado[i].setChave(-1);
    }

    int elemento;
    Item mediana;

    for(int i=0; i < k; ++i){

        elemento = rand() % tam;

         if(vet_particionado[i].getChave() != -1){
            break;
        }
        else {
            vet_particionado[i].setChave(vet[elemento].getChave());
            //break;
        }
    }
    int min=0;
    // for(int i=0; i < k; i++){
    //     min = i;

    //     for(int j=i+1; j<k; j++){
    //         if(vet_particionado[j].getChave() < vet_particionado[min].getChave()){
    //             min=j;
    //         }
    //     }
    //     int temp = vet_particionado[i].getChave();
    //     vet_particionado[i].setChave(vet_particionado[min].getChave());
    //     vet_particionado[min].setChave(temp);
    // }
    mediana.setChave(vet_particionado[k/2].getChave());
    return mediana.getChave();
}



void swap(Item *A, int i, int j){
    int temp = A[i].getChave();
    A[i].setChave(A[j].getChave());
    A[j].setChave(temp);
}

int partition(Item *A, int inicio, int fim, int k) {
    //procura a mediana entre inicio, meio e fim
    int meio = mediana(A,fim,k);
    Item a = A[inicio];
    Item b = A[meio];
    Item c = A[fim];
    int medianaIndice; //índice da mediana
    //A sequência de if...else a seguir verifica qual é a mediana
    if (a.getChave() < b.getChave()) {
        std::cout << "1 if" << "\n";
        if (b.getChave() < c.getChave()) {
            //a < b && b < c
            std::cout << "2 if" << "\n";

            medianaIndice = meio;
        } else {
            if (a.getChave() < c.getChave()) {
                //a < c && c <= b
                medianaIndice = fim;
                        std::cout << "3 if" << "\n";

            } else {
                //c <= a && a < b
                medianaIndice = inicio;
                        std::cout << "4 if" << "\n";

            }
        }
    } else {
        if (c.getChave() < b.getChave()) {
            //c < b && b <= a
            medianaIndice = meio;
                    std::cout << "5 if" << "\n";

        } else {
            if (c.getChave() < a.getChave()) {
                //b <= c && c < a
                medianaIndice = fim;
                        std::cout << "6 if" << "\n";

            } else {
                //b <= a && a <= c
                medianaIndice = inicio;
                        std::cout << "7 if" << "\n";

            }
        }
    }
    //coloca o elemento da mediana no fim para poder usar o Quicksort de Cormen
    swap(A, medianaIndice, fim);
        
    //*******************ALGORITMO DE PARTIÇÃO DE CORMEN*********************
    //o pivo é o elemento final
    Item pivo = A[fim];
    int i = inicio - 1;
    int j;
    /*
     * Este laço irá varrer os vetores da esquerda para direira
     * procurando os elementos que são menores ou iguais ao pivô.
     * Esses elementos são colocados na partição esquerda.         
     */
    for (j = inicio; j <= fim - 1; j++) {
        if (A[j].getChave() <= pivo.getChave()) {
            i = i + 1;
            swap(A, i, j);
                    std::cout << "1 if" << "\n";

        }
    }
    //coloca o pivô na posição de ordenação
    swap(A, i + 1, fim);
    return i + 1; //retorna a posição do pivô
}
//Quicksort mediana de três
void Mediana(Item *A, int inicio, int fim, int k) {
    if (inicio < fim) {
        //realiza a partição
        int q = partition(A, inicio, fim,k);
        //ordena a partição esquerda
        Mediana(A, inicio, q - 1,k);
        //ordena a partição direita
        Mediana(A, q + 1, fim,k);
                std::cout << "qs mediana" << "\n";

    }
}

void QuicksortMediana(Item *A, int inicio, int fim, int mediana)
{
    Mediana(A, 0, fim-1,mediana);
}


int main(int argc, char *argv[]) {
    int n, seed;
    std::cin >> n >> seed;
    srand(seed);
    Item *novoItem = new Item[n];
    //int vet[5] = {1,5,7,90,3};
    
    for(int i=0; i < n; i++){
        novoItem[i].preenche(seed);
        std::cout << "registro n:" << i << "\nchave:" << novoItem[i].getChave() << "\n" ;
    }
    
    QuicksortMediana(novoItem,0,n-1,3);
    
    // for(int i=0; i < 5; i++){
    //     std::cout << vet[i] << " ";
    // }
    return 0;
}