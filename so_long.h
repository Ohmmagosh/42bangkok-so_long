/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:58:56 by psuanpro          #+#    #+#             */
/*   Updated: 2022/08/28 01:18:34 by psuanpro         ###   ########.fr       */
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
}	t_vec;

typedef	struct s_map
{
	t_vec	size;
	char	**m_ar;
	int	fd;
	int lenl;
}	s_map;

typedef struct s_pro
{
	void	*mlx;
	t_vec	*window;
	s_map	map;
	t_vec	sprite;
}	t_pro;

void	ft_create_map(t_pro	*p);
int	ft_len_line_sl(t_pro *p, char *path);
void	ft_get_map(t_pro *p,char *path);

#endif