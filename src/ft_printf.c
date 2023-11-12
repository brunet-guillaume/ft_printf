/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:46:19 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/12 01:51:43 by gbrunet          ###   ########.fr       */
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
	options->dot = -1;
	options->hash = 0;
	options->space = 0;
	options->plus = 0;
	options->length = 0;
	options->type = 0;
}

void	set_type(t_opt *options, char c)
{
	options->type = c;
	if (c == '%')
		ft_putchar_fd('%', 1);
}

void	set_flags(t_opt *options, char c)
{
	if (c == '-')
		options->minus = 1;
	if (c == '0')
		options->zero = 1;
	if (c == '#')
		options->hash = 1;
	if (c == ' ')
		options->space = 1;
	if (c == '+')
		options->plus = 1;
}

size_t	set_precision(const char *s, t_opt *options)
{
	size_t	i;

	i = 0;
	options->dot = 0;
	while (s[++i] && ft_isdigit(s[i]))
	{
		options->dot = options->dot * 10 + (s[i] - '0');
	}
	return (i - 1);
}

size_t percent_parser(const char *s, t_opt *options)
{
	size_t	i;

	init_options(options);
	i = 0;
	while (s[++i] && valid_flag(s[i]) && !options->type)
	{
		if (is_type(s[i]))
			set_type(options, s[i]);
		else if (s[i] == '.')
		{
			i += set_precision(&s[i], options);
			printf("%d", options->dot);
		}
	}
	return (i - 1);
}

size_t	parser(const char *format, va_list *ap)
{
	size_t	i;
	size_t	add;
	t_opt	options;
	//size_t	count;
(void) ap;
	
	i = 0;
	//count = 0;
	while (format[i])
	{
		if(format[i] == '%' && format[i + 1])
		{
			add = percent_parser(&format[i], &options);
			if (options.type)
				i += add;
			else
				ft_putchar_fd('%', 1);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			//count++;
		}
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
	(void) c;
	return (0);
}
