#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT (10000000000000000)

void input(int *pa, int n);
void output(int *pa, int n, const char *msg);
void sort(int *pa, int n);
void insert_at_sorting_pos(int *pa, int n);
void insertion_sort(int *pa, int n);

int main(int argc, char *argv[])
{
    int *pa = NULL;
    int n = 0;

    if (argc != 2)
    {
        fprintf(stderr, "Usage error %s nr_elements \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    n = atoi(argv[1]);
    if (n <= 0)
    {
        fprintf(stderr, "Bad size for array\n");
        exit(EXIT_FAILURE);
    }
    pa = (int *)malloc(n * sizeof(int));
    if (pa == NULL)
    {
        fprintf(stderr, "out of memory\n");
        exit(EXIT_FAILURE);
    }
    input(pa, n);
    if (n <= 100)
        output(pa, n, "before sort:");
    time_t start_time = time(0);
    sort(pa, n);
    time_t end_time = time(0);
    output(pa, n, "After sort:");
    printf("End_time - Start_time = %lu\n", end_time - start_time);
    free(pa);
    pa = NULL;
    printf("%s",argv[0]);

    exit(EXIT_SUCCESS);

    // return 0;
}
void input(int *pa, int n)
{
    int i;
    srand(time(0));
    for (i = 0; i < n; i++)
        pa[i] = rand() % 6;
}
void output(int *pa, int n, const char *msg)
{
    int i;
    if (msg)
        puts(msg);
    for (i = 0; i < n; i++)
        printf("pa[%d] : %d\n",i, pa[i]);
}
void insert_at_sorting_pos(int *pa, int n)
{
    int key, i;
    key = pa[n - 1];
    i = n - 2;
    while (i > -1 && pa[i] > key)
    {
        pa[i + 1] = pa[i];
        i = i - 1;
    }
    pa[i + 1] = key;
}
void insertion_sort(int *pa, int n)
{
    int i;
    if (n < 2)
        return;
    for (i = 2; i <= n; i++)
        insert_at_sorting_pos(pa, i);
}
void sort(int *pa, int n)
{
    insertion_sort(pa, n);
}