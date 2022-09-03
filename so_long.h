/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:58:56 by psuanpro          #+#    #+#             */
/*   Updated: 2022/09/04 02:58:48 by psuanpro         ###   ########.fr       */
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

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

typedef struct s_vec
{
	int	x;
	int	y;
}				t_vec;

typedef struct s_map
{
	t_vec	size;
	char	**ar;
	char	**buf;
	int	lenl;
	int	fd;
}				t_map;

typedef struct s_pro
{
	void	*mlx;
	t_vec	*win;
	t_map	map;
}				t_pro;

int		count_line_map(t_pro *p, char *path);
void	get_map(t_pro *p,char *path);
void	get_map_ar(t_pro *p, char *path);
int		map_chk_size(t_pro *p);
int		map_chk_path(t_pro *p);
void	create_map_buff(t_pro *p);
int		map_chk_wall(t_pro *p);
int		flood_fill(t_pro *p);

# endif