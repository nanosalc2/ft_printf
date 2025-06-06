#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int print_char(int c)
{
    return write(1, &c, 1);
}

int print_str(char *str)
{
    int i;

    i = 0;
    while (*str)
    {
        print_char((int)*str);
        i++;
        str++;
    }
    return i;
}

int ft_print_format(char specifier, va_list ap)
{
    int count;

    count = 0;
    if (specifier == 'c')
        count += print_char(va_arg(ap, int));
    else if (specifier == 's')
        count += print_str(va_arg(ap, char *));
    else if (specifier == 'd')
        count += print_digit(va_arg(ap, int), 10);
    else if (specifier == 'x')
        count += print_digit(va_arg(ap, unsigned int), 16);
    else
        count += write(1, &specifier, 1);
    return count;
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int     count;

    va_start(ap, format);
    count = 0;
    while (*format != '\0')
    {
        if (*format == '%')
            count += ft_print_format(*(++format), ap);
        else
            count += write(1, format, 1);
        format++;
    }
    va_end(ap);
    return count;
}