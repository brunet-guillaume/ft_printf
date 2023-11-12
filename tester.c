/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:50:53 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/12 05:21:48 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	int	d = 1234;
	int d2 = 1590565623;
	int	result;
	result = ft_printf("%+08.6dun%- %%% %10ddeux% trois", d, d2);
	printf("\n%d\n", result);
	return (0);
}
