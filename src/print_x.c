/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:13:43 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/12 18:03:22 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_X_hex(unsigned int nb)
{
	if (nb >= 16)
	{
		print_X_hex(nb / 16);
		print_X_hex(nb % 16);
	}
	if (nb < 10)
		ft_putchar_fd('0' + nb, 1);
	else if (nb < 16)
		ft_putchar_fd('A' + nb - 10, 1);
}


void	print_x_hex(unsigned int nb)
{
	if (nb >= 16)
	{
		print_x_hex(nb / 16);
		print_x_hex(nb % 16);
	}
	if (nb < 10)
		ft_putchar_fd('0' + nb, 1);
	else if (nb < 16)
		ft_putchar_fd('a' + nb - 10, 1);
}

size_t	x_len(unsigned int nb)
{
	size_t	len;

	len = 0;
	while (nb / 16)
	{
		nb /= 16;
		len++;
	}
	return (len + 1);
}

size_t	calc_x_size(unsigned int x, t_opt opts)
{
	size_t	len;

	len = 0;
	len += x_len(x);
	if (opts.zero)
		len += opts.width;
	return (len);
}

size_t	print_x(t_opt opts, va_list *ap)
{
	unsigned int	x;
	size_t			len;

	x = va_arg(*ap, unsigned int);
	len = x_len((unsigned int)x);
	if (!opts.minus)
		print_c_i(' ', opts.width - max(calc_x_size(x, opts), opts.dot)
			- opts.hash * 2);
	if (opts.hash && x != 0)
	{
		if (opts.type == 'x')
			ft_putstr_fd("0x", 1);
		else
			ft_putstr_fd("0X", 1);
	}
	if (opts.zero)
		print_c_i('0', opts.width - len);
	if (opts.dot != -1)
		print_c_i('0', opts.dot - len);
	if (opts.type == 'x')
		print_x_hex((unsigned int)x);
	else	
		print_X_hex((unsigned int)x);
	if (opts.minus)
		print_c_i(' ', opts.width - max(calc_x_size(x, opts), opts.dot)
			- opts.hash * 2);
	if (x == 0)
		return(max(1, max(opts.width, opts.dot)));
	return (max(len + opts.hash * 2, max(opts.width, opts.dot)));
}
