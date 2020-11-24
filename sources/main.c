/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 09:09:55 by marvin            #+#    #+#             */
/*   Updated: 2020/11/24 20:19:24 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_exit(void)
{
	ft_putendl("error");
	exit(1);
}

void	ft_swap_mem(void *a, void *b)
{
	unsigned char	tmp;
	unsigned char	*one;
	unsigned char	*two;

	one = (unsigned char *)a;
	two = (unsigned char *)b;
	tmp = *one;
	*one = *two;
	*two = tmp;
}

int		main(int argc, char **argv)
{
	t_tetmap	*tmap;

	if (argc != 2)
		ft_printf("usage: ./fillit (input 1 source file) <.txt>\n");
	else
	{
		if (!validate(argv[1]))
		{
			ft_printf("error");
			return (0);
		}
		tmap = struct_tmap(argv[1]);
		ft_main(tmap);
		print_map(tmap);
		free_tmap(tmap);
	}
	return (0);
}
