/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:59:53 by psuanpro          #+#    #+#             */
/*   Updated: 2022/09/15 06:56:58 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	chk_token(t_pro *p)
{
	if (count_token(p, 0) != 1)
	{
		write(1, "NO -----> P <----- in map", 25);
		return (0);
	}
	if (count_token(p, 1) < 1)
	{
		write(1, "NO -----> C <----- in map", 25);
		return (0);
	}
	if (count_token(p, 2) != 1)
	{
		write(1, "NO -----> E <----- in map", 25);
		return (0);
	}	
	return (1);
}

int	count_token(t_pro *p, int mode)
{
	int	i;
	int	j;
	int len;

	i = 0;
	j = 0;
	len = 0;
	while (p->map.ar[i] != NULL)
	{
		j = 0;
		while (p->map.ar[i][j] != '\n' && p->map.ar[i][j] != '\0')
		{
			if (p->map.ar[i][j] == 'P' && mode == 0)
				len++;
			else if (p->map.ar[i][j] == 'C' && mode == 1)
				len++;
			else if (p->map.ar[i][j] == 'E' && mode == 2)
				len++;
			j++;
		}
		i++;
	}
	return (len);
}
