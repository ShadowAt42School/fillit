/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 21:12:41 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/15 19:05:51 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list		*tetra_parse_init(char *tetras_str)
{
	t_list		*list;
	t_tetra		*tetra;
	char		char_rep;

	char_rep = 'A';
	list = 0x00;
	while (*tetras_str)
	{
		tetra = tetra_node(&tetras_str, char_rep++);
		ft_lstpush(&list, ft_lstnew(tetra, sizeof(tetra)));
	}
	return (list);
}

t_tetra		*tetra_node(char **tetras_str, char char_rep)
{
	char		*tetra_str;
	t_tetra		*tetra;

	tetra_str = ft_strnew(TETRA_S);
	tetra = (t_tetra*)ft_memalloc(sizeof(t_tetra));
	ft_memcpy(tetra_str, *tetras_str, TETRA_S);
	if (!tetra_validate(tetra_str))
		exit(1);
		/*usage();*/
	*tetras_str += (*(*tetras_str + TETRA_S + 1) == '\n'
					? TETRA_S + 2 : TETRA_S + 1);
	tetra_outline(tetra_str, &tetra);
	tetra->char_rep = char_rep;
	return (tetra);
}

void		tetra_outline(char *tetra_str, t_tetra **tetra)
{
	int			x;
	int			y;
	int			counter;
	t_tetra		*tetra_one;

	x = 0;
	y = 0;
	counter = 0;
	tetra_one = *tetra;
	while (*tetra_str)
	{
		if (*tetra_str == '\n')
			y++;
		if (*tetra_str == '#')
		{
			tetra_one->points[counter].x = x;
			tetra_one->points[counter].y = y;
		}
		tetra_str++;
	}
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
