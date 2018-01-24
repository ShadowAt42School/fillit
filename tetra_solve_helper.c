/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_solve_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 19:36:28 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/23 15:59:47 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_bool			tetra_free_spot(
	t_point *map, t_point *init_p, t_point *tetra_ps, t_tetra_meta *tetra_meta)
{
	while (init_p->x < tetra_meta->min_sqr)
	{
		if (tetra_place_free(map, init_p, tetra_ps, tetra_meta->min_sqr))
			return (TRUE);
		else
			init_p->y++;
		if (init_p->y >= tetra_meta->min_sqr)
		{
			init_p->y = 0;
			init_p->x++;
		}
		if (init_p->x >= tetra_meta->min_sqr)
			return (FALSE);
	}
	return (FALSE);
}

t_bool			tetra_place_free(
				t_point *map, t_point *point, t_point *tetra_ps, int min_sqr)
{
	t_point		*map_c;
	int			counter;
	t_point		tmp_p;

	map_c = map;
	counter = -1;
	if (point->x >= min_sqr || point->y >= min_sqr)
		return (FALSE);
	while (++counter < TETRA_HASH_C)
	{
		tmp_p.x = point->x + tetra_ps[counter].x;
		tmp_p.y = point->y + tetra_ps[counter].y;
		if ((tmp_p.x >= min_sqr || tmp_p.y >= min_sqr)
			|| (tmp_p.x < 0 || tmp_p.y < 0))
			return (FALSE);
		map_c = map;
		while (map_c->taken)
		{
			if (map_c->x == tmp_p.x && map_c->y == tmp_p.y)
				return (FALSE);
			map_c++;
		}
	}
	return (TRUE);
}

t_bool			tetra_set_values(
t_point *tetra, t_point *init_p, t_point *tetra_ps, t_tetra_meta *tetra_meta)
{
	int			counter;
	t_point		*t_pr;
	int			min_sqr;

	counter = -1;
	t_pr = tetra;
	min_sqr = tetra_meta->min_sqr;
	while (++counter < TETRA_HASH_C)
	{
		t_pr[counter].x = init_p->x + tetra_ps[counter].x;
		t_pr[counter].y = init_p->y + tetra_ps[counter].y;
		t_pr[counter].rep = tetra_ps[counter].rep;
		if (t_pr[counter].x >= min_sqr || t_pr[counter].y >= min_sqr)
			return (FALSE);
	}
	return (TRUE);
}

void			reset_map(t_point **map, int count)
{
	t_point		*map_c;

	map_c = *map;
	ft_bzero(map_c, count);
}

void			reset_space(t_point *map, t_tetra_meta *t_meta)
{
	t_point		*map_c;

	map_c = map;
	ft_bzero((map_c + t_meta->tetra_num - 1),
		sizeof(t_tetra_meta) * TETRA_HASH_C);
	t_meta->tetra_num--;
}
