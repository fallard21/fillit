/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:24:35 by fallard           #+#    #+#             */
/*   Updated: 2020/06/20 00:34:14 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_main(t_tetmap *tmap)
{
	t_alg	*head;

	tetra_up(tmap->tetra);
	tetra_left(tmap->tetra);
	set_symbols(tmap->tetra);
	head = save_coords(tmap);
	while (!set_figures(head, tmap))
	{
		create_free_map(tmap, 2);
		tmap->size = tmap->size + 1;
		create_free_map(tmap, 1);
	}
	free_alg(head);
	return (0);
}

void	clear_figure(t_tetmap *tmap, int s)
{
	int i;

	i = 0;
	while (tmap->map[i])
	{
		if (tmap->map[i] == s)
			tmap->map[i] = '.';
		i++;
	}
}

int		check_tetramino(t_alg *tet, t_tetmap *tmap, int shift)
{
	int x;
	int y;

	x = tmap->size - tet->w + ((shift / tmap->size) * tmap->size);
	y = tmap->size - tet->h;
	if (shift > x)
		return (0);
	if (shift / tmap->size > y)
		return (0);
	if (tmap->map[tet->coords[0] + tet->coords[1] * tmap->size + shift] != '.')
		return (0);
	if (tmap->map[tet->coords[2] + tet->coords[3] * tmap->size + shift] != '.')
		return (0);
	if (tmap->map[tet->coords[4] + tet->coords[5] * tmap->size + shift] != '.')
		return (0);
	if (tmap->map[tet->coords[6] + tet->coords[7] * tmap->size + shift] != '.')
		return (0);
	return (1);
}

void	set_tetramino(int shift, t_alg *tet, t_tetmap *tmap)
{
	tmap->map[tet->coords[0] + tet->coords[1] * tmap->size + shift] = tet->s;
	tmap->map[tet->coords[2] + tet->coords[3] * tmap->size + shift] = tet->s;
	tmap->map[tet->coords[4] + tet->coords[5] * tmap->size + shift] = tet->s;
	tmap->map[tet->coords[6] + tet->coords[7] * tmap->size + shift] = tet->s;
}

int		set_figures(t_alg *head, t_tetmap *tmap)
{
	if (!head)
		return (1);
	head->shift = 0;
	while (head->shift < tmap->size * tmap->size)
	{
		if (check_tetramino(head, tmap, head->shift))
		{
			set_tetramino(head->shift, head, tmap);
			if (set_figures(head->next, tmap))
				return (1);
			else
				clear_figure(tmap, head->s);
		}
		head->shift++;
	}
	return (0);
}
