/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 04:08:44 by psuanpro          #+#    #+#             */
/*   Updated: 2022/09/16 03:55:40 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_window(t_pro *p)
{
	p->mlx = mlx_init();
	init_window(p);
	p->win = mlx_new_window(p->mlx, p->map.width, p->map.height, "so_long");
	draw_map(p);
	mlx_key_hook(p->win, key_hook, p);
	mlx_loop_hook(p->mlx, loop_hook, p);
	mlx_loop(p->mlx);
}

void	draw_loop(t_pro *p, t_pic *i, int x, int y)
{
	int	j;
	int	k;

	j = 0;
	while (p->map.ar[j] != NULL)
	{	
		x = 0;
		k = 0;
		while (p->map.ar[j][k] != '\n' && p->map.ar[j][k] != '\0' )
		{
			if (p->map.ar[j][k] == '1')
				k += draw_img(p, i->wall.ref, x, y);
			else if(p->map.ar[j][k] == '0')
				k += draw_img(p, i->floor.ref, x, y);
			else if(p->map.ar[j][k] == 'C')
				k += draw_img(p, i->col.ref, x, y);
			else if(p->map.ar[j][k] == 'E' && p->ct != p->countall)
				k += draw_img(p, i->exit.ref, x, y);
			else if(p->map.ar[j][k] == 'E' && p->ct == p->countall)
				k += draw_img(p, i->exitc.ref, x, y);
			else if(p->map.ar[j][k] == 'P' && p->time == 0)
				k += draw_img(p, i->spt1.ref, x, y);
			else if(p->map.ar[j][k] == 'P' && p->time == 1)
				k += draw_img(p, i->spt2.ref, x, y);
			else if(p->map.ar[j][k] == 'P' && p->time == 2)
				k += draw_img(p, i->spt3.ref, x, y);
			x+=48;
		}
		j++;
		y+=48;
	}
}

void	draw_map(t_pro *p)
{
	t_pic	i;

	init_img(&i, p);
	draw_loop(p, &i, 0, 0);

}

void	init_img(t_pic *pi, t_pro *p)
{
	pi->wall = new_img(p, "./asset/wall4.xpm");
	pi->floor = new_img(p, "./asset/floor.xpm");
	pi->col = new_img(p, "./asset/collect.xpm");
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
	int x = 0;
	int y = 0;
	// int i = 0;

	// i = mlx_mouse_get_pos(p->mlx, &x, &y);
	mlx_mouse_move(p->mlx,  x, y);
	printf(" x == %d y == %d\n", x, y);
	p->time = time(NULL) % 3;
	mlx_clear_window(p->mlx, p->win);
	draw_map(p);
	return (0);
}
