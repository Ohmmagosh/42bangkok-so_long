/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:31:19 by psuanpro          #+#    #+#             */
/*   Updated: 2022/08/28 03:20:13 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_chk_map(char **line)
{
	int	i;
	int j;
	
	i = -1;
	j = -1;
	while(line[++i] != NULL)
	{
		while (line[i][++j] != '\0')
		{
			if(line[i][j] != '0' || line[i][j] != '1' \
				|| line[i][j] != 'C' || line[i][j] != 'E'\
				|| line[i][j] != 'P' ||line[i][j] != '\n')
			{
				write(1, "map is wrong!!!", 15);
				// ft_free_map(&p);
			}
		}
	}
}

int	ft_len_line_sl(t_pro *p, char *path)
{
	char *line;
	int	len_line;

	p->map.fd = open(path, O_RDONLY);
	line = get_next_line(p->map.fd);
	len_line = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(p->map.fd);
		len_line++;
	}
	free(line);
	close(p->map.fd);
	return (len_line);
}

void	ft_get_map(t_pro *p, char *path)
{
	int	j;
	int	i;

	i = -1;
	j = ft_len_line_sl(p, path);
	p->map.fd = open(path, O_RDONLY);
	p->map.m_ar = (char **)malloc(sizeof(char *) * (j + 1));
	while (++i < j)
		p->map.m_ar[i] = get_next_line(p->map.fd);
	p->map.m_ar[i + 1] = NULL;
	close(p->map.fd);
	// ft_chk_map(p->map.m_ar);
}
// void	ft_create_map(t_pro	*p)
// {
// 	p->map.size.x = 1000;//48*ft_strlenline;
// 	p->map.size.y = 1000;//48*len_line;
// 	p->window = mlx_new_window(p->mlx, p->map.size.x, p->map.size.y, "so_long");
// }

int	main(int ac, char **av)
{
	(void)ac;
	t_pro	p;

	// p.mlx = mlx_init();
	
	ft_get_map(&p, av[1]);
	// ft_create_map(&p);
	int i = 0;
	while(p.map.m_ar[i] != NULL){
		printf("m_ar[%d] = %s\n",i, p.map.m_ar[i]);
		i++;
	}
	
	// ft_free_so_long();
	// mlx_loop(p.mlx);
}