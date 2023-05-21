#include <stdio.h>
#include <time.h>
int power(int base, int a) {
    if (a != 0)
        return (base * power(base, a - 1));
    else
        return 1;
}

int main() {
    clock_t t;
    t = clock();
    int base, a, result;
    printf("Enter base number: ");
    scanf("%d", &base);
    printf("Enter power number: ");
    scanf("%d", &a);
    result = power(base, a);
    t = clock() - t;
    double timeTaken = ((double)t)/CLOCKS_PER_SEC;
    printf("%d^%d = %d\n", base, a, result);
    printf("time taken: %f\n",timeTaken);
    return 0;
}


