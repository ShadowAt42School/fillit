/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 20:55:41 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/20 17:05:36 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		tetra_print(t_point *map, t_tetra_meta *t_meta)
{
	char	*print;
	int		c;
	int		index;

	index = 0;
	c = -1;
	print = ft_strnew(ft_pow(t_meta->min_sqr, 2) + (t_meta->min_sqr));
	ft_memset(print, '.', ft_pow(t_meta->min_sqr, 2) + (t_meta->min_sqr));
	while (++c < t_meta->t_hash_c)
	{
		index = map[c].x * (t_meta->min_sqr + 1) + map[c].y;
		print[index] = map[c].rep;
	}
	c = -1;
	while (++c < t_meta->min_sqr)
		print[c * (t_meta->min_sqr + 1) + t_meta->min_sqr] = '\n';
	ft_putstr(print);
}

void		errhandle(t_bool iserror, t_bool isusage)
{
	if (iserror)
	{
		ft_putstr("error\n");
		exit(1);
	}
	if (isusage)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(1);
	}
}
