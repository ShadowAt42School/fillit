/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:02:38 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/14 20:58:12 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		bytes_read;
	char	*buf;
	t_list	*split_tetras;

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
	// while (split_tetras)
	// {
	// 	t_tetra *test = (t_tetra*)split_tetras->content;
	// 	ft_putstr((char*)test->tetra);
	// 	ft_putchar('\n');
	// 	split_tetras = split_tetras->next;
	// }
	// ft_putchar('\n');
	return (0);
}
