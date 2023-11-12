/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:08:56 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/12 10:09:23 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
