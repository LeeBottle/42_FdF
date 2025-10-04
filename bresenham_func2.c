/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_func2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:52:38 by byeolee           #+#    #+#             */
/*   Updated: 2025/05/22 15:53:55 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_increments(t_point p0, t_point p1, int *x_inc, int *y_inc)
{
	if (p1.x > p0.x)
		*x_inc = 1;
	else
		*x_inc = -1;
	if (p1.y > p0.y)
		*y_inc = 1;
	else
		*y_inc = -1;
}

void	init_bresenham(t_bres *b, t_point p0, t_point p1, int is_steep)
{
	b->dx = abs(p1.x - p0.x);
	b->dy = abs(p1.y - p0.y);
	if (is_steep)
	{
		b->d = 2 * b->dx - b->dy;
		b->total_steps = b->dy;
	}
	else
	{
		b->d = 2 * b->dy - b->dx;
		b->total_steps = b->dx;
	}
	b->step = 0;
	set_increments(p0, p1, &b->x_inc, &b->y_inc);
}
