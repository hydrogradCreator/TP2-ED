#include <iostream>
#include "Item.hpp"



// class Mergesort
// {

// public:
//     int *merge(int *valuesL, int *valuesR, int nl, int nr);

    
// };

// int *merge(int *valuesL, int
// *valuesR, int nl, int nr) {

//     int *result = (int *)
//     malloc((nl+nr) * sizeof(int));

//     int i = 0;
//     int j = 0;
//     int k = 0;

//     while (i < nl && j < nr) {
//         if (valuesL[i] < valuesR[j]) {
//         result[k] = valuesL[i];
//         i++;
//     } 
//     else {
//         result[k] = valuesR[j];
//         j++;
//     }
//         k++;
//     }
//     if (k < nl + nr) {
//         for(; i < nl; i++) {
//             result[k] = valuesL[i];
//             k++;
//         }
//             for(; j < nr; j++) {
//             result[k] = valuesR[j];
//             k++;
//         }
//     }
//         return result;
// }




using namespace std;
 
// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(Item *array, int const left, int const mid,
           int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 
    // Create temp arrays
    Item *leftArray = new Item[subArrayOne],
         *rightArray = new Item[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne].getChave()
            <= rightArray[indexOfSubArrayTwo].getChave()) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */


void mergeSort(Item *array, int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

//drive code
int main(){

    int n, seed;
    std::cin >> n >> seed;
    srand(seed);
    Item *novoItem = new Item[n];

    
    for(int i=0; i < n; i++){
        novoItem[i].preenche(seed);
        //std::cout << "registro n:" << i << "\nchave:" << novoItem[i].getChave() << "\n" ;
    }
    mergeSort(novoItem,0,n-1);

    // for(int i=0; i < n; i++){
    //     std::cout << "\nregistro n:" << i << "\nchave:" << novoItem[i].getChave() << "\n";
    // }
}