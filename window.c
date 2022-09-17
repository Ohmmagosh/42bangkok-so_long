/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 04:08:44 by psuanpro          #+#    #+#             */
/*   Updated: 2022/09/17 22:15:25 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_pro *p)
{
	free_after_chk(p);
	mlx_destroy_window(p->mlx, p->win);
	return (0);
}

void	create_window(t_pro *p)
{
	p->mlx = mlx_init();
	init_window(p);
	p->win = mlx_new_window(p->mlx, p->map.width, p->map.height, "so_long");
	draw_map(p);
	mlx_loop_hook(p->mlx, loop_hook, p);
	mlx_hook(p->win, 2, 1L << 0, key_hook, p);
	mlx_hook(p->win, 17, 1L << 0, close_win, p);
	mlx_loop(p->mlx);
}

void	draw_loop(t_pro *p, t_pic *i)
{
	t_vec	axis;

	axis = init_axis(p);
	while (p->map.ar[axis.j] != NULL)
	{	
		axis.x = 0;
		axis.k = 0;
		while (draw_utils(p->map.ar[axis.j][axis.k]) && axis.x < axis.l)
		{
			draw_utils2(p->map.ar[axis.j][axis.k], p, &axis, i);
			axis.x += 48;
		}
		axis.j++;
		axis.y += 48;
	}
}

void	draw_utils2(char map, t_pro *p, t_vec *axis, t_pic *i)
{
	if (map == '1')
		axis->k += draw_img(p, i->wall.ref, axis->x, axis->y);
	else if (map == '0')
		axis->k += draw_img(p, i->floor.ref, axis->x, axis->y);
	else if (map == 'C' && p->time == 0)
		axis->k += draw_img(p, i->col.ref, axis->x, axis->y);
	else if (map == 'C' && p->time == 1)
		axis->k += draw_img(p, i->col.ref, axis->x, axis->y);
	else if (map == 'C' && p->time == 2)
		axis->k += draw_img(p, i->col2.ref, axis->x, axis->y);
	else if (map == 'P' && p->time == 0)
		axis->k += draw_img(p, i->spt1.ref, axis->x, axis->y);
	else if (map == 'P' && p->time == 1)
		axis->k += draw_img(p, i->spt2.ref, axis->x, axis->y);
	else if (map == 'P' && p->time == 2)
		axis->k += draw_img(p, i->spt3.ref, axis->x, axis->y);
	else if (map == 'E' && p->ct != p->countall)
		axis->k += draw_img(p, i->exit.ref, axis->x, axis->y);
	else if (map == 'E' && p->ct == p->countall)
		axis->k += draw_img(p, i->exitc.ref, axis->x, axis->y);
}

t_vec	init_axis(t_pro *p)
{
	t_vec	i;

	i.x = 0;
	i.y = 0;
	i.k = 0;
	i.j = 0;
	i.l = p->map.width;
	return (i);
}
