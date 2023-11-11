/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:46:19 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/11 23:47:42 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h" 

int is_flag(char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

int is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	valid_flag(char c)
{
	if (is_flag(c) || is_type(c) || ft_isdigit(c))
		return (1);
	return (0);
}

void	init_options(t_opt *options)
{
	options->minus = 0;
	options->zero = 0;
	options->dot = 0;
	options->hash = 0;
	options->space = 0;
	options->plus = 0;
	options->length = 0;
	options->type = '0';
}

void	set_type(t_opt *options, char c)
{
	options->type = c;
}

size_t percent_parser(const char *percent, t_opt *options)
{
	size_t	i;

	init_options(options);
	i = 0;
	while (percent[i++] && valid_flag(percent[i]) && options->type == '0')
	{
		if (is_type(percent[i]))
			set_type(options, percent[i]);
	}
	printf("%ld", i);
	return (i);
}

size_t	parser(const char *format, va_list *ap)
{
	size_t	i;
	t_opt	options;
(void) ap;
	
	i = 0;
	while (format[i])
	{
		if(format[i] == '%' && format[i + 1])
			i += percent_parser(&format[i], &options);
		else
			ft_putchar_fd(format[i], 1);
		i++;
		
	}
	return(0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	c;

	va_start(ap, format);
	c = parser(format, &ap);
	printf("%ld", c);
	return (0);
}
