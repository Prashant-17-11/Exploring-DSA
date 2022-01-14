/**
 * @file SelectionSort.c++
 * @author Prashant Singh (https://www.linkedin.com/in/prashant17-11/)
 * @brief Sorting Algorithm
 * @version 0.1
 * @date 2022-01-14
 * 
 * works by repeatedly finding the minimum element and shifting it at the front
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 * 
 * In each traversal we find the minimum element in the unsorted array and put it in the front of it
 * 
 * Eg:  
 *      Traversal 1:    Unsorted array: [5 4 2 3 1]
 *      [5 4 3 2 1]     ->      [1 4 2 3 5]
 *      Traversal 2:    Sorted array: [1]   Unsorted array: [4 2 3 5]
 *      [1 4 2 3 5]     ->      [1 2 4 3 5]
 *      Traversal 3:    Sorted array: [1 2]   Unsorted array: [4 3 5]
 *      [1 2 4 3 5]     ->      [1 2 3 4 5]
 *      Traversal 4:    Sorted array: [1 2 3]   Unsorted array: [4 5]
 *      [1 2 3 4 5]     ->      [1 2 3 4 5]
 *                      Sorted array: [1 2 3 4]   Unsorted array: [5]
 *      Process ends after n-1 traversals
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

void selectionSort(int arr[], int n) {
    int minimumIndex;

    for(int i = 0; i < n-1 ; i++) {
        minimumIndex = i;
        for(int j=i+1; j < n ; j++) {
            if(arr[j] < arr[minimumIndex]) {
                minimumIndex = j;
            }
        }

        swap(&arr[i],&arr[minimumIndex]);
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

    selectionSort(arr,n);

    cout<<"The Sorted array is:"<<endl;
    displayArray(arr,n);

    return 0;
}