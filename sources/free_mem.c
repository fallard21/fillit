/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:47:29 by fallard           #+#    #+#             */
/*   Updated: 2019/11/28 14:42:14 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_tetra(char **tetra)
{
	int i;

	if (tetra)
	{
		i = 0;
		while (tetra[i] != NULL)
		{
			free(tetra[i]);
			i++;
		}
		free(tetra);
	}
}

void	create_free_map(t_tetmap *tmap, int choice)
{
	if (!tmap->map && choice == 1)
	{
		tmap->map = create_map(tmap->size * tmap->size);
	}
	if (tmap && choice == 2)
	{
		ft_memdel((void **)&tmap->map);
	}
}

void	free_tmap(t_tetmap *tmap)
{
	free_tetra(tmap->tetra);
	ft_memdel((void**)&tmap->map);
	free(tmap);
}

void	free_alg(t_alg *fig)
{
	if (fig->next)
		free_alg(fig->next);
	free(fig);
}
