/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:39:04 by ablaamim          #+#    #+#             */
/*   Updated: 2022/05/06 19:32:37 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	selector(t_fractal *fractal, char **argv)
{
	if (!ft_strcmp(argv[1], "mandelbrot"))
		fractal->fractal.type = 1;
	else if (!ft_strcmp(argv[1], "julia"))
		fractal->fractal.type = 2;
	else
	{
		printf("ERROR : Invalid argument\n");
		options();
		exit (EXIT_SUCCESS);
	}
}

void	options(void)
{
	printf("Arg 1 : Select a fractal ###: \n");
	printf("######### mandelbrot ######## \n");
	printf("#########   julia  ########## \n");
}

void	ft_initialize(t_fractal *fractal)
{
	fractal->fractal.x_real = -2.0;
	fractal->fractal.y_im = -1.30;
	if (fractal->fractal.type == 1)
	{
		fractal->fractal.x_real = -2.5;
		fractal->fractal.y_im = -1.30;
	}
	fractal->fractal.c_real = 0x0;
	fractal->fractal.c_im = 0x0;
	fractal->fractal.iteration = 50;
	fractal->fractal.scale = 300.00;
	fractal->color.red = 0x42;
	fractal->color.green = 0x32;
	fractal->color.blue = 0x22;
	fractal->fractal.h = 0x0;
	fractal->fractal.w = 0x0;
}

int	main(int argc, char **argv)
{
	t_fractal	fract;

	if (argc >= 2)
	{
		selector(&fract, argv);
		fract.mlx.mlx = mlx_init();
		fract.mlx.win = mlx_new_window(fract.mlx.mlx, WIDTH, HEIGHT, MSG);
		fract.mlx.img = mlx_new_image(fract.mlx.mlx, WIDTH, HEIGHT);
		fract.mlx.addr = mlx_get_data_addr(fract.mlx.img,
				&fract.mlx.bits_per_pixel, &fract.mlx.line_length,
				&fract.mlx.endian);
		ft_initialize(&fract);
		ft_draw(&fract);
		//mlx_key_hook(fract.mlx.win, key, &fract);
		//mlx_mouse_hook(fract.mlx.win, mouse, &fract);
		mlx_loop(fract.mlx.mlx);
	}
	else
	{
		printf("\nERROR : Missing argument\n\n");
		options();
	}
	return (EXIT_SUCCESS);
}
