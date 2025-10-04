/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:55:26 by byeolee           #+#    #+#             */
/*   Updated: 2025/05/21 17:54:58 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= 1920 || y < 0 || y >= 1080)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	isometric(t_point *p, t_storage *storage)
{
	double	scale;
	double	x_center;
	double	y_center;
	double	x_result;
	double	y_result;

	scale = fmin(1920.0 / (storage->x_value + storage->y_value),
			1080.0 / (storage->x_value + storage->y_value)) * 1.2;
	x_center = (storage->x_value - 1) / 2.0;
	y_center = (storage->y_value - 1) / 2.0;
	x_result = (p->x - x_center - (p->y - y_center)) * cos(M_PI / 5) * scale;
	y_result = (p->x - x_center + (p->y - y_center)) * sin(M_PI / 5) * scale;
	y_result -= p->z * (scale * 0.1);
	p->x = (int)(x_result + 1920 / 2);
	p->y = (int)(y_result + 1080 / 2);
}

void	draw_horizontal(t_point **points, t_data *img, t_storage *storage)
{
	int		y;
	int		x;
	t_point	p0;
	t_point	p1;

	y = 0;
	while (y < storage->y_value)
	{
		x = 0;
		while (x < storage->x_value - 1)
		{
			p0 = points[y][x];
			p1 = points[y][x + 1];
			isometric(&p0, storage);
			isometric(&p1, storage);
			bresenham(img, p0, p1, storage);
			x++;
		}
		y++;
	}
}

void	draw_vertical(t_point **points, t_data *img, t_storage *storage)
{
	int		x;
	int		y;
	t_point	p0;
	t_point	p1;

	x = 0;
	while (x < storage->x_value)
	{
		y = 0;
		while (y < storage->y_value - 1)
		{
			p0 = points[y][x];
			p1 = points[y + 1][x];
			isometric(&p0, storage);
			isometric(&p1, storage);
			bresenham(img, p0, p1, storage);
			y++;
		}
		x++;
	}
}

void	draw_map(t_point **points, t_data *img, t_storage *storage)
{
	draw_vertical(points, img, storage);
	draw_horizontal(points, img, storage);
}
