/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_p2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:26:28 by fallard           #+#    #+#             */
/*   Updated: 2019/11/26 21:56:48 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_place(char *tetra)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 16)
	{
		if (tetra[i] == '#')
		{
			if ((i - 1) >= 0 && tetra[i - 1] == '#')
				count++;
			if ((i + 1) < 16 && tetra[i + 1] == '#')
				count++;
			if ((i + 4) < 16 && tetra[i + 4] == '#')
				count++;
			if ((i - 4) >= 0 && tetra[i - 4] == '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

int	check_full_place(char **tetra)
{
	int i;

	i = 0;
	while (tetra[i] != NULL)
	{
		if (check_place(tetra[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	get_filelen(char *input)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		i;
	int		fd;

	fd = open(input, O_RDONLY);
	i = 1;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		i = ret + i;
	}
	close(fd);
	return (i);
}

int	get_map_nbr(char *input)
{
	int		fd;
	char	*buf;
	int		i;

	fd = open(input, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &buf))
	{
		i++;
		if (!ft_strlen(buf))
			i--;
		free(buf);
	}
	close(fd);
	return (i * 4 / 16);
}
