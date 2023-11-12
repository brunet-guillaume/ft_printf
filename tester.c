/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:50:53 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/12 14:27:29 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	int	d = -1234;
	int c = 't';
	char s[] = "salut ca va gars";
	int	result;
	result = ft_printf("%+08.6d|\n%-8c|\n%+ 08.15s|\n%-+ 018.15p|\n%+28.15i|\n%+28.15u|\n", d, c, s, s, d, -123);
	printf("--%u--", -1234);
	printf("\n%d\n", result);
	return (0);
}
