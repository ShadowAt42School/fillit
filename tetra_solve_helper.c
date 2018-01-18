/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_solve_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 19:36:28 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/18 03:47:45 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_bool			tetra_free_spot(t_point **map, t_point *init_p, int min_square)
{
	while (*map)
	{
		if (!*map)
			return (TRUE);
		if ((*map)->y == init_p->y && init_p->y < min_square)
			init_p->y += 1;
		if (init_p->y == min_square)
		{
			init_p->x += 1;
			init_p->y = 0;
		}
		if (init_p->x == min_square)
			return (FALSE);
		(*map)++;
	}
	return (TRUE);
}

t_bool			tetra_location_check(t_point **map, t_point *points)
{
	t_point		*map_c;

	map_c = *map;
	while (map_c)
	{
		if (map_c->x == points->x || map_c->y == points->y)
			return (FALSE);
		map_c++;
	}
	return (TRUE);
}
