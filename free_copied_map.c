/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_copied_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:23:51 by dvan-der          #+#    #+#             */
/*   Updated: 2022/02/04 12:11:38 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_copied_map(t_fdf *fdf, float ***copied_map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < fdf->var->height_map)
	{
		x = 0;
		while (x < fdf->var->width_map)
		{
			free(copied_map[y][x]);
			x++;
		}
		free(copied_map[y]);
		y++;
	}
	free(copied_map);
	return ;
}
