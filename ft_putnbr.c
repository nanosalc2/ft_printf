/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlsalc <carlsalc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:39:59 by carlsalc          #+#    #+#             */
/*   Updated: 2025/06/12 20:56:08 by carlsalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(int n)
{
	int	len;

	len = (n <= 0);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	char			buffer[12];
	int				len;
	int				neg;
	unsigned int	nb;

	neg = (n < 0);
	len = ft_numlen(n);
	nb = neg ? -n : n;
	buffer[len] = '\0';
	while (len-- > neg)
	{
		buffer[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (neg)
		buffer[0] = '-';
	return (ft_putstr(buffer));
}
