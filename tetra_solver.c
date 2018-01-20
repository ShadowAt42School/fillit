/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 06:45:55 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/20 14:04:12 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_bool		tetra_solver(
			t_point **map, t_list *tetra_l, t_tetra_meta *t_meta)
{
	t_list			*tetra_l_cp;
	t_tetra			*tetra_i;

	tetra_l_cp = tetra_l;
	while (tetra_l_cp)
	{
		tetra_i = (t_tetra*)tetra_l_cp->content;
		if (t_meta->is_nx || tetra_check_place(*map, tetra_i->points, t_meta))
		{
			t_meta->is_nx = FALSE;
			if (tetra_solver(map, tetra_l_cp->next, t_meta))
				return (TRUE);
			else
			{
				if (tetra_increment(*map, tetra_i->points, t_meta))
					continue;
				return (FALSE);
			}
		}
		else
			return (FALSE);
	}
	if (!tetra_l_cp && t_meta->tetra_num * TETRA_HASH_C == t_meta->t_hash_c)
		return (TRUE);
	return (FALSE);
}

t_bool		tetra_check_place(
t_point *map, t_point *norm_points, t_tetra_meta *tetra_meta)
{
	int			hash_c;
	t_point		tetra_t_points[4];
	t_point		init_point;
	int			index;

	index = tetra_meta->tetra_num * TETRA_HASH_C;
	hash_c = 0;
	init_point.x = map[(index < 0 ? 0 : index)].x;
	init_point.y = map[(index < 0 ? 0 : index)].y;
	ft_bzero(&tetra_t_points, sizeof(t_point) * TETRA_HASH_C);
	if (tetra_free_spot(map, &init_point, norm_points, tetra_meta))
	{
		if (
		tetra_set_values(tetra_t_points, &init_point, norm_points, tetra_meta))
			return (map_place_tetra(map, tetra_t_points, tetra_meta, 1));
	}
	return (FALSE);
}

t_bool		map_place_tetra(
	t_point *map, t_point *tetra_ready, t_tetra_meta *t_meta, int t_down)
{
	int		count;
	int		init_pos;

	init_pos = t_meta->tetra_num * TETRA_HASH_C;
	count = 0;
	while (count < TETRA_HASH_C)
	{
		map[init_pos + count].x = tetra_ready[count].x;
		map[init_pos + count].y = tetra_ready[count].y;
		map[init_pos + count].rep = tetra_ready[count].rep;
		map[init_pos + count].taken = t_down;
		count++;
	}
	t_meta->tetra_num += t_down;
	return (TRUE);
}

t_bool		tetra_increment(
		t_point *map, t_point *t_points, t_tetra_meta *t_meta)
{
	int			index;
	t_point		tetra_t_points[4];
	t_point		init_point;

	ft_bzero(&init_point, sizeof(t_point));
	index = (t_meta->tetra_num - 1) * TETRA_HASH_C;
	index = (index < 0 ? 0 : index);
	init_point.x = map[index].x;
	init_point.y = map[index].y + 1;
	t_meta->tetra_num--;
	ft_bzero((map + index), sizeof(t_point) * TETRA_HASH_C);
	if (tetra_free_spot(map, &init_point, t_points, t_meta))
	{
		tetra_set_values(tetra_t_points, &init_point, t_points, t_meta);
		t_meta->is_nx = TRUE;
		return (map_place_tetra(map, tetra_t_points, t_meta, 1));
	}
	return (FALSE);
}
