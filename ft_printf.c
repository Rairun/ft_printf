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

bool	is_flag(char c)
{
	return (ft_strchr("#0-+ ", c) != NULL);
}

bool	is_spec(char c)
{
	return (ft_strchr("hljz", c) != NULL);
}

bool	is_small(char c)
{
	return (ft_strchr("spdiouxc", c) != NULL);
}

bool	is_big(char c)
{
	return (ft_strchr("SDOUXC", c) != NULL);
}

void	putf(char c, t_buff *b)
{
	if (b->size >= BUFF)
	{
		ft_putstr(b->buff);
		ft_strclr(b->buff);
		b->size = 0;
	}
	b->buff[b->size] = c;
	b->size++;
	b->len++;
}

void	putfstr(char *s, size_t len, t_buff *b)
{
	size_t	i;

	i = 0;
	while (s[i] && i < len)
	{
		putf(s[i], b);
		i++;
	}
}

void	get_all(char *s, t_pf *pf)
{
	get_flags();
	get_width();
	get_prec();
	get_size();
	get_conv();
}

void	get_format(char *s, va_list *ap, int *i, t_buff *b)
{
	int		start;
	t_pf	pf;

	(*i)++;
	start = *i;
	while (s[*i] && s[*i] != '%' && !is_small(s[*i]) && !is_big(s[*i]))
		(*i)++;
	if (s[*i] == '%' || is_small(s[*i]) || is_big(s[*i]))
		get_all(ft_strsub(s, start, *i - start + 1), &pf);
	else
		putfstr(s + start, *i - start, b);
}

void	parse_string(char *fmt, va_list *ap, t_buff *b)
{
	int		i;

	i = -1;
	while (fmt[++i])
	{
		if (fmt[i] == '%')
			get_format(fmt, ap, &i, b);
		else
			putf(fmt[i], b);
	}
}

int		ft_printf(char *fmt, ...)
{
	va_list	ap;
	t_buff	*b;

	if ((b = ft_memalloc(sizeof(t_buff))) == NULL)
		ft_putendl("Error malloc t_buff");
	if ((b->buff = ft_memalloc(sizeof(char) * BUFF)) == NULL)
		ft_putendl("Error malloc b->buff");
	b->size = 0;
	b->len = 0;
	va_start(ap, fmt);
	parse_string(fmt, &ap, b);
	va_end(ap);
	ft_putstr(b->buff);
	return (b->len);
}
