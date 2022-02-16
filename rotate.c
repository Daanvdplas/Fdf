/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:23:49 by dvan-der          #+#    #+#             */
/*   Updated: 2021/12/16 15:40:26 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	increase_angle(t_fdf *fdf, double x, int y);

void	rotate(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == 6)
		increase_angle(fdf, 0.1, 0);
	else if (key == 14)
		increase_angle(fdf, -0.1, 0);
	else if (key == 1)
		increase_angle(fdf, 0.1, 1);
	else if (key == 13)
		increase_angle(fdf, -0.1, 1);
	else if (key == 0)
		increase_angle(fdf, 0.1, 2);
	else if (key == 2)
		increase_angle(fdf, -0.1, 2);
}

static void	increase_angle(t_fdf *fdf, double x, int y)
{
	t_camera	*camera;

	camera = fdf->camera;
	if (y == 0)
		camera->a_x += x;
	else if (y == 1)
		camera->a_y += x;
	else if (y == 2)
		camera->a_z += x;
	make_black(fdf);
	letsdraw(fdf);
}
