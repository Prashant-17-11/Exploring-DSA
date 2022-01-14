/**
 * @file BubbleSort.c++
 * @author Prashant Singh (https://www.linkedin.com/in/prashant17-11/)
 * @brief Sorting Algorithm
 * @version 0.1
 * @date 2022-01-14
 * 
 * Works by repeatedly swapping adjacent elements
 * Time Complexity: Worst and Average Case O(n^2)   Best Case O(n)
 * Space Complexity: O(1)
 * 
 * This algorithm works by comparing two adjacent elements in an array and swapping them if the one on right is greater than the one on left, i.e., a[i] > a[i+1] thus effectiveily shifting the largest element in the array to the rightmost position in the unsorted array
 * Initially the whole array is unsorted but with each traversal the largest element in unsorted array shifts to its correct position thus becoming a part of the sorted array
 * It takes n-1 traversals at most to sort an unsorted array using bubble sort
 * 
 * Since the array can sort in somewhere between we can add a condition if there happens no swapping in traversal then end the process of bubble sort since the array is already in sorted state
 * 
 * Eg:  
 *      Traversal 1:    Unsorted array: [5 1 4 2 3]
 *          [5 1 4 2 3]     ->      [1 5 4 2 3]
 *          [1 5 4 2 3]     ->      [1 4 5 2 3]
 *          [1 4 5 2 3]     ->      [1 4 2 5 3]
 *          [1 4 2 5 3]     ->      [1 4 2 3 5]
 *      Traversl 2:     Unsorted array: [1 4 2 3]   Sorted array: [5]
 *          [1 4 2 3 5]     ->      [1 4 2 3 5]
 *          [1 4 2 3 5]     ->      [1 2 4 3 5]
 *          [1 2 4 3 5]     ->      [1 2 3 4 5]
 *      Traversal 3:    Unsorted arry: [1 2 3]      Sorted array: [4 5]
 *          [1 2 3 4 5]     ->      [1 2 3 4 5]
 *          [1 2 3 4 5]     ->      [1 2 3 4 5]
 *      Process Ends
 *      We can see that the array was sorted after second traversal but there is no way for the algortihm to know that
 *      So we do one more traversal and if no swaps are made we end the process in that step 
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(int arr[], int n) {
    bool swapped;

    for(int i = 0 ; i < n-1 ; i++) {
        swapped = false;
        for(int j = 0 ; j < n-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j],&arr[j+1]);
                swapped = true;
            }
        }

        if(!swapped) {
            break;
        }
    }
}

void inputArray(int arr[], int n) {
    for(int i = 0 ; i < n; i++) {
        cin>>arr[i];
    }
}

void displayArray(int arr[], int n) {
    for(int i = 0; i < n ; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int n;

    cout<<"Enter the size of the array:"<<endl;
    cin>>n;

    int arr[n];

    cout<<"Enter the elements of the array:"<<endl;
    inputArray(arr,n);

    cout<<"The Unsorted array is:"<<endl;
    displayArray(arr,n);

    bubbleSort(arr,n);

    cout<<"The Sorted array is:"<<endl;
    displayArray(arr,n);

    return 0;
}