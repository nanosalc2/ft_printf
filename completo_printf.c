#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>


int print_char(int c)
{
    return (write(1, &c, 1));
}

int print_str(char *str)
{
    int count;

    count = 0;
    while (*str != '\0')
    {
        print_char((int)*str);
        count++;
        str++;
    }
    return (count);
}

int print_digit(long n, int base)
{
    int count;
    char *symbols;
    symbols = "0123456789abcdef";
    if (n < 0)
    {
        write(1, "-", 1);
        return (print_digit(n * -1, base) + 1); 
    }
    else if (n < base)
        return (print_char(symbols[n]));
    else
    {
        count = print_digit(n / base, base);
        return (count + print_digit(n % base, base));
    }

}

int	print_format(char specifier, va_list ap)
{
    int count;

    count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd')
		count += print_digit((long)(va_arg(ap, int)), 10);
	else if (specifier == 'x')
		count += print_digit((long)(va_arg(ap, unsigned int)), 16);
	else
		count += write(1, &specifier, 1);
	return (count);
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int count;

    va_start(ap, format);
    count = 0;
    while (*format != '\0')
    {
        if (*format == '%')
            count += print_format(*(++format), ap);
        else
            count += write(1, format, 1);
        ++format;
    }
    va_end(ap);
    return (count);
}

int main()
{ 
    int count;

    // count = my_printf("%x\n", -100);
    // my_printf("the chars written are %d\n", count);
    // count = printf("%x\n", -100);
    // printf("the chars written are %d\n", count);
    // printf("este de la printf i: %i %i\n", 14, -14);
    // ft_printf("este de la ft_printf i: %i %i\n", 14, -14);

    printf("este de la printf d: %d\n",-14);
    my_printf("este de la ft_printf d: %d\n",-14);
    count = my_printf("%d\n", -14);
    my_printf("the chars written are %d\n", count);

    // printf("este de la printf s: %s\n", "toma");
    // ft_printf("este de la ft_printf s: %s\n", "toma");

    // printf("este de la printf c: %c\n", 'c');
    // ft_printf("este de la ft_printf c: %c\n", 'c');
    
    // printf("este de la printf x: %x\n", -1400);
    // ft_printf("este de la ft_printf x: %x\n", -1400);
    
    // printf("este de la printf X: %X\n", -1400);
    // ft_printf("este de la ft_printf X: %X\n", -1400);

    // printf("este de la printf p: %p\n", i);
    // ft_printf("este de la ft_printf p: %p\n", i); 
}