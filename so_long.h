/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:58:56 by psuanpro          #+#    #+#             */
/*   Updated: 2022/09/17 21:39:02 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <time.h>


typedef struct	s_vec
{
	int	x;
	int	y;
	int	j;
	int	k;
	int	l;
}				t_vec;

typedef struct	s_img
{
	void	*ref;
	t_vec	p;
	t_vec	c;
}				t_img;

typedef struct	s_pic
{
	t_img	wall;
	t_img	floor;
	t_img	exit;
	t_img	exitc;
	t_img	col;
	t_img	col2;
	t_img	spt;
	t_img	spt1;
	t_img	spt2;
	t_img	spt3;
}				t_pic;

typedef struct	s_map
{
	char	**ar;
	int		leny;
	int		lenx;
	int		width;
	int		height;
	int		lenc;
}				t_map;

typedef struct	s_pro
{
	void	*mlx;
	void	*win;
	int		ct;
	int		countall;
	int		step;
	int		time;
	t_map	map;
	t_vec	axis;
}				t_pro;

t_vec	init_axis(t_pro *p);
t_img	new_img(t_pro *p, char *path);
t_map	new_map(char *path);
void	get_map(t_pro *p, char *path);
void	create_window(t_pro *p);
void	draw_map(t_pro *p);
void	init_img(t_pic *pi, t_pro *p);
void	draw_loop(t_pro *p, t_pic *i);
void	init_window(t_pro *p);
void	error_checker(t_pro *p, int mode);
int		chk_map(t_pro *p, char *path);
int		chk_topnbot(t_pro *p);
int		chk_leftnright(t_pro *p);
int		chk_char(t_pro *p);
int		leny_map(char *path);
int		chk_retangle(t_pro *p);
int		lenx_map(char *map);
int		chk_flood(char **map, int x, int y);
int		find_p(t_pro *p,char **map, int mode);
int		flood_fill(char **map, int y, int x);
int		chk_len_token(t_pro *p, int mode);
int		count_token(t_pro *p, int mode);
int		chk_token(t_pro *p);
int		draw_img(t_pro *p, void *ref, int x, int y);
int		key_hook(int key, t_pro *p);
int		hello(int key, t_pro *p);
int		move_chk(t_pro *p, int x, int y, int mode);
int		move_chk_wall(t_pro *p, int x, int y, int mode);
int		move_chk_exit(t_pro *p, int x, int y, int mode);
int		move_chk_count_exit(t_pro *p, int x, int y, int mode);
int		count_c(t_pro *p, int x, int y, int mode);
int		move_p_utils(t_pro *p, int x, int y, int mode);
int		loop_hook(t_pro *p);
int		draw_utils(char map);
void	draw_utils2(char map, t_pro *p, t_vec *axis, t_pic *i);
void	free_after_chk(t_pro *p);
void	free_after_ff(t_map *pi, t_pro *p);
void	free_ff(t_map *p);

# endif