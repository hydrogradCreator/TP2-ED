// C++ implementation of QuickSort
// using Hoare's partition scheme

#include <cstdlib>
#include <iostream>
#include "./include/Item.hpp"
using namespace std;

int k =0;
// This function takes last element as
// pivot, places the pivot element at
// its correct position in sorted
// array, and places all smaller
// (smaller than pivot) to left of pivot
// and all greater elements to right
int partition(Item *arr, int low, int high)
{
	int pivot = partition_r(arr,low,high,k);
	int i = low - 1, j = high + 1;

	while (true) {

		// Find leftmost element greater than
		// or equal to pivot
		do {
			i++;
		} while (arr[i].getChave() < pivot);

		// Find rightmost element smaller than
		// or equal to pivot
		do {
			j--;
		} while (arr[j].getChave() > pivot);

		// If two pointers met
		if (i >= j)
			return j;

		swap(arr[i], arr[j]);
	}
}

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
// In Hoare partition the low element is selected
// as first pivot
int partition_r(Item *arr, int low, int high, int k)
{
	// Generate a random number in between
	// low .. high
	srand(time(NULL));
	int element = low + rand() % (high - low);

	// Swap A[random] with A[high]
	swap(arr[element], arr[low]);

	return partition(arr, low, high);
}

// The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low --> Starting index,
// high --> Ending index
void quickSort(Item *arr, int low, int high,int mediana)
{
	if (low < high) {
		// pi is partitioning index,
		// arr[p] is now at right place
		int pi = partition_r(arr, low, high,k);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi,mediana);
		quickSort(arr, pi + 1, high,mediana);
	}
}



// Driver Code
int main()
{
	int n, seed;
    std::cin >> n >> seed;
    srand(seed);
    Item *novoItem = new Item[n];
    //int vet[5] = {1,5,7,90,3};
    
    for(int i=0; i < n; i++){
        novoItem[i].preenche(seed);
        std::cout << "registro n:" << i << "\nchave:" << novoItem[i].getChave() << "\n" ;
    }
    
    quickSort(novoItem,0,n-1,3);
    std::cout << "\n";
    for(int i=0; i < n; i++){
        //novoItem[i].preenche(seed);
        std::cout << "registro n:" << i << "\nchave:" << novoItem[i].getChave() << "\n" ;
    }
	return 0;
}
