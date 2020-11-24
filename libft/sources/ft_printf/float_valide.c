/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_valide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:00:40 by fallard           #+#    #+#             */
/*   Updated: 2020/11/13 16:58:15 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void		error_f(t_printf *pf, t_ldbl_cast dbl)
{
	int		err;
	char	*str;
	int		len;

	err = valide_float(dbl);
	str = (err == 1 && err != 3) ? ft_strdup("inf") : ft_strdup("-inf");
	str = (err == 3) ? ft_strdup("nan") : str;
	if (!str)
		exit(1);
	len = ft_strlen(str);
	if (pf->plus && ft_strcmp(str, "inf") == 0)
		len++;
	if (!pf->minus)
		print_width(pf->plus, len, pf);
	if (pf->plus && ft_strcmp(str, "inf") == 0)
		ft_putchar('+');
	ft_putstr(str);
	if (pf->minus)
		print_width(pf->plus, len, pf);
	free(str);
	pf->tmp = (pf->width > len) ? pf->width : len;
	pf->len = pf->len + pf->tmp;
}

int			valide_float(t_ldbl_cast dbl)
{
	if (dbl.t_parts.exponent == 32767u &&
			dbl.t_parts.mantissa == 9223372036854775808ul &&
			dbl.t_parts.sign == 0u)
		return (1);
	if (dbl.t_parts.exponent == 32767u &&
			dbl.t_parts.mantissa == 9223372036854775808ul &&
			dbl.t_parts.sign == 1u)
		return (2);
	if (dbl.t_parts.exponent == 32767u &&
			dbl.d != dbl.d)
		return (3);
	return (0);
}

void		pf_free_floats(t_floats *flt)
{
	ft_memdel((void **)&flt->first);
	ft_memdel((void **)&flt->end);
	ft_memdel((void **)&flt->mant);
	ft_memdel((void **)&flt->one);
	ft_memdel((void **)&flt->two);
}
