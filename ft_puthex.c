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
	char	buffer[9];
	char	*base;
	int		i;

	base = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	i = 8;
	buffer[i] = '\0';
	if (n == 0)
		return (write(1, "0", 1));
	while (n && i--)
	{
		buffer[i] = base[n % 16];
		n /= 16;
	}
	return (ft_putstr(&buffer[i + 1]));
}
