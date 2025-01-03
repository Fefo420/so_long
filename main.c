/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:53:32 by fileonar          #+#    #+#             */
/*   Updated: 2025/01/03 14:45:58 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*get_and_parse_map(char	*map_arg, int *error)
{
	char	*finished_map;

	finished_map = get_map(map_arg, error);
	finished_map = parse_map(finished_map, error);
	return (finished_map);
}

int main(int argc, char **argv)
{
	int		error;
	char	*map;


	error = 0;
	if (argc != 2)
		return (error_msg("Need exactly 2 arguments...\n", &error), EXIT_FAILURE);
	if (check_if_ber(argv[1], &error))
		return (error_msg("Map is not a .ber file...\n", &error), EXIT_FAILURE);
	map = get_and_parse_map(argv[1], &error);
	if (error == 1)
		return (EXIT_FAILURE);
	main_menu();
	return (EXIT_SUCCESS);
}

// -----------------------------------------------------------------------------
// // Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// // See README in the root project for more information.
// // -----------------------------------------------------------------------------

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// #define WIDTH 1080
// #define HEIGHT 720

// static mlx_image_t* image;

// // -----------------------------------------------------------------------------

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void ft_randomize(void* param)
// {
// 	(void)param;
// 	for (uint32_t i = 0; i < image->width; ++i)
// 	{
// 		for (uint32_t y = 0; y < image->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				rand() % 0xFF, // R
// 				rand() % 0xFF, // G
// 				rand() % 0xFF, // B
// 				rand() % 0xFF  // A
// 			);
// 			mlx_put_pixel(image, i, y, color);
// 		}
// 	}
// }

// void ft_hook(void* param)
// {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_W))
// 		image->instances[0].y -= 20;
// 	if (mlx_is_key_down(mlx, MLX_KEY_S))
// 		image->instances[0].y += 20;
// 	if (mlx_is_key_down(mlx, MLX_KEY_A))
// 		image->instances[0].x -= 20;
// 	if (mlx_is_key_down(mlx, MLX_KEY_D))
// 		image->instances[0].x += 20;
// }

// // -----------------------------------------------------------------------------

// int32_t main(void)
// {
// 	mlx_t* mlx;

// 	// Gotta error check this stuff
// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, 128, 128)))
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
	
// 	mlx_loop_hook(mlx, ft_randomize, mlx);
// 	mlx_loop_hook(mlx, ft_hook, mlx);

// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }

