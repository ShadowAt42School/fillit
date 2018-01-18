/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 06:45:55 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/18 04:24:56 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		tetra_solver(
			t_point **map, t_list *tetra_l, int *min_square, int tetra_count)
{
	t_list			*tetra_l_cp;
	t_tetra			*tetra_i;
	t_tetra_meta	tetra_meta;

	tetra_l_cp = tetra_l;
	ft_bzero(&tetra_meta, sizeof(t_tetra_meta));
	while (tetra_l_cp)
	{
		tetra_i = (t_tetra*)tetra_l_cp->content;
		if (tetra_check_place(map, tetra_i->points, *min_square, &tetra_meta))
		{
			tetra_l_cp = tetra_l_cp->next;
			tetra_solver(map, tetra_l_cp, min_square, tetra_count);
		}
		else if (tetra_meta.is_nx)
			tetra_l_cp = tetra_l_cp->next;
		else
		{
			(*min_square)++;
			reset_map(map);
			tetra_solver(map, tetra_l, min_square, tetra_count);
		}
	}
}

t_bool		tetra_check_place(
t_point **map, t_point *norm_points, int min_square, t_tetra_meta *tetra_meta)
{
	int			hash_c;
	t_point		tetra_t_points[4];
	t_point		init_point;
	t_point		**map_c;

	map_c = map;
	hash_c = 0;
	ft_bzero(&init_point, sizeof(t_point));
	if (tetra_free_spot(map_c, &init_point, min_square))
	{
		while (hash_c < TETRA_HASH_C)
		{
			tetra_t_points[hash_c].x = norm_points[hash_c].x + init_point.x;
			tetra_t_points[hash_c].y = norm_points[hash_c].y + init_point.y;
			tetra_t_points[hash_c].rep = norm_points->rep;
			if (!tetra_location_check(map_c, &tetra_t_points[hash_c]))
			{
				tetra_meta->is_nx = TRUE;
				return (FALSE);
			}
			hash_c++;
		}
		return (map_place_tetra(map_c, tetra_t_points, tetra_meta));
	}
	return (FALSE);
}

t_bool		map_place_tetra(
			t_point **map, t_point *tetra_ready, t_tetra_meta *tetra_meta)
{
	int		count;
	int		init_pos;

	init_pos = tetra_meta->tetra_num * TETRA_HASH_C;
	count = 0;
	while (count < TETRA_HASH_C)
	{
		if (map[init_pos + count])
		{
			tetra_meta->is_nx = TRUE;
			return (FALSE);
		}
		map[init_pos + count] = &tetra_ready[count];
		tetra_meta->tetra_num++;
		count++;
	}
	return (TRUE);
}

void		reset_map(t_point **map)
{
	while (*map)
	{
		*map = NULL;
		(*map)++;
	}
}
