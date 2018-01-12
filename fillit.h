/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:10:15 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/11 20:55:22 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

typedef struct	s_tetra
{
	char			*tetra;
	size_t			content_size;
	struct s_list	*next;
}				t_tetra;

/*
** Pre-Def values
** Macroses Part 0
*/
# define MAX_BUF = 546
# define TETRA_S = 20

#endif
