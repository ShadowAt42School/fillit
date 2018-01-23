/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 21:12:41 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/23 00:00:04 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra		*tetra_node(char **tetras_str, char char_rep)
{
	char		*tetra_str;
	t_tetra		*tetra;

	tetra_str = ft_strnew(TETRA_S);
	tetra = (t_tetra*)ft_memalloc(sizeof(t_tetra));
	ft_memcpy(tetra_str, *tetras_str, TETRA_S);
	if (!tetra_validate(tetra_str))
		errhandle(1, 0);
	if (!(*(*tetras_str + TETRA_S) == '\n' ||
		*(*tetras_str + TETRA_S) == '\0'))
		errhandle(1, 0);
	*tetras_str += (*(*tetras_str + TETRA_S) == '\n'
					? TETRA_S + 1 : TETRA_S);
	tetra_outline(tetra_str, &tetra, char_rep);
	return (tetra);
}

void		tetra_outline(
			char *tetra_str, t_tetra **tetra, char rep)
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
	int		line_c;

	t_str = tetra_str;
	dot_c = 0;
	hash_c = 0;
	con_c = 0;
	line_c = 0;
	while (*t_str)
	{
		dot_c += (*t_str == TETRA_EMPTY ? 1 : 0);
		line_c += (*t_str == '\n' ? 1 : 0);
		if (*t_str == TETRA_HASH)
		{
			con_c += tetra_hash_conns(t_str, t_str - tetra_str);
			hash_c++;
		}
		t_str++;
	}
	if (dot_c != TETRA_DOTS_C || hash_c != TETRA_HASH_C || line_c != 4)
		return (FALSE);
	return (con_c == 6 || con_c == 8 ? TRUE : FALSE);
}
