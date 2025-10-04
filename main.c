/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:55:32 by byeolee           #+#    #+#             */
/*   Updated: 2025/05/27 13:45:16 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_data		img;
	t_point		**points;
	t_storage	storage;

	if (ac != 2)
	{
		perror("Error opening file");
		return (1);
	}
	preprocess_data(av, &points, &storage);
	preprocess_img(&img);
	draw_map(points, &img, &storage);
	free_data(points, storage.y_value);
	postprocess_img(&img);
	return (0);
}
