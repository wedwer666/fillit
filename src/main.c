

#include "fillit.h"

static void			print_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
			ft_putchar(map->map[i][j++]);
		ft_putchar('\n');
		i++;
	}
}

int					main(int argc, char **argv)
{
	t_info		*info;
	t_map		*map;

	if (argc == 2)
	{
		info = ft_info(argv[1]);
		if (info)
		{
			map = solve(info);
			if (map)
				print_map(map);
			else
				ft_putendl("error");
		}
		else
			ft_putendl("error");
	}
	else
	{
		ft_putendl("usage: fillit input_file\0");
	}
	return (0);
}
