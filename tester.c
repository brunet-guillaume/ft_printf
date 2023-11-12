/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:50:53 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/12 18:01:56 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int i;
	i = ft_printf("|%-9X|%-10X|%-11X|%-12X|%-13X|%-14X|%-15X|", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("%d\n", i);
	i = printf("|%-9X|%-10X|%-11X|%-12X|%-13X|%-14X|%-15X|", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("%d\n\n", i);
	i = ft_printf("|%-11X|%-12X|%-13X|%-14X|%-15X|", LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("%d\n", i);
	i = printf("|%-11X|%-12X|%-13X|%-14X|%-15X|", LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("%d\n\n", i);
	i = ft_printf("|%-13X|%-14X|%-15X|", ULONG_MAX, 0, -42);
	printf("%d\n", i);
	i = printf("|%-13X|%-14X|%-15X|", ULONG_MAX, 0, -42);
	printf("%d\n\n", i);
	i = ft_printf("|%-9X|%-10X|", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("%d\n", i);
	i = printf("|%-9X|%-10X|", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("%d\n\n", i);
	i = ft_printf("|%-11X|%-12X|", LONG_MAX, LONG_MIN);
	printf("%d\n", i);
	i = printf("|%-11X|%-12X|", LONG_MAX, LONG_MIN);
	printf("%d\n\n", i);
	return (0);
}
