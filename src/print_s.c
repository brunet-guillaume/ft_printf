/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:13:43 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/12 10:40:58 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	print_s(t_opt opts, va_list *ap)
{
	char	*s;
	size_t	slen;

	s = va_arg(*ap, char*);
	if (opts.dot != -1)
		s = ft_substr(s, 0, opts.dot);
			if (!s)
				return (0);
	if (!opts.minus)
		print_c_i(' ', opts.width - ft_strlen(s));
	ft_putstr_fd(s, 1);
	if (opts.minus)
		print_c_i(' ', opts.width - ft_strlen(s));
	slen = ft_strlen(s);
	free(s);
	return (max(slen, opts.width));
}
