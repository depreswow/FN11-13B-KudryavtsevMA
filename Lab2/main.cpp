#include <iostream>
#include <cmath>

int main() {
    double x=0, y=0;
    printf("Enter x and y:\n");
    scanf("%lf %lf", &x, &y);
    if (1>=pow((x+1), 2) + pow(y, 2)) {
        if (y>=pow((x+1), 2)) {
            printf("Yes\n");
        }
        else printf("x=%lf, y=%lf\nNo, point is below parabola\n", x, y);
    }
    else printf("No, point is not in circle.\n");
}

