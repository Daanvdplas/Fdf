/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:23:36 by dvan-der          #+#    #+#             */
/*   Updated: 2022/01/17 10:20:46 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	calc_pix_dist(t_fdf *fdf, float x0, float y0)
{
	float	screen_w_h;
	float	pix_amount;
	float	y;
	float	x;

	y = fdf->var->height_map - 1;
	x = fdf->var->width_map - 1;
	if ((float)SCREEN_H / (y - y0) > (float)SCREEN_W / (x - x0))
	{
		pix_amount = (y - y0);
		screen_w_h = (float)SCREEN_H;
	}
	else
	{
		pix_amount = (x - x0);
		screen_w_h = (float)SCREEN_W;
	}
	fdf->var->pix_dist = screen_w_h / ((pix_amount + 1) / 0.25);
	return ;
}

void	apply_zoom(t_fdf *fdf, int x, int y)
{
	fdf->copied_map[y][x][0] *= fdf->camera->zoom;
	fdf->copied_map[y][x][1] *= fdf->camera->zoom;
	fdf->copied_map[y][x][2] *= fdf->camera->zoom * fdf->camera->size_z;
	fdf->copied_map[y][x][3] = fdf->copied_map[y][x][2];
	return ;
}

void	rotation(t_fdf *fdf, int x, int y)
{
	float		oldx;
	float		oldy;

	oldy = fdf->copied_map[y][x][1];
	fdf->copied_map[y][x][1] = (fdf->copied_map[y][x][1] * \
	cos(fdf->camera->a_x)) + (fdf->copied_map[y][x][2] * sin(fdf->camera->a_x));
	fdf->copied_map[y][x][2] = (-oldy * sin(fdf->camera->a_x)) + \
	(fdf->copied_map[y][x][2] * cos(fdf->camera->a_x));
	oldx = fdf->copied_map[y][x][0];
	fdf->copied_map[y][x][0] = (fdf->copied_map[y][x][0] * \
	cos(fdf->camera->a_y)) + (fdf->copied_map[y][x][2] * sin(fdf->camera->a_y));
	fdf->copied_map[y][x][2] = (-oldx * sin(fdf->camera->a_y)) + \
		(fdf->copied_map[y][x][2] * cos(fdf->camera->a_y));
	oldx = fdf->copied_map[y][x][0];
	fdf->copied_map[y][x][0] = (fdf->copied_map[y][x][0] * \
	cos(fdf->camera->a_z)) - (fdf->copied_map[y][x][1] * sin(fdf->camera->a_z));
	fdf->copied_map[y][x][1] = (oldx * sin(fdf->camera->a_z)) + \
		(fdf->copied_map[y][x][1] * cos(fdf->camera->a_z));
	return ;
}

void	isometric_scale(t_fdf *fdf, int x, int y, float u)
{
	float	old;

	old = fdf->copied_map[y][x][0];
	fdf->copied_map[y][x][0] = (fdf->copied_map[y][x][0] - \
		fdf->copied_map[y][x][1]) * (u / 2);
	fdf->copied_map[y][x][1] = (old + fdf->copied_map[y][x][1]) * (u / 2);
	return ;
}

void	translation(t_fdf *fdf, int x, int y, float u)
{
	float	w;
	float	h;

	w = fdf->var->width_map;
	h = fdf->var->height_map;
	fdf->copied_map[y][x][0] = fdf->copied_map[y][x][0] + (SCREEN_W / 2) - \
		(w * u / 4) + (h * u / 4) + fdf->camera->x;
	fdf->copied_map[y][x][2] = fdf->copied_map[y][x][2] * u / 8;
	fdf->copied_map[y][x][1] = (fdf->copied_map[y][x][1] / 2) + (SCREEN_H / 2) \
	- (w * u / 8) - (h * u / 8) - fdf->copied_map[y][x][2] + fdf->camera->y;
	return ;
}
