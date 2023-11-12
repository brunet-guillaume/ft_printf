/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:50:53 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/12 09:34:12 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	int	d = 1234;
	int c = 't';
	int	result;
	result = ft_printf("%+08.6d|\n%-8c|\n", d, c);
	printf("\n%d\n", result);
	return (0);
}
