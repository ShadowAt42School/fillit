/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:02:38 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/11 23:13:13 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		bytes_read;
	char	*buf;

	argv++;
	argc--;
	if (argc != 1 || !argv)
		return (0);
	fd = open(*argv, O_RDONLY);
	if (!fd)
		return (0);
	buf = ft_strnew(MAX_BUF + 1);
	bytes_read = read(fd, buf, MAX_BUF + 1);
	ft_putnbr(bytes_read);
	if (bytes_read <= 0 || bytes_read % 21 != 0)
		return (0);
	tetra_parse_init(buf);
	return (0);
}
