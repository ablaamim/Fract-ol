/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:39:04 by ablaamim          #+#    #+#             */
/*   Updated: 2022/05/11 16:27:26 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	man_fractol(void)
{
	printf("-----------------------------------------------------------\n");
	printf("             MAN fractol (42 project) : \n");
	printf("-----------------------------------------------------------\n\n");
	printf("SYNOPSYS :\n");
	printf("     ./fractol [-man/-julia/-mandelbrot]\n");
	printf("DESCRIPTION : \n");
	printf("     Render a choosen fractal using mlx library.\n\n");
	printf("-----------------------------------------------------------\n");
	printf ("                 COMPILATION :\n");
	printf("-----------------------------------------------------------\n\n");
	printf("Make : compile all source files and generate the executable.\n");
	printf("Make fclean : clean all objects and the executable file.\n");
	printf("Make clean : clean only executable.\n\n");
	printf("-----------------------------------------------------------\n");
	printf("             OPTIONS : ./fractol [option]\n");
	printf("-----------------------------------------------------------\n\n");
	printf("-man : display man.\n");
	printf("-mandelbrot : render mandelbrot set.\n");
	printf("-julia : render julia set.\n\n");
	printf("-----------------------------------------------------------\n");
}

void	selector(t_fractal *fractal, char **argv)
{
	if (!ft_strcmp(argv[1], "-man"))
	{
		man_fractol();
		exit (EXIT_SUCCESS);
	}
	else if (!ft_strcmp(argv[1], "-mandelbrot"))
		fractal->fractal.type = 1;
	else if (!ft_strcmp(argv[1], "-julia"))
		fractal->fractal.type = 2;
	else if (!ft_strcmp(argv[1], "-rabbit"))
		fractal->fractal.type = 3;
	else
	{
		printf("\nERROR : Invalid argument\n\n");
		options_menu();
		exit (EXIT_SUCCESS);
	}
}

void	options_menu(void)
{
	printf("###########     HELP MENU     #############\n");
	printf("#                                         #\n");
	printf("# Please enter an option from bellow :    #\n");
	printf("#                                         #\n");
	printf("# Option 0 : -man                         #\n");
	printf("# Option 1 : -mandelbrot                  #\n");
	printf("# Option 2 : -julia                       #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
}

void	ft_initialize(t_fractal *fractal, char **argv)
{
	fractal->fractal.z.re = -2.0;
	fractal->fractal.z.im = -1.2;
	fractal->fractal.c.re = 0x0;
	fractal->fractal.c.im = 0x0;
	if (argv[2])
		fractal->fractal.iteration = atoi(argv[2]);
	if (argv[3] && argv[4])
	{
		fractal->fractal.c.re = atof(argv[3]);
		fractal->fractal.c.im = atof(argv[4]);
	}
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
		ft_initialize(&fract, argv);
		ft_draw(&fract);
		ft_afplay();
		mlx_key_hook(fract.mlx.win, key_hook, &fract);
		mlx_mouse_hook(fract.mlx.win, mouse_hook, &fract);
		mlx_hook(fract.mlx.win, DESTROY, 0, close_afplay, &fract);
		mlx_loop(fract.mlx.mlx);
	}
	else
	{
		printf("\nERROR : Missing argument\n\n");
		options_menu();
		printf("\n");
	}

	return (EXIT_SUCCESS);
}
