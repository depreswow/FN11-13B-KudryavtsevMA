#include <iostream>
#include <cmath>

int main() {
    int x=0, k=0, i=1;
    bool p=false;
    printf("Enter x, k:\n");
    scanf("%d %d", &x, &k);
//    for (i; i<=k; i++) {
//        if (sin(pow(x, i))<0) p=true;
//    }
    while ((not p) and (i<=k)) {
        if (sin(pow(x, i))<0) p=true;
        i++;
    }
//    do {
//        if (sin(pow(x, i))<0) {
//            p=true;
//        }
//        i++;
//    } while ((i<=k) and (not p));
    if (p) printf("True\n");
    else printf("False\n");

}
