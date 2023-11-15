#include <iostream>
#include <cmath>

int main () {
//    while (true) {
    double ksi=0, m=1, s=1;
    int k=0;
    printf("Enter ksi:\n");
    scanf("%lf", &ksi);
    while (m>ksi) {
        k++;
        m=m/k;
        s=s+m;
        printf("%0.12lf\n", s);
    }
    printf("s=%.12lf\n%d Iterations\n\n", s, k);
//    }
}

