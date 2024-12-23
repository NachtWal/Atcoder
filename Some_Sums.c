#include <stdio.h>

int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    double sum = 0;

    for (int i = 1; i < n + 1; i++)
    {
        // 10以下の数字の場合
        if (i < 10 )
        {
            if(i >= a && i <= b)
            {   
                sum += i;
                continue;
            }
        }
        int x;

        // １０以上100未満の数字の場合
        if ( 10 <= i && i < 100)
        {
            x = i % 10 + i / 10;
        }
        // 100以上1000未満の場合
        if (100 <= i && i < 1000)
        {
            x = (i / 100) + (i / 10) % 10 + i % 10;
        }
        // 1000以上10000未満の場合
        if (1000 <= i && i < 10000)
        {
            x = (i / 1000) + (i / 100) % 10 + (i / 10) % 10 + i % 10;
        }
        // 10000の場合
        if (i == 10000)
        {
            x = 1;
        }

        // 最後にジャッジ
        if (x >= a && x <= b)
        {
            sum += i;
        }
    }

    printf("%.0f", sum);
}
