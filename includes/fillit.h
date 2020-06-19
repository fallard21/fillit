/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 09:10:37 by marvin            #+#    #+#             */
/*   Updated: 2020/06/20 00:06:36 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <sys/types.h>

typedef struct		s_tetmap
{
	char			**tetra;
	char			*map;
	int				map_nbr;
	int				size;
}					t_tetmap;

typedef struct		s_alg
{
	struct s_alg	*next;
	int				coords[8];
	int				w;
	int				h;
	int				s;
	int				shift;
}					t_alg;

/*
** VALIDATING PART
*/
int					check_lines(char *input);
int					check_last_n(char *input);
int					check_symbols(char **tetra);
int					check_symbols_nbr(char **tetra);
int					validate(char *input);
int					check_place(char *tetra);
int					check_full_place(char **tetra);
int					get_filelen(char *input);
int					get_map_nbr(char *input);
char				**tetra_mem_create(char *input);
char				**save_tetra(char *input);
void				free_tetra(char **tetra);

/*
**	ALGORITHM PART
*/
t_tetmap			*struct_tmap(char *input);
int					get_min_map(int map_nbr);
char				*create_map(int size);
void				print_map(t_tetmap *tetmap);

void				tetra_up(char **tetra);
void				tetra_left(char **tetra);
void				set_symbols(char **tetra);
int					check_coord_x(char *tetra);
int					check_coord_y(char *tetra);
void				ft_swap_mem(void *a, void *b);

int					ft_main(t_tetmap *tmap);
t_alg				*save_coords(t_tetmap *tmap);
t_alg				*new_struct(t_tetmap *tmap);
int					get_biggest_w(char *tetra, int s);
int					get_biggest_h(char *tetra, int s);

void				set_xy(t_alg *alg, char *tetra);
int					check_tetramino(t_alg *tet, t_tetmap *tmap, int shift);
void				clear_figure(t_tetmap *tmap, int s);
int					set_figures(t_alg *head, t_tetmap *tmap);
void				create_free_map(t_tetmap *tmap, int choice);

void				free_tmap(t_tetmap *tmap);
void				free_alg(t_alg *fig);
void				ft_exit();

#endif
