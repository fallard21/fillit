/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:12:40 by fallard           #+#    #+#             */
/*   Updated: 2020/11/24 18:45:35 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa(uint64_t nbr)
{
	uint64_t	tmp;
	char		*res;
	int			len;
	int			i;

	if (nbr == 0)
		return (ft_strdup("0"));
	tmp = nbr;
	len = 0;
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	if (!(res = ft_calloc(1, len + 1)))
		return (NULL);
	i = len - 1;
	while (nbr)
	{
		res[i--] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (res);
}
