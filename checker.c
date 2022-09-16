/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:46:51 by psuanpro          #+#    #+#             */
/*   Updated: 2022/09/16 07:35:38 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	chk_retangle(t_pro *p)
{
	int i;

	i = 1;
	while (p->map.ar[i])
	{
		if(lenx_map(p->map.ar[i]) != p->map.lenx)
			return (0);
		i++;
	}
	return (1);
}

int	chk_topnbot(t_pro *p)
{
	int	i;

	i = 0;
	while (i < p->map.lenx)
	{
		if (p->map.ar[0][i] != '1' || p->map.ar[p->map.leny - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	chk_leftnright(t_pro *p)
{
	int	i;
	
	i = 0;
	while (i < p->map.leny)
	{
		if (p->map.ar[i][0] != '1' || p->map.ar[i][p->map.lenx - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	chk_char(t_pro *p)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (p->map.ar[i] != NULL)
	{
		j = 0;
		while (p->map.ar[i][j] != '\n' && p->map.ar[i][j] != '\0')
		{
			if (ft_strchr("10PEC", p->map.ar[i][j]) == NULL)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	chk_map(t_pro *p, char *path)
{
	t_map	mbuff;

	if (ft_strnstr(path + ft_strlen(path) -4,".ber", 4) == NULL)
		error_checker(p, 0);
	if (p->map.leny <= 1 || !chk_retangle(p))
		printf("Map is Errror\n");
	if (!chk_topnbot(p) || !chk_leftnright(p))
		printf("Wall is Error!!\n");
	if (!chk_token(p))
		printf("token Error\n");
	if (!chk_char(p))
	 	printf("map Error\n");
	mbuff = new_map(path);
	if (!flood_fill(mbuff.ar, find_p(p, mbuff.ar, 0), find_p(p, mbuff.ar, 1)))
		printf("map is invalid exit");
	return(0);
}

void	error_checker(t_pro *p, int mode)
{
	(void)p; 
	(void)mode;
}