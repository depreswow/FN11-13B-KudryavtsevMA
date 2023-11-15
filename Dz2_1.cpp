#include <iostream>
const int N = 49;
static char array[N];
int main() {
    int n=0;
    puts("Enter integer n (<50):");
    scanf("%d", &n);
    puts("Enter your array: ");
    for (int i=0; i<n; i++) {
        scanf(" %c", &array[i]);
    }
    puts("Your array:");
    for (int i=0; i<n; i++) printf("%c ", array[i]);
    printf("\n");
    int min_i=0;
    char min_c;
    for (int i=0; i<n-1; i++) {
        min_c=array[i];
        min_i=i;
        for (int j=i+1; j<n; j++) {
            if (array[j]<min_c) {min_c=array[j]; min_i=j;};
        }
        array[min_i]=array[i];
        array[i]=min_c;
    }
    puts("Sorted array:");
    for (int i=0; i<n; i++) printf("%c ", array[i]);
    puts("");
}

