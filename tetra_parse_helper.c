/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_parse_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 19:44:35 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/18 03:19:04 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			tetra_hash_conns(char *tetra_str, int cur_pos)
{
	int		cons;

	cons = 0;
	if (*(tetra_str - 1) == TETRA_HASH && (cur_pos - 1) >= 0)
		cons++;
	if (*(tetra_str + 1) == TETRA_HASH && (cur_pos + 1) != TETRA_S)
		cons++;
	if (*(tetra_str - 5) == TETRA_HASH && (cur_pos - 5) >= 0)
		cons++;
	if (*(tetra_str + 5) == TETRA_HASH && (cur_pos + 5) < TETRA_S)
		cons++;
	return (cons);
}

void		tetra_fix_negative(t_tetra *tetra_o, t_point tetra_min)
{
	int		counter;

	counter = 0;
	if (!tetra_min.x && !tetra_min.y)
		return ;
	while (counter < TETRA_HASH_C)
	{
		tetra_o->points[counter].x += ABS(tetra_min.x);
		tetra_o->points[counter].y += ABS(tetra_min.y);
		counter++;
	}
	return ;
}
