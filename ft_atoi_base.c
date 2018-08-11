/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:34:43 by psaprono          #+#    #+#             */
/*   Updated: 2018/07/23 14:34:46 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_isdigit1(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int		ft_verif(char *str, int *i, int sign)
{
	while (str[*i] == ' ' || str[*i] == '\n' || str[*i] == '\t' ||
			str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
		(*i)++;
	if (str[*i] == '-')
		sign = -1;
	else if (str[*i] == '+')
		sign = 1;
	return (sign);
}

ssize_t			ft_atoi_base(char *str, int base)
{
	int			i;
	ssize_t		res;
	int			sign;

	i = 0;
	res = 0;
	sign = ft_verif(str, &i, 1);
	while (ft_isdigit1(str[i]) == 1 || (str[i] <= 'f' && str[i] >= 'a') ||
			(str[i] <= 'F' && str[i] >= 'A'))
	{
		if (str[i] == '\0')
			return (res);
		res *= base;
		if (ft_isdigit1(str[i]) == 1)
			res += (str[i] - '0') * base;
		else if (str[i] <= 'f' && str[i] >= 'a')
			res += (str[i] - 'a' + 10) * base;
		else if (str[i] <= 'F' && str[i] >= 'A')
			res += (str[i] - 'A' + 10) * base;
		i++;
	}
	return (sign * (res /= base));
}
