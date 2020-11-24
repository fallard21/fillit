/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:26:57 by fallard           #+#    #+#             */
/*   Updated: 2020/11/13 16:30:52 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_color(t_printf *pf, int a)
{
	char	c;

	c = a + '0';
	if (pf->format[pf->i + 2] == '}')
	{
		write(1, "{", 1);
		write(1, &c, 1);
	}
	else
	{
		if (a == 1)
			write(1, "\x1b[31m", 5);
		if (a == 2)
			write(1, "\x1b[32m", 5);
		if (a == 3)
			write(1, "\x1b[33m", 5);
		if (a == 4)
			write(1, "\x1b[34m", 5);
		if (a == 5)
			write(1, "\x1b[35m", 5);
		if (a == 6)
			write(1, "\x1b[36m", 5);
		if (a == 0)
			write(1, "\x1b[0m", 4);
	}
}
