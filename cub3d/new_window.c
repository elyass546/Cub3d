#include "cub3d.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
	}
}

void	DrawSquare(t_vars *vars, int x, int y, int color)
{
	int	n = x;
	int	m = y;

	while (n < x + 50)
	{
		m = y;
		while (m < y + 50)
		{
			my_mlx_pixel_put(&vars->img, n, m, color);
			m++;
		}
		n++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void	new_win(t_vars *vars, int height, int fd)
{
	int		i;

	i = 0;
	vars->map = (char **)malloc(sizeof(char *) * (height + 1));
	while (i < height)
	{
		vars->map[i] = get_next_line(fd);
		i++;
	}
	vars->map[i] = NULL;
}
