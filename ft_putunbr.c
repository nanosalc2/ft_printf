#include "ft_printf.h"

static int  ft_unumlen(unsigned int n)
{
    int len = 1;
    while (n /= 10)
        len++;
    return len;
}

int ft_putunbr(unsigned int n)
{
    char buffer[11];
    int len = ft_unumlen(n);

    buffer[len] = '\0';
    while (len--)
    {
        buffer[len] = n % 10 + '0';
        n /= 10;
    }
    return ft_putstr(buffer);
}