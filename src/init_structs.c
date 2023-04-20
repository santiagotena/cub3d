#include "cub3d.h"

void	init_param(t_cube *cube)
{
	t_param	*param;

	param = &cube->param;
	param->input_str = NULL;
	param->splitted_input = NULL;
	param->no = NULL;
	param->so = NULL;
	param->we = NULL;
	param->ea = NULL;
	param->f = NULL;
	param->c = NULL;
	param->f_rgb = malloc(sizeof(int) * 3);
	param->c_rgb = malloc(sizeof(int) * 3);
	param->map = NULL;
}

void	init_mlx(t_cube *cube)
{
	t_mlx	*mlx;

	mlx = &cube->mlx;
	mlx->mlx_ptr = NULL;
	mlx->window = NULL;
}

void	init_cube(t_cube *cube)
{
	cube->param.cube = cube;
	cube->mlx.cube = cube;
}

void	init_structs(t_cube *cube)
{
	init_cube(cube);
	init_param(cube);
	init_mlx(cube);
}