/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:46:19 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/12 09:32:26 by gbrunet          ###   ########.fr       */
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
	options->width = 0;
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
		options->dot = options->dot * 10 + (s[i] - '0');
	return (i - 1);
}

size_t	set_width(const char *s, t_opt *options)
{
	size_t	i;

	i = 0;
	while (s[i] && ft_isdigit(s[i]))
	{
		options->width = options->width * 10 + (s[i] - '0');
		i++;
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
			i += set_precision(&s[i], options);
		else if (is_flag(s[i]))
			set_flags(options, s[i]);
		else if (ft_isdigit(s[i]))
			i += set_width(&s[i], options);
	}
	return (i - 1);
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
	char	*s;

	d = va_arg(*ap, int);
	s = ft_itoa(d);
	if (!s)
		return (0);
	if (!opts.minus)
		print_c_i(' ', opts.width - max(ft_intlen(d), opts.dot)
			- max(opts.plus, opts.space));
	print_int_sign(opts, d);
	if (opts.dot)
		print_c_i('0', opts.dot - ft_intlen(d));
	if (d < 0)
		ft_putstr_fd(&s[1], 1);
	else
		ft_putstr_fd(s, 1);
	if (opts.minus)
		print_c_i(' ', opts.width - max(ft_intlen(d), opts.dot)
			- max(opts.plus, opts.space));
	free(s);
	return (get_int_size(opts, d));
}

size_t	print_c(t_opt opts, va_list *ap)
{
	char	c;
	c = (char)va_arg(*ap, int);

	if (!opts.minus)
		print_c_i(' ', opts.width - 1);
	ft_putchar_fd(c, 1);
	if (opts.minus)
		print_c_i(' ', opts.width - 1);
	return (max(1, opts.width));
}

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
