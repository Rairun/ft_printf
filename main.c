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
#include "ft_printf.h"

int     main()
{
	int		n;
	int		n1;
	// char	*s = "123";

	// n = ft_printf("%s-%s\t%s\v->\r%s%%\n", "POWER", "IN", "OUR", "HEARTS");
	// n1 = printf("%s-%s\t%s\v->\r%s%%\n", "POWER", "IN", "OUR", "HEARTS");
	n = ft_printf("%o\t%u\t%x\n", 1100, 2131, 756356);
	n1 = printf("%o\t%u\t%x\n", 1100, 2131, 756356);
	printf("%d?=%d\n", n, n1);
	// system("leaks -q a.out");
	return (0);
}
