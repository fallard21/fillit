/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_alg_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 20:33:22 by fallard           #+#    #+#             */
/*   Updated: 2019/11/30 22:09:29 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_alg	*new_struct(t_tetmap *tmap)
{
	t_alg	*alg;
	t_alg	*tmp;
	int		i;

	if (!(alg = ft_memalloc(sizeof(t_alg))))
		ft_exit();
	tmp = alg;
	i = 0;
	while (i++ < tmap->map_nbr - 1)
	{
		if (!(tmp->next = ft_memalloc(sizeof(t_alg))))
			ft_exit();
		tmp = tmp->next;
	}
	tmp->next = NULL;
	tmp = alg;
	i = -1;
	while (tmp && i++ < tmap->map_nbr)
	{
		tmp->s = 65 + i;
		tmp->w = get_biggest_w(tmap->tetra[i], 65 + i);
		tmp->h = get_biggest_h(tmap->tetra[i], 65 + i);
		tmp = tmp->next;
	}
	return (alg);
}

t_alg	*save_coords(t_tetmap *tmap)
{
	t_alg	*head;
	t_alg	*tmp;
	int		i;

	i = 0;
	head = new_struct(tmap);
	tmp = head;
	while (tmp)
	{
		set_xy(tmp, tmap->tetra[i]);
		i++;
		tmp = tmp->next;
	}
	return (head);
}

void	set_xy(t_alg *alg, char *tetra)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (tetra[i])
	{
		if (tetra[i] == alg->s)
		{
			alg->coords[k] = i % 4;
			alg->coords[k + 1] = i / 4;
			k = k + 2;
		}
		i++;
	}
}

int		get_biggest_w(char *tetra, int s)
{
	int i;
	int max_len;

	i = 0;
	max_len = 0;
	while (tetra[i])
	{
		if (tetra[i] == s)
		{
			if (i % 4 > max_len)
				max_len = i % 4;
		}
		i++;
	}
	return (max_len + 1);
}

int		get_biggest_h(char *tetra, int s)
{
	int len;
	int i;

	i = 15;
	len = 0;
	while (tetra[i] != s)
		i--;
	len = i / 4;
	return (len + 1);
}
