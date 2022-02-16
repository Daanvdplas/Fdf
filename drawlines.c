/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:23:39 by dvan-der          #+#    #+#             */
/*   Updated: 2022/01/17 10:13:55 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	send_2points(int y, int x, t_fdf *fdf);
static void	calc_line(float *point_0, float *point_n, t_fdf *fdf);
static void	draw_line(t_fdf *fdf, int x, int y);
static int	edit_err(t_fdf *fdf, int e2, int err);

void	drawlines(t_fdf *fdf)
{
	int		y;
	int		x;

	y = 0;
	while (y <= fdf->var->height_map - 1)
	{
		x = 0;
		while (x <= fdf->var->width_map - 1)
		{
			if (y == fdf->var->height_map - 1 && x == fdf->var->width_map - 1)
				return ;
			send_2points(y, x, fdf);
			x++;
		}
		y++;
	}
	return ;
}

static void	send_2points(int y, int x, t_fdf *fdf)
{
	if (y == fdf->var->height_map - 1)
		calc_line(fdf->copied_map[y][x], fdf->copied_map[y][x + 1], fdf);
	else if (x == fdf->var->width_map - 1)
		calc_line(fdf->copied_map[y][x], fdf->copied_map[y + 1][x], fdf);
	else
	{
		calc_line(fdf->copied_map[y][x], fdf->copied_map[y + 1][x], fdf);
		calc_line(fdf->copied_map[y][x], fdf->copied_map[y][x + 1], fdf);
	}
	return ;
}

static void	calc_line(float *point_0, float *point_n, t_fdf *fdf)
{
	fdf->var->x0 = (int)point_0[0];
	fdf->var->x1 = (int)point_n[0];
	fdf->var->y0 = (int)point_0[1];
	fdf->var->y1 = (int)point_n[1];
	fdf->var->z0 = (int)point_0[3];
	fdf->var->z1 = (int)point_n[3];
	fdf->var->dx = (int)point_n[0] - (int)point_0[0];
	fdf->var->dy = (int)point_n[1] - (int)point_0[1];
	fdf->var->dz = (int)point_n[3] - (int)point_0[3];
	if (fdf->var->dx < 0)
	{
		fdf->var->xs = -1;
		fdf->var->dx *= -1;
	}
	else
		fdf->var->xs = 1;
	if (fdf->var->dy > 0)
	{
		fdf->var->ys = 1;
		fdf->var->dy *= -1;
	}
	else
		fdf->var->ys = -1;
	draw_line(fdf, fdf->var->x0, fdf->var->y0);
	return ;
}

static void	draw_line(t_fdf *fdf, int startx, int starty)
{
	int		err;
	int		e2;

	err = fdf->var->dx + fdf->var->dy;
	while (1)
	{
		if (fdf->var->x0 >= 0 && fdf->var->x0 < SCREEN_W && \
				fdf->var->y0 < SCREEN_H && fdf->var->y0 >= 0)
		{
			my_mlx_pixel_put(fdf, fdf->var->x0, fdf->var->y0, \
								make_colour(fdf, startx, starty));
		}
		if (fdf->var->x0 == fdf->var->x1 && fdf->var->y0 == fdf->var->y1)
			break ;
		e2 = 2 * err;
		err = edit_err(fdf, e2, err);
	}
	return ;
}

static int	edit_err(t_fdf *fdf, int e2, int err)
{
	if (e2 >= fdf->var->dy)
	{
		err += fdf->var->dy;
		fdf->var->x0 += fdf->var->xs;
	}
	if (e2 <= fdf->var->dx)
	{
		err += fdf->var->dx;
		fdf->var->y0 += fdf->var->ys;
	}
	return (err);
}
