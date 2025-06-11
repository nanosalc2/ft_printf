#include "ft_printf.h"

int ft_puthex(unsigned int n, int uppercase)
{
    char buffer[9];
    char *base = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    int i = 8;

    buffer[i] = '\0';
    if (n == 0)
        return write(1, "0", 1);
    while (n && i--)
    {
        buffer[i] = base[n % 16];
        n /= 16;
    }
    return ft_putstr(&buffer[i + 1]);
}