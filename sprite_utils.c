/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 02:42:09 by psuanpro          #+#    #+#             */
/*   Updated: 2022/09/17 21:54:05 by psuanpro         ###   ########.fr       */
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

int	move_p_utils(t_pro *p, int x, int y, int mode)
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

int	chk_counter_c(int catch, int all)
{
	if (catch < all)
		return (0);
	return (1);
}

int	move_chk_wall(t_pro *p, int x, int y, int mode)
{
	if (mode == 0 && p->map.ar[y - 1][x] == '1')
		return (0);
	else if (mode == 2 && p->map.ar[y][x - 1] == '1')
		return (0);
	else if (mode == 1 && p->map.ar[y + 1][x] == '1')
		return (0);
	else if (mode == 3 && p->map.ar[y][x + 1] == '1')
		return (0);
	return (1);
}

int	move_chk_exit(t_pro *p, int x, int y, int mode)
{
	if (mode == 0 && p->map.ar[y - 1][x] == 'E' && p->ct == p->countall)
		return (0);
	else if (mode == 2 && p->map.ar[y][x - 1] == 'E' && p->ct == p->countall)
		return (0);
	else if (mode == 1 && p->map.ar[y + 1][x] == 'E' && p->ct == p->countall)
		return (0);
	else if (mode == 3 && p->map.ar[y][x + 1] == 'E' && p->ct == p->countall)
		return (0);
	return (1);
}
