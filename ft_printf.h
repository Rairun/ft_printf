/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:33:44 by psaprono          #+#    #+#             */
/*   Updated: 2018/07/19 15:33:47 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <wchar.h>
# include <stdarg.h>
# include <stdbool.h>
# include "get_next_line.h"
# define BUFF 80
enum			e_conv
{
	d,
	c,
	pr
};

enum			e_size
{
	hh,
	h,
	l,
	ll,
	j,
	z
};

enum			e_flag
{
	hash,
	zero,
	plus,
	minus,
	space
};

typedef	struct	s_buff
{
	char		*buff;
	int			size;
	int			len;
}				t_buff;

typedef struct	s_pf
{
	bool		flags[5];
	bool		conv[15];
	bool		size[6];
}				t_pf;

int				ft_printf(char *fmt, ...);
long			ft_atoi_base(char *str, int base);
char			*ft_itoa_base(intmax_t value, int base);
char			*ft_uitoa_base(uintmax_t value, int base);

#endif
