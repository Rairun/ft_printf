/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 16:27:12 by psaprono          #+#    #+#             */
/*   Updated: 2018/07/19 16:27:14 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include "ft_printf.h"

int     main()
{
	setlocale(LC_ALL, "");
	int					o = 1;
	int					x = 0;
	int					n;
	int					n1;
	char				*s = "abcd";
	short				sh = 12312;
	long				l = -1212312342412412432;
	long long			ll = -1212312342412412432;
	intmax_t			im = 171231234241241;
	ssize_t				sst = 468712354623;
	unsigned char		cu = 245;
	unsigned short		su = 41241;
	unsigned int		iu = 121412415;
	unsigned long		lu = 325235325235235;
	unsigned long long	llu = 52353252352352532;
	uintmax_t			uim = 235235235234234243;
	size_t				st = -3253523523535235;
	signed char			c = 50;
	wint_t				ct = L'🙈';
	wchar_t				*w = L"我是一只猫。";
	int					in = 1236249241;
	sst = -1;

	#define PRINTF "|%d|\n", 1
	// #define PRINTF1 "%.x\n", 0
	// #define PRINTF2 "%.x\n", 1
	// #define PRINTF3 "%.x\n", -12
	// #define PRINTF4 "%.x\n", 0
	// #define PRINTF5 "%.x\n", 12

	n = ft_printf(PRINTF);
	n1 = printf(PRINTF);
	printf("%d?=%d\n--------\n", n, n1);
	// system("leaks -q a.out");
	return (0);
}

//s(undefined behaviour) -> #,0, ,+
//d,i(undefined behaviour) -> #
//p(undefined behaviour) -> +,
