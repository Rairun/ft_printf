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

#include <stdarg.h>
# include "get_next_line.h"

typedef struct  s_types
{
	int				d;
	unsigned long	lu;
	char			c;
	char			*s;
	void			*v;
}               t_types;

int     ft_printf(char *fmt, ...);
char	*ft_itoa_base(unsigned long value, int base);

#endif
