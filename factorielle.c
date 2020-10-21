#include <stdio.h>

long factorielle(int n)
{
    if (n == 0)
    {
        return 1;
    } else
    {
        long y = factorielle(n-1);
        return n*y;
    }
    
}

void main()
{
    while (1)
    {
        printf("Entier dont on veut le factorielle (n<14) ?\n");
        int n; scanf("%d", &n);
        printf("Factorielle de %d est: %li\n", n, factorielle(n));
        if (n == 0001)
        {
            break;
        }
    }
}