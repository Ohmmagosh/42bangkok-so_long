/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:48:00 by psuanpro          #+#    #+#             */
/*   Updated: 2022/09/19 17:29:25 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_pro *p)
{
	t_pic	i;

	init_img(&i, p);
	draw_loop(p, &i);
}

void	init_img(t_pic *pi, t_pro *p)
{
	pi->wall = new_img(p, "./asset/wall4.xpm");
	pi->floor = new_img(p, "./asset/floor.xpm");
	pi->col = new_img(p, "./asset/collect.xpm");
	pi->col2 = new_img(p, "./asset/col2.xpm");
	pi->exit = new_img(p, "./asset/exit.xpm");
	pi->exitc = new_img(p, "./asset/exit2.xpm");
	pi->spt = new_img(p, "./asset/spt.xpm");
	pi->spt1 = new_img(p, "./asset/spt1.xpm");
	pi->spt2 = new_img(p, "./asset/spt2.xpm");
	pi->spt3 = new_img(p, "./asset/spt3.xpm");
}

t_img	new_img(t_pro *p, char *path)
{
	t_img	img;

	img.c.x = 0;
	img.c.y = 0;
	img.ref = mlx_xpm_file_to_image(p->mlx, path, &img.p.x, &img.p.y);
	return (img);
}

int	loop_hook(t_pro *p)
{
	p->time = time(NULL) % 3;
	if (p->time == 0 || p->time == 1 || p->time == 2)
	{	
		mlx_clear_window(p->mlx, p->win);
		draw_map(p);
	}
	return (0);
}

int	move_chk_count_exit(t_pro *p, int x, int y, int mode)
{
	if (mode == 0 && p->map.ar[y - 1][x] == 'E' && p->ct < p->countall)
		return (0);
	else if (mode == 2 && p->map.ar[y][x - 1] == 'E' && p->ct < p->countall)
		return (0);
	else if (mode == 1 && p->map.ar[y + 1][x] == 'E' && p->ct < p->countall)
		return (0);
	else if (mode == 3 && p->map.ar[y][x + 1] == 'E' && p->ct < p->countall)
		return (0);
	return (1);
}
