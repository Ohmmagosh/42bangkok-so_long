/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:31:19 by psuanpro          #+#    #+#             */
/*   Updated: 2022/09/16 01:08:06 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ar, char **av)
{
	t_pro p;
	if (ar == 2)
	{
		get_map(&p, av[1]);
		create_window(&p);
	}
	else
		printf("argument error\n");
	return (0);
}