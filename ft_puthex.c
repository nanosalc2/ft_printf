/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlsalc <carlsalc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:39:51 by carlsalc          #+#    #+#             */
/*   Updated: 2025/06/12 20:39:38 by carlsalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int uppercase)
{
	int		count;
	char	*base;

	if (n < 16)
	{
		if (uppercase == 0)
		{
			base = "0123456789abcdef";
			return (ft_putchar(base[n]));
		}
		else
		{
			base = "0123456789ABCDEF";
			return (ft_putchar(base[n]));
		}
	}
	else
	{
		count = ft_puthex(n / 16, uppercase);
		return (count + ft_puthex(n % 16, uppercase));
	}
}
