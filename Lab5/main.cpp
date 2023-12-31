#include <iostream>
const int N=11;
static int matrix[N][N];
int main() {
    int n=0, upper_sum=0, lower_sum=0;
    printf("Enter integer n (<=11):\n");
    scanf("%d", &n);
    puts("Matrix:");
    for (int i=0; i<=n-1; i++) {
        for (int j=0; j<=n-1; j++) {
            matrix[i][j] = rand() % 10;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i=0; i<=n/2-1; i++) {
        for (int j=i; j<=n-1-i; j++) {
            if (matrix[i][j]%2==0) upper_sum=upper_sum+matrix[i][j];
            if (matrix[n-1-i][j]%2==0) lower_sum=lower_sum+matrix[n-1-i][j];
        }
    }
    if (n%2!=0) {
        if (matrix[(n-1)/2][(n-1)/2]%2==0) upper_sum=upper_sum+matrix[(n-1)/2][(n-1)/2];
    }
    printf("upper sum = %d\n", upper_sum);
    printf("lower_sum = %d\n", lower_sum);
}

