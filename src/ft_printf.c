/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:46:19 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/12 10:13:29 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h" 

size_t	print_value(t_opt options, va_list *ap)
{
	size_t	len;

	len = 1;
	if (options.type == 'c')
		len = print_c(options, ap);
	if (options.type == 'd')
		len = print_d(options, ap);
	return (len);
}

size_t	parser(const char *format, va_list *ap)
{
	size_t	i;
	size_t	add;
	t_opt	options;
	size_t	count;
	
	i = 0;
	count = 0;
	while (format[i])
	{
		if(format[i] == '%' && format[i + 1])
		{
			add = percent_parser(&format[i], &options);
			if (options.type)
			{
				i += add;
				count += print_value(options, ap) - 1;
			}
			else
				ft_putchar_fd('%', 1);
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
		count++;	
	}
	return(count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	count;

	va_start(ap, format);
	count = parser(format, &ap);
	return (count);
}
