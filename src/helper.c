/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:08:56 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/20 10:49:41 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_d_num(int nb)
{
	long	nbr;

	nbr = nb;
	if (nb < 0)
		nbr = -nbr;
	if (nbr >= 10)
	{
		print_d_num(nbr / 10);
		print_d_num(nbr % 10);
	}
	if (nbr < 10)
		ft_putchar_fd('0' + nbr, 1);
}

size_t	ft_unsigned_intlen(unsigned int u)
{
	size_t	len;

	len = 0;
	while (u / 10 != 0)
	{
		u /= 10;
		len++;
	}
	return (len + 1);
}

size_t	ft_intlen(int d)
{
	size_t	len;

	len = 0;
	while (d / 10 != 0)
	{
		d /= 10;
		len++;
	}
	return (len + 1);
}

void	print_c_i(char c, int i)
{
	while (i-- > 0)
		ft_putchar_fd(c, 1);
}

int	max(int a, int b)
{
	if (b > a)
		return (b);
	return (a);
}
