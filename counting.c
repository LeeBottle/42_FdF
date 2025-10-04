#include "fdf.h"

void	count_values(char **av, t_storage *storage)
{
	int		fd;
	char	*line;
	char	**split;
	int		value_count;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	storage->y_value = 0;
	line = get_next_line(fd);
	while (line)
	{
		split = ft_split(line, ' ');
		value_count = 0;
		while (split[value_count] && split[value_count][0] != '\n')
			value_count++;
		storage->y_value++;
		free_value(split, line);
		line = get_next_line(fd);
	}
	close(fd);
	storage->x_value = value_count;
}

int	count_value_max(t_point **points, t_storage *storage)
{
	int	i;
	int	x;
	int	y;

	x = 0;
	i = points[0][0].z;
	while (x < storage->x_value)
	{
		y = 0;
		while (y < storage->y_value)
		{
			if (i <= points[y][x].z)
			{
				i = points[y][x].z;
			}
			y++;
		}
		x++;
	}
	return (i);
}

int	count_value_min(t_point **points, t_storage *storage)
{
	int	i;
	int	x;
	int	y;

	x = 0;
	i = points[0][0].z;
	while (x < storage->x_value)
	{
		y = 0;
		while (y < storage->y_value)
		{
			if (i > points[y][x].z)
				i = points[y][x].z;
			y++;
		}
		x++;
	}
	return (i);
}
