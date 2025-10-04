/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:55:30 by byeolee           #+#    #+#             */
/*   Updated: 2025/05/27 14:06:10 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_value(char **values, char *line)
{
	int	i;

	if (values)
	{
		i = 0;
		while (values[i])
			free(values[i++]);
	}
	free(values);
	free(line);
}

static void	mapping_per(int fd, t_point **map, t_storage storage)
{
	int		y;
	int		x;
	char	*line;
	char	**z_values;

	y = 0;
	while (y < storage.y_value)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		z_values = ft_split(line, ' ');
		map[y] = malloc(sizeof(t_point) * storage.x_value);
		x = 0;
		while (x < storage.x_value)
		{
			map[y][x].x = x;
			map[y][x].y = y;
			map[y][x].z = ft_atoi(z_values[x]);
			x++;
		}
		free_value(z_values, line);
		y++;
	}
}

t_point	**mapping(char **av, t_storage storage)
{
	int		fd;
	t_point	**mapping;

	mapping = (t_point **)malloc(sizeof(t_point *) * storage.y_value);
	if (!mapping)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error reopening file");
		exit(1);
	}
	mapping_per(fd, mapping, storage);
	close(fd);
	return (mapping);
}
