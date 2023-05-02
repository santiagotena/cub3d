# cub3D
 
<p align="center">
<img src="https://github.com/santiagotena/assets/blob/master/logos/42%20logo.jpeg?raw=true" alt="42 Wolfsburg Logo" width="150" height="150">
</p>
 
Cub3D is a 42 Wolfsburg raycasting project where a pseudo-3D maze is to be rendered.

For this project it was key to implement a parser that processes custom .cub files and to connect it with a raycasting module. 
The latter has a Digital Differential Analysis (DDA) at its core. 

Other things of note for completing this particular project include

structs, generizable memory freeing strategies


This project was done as a team by:
<ul>
<li> Yurii Arutiunov - <a href="https://github.com/yarutiun">Github</a></li>
<li> Santiago Tena - <a href="https://github.com/santiagotena">Github</a> </li>
</ul>
 
## Rules

### Map:

The program is to parse a .cub file.

This file contains 6 elements and a map.
Elements `NO` `SO` `WE` `EA` are to be paired with paths for.xpm texture files.
The elements`C` and `F` match with RGB values to render the colors of the ceiling and floor respectively.
The map is to have a values of `1` for walls, `0` for empty spaces.
Finally, the map is also to have `N` `S` `W` or `E` character for the player staring position and spatial orientation.

An example of a valid map looks like this:
<p align="center">
<img src="https://github.com/santiagotena/cub3d/blob/main/screenshots/test_map.png?raw=true" alt="Map.cub example image">
</p>

### Movement:

The user can use the following keys for movement of the player and the camera:

`W` - Forward movement.</li>
`S` - Backward movement.</li>
`A` - Movement to the left.</li>
`D` - Movement to the right.</li>
`LEFT_ARROW` - Rotate the camera to the left.</li>
`RIGHT_ARROW` - Rotate the camera to the right.</li>

### Available parameters:
 
The only parameter that is needed for this program to run is `path_to_cub_file`.
 
In case of providng an invalid path to a .cub file or by feeding a .cub file with erroneous elements or maps,
the program displays an appropriate error message.

Errors include for example: Providing a non-closed map, not providing a player starting position and not 
providing a valid texture file for the walls.
 
# Usage
 
Use `make` to compile the program.
 
Add the required parameter:
 
```
./cub3D <path_to_cub_file>
```
 
# Example
 
Input:
 
```
./cub3D maps/test.cub
```
 
# Screenshots

<p align="center">
<img src="https://github.com/santiagotena/cub3d/blob/main/screenshots/cube01.png?raw=true" alt="Cub3d example image">
</p>
<p align="center">
<img src="https://github.com/santiagotena/cub3d/blob/main/screenshots/cube02.png?raw=true" alt="Cub3d example image">
</p>
<p align="center">
<img src="https://github.com/santiagotena/cub3d/blob/main/screenshots/cube03.png?raw=true" alt="Cub3d example image">
</p>
