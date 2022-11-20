#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include "Qs_recursivo.hpp"
#include "Qs_mediana.hpp"
#include "Qs_selecao.hpp"
#include "Qs_iterativo.hpp"
#include "Qs_inteligente.hpp"
#include "memlog.h"


int main(int argc, char* argv[]){


    FILE *entrada, *saida,*log_out;
    char analisa[10] = "log.out";
    fopen(analisa,"wb");
    int seed, tam, n, c;
    int mediana, m;
    //int option; 
    int version;
    extern char * optarg;
    //extern int optind;
    
    clock_t begin,end;
    double t1 = 0.0;

    //std::cout << m;
    iniciaMemLog(analisa);

    while ((c = getopt(argc, argv, "v:m:k:s:i:o")) != EOF)
       switch(c) {
          case 'v':
                version = atoi(optarg);
            break;
          case 's':
                seed = atoi(optarg);
            break;
          case 'i':
                //arquivo de entrada
                entrada = fopen(optarg, "r");
            break;
          case 'o':
                //arquivo de saida
                saida = fopen(optarg,"wb");
            break;
          case 'k':
                //mediana
                mediana = atoi(optarg);
            break;
          case 'm':   
                m = atoi(optarg);
            break;
         
         default:
          exit(1);

       }

    srand(seed);
    fscanf(entrada, "%d", &n);
    std::cout << version << "\n";

    switch (version)
    {
    case 1:
            std::cout << "qs recursivo\n";
            for(int i=0; i < n; i++){
                fscanf(entrada,"%d",&tam);
                Item *array = new Item[tam];
                array->preenche_vetor(tam);

                //começa a ordenação e a contagem do tempo
                begin = clock();
                QuickSort(array,tam);
                end = clock();
                t1 += (double)(end - begin) / CLOCKS_PER_SEC;
                array->imprime(array,tam);
            }   
        break;
    case 2:
        //qs com mediana
        std::cout << "qs mediana\n";
        for(int i=0; i < n; i++){
            fscanf(entrada,"%d",&tam);
            std::cout << tam << "\n";
            Item *array = new Item[tam];
            array->preenche_vetor(tam);

            //ordenação e contagem de tempo
            begin = clock();
            QuicksortMediana(array,tam,mediana);
            end = clock();
            t1 += (double)(end - begin) / CLOCKS_PER_SEC;
            //defineFaseMemLog(1);
            array->imprime(array,tam);
        }
        break;
    case 3:
        std::cout << "qs_iterativo\n";
        for(int i=0; i < n; i++){
            fscanf(entrada,"%d",&tam);
            Item *array = new Item[tam];
            array->preenche_vetor(tam);

            //ordenalçao e contagem de tempo
            begin = clock();          
            quickSortIterativo(array,0,tam-1);
            end = clock();
            t1 += (double)( end - begin) / CLOCKS_PER_SEC;
            array->imprime(array,tam);
        }
        break;
    case 4:
        std::cout << "qs selection\n";
        std::cout << m << "\n";
        for(int i=0; i < n; i++){
            fscanf(entrada,"%d",&tam);
            Item *array = new Item[tam];
            array->preenche_vetor(tam);


            begin = clock(); 
            QuickSortSelection(array,tam,m);
            end = clock();
            t1 += (double) (end - begin) / CLOCKS_PER_SEC;
            array->imprime(array,tam);
        }
        break;
    case 5:
        std::cout << "qs inteligente\n";
        for(int i=0; i < n; i++){
            fscanf(entrada,"%d",&tam);
            std::cout << tam << "\n";
            Item *array = new Item[tam];
            array->preenche_vetor(tam);

            begin = clock();
            QuickSortNaoRec(array,tam);
            end = clock();
            t1 += (double) (end - begin) / CLOCKS_PER_SEC;
            array->imprime(array,tam);
        }
        break;
    default:
        break;
    }

    std::cout << "\nQuicksort versao: " << version << "\nTempo de execução " << t1/n <<  std::endl;
    finalizaMemLog();
    return 0 ;
}