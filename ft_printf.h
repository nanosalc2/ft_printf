#ifndef FT_PRINTF_H
#   define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int     ft_printf(const char *format, ...);
int     ft_putchar(char c);
int     ft_putstr(char *s);
int     ft_putnbr(int n);
int     ft_putunbr(unsigned int n);
int     ft_puthex(unsigned int n, int uppercase);
int     ft_putptr(unsigned long ptr);

#endif