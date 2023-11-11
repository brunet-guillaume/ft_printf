/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:46:19 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/11 21:53:07 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h" 

int	parser(const char *format, va_list *ap)
{
	size_t	i;

	i = 0;
	while (format[i])
	{
		if(format[i] == '%')
			printf("une var");
		i++;
	}
	return(0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		c;

	va_start(ap, format);
	c = parser(format, &ap);

	return (0);
}
