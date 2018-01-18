/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:10:15 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/18 04:12:23 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libs/libft/libft.h"
# include "./libs/libmath/libmath.h"
# include <fcntl.h>

typedef struct	s_point
{
	int				x;
	int				y;
	char			rep;
}				t_point;

typedef struct	s_tetra
{
	t_point			points[4];
	size_t			content_size;
}				t_tetra;

typedef struct	s_tetra_main
{
	int				tetras_c;
	t_list			*list;
}				t_tetra_main;

typedef struct	s_tetra_meta
{
	t_bool			is_nx;
	int				tetra_num;
}				t_tetra_meta;

/*
** Pre-Def values
** Macroses Part 0
*/
# define MAX_BUF 546
# define TETRA_S 20
# define TETRA_HASH_C 4
# define TETRA_DOTS_C 12
# define TETRA_EMPTY '.'
# define TETRA_HASH '#'
# define TETRA_CHECK(x) (x == '\n' || x == '.' || x == '#')

/*
** Init parsing functions
*/
t_tetra_main	*tetra_parse_init(char *tetras_str);
t_tetra			*tetra_node(char **tetras_str, char represent);
void			tetra_outline(
				char *tetra_str, t_tetra **tetra, t_point minimal, char rep);
t_bool			tetra_validate(char *tetra_str);
int				tetra_hash_conns(char *tetra_str, int cur_pos);
t_point			tetra_first_hash(char *tetra_str);
void			tetra_fix_negative(t_tetra *tetra_o, t_point tetra_min);

/*
** Init solving functions
*/
void			solve_init(t_tetra_main *tetra_main);
void			tetra_solver(
			t_point **map, t_list *tetra_l, int *min_square, int tetra_count);
t_bool			tetra_check_place(
t_point **map, t_point *norm_points, int min_square, t_tetra_meta *tetra_meta);
t_bool			tetra_free_spot(t_point **map, t_point *init_p, int min_square);
t_bool			tetra_location_check(t_point **map, t_point *points);
t_bool			map_place_tetra(
				t_point **map, t_point *tetra_ready, t_tetra_meta *tetra_meta);
void			reset_map(t_point **map);

#endif
