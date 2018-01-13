/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 21:12:41 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/13 00:58:16 by maghayev         ###   ########.fr       */
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
	ft_strcpy(tetra_str, *tetras_str);
	*tetras_str += (*(*tetras_str + TETRA_S + 1) == '\n'
					? TETRA_S + 2 : TETRA_S + 1);
	tetra->tetra = tetra_str;
	tetra->char_rep = char_rep;
	tetra_outline(&tetra);
	return (tetra);
}

void		tetra_outline(t_tetra **tetra)
{
	t_tetra		*tetra_o;

	tetra_o = *tetra;
	while (tetra_o->tetra)
	{
		
	}
}

t_bool		tetra_validate(t_tetra *tetra)
{

}
