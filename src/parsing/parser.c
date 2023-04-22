#include "cub3d.h"

char *read_from_file(char *path)
{
    int     fd;
    char    *output;
    int     counter;
    int     rd;

    fd = 0;
    rd = 0;
    counter = 0;
    fd = open(path, O_RDONLY);
    if(fd < 0)
        return(NULL);
    output = malloc(10000);
    while(1)
    {
        rd = read(fd, &output[counter], 1);
        if (rd <= 0)
            break;
        counter++;
    }
    output[counter + 1] = '\0';
    return(output);
}

char **split_input(char *input_str)
{
    char **output;
    output = ft_split(input_str, '\n');
    if(output == 0)
        return(NULL);
    return(output);
}

void    init_elements(char **splitted, t_param *param)
{
    int i;
    t_cube *cube;

    i = 0;
    cube = param->cube;
    while (i < 6)
    {
        if (ft_strncmp(splitted[i], "NO ", 3) == 0)
            param->no = ft_strdup(&splitted[i][3]);
        else if (ft_strncmp(splitted[i], "SO ", 3) == 0)
            param->so = ft_strdup(&splitted[i][3]);
        else if (ft_strncmp(splitted[i], "WE ", 3) == 0)
            param->we = ft_strdup(&splitted[i][3]);
        else if (ft_strncmp(splitted[i], "EA ", 3) == 0)
            param->ea = ft_strdup(&splitted[i][3]);
        else if (ft_strncmp(splitted[i], "F ", 2) == 0)
            param->f = ft_strdup(&splitted[i][2]);
        else if (ft_strncmp(splitted[i], "C ", 2) == 0)
            param->c = ft_strdup(&splitted[i][2]);
        else
            init_elements_error(cube);
        i++;
    }
}

//This function takes our ".cub" map as an input
//Opens a file and copies the map with all symbols to char **map
//Returns Null (almost impossible) or a filled map
//Needs tests, also not sure is sets last map[i] to NULL
void    assign_map(char **splitted_input, t_cube *cube)
{
    int i;
    int j;

    i = 6;
    j = 0;
    while (splitted_input[i])
    {
        i++;
        j++;
    }
    i = 6;
    cube->param.map = malloc(sizeof(char *) * j);
    cube->param.map[j] = NULL;
    j = 0;
    while (splitted_input[i])
    {
        cube->param.map[j] = ft_strdup(splitted_input[i]);
        i++;
        j++;
    }
}

void     parse_input(int argc, char *path, t_cube *cube)
{
    if (argc != 2)
        argc_error(cube);
    check_extension(path, cube);
    cube->param.input_str = read_from_file(path);
    cube->param.splitted_input = split_input(cube->param.input_str);
    init_elements(cube->param.splitted_input, &cube->param);
    check_texture_files(&cube->param); // Uncomment later
    check_rgb(&cube->param);
    check_map_double_n(cube->param.input_str, cube);
    check_map_row(cube->param.splitted_input, cube);
    assign_map(cube->param.splitted_input, cube);
    // check_map_column(); Julien's approach fill end of lines with spaces
    // check_player_inside_wall(); Use same approach as above and check_map_row
    check_invalid_spaces(cube->param.map, cube);
    check_forbidden_chars(cube->param.map, cube);
    check_player(cube->param.map, cube);
}