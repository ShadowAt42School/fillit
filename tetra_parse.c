/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 21:12:41 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/11 22:29:08 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		tetra_parse_init(char *tetras_str)
{
	t_list		*list;
	t_tetra		*tetra;
	char		represent;

	represent = 'A';
	while (*tetras_str)
	{
		tetra = tetra_node(&tetras_str, represent++);
		ft_lstadd(&list, ft_lstnew(tetra, sizeof(tetra)));
	}
	return ;
}

t_tetra		*tetra_node(char **tetras_str, char represent)
{
	char		*tetra_str;
	t_tetra		*tetra;

	tetra_str = ft_strnew(TETRA_S);
	tetra = (t_tetra*)ft_memalloc(sizeof(t_tetra));
	ft_memcpy(tetra_str, *tetras_str, TETRA_S);
	*tetras_str += (*(*tetras_str + TETRA_S + 1) == '\n'
					? TETRA_S + 2 : TETRA_S + 1);
	tetra->tetra = tetra_str;
	tetra->represent = represent;
	return (tetra);
}
