// WAP to find the largest element in the array in C

#include <stdio.h>

int maxElement(int* arr , int n) {
    int max = arr[0];
    for(int i = 1; i < n ; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}   // function to find the maximum element in the array

int main() {
    int n, sum = 0 , max = 0;

    printf("Enter the size of array:\n");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the elements of array:\n");
    for(int i = 0 ; i < n ; i++) {
        scanf("%d",&arr[i]);
    }

    max = maxElement(arr,n);

    printf("The largest element in the array is : %d",max);

    return 0;
}