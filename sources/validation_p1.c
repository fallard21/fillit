/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_p1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:10:31 by fallard           #+#    #+#             */
/*   Updated: 2019/11/28 19:10:31 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_lines(char *input)
{
	int		fd;
	char	*buf;
	int		i;
	int		count;

	fd = open(input, O_RDONLY);
	i = 1;
	count = 0;
	while (get_next_line(fd, &buf))
	{
		if (i % 5 != 0 && (ft_strlen(buf) != 4))
			ft_exit();
		(i % 5 == 0) ? count = 0 : count++;
		if (i % 5 == 0 && (ft_strlen(buf) != 0))
			ft_exit();
		i++;
		ft_memdel((void **)&buf);
	}
	if (count < 4 || count > 4)
		return (0);
	close(fd);
	return (1);
}

int	check_last_n(char *input)
{
	int mnbr;
	int flen;

	mnbr = get_map_nbr(input);
	flen = get_filelen(input);
	if (mnbr % 2 == 0 && flen % 2 == 0)
		return (1);
	if (mnbr % 2 != 0 && flen % 2 != 0)
		return (1);
	return (0);
}

int	check_symbols(char **tetra)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tetra[i] != NULL)
	{
		j = 0;
		while (tetra[i][j] != '\0')
		{
			if (tetra[i][j] != '#' && tetra[i][j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_symbols_nbr(char **tetra)
{
	int i;
	int j;
	int count;

	i = 0;
	while (tetra[i] != NULL)
	{
		j = 0;
		count = 0;
		while (tetra[i][j] != '\0')
		{
			if (tetra[i][j] == '#')
				count++;
			j++;
			if (count > 4)
				return (0);
		}
		i++;
	}
	return (1);
}

int	validate(char *input)
{
	char	**tetra;

	tetra = NULL;
	if (!check_lines(input))
		return (0);
	else if (!check_last_n(input))
		return (0);
	else if (get_map_nbr(input) > 26)
		return (0);
	else
	{
		tetra = save_tetra(input);
		if (check_symbols(tetra) == 0)
			ft_exit();
		else if (check_symbols_nbr(tetra) == 0)
			ft_exit();
		else if (check_full_place(tetra) == 0)
			ft_exit();
	}
	free_tetra(tetra);
	return (1);
}
