/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:13:34 by psuanpro          #+#    #+#             */
/*   Updated: 2022/09/16 03:44:46 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	draw_img(t_pro *p, void *ref, int x, int y)
{
	mlx_put_image_to_window(p->mlx, p->win, ref, x, y);
	return (1);
}

void	move_p(t_pro *p, int x, int y, int mode)
{
	if (mode == 0 && move_chk(p, x, y, 0) && count_c(p, x, y - 1, 0))
		p->step += move_p_utils(p, x, y, 0);
	else if (mode == 1 && move_chk(p, x, y, 1) && count_c(p, x, y + 1, 1))
		p->step += move_p_utils(p, x, y, 1);
	else if (mode == 2 && move_chk(p, x, y, 2) && count_c(p, x - 1, y, 2))
		p->step += move_p_utils(p, x, y, 2);
	else if (mode == 3 && move_chk(p, x, y, 3) && count_c(p, x + 1, y, 3))
		p->step += move_p_utils(p, x, y, 3);
	ft_printf("count step == %d count c == %d\n", p->step, p->ct);
	// draw_map(p);
}

int	key_hook(int key, t_pro *p)
{
	if (key == 53){
		mlx_destroy_window(p->mlx, p->win);
		exit(0);
	}
	else if(key == 13 || key == 126)
		move_p(p, find_p(p, p->map.ar, 1),find_p(p, p->map.ar, 0), 0);
	else if(key == 0 || key == 123)
		move_p(p, find_p(p, p->map.ar, 1), find_p(p, p->map.ar, 0), 2);
	else if(key == 1 || key == 125)
		move_p(p, find_p(p, p->map.ar, 1), find_p(p, p->map.ar, 0), 1);
	else if(key == 2 || key == 124)
		move_p(p, find_p(p, p->map.ar, 1), find_p(p, p->map.ar, 0), 3);
	return (0);
}

int	move_chk(t_pro *p, int x, int y, int mode)
{
	if (!move_chk_wall(p, x, y, mode))
		return (0);
	else if(!move_chk_count_exit(p, x, y, mode))
		return (0);
	else if(!move_chk_exit(p, x, y, mode))
		exit(0);
	return (1);
}

int	count_c(t_pro *p, int x, int y, int mode)
{
	if (p->map.ar[y][x] == 'C')
	{
		if (mode == 0)
			p->ct += 1;
		else if (mode == 2)
			p->ct += 1;
		else if (mode == 1)
			p->ct += 1;
		else if (mode == 3)
			p->ct += 1;
	}
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