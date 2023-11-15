#include <iostream>
const int N = 6;
static double array1[N], array2[N];
double sum(double array[N]);
double product(double array[N]);
bool is_in_array (double number, double array[N]);
int main () {
    puts("Enter array 1:");
    for (int i=0; i<N; i++) scanf("%lf", &array1[i]);
    puts("Enter array 2:");
    for (int i=0; i<N; i++) scanf("%lf", &array2[i]);
    printf("\nArray1 is: "); for (int i=0; i<N; i++) printf("%lf ", array1[i]);
    printf("\nArray2 is: "); for (int i=0; i<N; i++) printf("%lf ", array2[i]);
    double sum1=sum(array1), sum2=sum(array2), pr1=product(array1), pr2=product(array2);
    printf("\n\nSum of array 1 is %lf\nSum of array 2 is %lf\n", sum1, sum2);
    printf("\nProduct of array 1 is %lf\nProduct of array 2 is %lf\n", pr1, pr2);
    printf("\nElements in both arrays are: ");
    for (int i=0; i<6; i++) {
        if (is_in_array(array1[i], array2)) printf("%lf ", array1[i]);
    }
    puts("");
}

double sum(double array[N]) {
    double s=0;
    for (int i=0; i<N; i++) s=s+array[i];
    return s;
}
double product(double array[N]) {
    double pr=1;
    for (int i=0; i<N; i++) pr=pr*array[i];
    return pr;
}
bool is_in_array (double number, double array[N]) {
    for (int i=0; i<N; i++) {
        if (number==array[i]) return true;
    }
    return false;
}
