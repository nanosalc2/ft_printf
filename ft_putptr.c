#include "ft_printf.h"

int ft_putptr(unsigned long ptr)
{
    char buffer[17];
    char *base = "0123456789abcdef";
    int i = 16;

    buffer[i] = '\0';
    if (ptr == 0)
        return write(1, "(nil)", 5);
    while (ptr && i--)
    {
        buffer[i] = base[ptr % 16];
        ptr /= 16;
    }
    write(1, "0x", 2);
    return 2 + ft_putstr(&buffer[i + 1]);
}