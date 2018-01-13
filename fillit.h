/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:10:15 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/13 00:54:55 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>

typedef struct	s_point
{
	int				x;
	int				y;
}				t_point;

typedef struct	s_tetra
{
	char			*tetra;
	char			char_rep;
	t_point			points[4];
	t_point			pointsp[6];
	size_t			content_size;
}				t_tetra;

/*
** Pre-Def values
** Macroses Part 0
*/
# define MAX_BUF 546
# define TETRA_S 20

t_list			*tetra_parse_init(char *tetras_str);
t_tetra			*tetra_node(char **tetras_str, char represent);
void			tetra_outline(t_tetra **tetra);

#endif
