#include "so_long.h"

#define WIDTH 1920
#define HEIGHT 1080

int32_t main_menu(void)
{
	mlx_t *mlx;
	int error = 0;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "so_long", true)))
		error_msg("Failed to initialize MLX42", &error);
	mlx_texture_t *texture = mlx_load_png("pngs/mm.png");
	if (!texture)
		error_msg("Failed to load texture\n", &error);
	mlx_image_t *img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error_msg("Failed to load image\n", &error);
	if (mlx_image_to_window(mlx, img, 0, 0 < 0))
		error_msg("Failed to put image to window\n", &error);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	return(0);
}
