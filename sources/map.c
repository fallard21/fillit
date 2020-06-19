/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:20:53 by fallard           #+#    #+#             */
/*   Updated: 2019/11/28 19:16:57 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_min_map(int map_nbr)
{
	int min_map;
	int count;

	min_map = 0;
	count = map_nbr * 4;
	while (min_map * min_map < count)
		min_map++;
	return (min_map);
}

void	print_map(t_tetmap *tetmap)
{
	int i;

	i = 0;
	while (i < tetmap->size * tetmap->size)
	{
		ft_putchar(tetmap->map[i]);
		i++;
		if (i % tetmap->size == 0)
			ft_putchar('\n');
	}
}

char	*create_map(int size)
{
	char	*map;

	map = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (!map)
		ft_exit();
	ft_memset(map, '.', size);
	map[size] = '\0';
	return (map);
}
