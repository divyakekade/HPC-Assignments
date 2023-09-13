//Hello World program using open mp

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
void printMes()
{
    printf("Hello world %d \n", omp_get_thread_num());
}

int main(int argc, char *argv[])
{
#pragma omp parallel num_threads(6)
    printMes();
    return 0;
}
