#include "cub3d.h"

int mapx=8, mapy=8, maps=64;
int map[]=
{
    1,1,1,1,1,1,0,1,
    1,0,1,0,0,0,0,1,
    1,0,1,0,0,0,0,1,
    1,0,1,0,0,0,0,1,
    1,0,0,0,1,0,0,1,
    1,0,0,0,0,1,0,1,
    1,1,1,1,1,1,0,1,
};

void    print_Map(t_vars *vars)
{
    int x,y,xo,yo;

    y = 0;
    while(y < mapy)
    {
        x = 0;
        while (x < mapx)
        {
            if (map[y * (mapx + x)] == 1)
                DrawSquare(vars, x, y, 0x8E8E8E);
            else
                DrawSquare(vars, x, y, 0x000000);
            x++;
            xo = x * maps; yo = y * maps;
        }
        y++;
    }
}