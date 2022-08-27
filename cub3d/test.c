#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "cub3d.h"

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

t_point	new_point(float x, float y)
{
	t_point a;
	
	a.x = x;
	a.y = y;
	return (a);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void	calculation(t_vars *vars, int right, int left, int r)
// {
// 	static const double PI = 3.1415926535;

// 	vars->x2 = vars->x1 +  (r * cos(right * PI / 180));
// 	vars->y2 = vars->y1 +  (r * sin(right * PI / 180));
// 	dda(&vars->img, new_point(vars->x1, vars->y1), new_point(vars->x2, vars->y2));
// 	vars->x3 = vars->x1 +  (r * cos(left * PI / 180));
// 	vars->y3 = vars->y1 +  (r * sin(left * PI / 180));
// 	dda(&vars->img, new_point(vars->x1, vars->y1), new_point(vars->x3, vars->y3));
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
// }

// void DrawCircle(int r, t_vars *vars)
// {
// 	int right;
// 	int left;

// 	if (vars->angle + 45 > 360)
// 		right = 45 - (360 - vars->angle);
// 	else
// 		right = vars->angle + 45;
// 	if (vars->angle - 45 < 0)
// 		left = 360 - (45 - vars->angle);
// 	else
// 		left = vars->angle - 45;
// 	mlx_clear_window(vars->mlx, vars->win);
// 	vars->img.img = mlx_new_image(vars->mlx, 1920, 1080);
// 	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
// 				&vars->img.line_length, &vars->img.endian);
// 	calculation(vars, right, left, r);
// }

void DrawCircle(int x, int y, int r, t_data *data)
{
    static const double PI = 3.1415926535;
    double i, angle, x1, y1;

    for(i = 0; i < 360; i += 0.1)
    {
        angle = i;
        x1 = r * cos(angle * PI / 180);
        y1 = r * sin(angle * PI / 180);
        my_mlx_pixel_put(data, x1 + x, y + y1,  0xFFFF00);
    }
}

int	main(void)
{
	t_data	img;
    t_vars  vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    vars.img = img;
    vars.angle = 270;
    vars.x1 = 500;
    vars.y1 = 500;
    DrawCircle(vars.x1, vars.y1, 100, &img);
    mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0 , 0);
	mlx_loop(vars.mlx);
}