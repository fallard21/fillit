/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 21:07:03 by fallard           #+#    #+#             */
/*   Updated: 2020/11/24 19:19:17 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_base_size(uintmax_t n, int base)
{
	int i;

	i = 0;
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(uintmax_t n, int hex_up, uint8_t base)
{
	char	*hex;
	char	*res;
	int		i;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	if (hex_up)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	len = get_base_size(n, base);
	if (!(res = ft_calloc(1, len + 1)))
		return (NULL);
	i = len - 1;
	while (n)
	{
		res[i] = hex[n % base];
		n = n / base;
		i--;
	}
	return (res);
}
