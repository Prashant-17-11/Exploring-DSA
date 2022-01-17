/**
 * @file InsertionSort.c++
 * @author Prashant Singh (https://www.linkedin.com/in/prashant17-11/)
 * @brief Sorting Algorithm
 * @version 0.1
 * @date 2022-01-17
 * 
 * Array is virtually divided into sorted and unsorted part. Values from unsorted part are picked and placed in correct position in sorted part.
 * Time Complexity: O(n^2) Worst Case
 *                  O(n)   Best Case
 * Space Complexity: O(1)
 * In-Place and Stable
 * 
 * used for small arrays
 * 
 * Algorithm:
 * 1) Iterate from arr[1] to arr[n]
 * 2) Compare current element to its predecessor
 * 3) If current element is smaller then compare it to previous elements. Move greater elements one position up and make space for current element at right position in sorted part
 * 
 * Example: [20 5 40 60 10 30]
 *      Sorted Part         Unsorted part
 *      [20                 5 40 60 10 30]
 *      [5 20               40 60 10 30]
 *      [5 20 40            60 10 30]
 *      [5 20 40 60         10 30]
 *      [5 10 20 40 60      30]
 *      [5 10 20 30 40 60]
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

using namespace std;

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n ; i++) {
        int key = arr[i];
        int j = i-1;
        while(j>= 0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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

    insertionSort(arr,n);

    cout<<"The Sorted array is:"<<endl;
    displayArray(arr,n);

    return 0;
}