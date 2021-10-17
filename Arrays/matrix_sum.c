// WAP to add two matrixes in C
#include <stdio.h>

int main() {
    int n , m;
    printf("Enter the no of rows and columns of matrices:\n");
    scanf("%d%d",&n,&m);

    int a[n][m] , b[n][m] , c[n][m];

    printf("Enter the elements of Matrix A:\n");
    for(int i = 0 ;i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter the elements of Matrix B:\n");
    for(int i = 0 ;i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            scanf("%d",&b[i][j]);
        }
    }

    for(int i = 0 ;i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("Matrix A :\n");
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B :\n");
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    
    printf("Matrix C :\n");
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }

    return 0;
}