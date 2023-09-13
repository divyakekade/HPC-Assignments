#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    clock_t start, end;
    start = clock();
    int n = 10000;
    int a[n], c[n];
    int b = 4;

#pragma omp parallel for schedule(static, 100) firstprivate(b) num_threads(4)
    for (int i = 0; i < n; i++)
    {
        a[i] = 5;
        c[i] = a[i] + b;
        printf("%d ", c[i]);
    }

    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f", duration);

    return 0;
}