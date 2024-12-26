#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


long N, L, K;
long* a;

bool isAvailable(long);

int main(void)
{
    scanf("%ld %ld", &N, &L);
    scanf("%ld", &K);

    a = (long *)malloc(sizeof(long) * N);
    a[0] = 0;
    for (int i = 0; i < N ; i++)
    {
        scanf("%ld", &a[i]);
    }

    long left = -1;
    long right = L + 1;
    while (right - left > 1)
    {
        long mid = (right + left) / 2;
        if (isAvailable(mid))
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    printf("%ld", left);
    return 0;
}

bool isAvailable(long x)
{
    long count = 0;
    long preCut = 0;

    for (int i = 0; i < N; i++)
    {
        if (a[i] - preCut >= x)
        {
            ++count;
            preCut = a[i];
        }
    }
    if (L - preCut >= x)
    {
        ++count;
    }
    return (count >= K + 1);
}
