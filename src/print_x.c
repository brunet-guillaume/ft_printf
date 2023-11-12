/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:13:43 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/12 18:56:31 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_upx_hex(unsigned int nb)
{
	if (nb >= 16)
	{
		print_upx_hex(nb / 16);
		print_upx_hex(nb % 16);
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

void	print_x_prefix(t_opt opts, unsigned int x)
{
	if (opts.hash && x != 0)
	{
		if (opts.type == 'x')
			ft_putstr_fd("0x", 1);
		else
			ft_putstr_fd("0X", 1);
	}
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
	print_x_prefix(opts, x);
	if (opts.zero)
		print_c_i('0', opts.width - len);
	if (opts.dot != -1)
		print_c_i('0', opts.dot - len);
	if (opts.type == 'x')
		print_x_hex((unsigned int)x);
	else
		print_upx_hex((unsigned int)x);
	if (opts.minus)
		print_c_i(' ', opts.width - max(calc_x_size(x, opts), opts.dot)
			- opts.hash * 2);
	if (x == 0)
		return (max(1, max(opts.width, opts.dot)));
	return (max(len + opts.hash * 2, max(opts.width, opts.dot)));
}
