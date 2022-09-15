/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 02:42:09 by psuanpro          #+#    #+#             */
/*   Updated: 2022/09/16 03:09:26 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	init_window(t_pro *p)
{
	p->map.width = (p->map.lenx * 48) + 1;
	p->map.height = (p->map.leny * 48) + 1;
	p->ct = 0;
	p->step = 0;
	p->countall = count_token(p, 1);
}

int		move_p_utils(t_pro *p, int x, int y, int mode)
{
	p->map.ar[y][x] = '0';
	if (mode == 0)
		p->map.ar[y - 1][x] = 'P';
	else if (mode == 1)
		p->map.ar[y + 1][x] = 'P';
	else if (mode == 2)
		p->map.ar[y][x - 1] = 'P';
	else if (mode == 3)
		p->map.ar[y][x + 1] = 'P';
	return (1);
}