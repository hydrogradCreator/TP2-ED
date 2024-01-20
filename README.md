# TP2-ED

Trabalho Prático da Disciplina de Estruturas de Dados


Esse trabalho teve como objetivo análisar o desempenho das variações do algoritmo de ordenação QuickSort

As variações do Quicksort a serem implementadas e avaliadas são:

1. Quicksort Recursivo: este é o Quicksort recursivo apresentado em sala de aula.
2. Quicksort Mediana(k): esta variação do Quicksort recursivo escolhe o pivô para partição
como sendo a mediana de k elementos do vetor, aleatoriamente escolhidos. Experimente
com k = 3, k = 5, e k = 7.
3. Quicksort Seleção(m): esta variação modifica o Quicksort Recursivo para utilizar o
algoritmo de Seleção para ordenar partições (isto é, pedaços do vetor) com tamanho
menor ou igual a m. Experimente com m = 10 e m = 100.
4. Quicksort não Recursivo: esta variação escolhe o pivô como o elemento do meio (como
apresentado em sala de aula), mas não é recursiva, utilizando uma pilha para armazenar
partições a serem processadas posteriormente.
5. Quicksort Empilha Inteligente: esta variação do Quicksort processa primeiro a menor
partição. Você deve aplicar esta otimização à versão não recursiva do Quicksort
