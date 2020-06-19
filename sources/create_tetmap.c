/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:32:28 by fallard           #+#    #+#             */
/*   Updated: 2019/11/28 19:43:29 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**tetra_mem_create(char *input)
{
	char	**fresh;
	int		i;
	int		len;

	len = get_map_nbr(input);
	i = 0;
	if (!(fresh = ft_memalloc(sizeof(*fresh) * (len + 1))))
		ft_exit();
	while (i < len)
	{
		fresh[i] = ft_strnew(0);
		i++;
	}
	fresh[i] = NULL;
	return (fresh);
}

char		**save_tetra(char *input)
{
	char	*buf;
	char	**fresh;
	char	*tmp;
	int		i[2];
	int		fd;

	fd = open(input, O_RDONLY);
	i[0] = 0;
	fresh = tetra_mem_create(input);
	while (fresh[i[0]] != NULL)
	{
		i[1] = 0;
		while (get_next_line(fd, &buf) && i[1] < 4)
		{
			tmp = fresh[i[0]];
			fresh[i[0]] = ft_strjoin(fresh[i[0]], buf);
			ft_memdel((void **)&buf);
			ft_memdel((void **)&tmp);
			i[1]++;
		}
		ft_memdel((void **)&buf);
		i[0]++;
	}
	close(fd);
	return (fresh);
}

t_tetmap	*struct_tmap(char *input)
{
	t_tetmap	*tetmap;

	if (!(tetmap = ft_memalloc(sizeof(t_tetmap))))
		ft_exit();
	tetmap->tetra = save_tetra(input);
	tetmap->map_nbr = get_map_nbr(input);
	tetmap->size = get_min_map(tetmap->map_nbr);
	tetmap->map = create_map(tetmap->size * tetmap->size);
	return (tetmap);
}
