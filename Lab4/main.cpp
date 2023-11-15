#include <iostream>
const int N=59;
static int s[N], a[N]; //s-исходный массив, a-конечный массив
int main() {
    printf("Enter 59 numbers:\n");
    for (int i=0; i<59; i++) {
        scanf("%d", &s[i]);
    }
    printf("\n");
    printf("Your array:\n");
    for (int i=0; i<59; i++) printf("%d ", s[i]);
    printf("\nFinal array:\n");
    for (int j=0; j<=4; j=j+2) {
        for (int i=1; i<=9; i++) {
            a[10*j+i-1]=s[10*j+i-1]; printf("%d ", a[10*j+i-1]);
            a[10*j+i]=s[10*(j+1)+i-1]; printf("%d ", a[10*j+i]);
        }
    }
    printf("\n");
}

