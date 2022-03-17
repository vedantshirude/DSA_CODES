#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define MAX 100000000

void input(int *pa, int n);
void output(int *pa, int n, const char *msg);
int partition(int *pa, int p, int r);
void quick_sort(int *pa, int p, int r);
void sort(int *pa, int n);

int main(int argc, char *argv[])
{
    int *pa = NULL;
    int size = 0;

    assert(argc == 2);
    size = atoi(argv[1]);
    assert(size > 0);
    pa = (int *)malloc(size * sizeof(int));
    assert(pa);
    memset(pa, 0, size * sizeof(int));
    input(pa, size);
    if (size < 100)
        output(pa, size, "Before sort :");
    
    sort(pa,size);
    printf("hello");
    output(pa, size, "After sort :");
    free(pa);
    pa = NULL;
    return 0;
}
void input(int *pa, int n)
{
    int i;
    srand(time(0));
    for (i = 0; i < n; i++)
        pa[i] = rand() % MAX;
}
void output(int *pa, int n, const char *msg)
{
    int i;
    if (msg)
        puts(msg);
    for (i = 0; i < n; i++)
        printf("pa[%d] : %d \n", i, pa[i]);
}
int partition(int *pa, int p, int r)
{
    int i, j, tmp, pivot;
    pivot = pa[r];
    i=p-1;
    for (j = p; j < r; j++)
    {
        if (pa[j] <= pivot)
        {
            i = i + 1;
            tmp = pa[i];
            pa[i] = pa[j];
            pa[j] = tmp;
        }
    }
    tmp = pa[i + 1];
    pa[i + 1] = pa[r];
    pa[r] = tmp;

    return (i + 1);
}
void quick_sort(int *pa, int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(pa, p, r);
        quick_sort(pa, p, q - 1);
        quick_sort(pa, q + 1, r);
    }
}
void sort(int *pa, int n)
{
    quick_sort(pa, 0, n - 1);
}