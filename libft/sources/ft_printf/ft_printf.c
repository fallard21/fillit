/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:35:41 by fallard           #+#    #+#             */
/*   Updated: 2020/11/13 16:30:38 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int		ft_printf(const char *format, ...)
{
	t_printf	pf;

	ft_memset(&pf, 0, sizeof(t_printf));
	pf.format = (char*)format;
	va_start(pf.args, format);
	parse_format(&pf);
	va_end(pf.args);
	return (pf.len);
}
