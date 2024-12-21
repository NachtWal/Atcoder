#include <stdio.h>

int main()
{
    double a, b, c;
    char s[100];
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    scanf("%s", s);
    printf("%.0f %s", a + b + c, s);

}