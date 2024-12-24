#include <stdio.h>
#include <stdlib.h>

int compnum(const void * n1, const void * n2)
{
    return *(int *)n1 - *(int *)n2;
}

int main()
{
    int N;
    int* d;

    scanf("%d", &N);
    d = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &d[i]);
    }

    qsort(d, N, sizeof(int), compnum);

    int count = 1;
    for (int i = 0; i < N - 1; i++)
    {
        if (d[i] != d[i+1])
        {
            ++count;
        }
    }
    printf("%d", count);
}
