/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:23:49 by dvan-der          #+#    #+#             */
/*   Updated: 2022/01/28 09:52:11 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	increase_zoom(t_fdf *fdf, double x, int y);

void	zoom(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == 34)
		increase_zoom(fdf, 0.5, 0);
	else
		increase_zoom(fdf, -0.5, 0);
}

static void	increase_zoom(t_fdf *fdf, double x, int y)
{
	t_camera	*camera;

	camera = fdf->camera;
	if (y == 0)
		camera->zoom += x;
	else
		camera->size_z += x;
	make_black(fdf);
	letsdraw(fdf);
}
