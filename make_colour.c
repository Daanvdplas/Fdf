/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_colour.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:23:39 by dvan-der          #+#    #+#             */
/*   Updated: 2022/01/17 10:06:26 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static double	percent(int start, int end, int current);
static int		make_green(t_fdf *fdf, double z_perc, \
								double z_perc2, double percentage);

int	make_colour(t_fdf *fdf, int startx, int starty)
{
	int		green;
	double	percentage;
	double	z_perc;
	double	z_perc2;

	z_perc = fabs(fdf->var->dz / fdf->camera->max_z);
	z_perc2 = fabs(fdf->var->z0 / fdf->camera->max_z);
	if (fdf->var->dz == 0)
		return (255 << 16 | (int)(z_perc2 * 255) << 8 | 0);
	if (fdf->var->dx > fdf->var->dy)
		percentage = percent(startx, fdf->var->x1, fdf->var->x0);
	else
		percentage = percent(starty, fdf->var->y1, fdf->var->y0);
	green = make_green(fdf, z_perc, z_perc2, percentage);
	return ((255 << 16) | (green << 8) | 0);
}

static double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

static int	make_green(t_fdf *fdf, double z_perc, \
							double z_perc2, double percentage)
{
	int	green;

	if (fdf->camera->max_z > 0)
	{
		if (fdf->var->dz < 0 && fdf->var->z0 >= 0 && fdf->var->z1 >= 0)
			green = (255 * z_perc2) - (255 * z_perc * percentage);
		else
			green = (255 * z_perc2) + (255 * z_perc * percentage);
	}
	else
	{
		if (fdf->var->dz < 0 && fdf->var->z0 <= 0 && fdf->var->z1 <= 0)
			green = (255 * z_perc2) + (255 * z_perc * percentage);
		else
			green = (255 * z_perc2) - (255 * z_perc * percentage);
	}
	return (green);
}
