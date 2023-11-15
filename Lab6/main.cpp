#include <iostream>

const int N=10, M=10;
static int matrix[N][M];
void reverse_row (int matrix[N][M], int r);
int n=0, m=0;

int main() {
    printf("Enter integer n and m (<=10):\n");
    scanf("%d %d", &n, &m);
    printf("\nEnter your matrix:\n\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\nYour matrix:\n\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    for (int i=0; i<m; i=i+2) {
        reverse_row(matrix, i);
    }
    printf("\nNew matrix:\n\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void reverse_row (int matrix[N][M], int r) {
    int buffer;
    for (int i=0; i<n/2; i++) {
        buffer=matrix[n-1-i][r];
        matrix[n-1-i][r]=matrix[i][r];
        matrix[i][r]=buffer;
    }
}

