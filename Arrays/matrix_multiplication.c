// WAP for matrix multiplication in C

#include <stdio.h>

int main() {
    int n , m , x , y;
    printf("Enter the no of rows and column of Matrix A:\n");
    scanf("%d%d",&n,&m);

    printf("Enter the no of rows and column of Matrix B:\n");
    scanf("%d%d",&x,&y);
    
    if(m != x) {
        printf("These matrix will not be compatible for multiplication. Try again!!\n");
        return 0;
    }

    int a[n][m], b[x][y], c[n][y];

    printf("Enter the elements of matrix A:\n");
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0; j < m ; j++) {
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter the elements of matrix B:\n");
    for(int i = 0 ; i < x ; i++) {
        for(int j = 0; j < y ; j++) {
            scanf("%d",&b[i][j]);
        }
    }

    int sum;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m; j++) {
            sum = 0;
            for(int k = 0 ; k < y ; k++) {
                sum += (a[i][k] * b[k][j]);
            }
            c[i][j] = sum;
        }
    }

    printf("Matrix A:\n");
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B:\n");
    for(int i = 0 ; i < x ; i++) {
        for(int j = 0 ; j < y ; j++) {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }

    printf("Matrix C:\n");
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < y ; j++) {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }

    return 0;
}