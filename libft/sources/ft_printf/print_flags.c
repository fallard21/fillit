/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:18:38 by fallard           #+#    #+#             */
/*   Updated: 2020/11/13 17:19:44 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_s(t_printf *pf)
{
	char	*str;
	char	*tmp;
	int		len;

	tmp = va_arg(pf->args, char*);
	str = (tmp) ? ft_strdup(tmp) : ft_strdup("(null)");
	if (!str)
		exit(1);
	len = ft_strlen(str);
	if (pf->prec >= 0)
		len = (pf->prec <= len) ? pf->prec : len;
	if (!pf->minus)
		print_width(0, len, pf);
	write(1, str, len);
	if (pf->minus)
		print_width(0, len, pf);
	free(str);
	pf->tmp = (pf->width > len) ? pf->width : len;
	pf->len = pf->len + pf->tmp;
}

void	print_c(t_printf *pf)
{
	unsigned char c;

	c = va_arg(pf->args, int);
	if (!pf->minus)
		print_width(0, 1, pf);
	write(1, &c, 1);
	if (pf->minus)
		print_width(0, 1, pf);
	pf->tmp = (pf->width > 1) ? pf->width : 1;
	pf->len = pf->len + pf->tmp;
}

void	print_result(t_printf *pf)
{
	if (pf->conv == 'd' || pf->conv == 'i')
		print_d(pf);
	else if (pf->conv == 'o')
		print_o(pf);
	else if (pf->conv == 'u')
		print_u(pf);
	else if (pf->conv == 'x' || pf->conv == 'X')
		print_x(pf);
	else if (pf->conv == 'f' || pf->conv == 'F')
		print_f(pf);
	else if (pf->conv == 'c')
		print_c(pf);
	else if (pf->conv == 's')
		print_s(pf);
	else if (pf->conv == 'p')
		print_p(pf);
	else if (pf->conv == 37)
		print_percent(pf);
	else if (pf->conv == 'b')
		print_b(pf);
	else if (pf->conv == 'k')
		print_k(pf);
}
