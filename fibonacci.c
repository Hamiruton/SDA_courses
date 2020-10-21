#include <stdio.h>

long fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    } else
    {
        long x = fibonacci(n-1);
        long y = fibonacci(n-2);
        return x+y;
    }
    
}

void main()
{
    printf("Fibonacci de n ?\n");
    int n; scanf("%d", &n);
    printf("Le fibonacci de %d est: %ld\n", n, fibonacci(n));
}