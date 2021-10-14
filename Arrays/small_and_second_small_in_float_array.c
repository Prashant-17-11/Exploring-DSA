// WAP to find out the smallest and the second smallest element in a float 1-D array in C

#include <stdio.h>
float small[2] = {__INT_MAX__,__INT_MAX__};

void smallestSecondSmallest(float* arr, int n) {
    for(int i = 0 ; i < n ; i++) {
        if(small[0] > arr[i]) {
            small[1] = small[0];
            small[0] = arr[i];
        } else if(small[1] > arr[i] && arr[i] != small[0]) {
            small[1] = arr[i];
        }
    }
}

int main() {
    int n;

    printf("Enter the size of array:\n");
    scanf("%d",&n);

    float arr[n];
    printf("Enter the elements of array:\n");
    for(int i = 0 ; i < n ; i++) {
        scanf("%f",&arr[i]);
    }

    smallestSecondSmallest(arr,n);

    printf("The smallest number in the array is : %0.2f\n",small[0]);
    if(small[1] == __INT_MAX__) {
        printf("NO second smallest element!");
    } else {
        printf("The second smallest number in the array is : %0.2f",small[1]);
    }

    return 0;
}