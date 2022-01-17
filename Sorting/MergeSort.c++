/**
 * @file MergeSort.c++
 * @author Prashant Singh (https://www.linkedin.com/in/prashant17-11/)
 * @brief Sorting Algorithm
 * @version 0.1
 * @date 2022-01-17
 * 
 * It is a Divide and Conquer Algorithm which divides array into two halves,calls itself for the two halves, and then merges the two sorted halves.
 * Time Complexity: O(n logn)
 * Space Complexity: O(n)
 * 
 * Stable algorithm
 * used in external sorting
 * well suited for linked lists. Works in O(1) auxillary space
 * 
 * Algorithm:
 * )if r>1
 *      1) Find the middle point to divide the array into two halves
 *              middle m = l + (r-1)/2
 *      2) Call mergesort for first half
 *              Call mergeSort(arr,l,m)
 *      3) Call mergesort for second half
 *              Call mergeSort(arr,m+1,r)
 *      4) Merge the two halves sorted in step 2 and 3
 *              Call merge(arr,l,m,r)
 *  merge function assumes that arr[l..m] and arr[m+1..r] are sorted and just merges them.
 * 
 * Example:                  38 27 43 3 9 82 10
 *                        38 27 43 3      9 82 10
 *                      38 27    43 3     9 82       10
 *                  38   27       43     3        9      82       10
 *                      27 38    3 43     9 82       10
 *                        3 27 38 43      9 10 82
 *                           3 9 10 27 38 43 82
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

using namespace std;

void merge(int arr[], int const left, int const mid, int const right) {
    auto const subArrayOne = mid-left+1;
    auto const subArrayTwo = right-mid;

    auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];

    for(auto i = 0; i < subArrayOne; i++) {
        leftArray[i] = arr[left+i];
    }
    for(auto j = 0; j < subArrayTwo; j++) {
        rightArray[j] = arr[mid+1+j];
    }

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while(indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if(leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while(indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfMergedArray++;
        indexOfSubArrayOne++;
    }

    while(indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfMergedArray++;
        indexOfSubArrayTwo++;
    }
}

void mergeSort(int arr[], int const begin, int const end) {
    if(begin >= end) {
        return;
    }

    auto mid = begin + (end-begin)/2;
    mergeSort(arr,begin,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,begin,mid,end);
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

    mergeSort(arr,0,n-1);
 
    cout<<"The Sorted array is:"<<endl;
    displayArray(arr,n);

    return 0;
}