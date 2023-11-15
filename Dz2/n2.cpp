#include <iostream>
const int N=8, M=12;
static char matrix[N][M];
static int b[M];
int main () {
    int n=0, m=0, star_counter, space_counter;
    puts("Enter integer n(<=8) and m(<=12):");
    scanf("%d %d", &n, &m);
    puts("Enter your matrix(w/o separating characters with space):");
    for (int i=0; i<n; i++) {
        scanf("%*c");
        for (int j=0; j<m; j++) scanf("%c", &matrix[i][j]);
    }
    puts("Your matrix");
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%c ", matrix[i][j]);
        }
        puts("");
    }
    for (int i=0; i<m; i++) {
        star_counter=0, space_counter=0;
        for (int j=0; j<n; j++) {
            if (matrix[j][i] == '*') star_counter++;
            else if (matrix[j][i] == ' ') space_counter++;
        }
        if (star_counter>=space_counter) b[i]=1;
        else b[i]=0;
    }
    puts("Generated array:");
    for (int i=0; i<m; i++) printf("%d ", b[i]);
    puts("");
}

