#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    char *str = "Hola 42";
    char c = 'Z';
    int i = 42;
    int neg = -42;
    unsigned int u = 4294967295;
    void *ptr = str;
    int hex = 255;

    printf("\n--- PRUEBA FORMATO %%c ---\n");
    printf("printf   : [%c]\n", c);
    ft_printf("ft_printf: [%c]\n", c);

    printf("\n--- PRUEBA FORMATO %%s ---\n");
    printf("printf   : [%s]\n", str);
    ft_printf("ft_printf: [%s]\n", str);

    printf("\n--- PRUEBA FORMATO %%p ---\n");
    printf("printf   : [%p]\n", ptr);
    ft_printf("ft_printf: [%p]\n", ptr);

    printf("\n--- PRUEBA FORMATO %%d y %%i ---\n");
    printf("printf   : [%d] [%i]\n", neg, i);
    ft_printf("ft_printf: [%d] [%i]\n", neg, i);

    printf("\n--- PRUEBA FORMATO %%u ---\n");
    printf("printf   : [%u]\n", u);
    ft_printf("ft_printf: [%u]\n", u);

    printf("\n--- PRUEBA FORMATO %%x ---\n");
    printf("printf   : [%x]\n", hex);
    ft_printf("ft_printf: [%x]\n", hex);

    printf("\n--- PRUEBA FORMATO %%X ---\n");
    printf("printf   : [%X]\n", hex);
    ft_printf("ft_printf: [%X]\n", hex);

    printf("\n--- PRUEBA FORMATO %% ---\n");
    printf("printf   : [%%]\n");
    ft_printf("ft_printf: [%%]\n");

    printf("\n--- PRUEBA COMBINADA ---\n");
    printf("printf   : char: %c, str: %s, ptr: %p, int: %d, uint: %u, hex: %x, HEX: %X, %%\n",
        c, str, ptr, i, u, hex, hex);
    ft_printf("ft_printf: char: %c, str: %s, ptr: %p, int: %d, uint: %u, hex: %x, HEX: %X, %%\n",
        c, str, ptr, i, u, hex, hex);

    return 0;
}
