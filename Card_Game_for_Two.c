#include <stdio.h>
#include <stdlib.h>

int cmpnum(const void * n1, const void * n2)
{
    if (*(int *)n1 > *(int *)n2)
    {
        return -1;
    }
    else if (*(int *)n1 < *(int *)n2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    int* a;
    int *b;
    a = (int *)malloc(sizeof(int) * N);
    if (a == NULL)
    {
        exit(0);
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }

    qsort(a, N, sizeof(int), cmpnum);

    int alice = 0;
    int bob = 0;
    if (N % 2 == 0)
    {
        for (int i = 0; i < N / 2; i++)
        {
            alice += a[2*i];
            bob += a[2*i + 1];
        }
    }else
    {
        for (int i = 0; i < N / 2; i++)
        {
            alice += a[2*i];
            bob += a[2*i + 1];
        }
        alice += a[N - 1];
    }
    printf("%d", alice - bob);
}
