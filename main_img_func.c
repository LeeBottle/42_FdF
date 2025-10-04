/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_img_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:39:57 by byeolee           #+#    #+#             */
/*   Updated: 2025/05/23 17:42:12 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int keycode, t_data *img)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(img->mlx, img->win);
		mlx_destroy_image(img->mlx, img->img);
		mlx_destroy_display(img->mlx);
		free(img->mlx);
		exit(0);
	}
	return (0);
}

int	handle_close(t_data *img)
{
	mlx_destroy_window(img->mlx, img->win);
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	exit(0);
	return (0);
}

void	preprocess_img(t_data *img)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, 1920, 1080, "FDF");
	img->img = mlx_new_image(img->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	postprocess_img(t_data *img)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_hook(img->win, 17, 0, handle_close, img);
	mlx_key_hook(img->win, handle_keypress, img);
	mlx_loop(img->mlx);
}
