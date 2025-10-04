/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:10:44 by byeolee           #+#    #+#             */
/*   Updated: 2025/05/22 15:52:57 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(int z, t_storage *storage)
{
	double	ratio;
	t_color	color;

	color.r = 255;
	if (storage->z_value_max == storage->z_value_min)
		ratio = 0.0;
	else
		ratio = (double)(z - storage->z_value_min)
			/ (storage->z_value_max - storage->z_value_min);
	if (ratio < 0.5)
	{
		color.g = 255;
		color.b = 255 * (1.0 - ratio * 2.0);
	}
	else
	{
		color.g = 255 * (2.0 - ratio * 2.0);
		color.b = 255 * ((ratio - 0.5) * 2.0);
	}
	return ((color.r << 16) | (color.g << 8) | color.b);
}

void	bres_x(t_data *img, t_point p0, t_point p1, t_storage *st)
{
	t_bres	b;

	init_bresenham(&b, p0, p1, 0);
	while (p0.x != p1.x)
	{
		if (b.total_steps == 0)
			b.ratio = 0;
		else
			b.ratio = (double)b.step / b.total_steps;
		b.z = p0.z + (p1.z - p0.z) * b.ratio;
		my_mlx_pixel_put(img, p0.x, p0.y, get_color(b.z, st));
		if (b.d > 0)
		{
			p0.y += b.y_inc;
			b.d -= 2 * b.dx;
		}
		b.d += 2 * b.dy;
		p0.x += b.x_inc;
		b.step++;
	}
	my_mlx_pixel_put(img, p1.x, p1.y, get_color(p1.z, st));
}

void	bres_y(t_data *img, t_point p0, t_point p1, t_storage *st)
{
	t_bres	b;

	init_bresenham(&b, p0, p1, 1);
	while (p0.y != p1.y)
	{
		if (b.total_steps == 0)
			b.ratio = 0;
		else
			b.ratio = (double)b.step / b.total_steps;
		b.z = p0.z + (p1.z - p0.z) * b.ratio;
		my_mlx_pixel_put(img, p0.x, p0.y, get_color(b.z, st));
		if (b.d > 0)
		{
			p0.x += b.x_inc;
			b.d -= 2 * b.dy;
		}
		b.d += 2 * b.dx;
		p0.y += b.y_inc;
		b.step++;
	}
	my_mlx_pixel_put(img, p1.x, p1.y, get_color(p1.z, st));
}

void	bresenham(t_data *img, t_point p0, t_point p1, t_storage *storage)
{
	if (abs(p1.y - p0.y) <= abs(p1.x - p0.x))
		bres_x(img, p0, p1, storage);
	else
		bres_y(img, p0, p1, storage);
}
