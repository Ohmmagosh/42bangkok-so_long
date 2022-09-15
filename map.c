/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:12:48 by psuanpro          #+#    #+#             */
/*   Updated: 2022/09/15 08:01:26 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	lenx_map(char *map)
{
	int	lenx;

	lenx = 0;
	while (map[lenx] != '\n' && map[lenx] != '\0')
		lenx++;
	return (lenx);
}

int	leny_map(char *path)
{
	char	*line;
	int		fd;
	int		leny;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	leny = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		leny++;
	}
	free(line);
	close(fd);
	return (leny);
}

t_map	new_map(char *path)
{
	t_map	map;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
		printf("path Error!!");
	map.leny = leny_map(path);
	map.ar = (char **)malloc(sizeof(char *) * map.leny + 1);
	i = 0;
	while (i <= map.leny)
		map.ar[i++] = get_next_line(fd);
	close(fd);
	map.lenx = lenx_map(map.ar[0]);
	return (map);
}

void	get_map(t_pro *p, char *path)
{
	p->map = new_map(path);
	chk_map(p, path);
}