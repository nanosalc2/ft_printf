#include "ft_printf.h"

static int  ft_numlen(int n)
{
    int len = (n <= 0);
    while (n)
    {
        len++;
        n /= 10;
    }
    return len;
}

int ft_putnbr(int n)
{
    char buffer[12];
    int len = ft_numlen(n);
    int neg = (n < 0);
    unsigned int nb = neg ? -n : n;

    buffer[len] = '\0';
    while (len-- > neg)
    {
        buffer[len] = nb % 10 + '0';
        nb /= 10;
    }
    if (neg)
        buffer[0] = '-';
    return ft_putstr(buffer);
}