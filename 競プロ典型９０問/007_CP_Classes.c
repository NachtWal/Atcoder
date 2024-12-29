#include <stdio.h>
#include <stdlib.h>

int compnum(const void *n1, const void *n2)
{
    return *(int *)n1 - *(int *)n2;
}

int main(void)
{
    int n;
    int q;
    long *a;
    long *b;
    scanf("%d", &n);
    a = (long *)calloc(n, sizeof(long));
    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &a[i]);
    }

    qsort(a, n, sizeof(long), compnum);

    scanf("%d", &q);
    b = (long *)calloc(q, sizeof(long));
    for (int i = 0; i < q; i++)
    {
        scanf("%ld", &b[i]);
    }

    for (int i = 0; i < q; i++)
    {
        
        int left = 0;
        int right = n - 1;
        if (b[i] < a[left])
        {
            printf("%ld\n", a[left] - b[i]);
            continue;
        }
        if (b[i] > a[right])
        {
            printf("%ld\n", b[i] - a[right]);
            continue;
        }

        while(right - left > 1)
        {
            int mid = (left + right) / 2;
            if(b[i] < a[mid])
            {
                right = mid;
            }
            else if (b[i] > a[mid])
            {
                left = mid;
            }
            else
            {
                right = mid;
                left = mid;
                break;
            }
        }

        if (right == left)
        {
            printf("0\n");
            continue;
        }

        if (a[right] - b[i] > b[i] - a[left])
        {
            printf("%ld\n", b[i] - a[left]);
        }
        else
        {
            printf("%ld\n", a[right] - b[i]);
        }
    }
}
