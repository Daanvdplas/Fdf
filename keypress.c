/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:23:33 by dvan-der          #+#    #+#             */
/*   Updated: 2022/01/28 09:52:47 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == 53)
		exit (0);
	if (key == 34 || key == 32)
		zoom(key, fdf);
	else if (key == 123 || key == 124
		|| key == 126 || key == 125)
		move(key, fdf);
	else if (key == 0 || key == 1
		|| key == 2 || key == 6
		|| key == 13 || key == 14)
		rotate(key, fdf);
	else if (key == 24 || key == 27)
		flatten(key, fdf);
	return (0);
}

void	make_black(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_W)
	{
		j = 0;
		while (j < SCREEN_H)
		{
			my_mlx_pixel_put(fdf, j, i, 0x00000000);
			j++;
		}
		i++;
	}
	return ;
}
