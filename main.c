/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:02:38 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/18 03:20:07 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra_main		*tetra_parse_init(char *tetras_str)
{
	t_list			*list;
	t_tetra			*tetra;
	char			char_rep;
	int				tetra_c;
	t_tetra_main	*tetra_main;

	char_rep = 'A';
	list = 0x00;
	tetra_c = 0;
	while (*tetras_str)
	{
		tetra = tetra_node(&tetras_str, char_rep++);
		ft_lstpush(&list, ft_lstnew(tetra, sizeof(t_tetra)));
		tetra_c++;
	}
	tetra_main = (t_tetra_main*)(ft_memalloc(sizeof(t_tetra_main)));
	tetra_main->list = list;
	tetra_main->tetras_c = tetra_c;
	return (tetra_main);
}

void				solve_init(t_tetra_main *tetra_mn)
{
	t_point			**map;
	t_list			*list;
	int				min_square;

	min_square = ft_floorsqrt(tetra_mn->tetras_c * TETRA_HASH_C);
	map = (t_point**)ft_memalloc(sizeof(t_point*) * (tetra_mn->tetras_c + 1));
	list = tetra_mn->list;
	tetra_solver(map, list, &min_square, tetra_mn->tetras_c);
	while (*map)
	{
		ft_putnbr((*map)->x);
		ft_putchar('\n');
		ft_putnbr((*map)->y);
		ft_putchar('\n');
		(*map)++;
	}
}

int					main(int argc, char **argv)
{
	int				fd;
	int				bytes_read;
	char			*buf;
	t_tetra_main	*split_tetras;

	argv++;
	argc--;
	if (argc != 1 || !argv)
		return (0);
	fd = open(*argv, O_RDONLY);
	if (!fd)
		return (0);
	buf = ft_strnew(MAX_BUF + 1);
	bytes_read = read(fd, buf, MAX_BUF);
	if (bytes_read <= 0 || (bytes_read + 1) % 21 != 0)
		return (0);
	split_tetras = tetra_parse_init(buf);
	solve_init(split_tetras);
	return (0);
}
