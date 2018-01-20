/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 21:12:41 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/20 14:46:53 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra		*tetra_node(char **tetras_str, char char_rep)
{
	char		*tetra_str;
	t_tetra		*tetra;
	t_point		minimal;

	tetra_str = ft_strnew(TETRA_S);
	tetra = (t_tetra*)ft_memalloc(sizeof(t_tetra));
	ft_memcpy(tetra_str, *tetras_str, TETRA_S);
	if (!tetra_validate(tetra_str))
	{
		ft_putstr("error\n");
		exit(1);
	}
	*tetras_str += (*(*tetras_str + TETRA_S + 1) == '\n'
					? TETRA_S + 2 : TETRA_S + 1);
	ft_bzero(&minimal, sizeof(t_point));
	tetra_outline(tetra_str, &tetra, minimal, char_rep);
	return (tetra);
}

void		tetra_outline(
			char *tetra_str, t_tetra **tetra, t_point minimal, char rep)
{
	t_tetra		*tetra_o;
	t_point		init_point[1];
	int			cur_pos;
	int			hash_c;

	init_point[0] = tetra_first_hash(tetra_str);
	tetra_o = *tetra;
	cur_pos = 0;
	hash_c = -1;
	while (*tetra_str)
	{
		if (*tetra_str == '#')
		{
			tetra_o->points[++hash_c].x = cur_pos / 5 - init_point->x;
			tetra_o->points[hash_c].y = cur_pos % 5 - init_point->y;
			tetra_o->points[hash_c].rep = rep;
			if (tetra_o->points[hash_c].x < 0)
				minimal.x = ft_min(minimal.x, tetra_o->points[hash_c].x);
			if (tetra_o->points[hash_c].y < 0)
				minimal.y = ft_min(minimal.y, tetra_o->points[hash_c].y);
		}
		(tetra_str++ ? cur_pos++ : cur_pos++);
	}
}

t_point		tetra_first_hash(char *tetra_str)
{
	t_point		initial_point[1];
	char		*fr_occur;
	int			fr_occur_pos;

	fr_occur = ft_strchr(tetra_str, '#');
	fr_occur_pos = fr_occur - tetra_str;
	initial_point[0].x = fr_occur_pos / 5;
	initial_point[0].y = fr_occur_pos % 5;
	return (initial_point[0]);
}

t_bool		tetra_validate(char *tetra_str)
{
	char	*t_str;
	int		dot_c;
	int		hash_c;
	int		con_c;

	t_str = tetra_str;
	dot_c = 0;
	hash_c = 0;
	con_c = 0;
	while (*t_str)
	{
		if (*t_str == TETRA_EMPTY)
			dot_c++;
		if (*t_str == TETRA_HASH)
		{
			con_c += tetra_hash_conns(t_str, t_str - tetra_str);
			hash_c++;
		}
		t_str++;
	}
	if (dot_c != TETRA_DOTS_C || hash_c != TETRA_HASH_C)
		return (FALSE);
	return (con_c == 6 || con_c == 8 ? TRUE : FALSE);
}
