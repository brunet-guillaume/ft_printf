/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:02:18 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/12 14:43:09 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_d_num(int nb)
{
	long	nbr;

	if (nb < 0)
		nbr = -nb;
	else
		nbr = nb;
	if (nbr >= 10)
	{
		print_d_num(nbr / 10);
		print_d_num(nbr % 10);
	}
	if (nbr < 10)
		ft_putchar_fd('0' + nbr, 1);
}

void	print_int_sign(t_opt opts, int d)
{
	if (d < 0)
		ft_putchar_fd('-', 1);
	if (opts.plus && d >= 0)
		ft_putchar_fd('+', 1);
	if (opts.space && !opts.plus && d >= 0)
		ft_putchar_fd(' ', 1);
}

size_t	get_int_size(t_opt opts, int d)
{
	size_t	len;
	size_t	sign;
	
	sign = 0;
	if (opts.space || opts.plus || d < 0)
		sign = 1;
	len = max(ft_intlen(d) + sign, opts.dot);
	len = max(len, opts.width);
	return (len);
}

size_t	print_d(t_opt opts, va_list *ap)
{
	int		d;

	d = va_arg(*ap, int);
	if (!opts.minus)
		print_c_i(' ', opts.width - max(ft_intlen(d), opts.dot)
			- max(opts.plus, opts.space));
	print_int_sign(opts, d);
	if (opts.dot != -1)
		print_c_i('0', opts.dot - ft_intlen(d));
	print_d_num(d);
	if (opts.minus)
		print_c_i(' ', opts.width - max(ft_intlen(d), opts.dot)
			- max(opts.plus, opts.space));
	return (get_int_size(opts, d));
}
