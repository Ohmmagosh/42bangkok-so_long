/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 00:52:19 by psuanpro          #+#    #+#             */
/*   Updated: 2022/09/04 02:57:26 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	len_map_size(char *str)
{
	int i;

	i = 0;
	if(!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

int	count_line_map(t_pro *p, char *path)
{
	int	lenl;
	char	*line;
	
	lenl = 0;
	p->map.fd = open(path, O_RDONLY);
	line = get_next_line(p->map.fd);
	while(line != NULL)
	{
		free(line);
		line = get_next_line(p->map.fd);
		lenl++;
	}
	free(line);
	close(p->map.fd);
	return (lenl);
}

void	get_map_ar(t_pro *p, char *path)
{
	int	i;

	i = 0;
	p->map.lenl = count_line_map(p, path);
	p->map.fd = open(path, O_RDONLY);
	p->map.ar = malloc(sizeof(char *) * p->map.lenl + 1);
	while (i < p->map.lenl)
		p->map.ar[i++] = get_next_line(p->map.fd);
	p->map.ar[i] = get_next_line(p->map.fd);
	close(p->map.fd);
}

void	get_map(t_pro *p, char *path)
{
	// p->map.fd = open(path, O_RDONLY);
	// printf("map.fd == %d\n", p->map.fd);
	get_map_ar(p, path);
	// if (map_chk_size(p) != 0 || map_chk_wall(p) != 0)
	// {
	// 	if (map_chk_path(p) != 0)
	// 		printf("create map");
	// 	printf("free map after chk path");
	// }
	// else
	// 	printf("free map");
	
		
	// 	printf("hello\n");
	map_chk_path(p);
	// printf("map_chk == %d\n", map_chk_size(p));
	// if (chk_map(p) > 0)
		// create_map(p);
}