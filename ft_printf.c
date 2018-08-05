/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 16:13:57 by psaprono          #+#    #+#             */
/*   Updated: 2018/07/19 16:14:22 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_numbers(long long nbr)
{
	int i;

	i = (nbr == 0) ? 1 : 0;
	while (nbr != 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

int		get_format(char *fmt, t_types *t, va_list ap)
{
	int n;

	n = 0;
	fmt++;
	if (*fmt == '%')
	{
		ft_putchar('%');
		n++;
	}
	else if (*fmt == 's')
	{
		t->s = va_arg(ap, char *);
		n = ft_strlen(t->s);
		ft_putstr(t->s);
		// ft_strdel(&t->s);
	}
	else if (*fmt == 'p')
	{
		t->v = va_arg(ap, void *);
		t->lu = (unsigned long)(t->v);
		t->s = ft_itoa_base(t->lu, 16);
		n = ft_strlen(t->s) + 2;
		ft_putstr("0x");
		ft_putstr(t->s);
		ft_strdel(&t->s);
	}
	else if (*fmt == 'd' || *fmt == 'i')
	{
		t->d = va_arg(ap, int);
		n = get_numbers(t->d);
		ft_putnbr(t->d);
	}
	else if (*fmt == 'o' || *fmt == 'u' || *fmt == 'x')
	{
		t->d = va_arg(ap, unsigned int);
		if (*fmt == 'o')
			t->s = ft_itoa_base(t->d, 8);
		else if (*fmt == 'u')
			t->s = ft_itoa_base(t->d, 10);
		else if (*fmt == 'x')
			t->s = ft_itoa_base(t->d, 16);
		n = ft_strlen(t->s);
		ft_putstr(t->s);
		ft_strdel(&t->s);
	}
	return (n);
}

int		ft_printf(char *fmt, ...)
{
	int		n;
	va_list	ap;
	t_types	t;

	n = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			n += get_format(fmt, &t, ap);
			fmt++;
		}
		else
		{
			ft_putchar(*fmt);
			n++;
		}
		fmt++;
	}
	return (n);
}
