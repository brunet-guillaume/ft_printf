/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:52:02 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/12 19:02:37 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_opt {
	int		minus;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		plus;
	int		width;
	char	type;
}	t_opt;

int		is_flag(char c);
int		is_type(char c);
int		max(int a, int b);
int		valid_flag(char c);
int		ft_printf(const char *s, ...);

void	print_d_num(int nb);
void	print_c_i(char c, int i);
void	init_options(t_opt *options);
void	set_type(t_opt *options, char c);
void	set_flags(t_opt *options, char c);
void	print_int_sign(t_opt opts, int d);

size_t	ft_intlen(int d);
size_t	x_len(unsigned int nb);
size_t	get_int_size(t_opt opts, int d);
size_t	print_c(t_opt opts, va_list *ap);
size_t	print_s(t_opt opts, va_list *ap);
size_t	print_p(t_opt opts, va_list *ap);
size_t	print_u(t_opt opts, va_list *ap);
size_t	print_x(t_opt opts, va_list *ap);
size_t	print_d(t_opt opts, va_list *ap);
size_t	ft_unsigned_intlen(unsigned int u);
size_t	calc_x_size(unsigned int x, t_opt opts);
size_t	set_width(const char *s, t_opt *options);
size_t	set_precision(const char *s, t_opt *options);
size_t	percent_parser(const char *s, t_opt *options);
size_t	get_unsigned_int_size(t_opt opts, unsigned int u);

#endif
