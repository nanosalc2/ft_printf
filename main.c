#include "ft_printf.h"

int main()
{ 
    int i = 42;
    printf("este de la printf i: %i\n",-14);
    ft_printf("este de la ft_printf i: %i\n", -14);

    printf("este de la printf d: %d\n", -14);
    ft_printf("este de la ft_printf d: %d\n", -14);

    printf("este de la printf s: %s\n", "toma");
    ft_printf("este de la ft_printf s: %s\n", "toma");

    printf("este de la printf c: %c\n", 'c');
    ft_printf("este de la ft_printf c: %c\n", 'c');
    
    printf("este de la printf x: %x\n", -1);
    ft_printf("este de la ft_printf x: %x\n", -1);
    
    printf("este de la printf X: %X\n", -1);
    ft_printf("este de la ft_printf X: %X\n", -1);

    printf("este de la printf p: %p\n", i);
    ft_printf("este de la ft_printf p: %p\n", i); 
}