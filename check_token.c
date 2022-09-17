/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:59:53 by psuanpro          #+#    #+#             */
/*   Updated: 2022/09/17 20:25:30 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	chk_token(t_pro *p)
{
	if (count_token(p, 0) != 1)
	{
		write(1, "NO -----> P <----- in map", 25);
		return (0);
	}
	if (count_token(p, 1) < 1)
	{
		write(1, "NO -----> C <----- in map", 25);
		return (0);
	}
	if (count_token(p, 2) != 1)
	{
		write(1, "NO -----> E <----- in map", 25);
		return (0);
	}	
	return (1);
}

int	count_token(t_pro *p, int mode)
{
	int	i;
	int	j;
	int len;

	i = 0;
	j = 0;
	len = 0;
	while (p->map.ar[i] != NULL)
	{
		j = 0;
		while (p->map.ar[i][j] != '\n' && p->map.ar[i][j] != '\0')
		{
			if (p->map.ar[i][j] == 'P' && mode == 0)
				len++;
			else if (p->map.ar[i][j] == 'C' && mode == 1)
				len++;
			else if (p->map.ar[i][j] == 'E' && mode == 2)
				len++;
			j++;
		}
		i++;
	}
	return (len);
}
void	error_checker(t_pro *p, int mode)
{
	free_after_chk(p);
	if (mode == 0)
		ft_printf("Error: map is invalid\n");
	else if (mode == 1)
		ft_printf("Error: map is not retangle\n");
	else if (mode == 2)
		ft_printf("Error: Wall is invalid\n");
	else if (mode == 3)
		ft_printf("Error: Token\n");
	else if (mode == 4)
		ft_printf("Error: Map invalid character\n");
}

void	free_after_chk(t_pro *p)
{
	int i;

	i = -1;
	while (p->map.ar[++i])
		free(p->map.ar[i]);
	free(p->map.ar);
	p->map.ar = NULL;
}

void	free_after_ff(t_map *pi, t_pro *p)
{
	int i;

	i = -1;
	while (pi->ar[++i])
		free(pi->ar[i]);
	free(pi->ar);
	pi->ar = NULL;
	free_after_chk(p);
}

