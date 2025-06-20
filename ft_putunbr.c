/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlsalc <carlsalc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:40:09 by carlsalc          #+#    #+#             */
/*   Updated: 2025/06/12 21:50:38 by carlsalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unumlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_putunbr(unsigned int n)
{
	char	buffer[11];
	int		len;

	len = ft_unumlen(n);
	buffer[len] = '\0';
	while (len--)
	{
		buffer[len] = n % 10 + '0';
		n /= 10;
	}
	return (ft_putstr(buffer));
}
