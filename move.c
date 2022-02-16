/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:23:49 by dvan-der          #+#    #+#             */
/*   Updated: 2021/12/16 15:41:05 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	increase_xy(t_fdf *fdf, double x, int y);

void	move(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == 123)
		increase_xy(fdf, -100, 1);
	else if (key == 124)
		increase_xy(fdf, 100, 1);
	else if (key == 125)
		increase_xy(fdf, 100, 0);
	else if (key == 126)
		increase_xy(fdf, -100, 0);
}

static void	increase_xy(t_fdf *fdf, double x, int y)
{
	t_camera	*camera;

	camera = fdf->camera;
	if (y == 0)
		camera->y += x;
	else
		camera->x += x;
	make_black(fdf);
	letsdraw(fdf);
}
