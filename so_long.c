/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 20:28:18 by psuanpro          #+#    #+#             */
/*   Updated: 2022/08/16 22:23:55 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct	s_program
{
	void	*mlx;
	void	*window;
	void	*img;
	t_vector	size;
	
}				t_program;

typedef struct	s_image
{
	t_vector	size;
}	t_image;

int	key_hook(int key, t_program *program)
{
	if (key)
		printf("hello keyboard %d\n", key);
	return (0);
}

int	mouse_hook(int key, t_program *program)
{
	if (key)
		printf("hello mouse %d\n", key);
	return (0);
}

int	main(void)
{
	t_program	program;
	int	width;
	int	height;

	program.mlx = mlx_init();
	program.window = mlx_new_window(program.mlx, 1981, 1081, "hello!!!!");
	mlx_key_hook(program.window, key_hook, &program);//keyboard
	mlx_mouse_hook(program.window, mouse_hook, &program);//mouse
	
	program.img = mlx_xpm_file_to_image(program.mlx, "./474dfc565947440db50294afb746667d9bnyCRIgMe4EPIsB-10.xpm", &width, &height);
	int x = 0;
	int y = 0;
	
	while (y <= 1080)
	{
		x = 0;
		while (x <= 1980)
		{
			mlx_put_image_to_window(program.mlx , program.window, program.img, x, y);
			x += 64;
		}
		y += 64;
	}
	mlx_loop(program.mlx);
}
