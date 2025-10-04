/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:36:39 by byeolee           #+#    #+#             */
/*   Updated: 2025/05/27 14:37:02 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./mlx_linux/mlx.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_storage
{
	int	x_value;
	int	y_value;
	int	z_value_max;
	int	z_value_min;
}	t_storage;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_bres
{
	int		d;
	int		step;
	int		total_steps;
	double	ratio;
	int		z;
	int		x_inc;
	int		y_inc;
	int		dx;
	int		dy;
}	t_bres;

int		main(int ac, char **av);
void	preprocess_data(char **av, t_point ***points, t_storage *storage);
void	free_data(t_point **points, int height);
int		handle_keypress(int keycode, t_data *img);
int		handle_close(t_data *img);
void	preprocess_img(t_data *img);
void	postprocess_img(t_data *img);
void	count_values(char **av, t_storage *storage);
int		count_value_max(t_point **points, t_storage *storage);
int		count_value_min(t_point **points, t_storage *storage);
t_point	**mapping(char **av, t_storage storage);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	isometric(t_point *p, t_storage *storage);
void	draw_horizontal(t_point **points, t_data *img, t_storage *storage);
void	draw_vertical(t_point **points, t_data *img, t_storage *storage);
void	draw_map(t_point **points, t_data *img, t_storage *storage);
void	set_increments(t_point p0, t_point p1, int *x_inc, int *y_inc);
void	init_bresenham(t_bres *b, t_point p0, t_point p1, int is_steep);
void	brese_x(t_data *img, t_point p0, t_point p1, t_storage *storage);
void	brese_y(t_data *img, t_point p0, t_point p1, t_storage *storage);
void	bresenham(t_data *img, t_point p0, t_point p1, t_storage *storage);
void	free_points(t_point **points, int height);
void	free_value(char **values, char *line);

#endif
