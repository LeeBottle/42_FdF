/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_data_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:39:52 by byeolee           #+#    #+#             */
/*   Updated: 2025/05/27 13:45:18 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	preprocess_data(char **av, t_point ***points, t_storage *storage)
{
	count_values(av, storage);
	*points = mapping(av, *storage);
	storage->z_value_max = count_value_max(*points, storage);
	storage->z_value_min = count_value_min(*points, storage);
}

void	free_data(t_point **points, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(points[i++]);
	free(points);
}
