// try with minilbx
#include "stdio.h"
#include "stdlib.h"
#include "mlx/mlx.h"


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


int main()
{

	void	*mlx;
    void	*mlx_win;
    t_data    img;

	mlx = mlx_init();
    img.img = mlx_new_image(mlx, 1920, 1080);
   	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_win = mlx_new_window(mlx, 2000, 2000, "the name of the window");// the number stand for the hight and tail
    
	mlx_loop(mlx);
}