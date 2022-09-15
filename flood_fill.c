/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:33:03 by psuanpro          #+#    #+#             */
/*   Updated: 2022/09/14 02:58:53 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_p(t_pro *p,char **map, int mode)
{
	int i;
	int j;

	i = 0;
	while (map[i] != NULL && i < p->map.leny )
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if(map[i][j] == 'P')
			{
				if (mode == 0)
					return (i);
				return (j);
			}
			j++;
		}
	i++;
	}
	return (-1);
}

int	chk_flood(char **map, int x, int y)
{
	if (map[y][x] == '0' || map[y][x] == 'C' \
	 || map[y][x] == 'P')
	{
		map[y][x] = '1';
			return (1);
	}
	return (0);
}

int	flood_fill(char **map, int y, int x)
{
	int	floodfill;

	floodfill = 0;
	if (map[y][x] == 'E')
		return (1);
	if (map[y][x] != '1')
	{
		chk_flood(map, x, y);
		if (floodfill == 0)
			floodfill = flood_fill(map, y, x - 1);
		if (floodfill == 0)
			floodfill = flood_fill(map, y - 1, x);
		if (floodfill == 0)
			floodfill = flood_fill(map, y, x + 1);
		if (floodfill == 0)
			floodfill = flood_fill(map, y + 1, x);
	}
	return (floodfill);
}