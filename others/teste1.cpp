// std::string gen_random() {
//     static const char alphanum[] =
//         "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
//         "abcdefghijklmnopqrstuvwxyz";
//     std::string tmp_s;
//     tmp_s.reserve(10);

//     for (int i = 0; i < 10; ++i) {
//         tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
//     }
    
//     return tmp_s;
// }

// class Item
// {
//     //colocar private
//     public:
//         int chave;
//         std::string caracter[15]; //inicia {{0}}  inicia todas as pocições com 0
//         int numeros[10]; //inicia todas as posições com 0
//         //Item();
//         void preenche(int n);
// };

// void Item::preenche(int n){
//     for(int i=0; i < 15; i++){
//             this->caracter[i] = gen_random();
//     }   

//     //srand(n);
//     this->chave = rand();

//     for(int i=0 ; i < 10 ; i++){
//         this->numeros[i] = rand();
//     }
// }

// int qs_mediana(Item *vet, int tam, int k){
//     //k = numero de elementos para selecionar do vetor
//     Item vet_particionado[k];
//     for(int i=0; i < k; i++){
//         vet_particionado[i].setChave(-1);
//     }

//     int elemento;
//     int mediana;

//     for(int i=0; i < k; ++i){

//         elemento = rand() % tam;

//         if(vet_particionado[i].getChave() != -1){
//             break;
//         }
//         else {
//             vet_particionado[i].setChave(vet[elemento].getChave());
//         }
//         std::cout << "posicao vet: " << vet_particionado[i].getChave() << "\nelemento: " << vet[elemento].getChave() << "\n";
//     }
//         //cont++;
//     for(int j=0; j < k; j++){
//         std::cout << vet_particionado[j].getChave() << " ";
//     }
//     mediana = vet_particionado[k/2].getChave();
//     std::cout << "\n" << mediana;
    
//     return mediana;
// }

// Item qs_mediana(Item *vet, int tam, int k){
//     //k = numero de elementos para selecionar do vetor
//     Item vet_particionado[k];
//     for(int i=0; i < k; i++){
//         vet_particionado[i].setChave(-1);
//     }

//     int elemento;
//     Item mediana;

//     for(int i=0; i < k; ++i){

//         elemento = rand() % tam;

//         if(vet_particionado[i].getChave() != -1){
//             break;
//         }
//         else {
//             vet_particionado[i].setChave(vet[elemento].getChave());
//         }
//         std::cout << "posicao vet: " << vet_particionado[i].getChave() << "\nelemento: " << vet[elemento].getChave() << "\n";
//     }
//         //cont++;
//     int min=0;
//     for(int i=0; i < k; i++){
//         min = i;

//         for(int j=i+1; j<k; j++){
//             if(vet_particionado[j].getChave() < vet_particionado[min].getChave()){
//                 min=j;
//             }
//         }
//         int temp = vet_particionado[i].getChave();
//         vet_particionado[i].setChave(vet_particionado[min].getChave());
//         vet_particionado[min].setChave(temp);
//         std::cout << vet_particionado[i].getChave() << " ";
//     }
//     mediana.setChave(vet_particionado[k/2].getChave());
//     std::cout << "\nmediana " << mediana.getChave();
    
//     return mediana;
// }
// void troca(Item *A, Item* b)
// {
//     int t = A->getChave();
//     A->setChave(b->getChave());
//     b->setChave(t);
// }
 
// /* Função Partição*/
// int Particao(Item *vetor, int inicio, int final)
// {
//     Item x = vetor[final];
//     int i = (inicio - 1);
 
//     for (int j = inicio; j <= final - 1; j++) {
//         if (vetor[j].getChave() <= x.getChave()) {
//             i++;
//             troca(&vetor[i], &vetor[j]);
//         }
//     }
//     troca(&vetor[i + 1], &vetor[final]);
//     return (i + 1);
// }
 

// void QSIterativo(Item *vetor, int inicio, int final)
// {
    
//     int pilha[final - inicio + 1];
 
//     int topo = -1;
 
//     pilha[++topo] = inicio;
//     pilha[++topo] = final;
 
//     while (topo >= 0) {

//         final = pilha[topo--];
//         inicio = pilha[topo--];
 
//         int pivo = Particao(vetor, inicio, final);
 
//         if (pivo - 1 > inicio) {
//             pilha[++topo] = inicio;
//             pilha[++topo] = pivo - 1;
//             // trocas++;
//         }
//         if (pivo + 1 < final) {
//             pilha[++topo] = pivo + 1;
//             pilha[++topo] = final;
//             // trocas++;
//         }
//     }
// }
