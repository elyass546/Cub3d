#include "cub3d.h"

int	salam(void)
{
	exit(1);
	return (0);
}

int	keys_hook(int key, t_vars *vars)
{
	static const double PI = 3.1415926535;
	if (key == 53)
		exit(1);
	if (key == 13)
	{
		// go
		vars->x1 = vars->x1 +  (10 * cos(vars->angle * PI / 180));
		vars->y1 = vars->y1 +  (10 * sin(vars->angle * PI / 180));
	}
	if (key == 0)
	{
		//left
		vars->x1 -= 5;
	}
	if (key == 1)
	{
		// back
		vars->x1 = vars->x1 -  (10 * cos(vars->angle * PI / 180));
		vars->y1 = vars->y1 -  (10 * sin(vars->angle * PI / 180));
	}
	if (key == 2)
	{
		// right
		vars->x1 += 5;
	}
	if (key == 124)
	{
		//right rotation
		vars->angle += 10;
	}
	if (key == 123)
	{
		// left rotation
		vars->angle -= 10;
	}
	DrawCircle(100, vars);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_point	new_point(float x, float y)
{
	t_point a;
	
	a.x = x;
	a.y = y;
	return (a);
}

void	calculation(t_vars *vars, int r)
{
	static const double PI = 3.1415926535;

	vars->x2 = vars->x1 +  (r * cos(vars->angle * PI / 180));
	vars->y2 = vars->y1 +  (r * sin(vars->angle * PI / 180));
	dda(&vars->img, new_point(vars->x1, vars->y1), new_point(vars->x2, vars->y2));
	// vars->x3 = vars->x1 +  (r * cos(left * PI / 180));
	// vars->y3 = vars->y1 +  (r * sin(left * PI / 180));
	// dda(&vars->img, new_point(vars->x1, vars->y1), new_point(vars->x3, vars->y3));
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void DrawCircle(int r, t_vars *vars)
{
	// int right;
	// int left;

	// if (vars->angle + 45 > 360)
	// 	right = 45 - (360 - vars->angle);
	// else
	// 	right = vars->angle + 45;
	// if (vars->angle - 45 < 0)
	// 	left = 360 - (45 - vars->angle);
	// else
	// 	left = vars->angle - 45;
	mlx_clear_window(vars->mlx, vars->win);
	vars->img.img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
				&vars->img.line_length, &vars->img.endian);
	Show_Map(vars);
	calculation(vars, r);
}

int	main(int ac, char **av)
{
	(void)ac;
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	// vars.lines = i[0];
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "cub3d");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	vars.angle = 270; 
	vars.x1 = 500;
	vars.y1 = 500;
	vars.img = img;
	vars.mapa.av = av[1];
	Show_Map(&vars);
	DrawCircle(100, &vars);
	// ft_line_counter(i, av[1], &vars);
	// new_win(&vars, i[0], fd);
	mlx_hook(vars.win, 17, 0, salam, &vars);
	mlx_key_hook(vars.win, keys_hook, &vars);
	mlx_loop(vars.mlx);
}
