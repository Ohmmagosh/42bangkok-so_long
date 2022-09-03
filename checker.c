/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 23:42:54 by psuanpro          #+#    #+#             */
/*   Updated: 2022/09/04 02:25:34 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_chk_size(t_pro *p)
{
	int	len;
	int	i;

	i = 1;
	len = len_map_size(p->map.ar[0]);
	printf("lenl == %d\n", p->map.lenl);
	while (i < p->map.lenl && p->map.ar[i] != NULL)
	{
		printf("p->map.ar[%d] == %s\n", i, p->map.ar[i]);
		if (len != len_map_size(p->map.ar[i]))
			return (0);
		i++;
	}
	return (i);
}

void	create_map_buff(t_pro *p)
{
	int	i;

	i = 0;
	p->map.buf = malloc(sizeof(char *) * p->map.lenl + 1);
	while (i < p->map.lenl)
	{
		p->map.buf[i] = ft_strdup(p->map.ar[i]);
		i++;
	}
	p->map.buf[i] = NULL;
}

int	find_p_line(t_pro *p)
{
	return (0);
}

int	find_p_index(t_pro *p)
{
	return (0);
}

int	map_chk_path(t_pro *p)
{
	create_map_buff(p);


	return (0);
}