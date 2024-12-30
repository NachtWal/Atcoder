#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, Q;
    int *C;
    int *P;
    int *L;
    int *R;
    scanf("%d", &N);

    C = (int *)calloc(N, sizeof(int));
    P = (int *)calloc(N, sizeof(int));

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &C[i], &P[i]);
    }

    scanf("%d", &Q);

    L = (int *)calloc(Q, sizeof(int));
    R = (int *)calloc(Q, sizeof(int));

    for (int i = 0; i < Q; i++)
    {
        scanf("%d %d", &L[i], &R[i]);
    }

    int *sum1;
    int *sum2;

    sum1 = (int *)calloc(N, sizeof(int));
    sum2 = (int *)calloc(N, sizeof(int));

    if (C[0] == 1)
    {
        sum1[0] = P[0];
        sum2[0] = 0;
    }
    else if (C[0] == 2)
    {
        sum1[0] = 0;
        sum2[0] = P[0];
    }

    /* 累積和を求めておく */
    for (int i = 1; i < N; i++)
    {
        if (C[i] == 1)
        {
            sum1[i] = sum1[i - 1] + P[i];
            sum2[i] = sum2[i - 1];
        }
        else if(C[i] == 2)
        {
            sum1[i] = sum1[i - 1];
            sum2[i] = sum2[i - 1] + P[i];
        }
    }

    /* 累積和の差で区間の合計を求める */
    for (int i = 0; i < Q; i++)
    {
        printf("%d %d", sum1[R[i] - 1] - sum1[L[i] - 2], sum2[R[i] - 1] - sum2[L[i] - 2]);
        if (i != Q - 1)
        {
            printf("\n");
        }
    }
}
