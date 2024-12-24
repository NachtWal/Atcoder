#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);
    int* a;
    int *b;
    a = (int *)malloc(sizeof(int) * N);
    b = (int *)malloc(sizeof(int) * N);
    if (a == NULL || b == NULL)
    {
        exit(0);
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int j = 0; j < N; j++)
    {
        int index = j;
        int x = a[j];
        for (int k = 0; k < N; k++)
        {
            if (x < a[k])
            {
                x = a[k];
                index = k;
            }
        }
        b[j] = x;
        a[index] = 0;
    }

    int alice = 0;
    int bob = 0;
    if (N % 2 == 0)
    {
        for (int i = 0; i < N / 2; i++)
        {
            alice += b[2*i];
            bob += b[2*i + 1];
        }
    }else
    {
        for (int i = 0; i < N / 2; i++)
        {
            alice += b[2*i];
            bob += b[2*i + 1];
        }
        alice += b[N - 1];
    }
    printf("%d", alice - bob);
}
