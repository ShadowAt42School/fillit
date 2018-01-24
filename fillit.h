/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:10:15 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/23 16:32:56 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# include <fcntl.h>

typedef struct	s_point
{
	int				x;
	int				y;
	char			rep;
	t_bool			taken;
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
	int				tetra_count;
	int				min_sqr;
	int				t_hash_c;
}				t_tetra_meta;

typedef struct	s_tetra_valid
{
	int				dot_c;
	int				hash_c;
	int				con_c;
	int				line_c;
	char			*t_str;
}				t_tetra_vaid;

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
				char *tetra_str, t_tetra **tetra, char rep);
t_bool			tetra_validate(char *tetra_str);
int				tetra_hash_conns(char *tetra_str, int cur_pos);
t_point			tetra_first_hash(char *tetra_str);

/*
** Init solving functions
*/
void			solve_init(t_tetra_main *tetra_main);
t_bool			tetra_solver(
			t_point **map, t_list *tetra_l, t_tetra_meta *meta);
t_bool			tetra_check_place(
				t_point *map, t_point *norm_points, t_tetra_meta *tetra_meta);
t_bool			tetra_free_spot(
	t_point *map, t_point *init_p, t_point *tetra_ps, t_tetra_meta *tetra_meta);
t_bool			tetra_place_free(
				t_point *map, t_point *point, t_point *tetra_ps, int min_sqr);
t_bool			tetra_set_values(
		t_point *t_pre, t_point *init_p, t_point *normed, t_tetra_meta *t_m);
t_bool			map_place_tetra(
t_point *map, t_point *tetra_ready, t_tetra_meta *tetra_meta, int t_down);
void			reset_map(t_point **map, int count);
void			reset_space(t_point *map, t_tetra_meta *t_meta);
t_bool			tetra_increment(
						t_point *map, t_point *t_points, t_tetra_meta *t_meta);

/*
** Printing
*/
void			tetra_print(t_point *map, t_tetra_meta *t_meta);
void			errhandle(t_bool iserror, t_bool isusage);

#endif
