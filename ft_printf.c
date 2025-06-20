/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlsalc <carlsalc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:56:54 by carlsalc          #+#    #+#             */
/*   Updated: 2025/06/12 20:21:19 by carlsalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_format(char spec, va_list *args)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (spec == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (spec == 'p')
		return (ft_putptr(va_arg(*args, unsigned long)));
	if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (spec == 'u')
		return (ft_putunbr(va_arg(*args, unsigned int)));
	if (spec == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), 0));
	if (spec == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), 1));
	if (spec == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%'&& *(format + 1))
			{
				format++;
				count += ft_format(*format, &args);
			}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
