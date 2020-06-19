/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetramino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:49:09 by fallard           #+#    #+#             */
/*   Updated: 2019/11/30 19:15:27 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetra_up(char **tetra)
{
	int i;
	int j;

	i = 0;
	while (tetra[i] != NULL)
	{
		j = 0;
		while (tetra[i][j])
		{
			if (tetra[i][j] == '#' && j < 4)
				break ;
			if (tetra[i][j] == '#' && j >= 4)
				ft_swap_mem(&tetra[i][j], &tetra[i][j - 4]);
			j++;
		}
		i++;
		if (check_coord_x(tetra[i - 1]) == 1)
			i = i - 1;
	}
}

int		check_coord_x(char *tetra)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tetra[i] == '#')
			return (0);
		i++;
	}
	return (1);
}

void	tetra_left(char **tetra)
{
	int i;
	int j;

	i = 0;
	while (tetra[i] != NULL)
	{
		j = 0;
		if (check_coord_y(tetra[i]) == 0)
		{
			while (tetra[i][j])
			{
				if (tetra[i][j] == '#' && j > 0)
					ft_swap_mem(&tetra[i][j], &tetra[i][j - 1]);
				j++;
			}
		}
		i++;
		if (check_coord_y(tetra[i - 1]) == 0)
			i--;
	}
}

int		check_coord_y(char *tetra)
{
	int i;

	i = 0;
	while (tetra[i])
	{
		if (i % 4 == 0)
		{
			if (tetra[i] == '#')
				return (1);
		}
		i++;
	}
	return (0);
}

void	set_symbols(char **tetra)
{
	int i;
	int j;

	i = 0;
	while (tetra[i] != NULL)
	{
		j = 0;
		while (tetra[i][j])
		{
			if (tetra[i][j] == '#')
				tetra[i][j] = 65 + i;
			j++;
		}
		i++;
	}
}
