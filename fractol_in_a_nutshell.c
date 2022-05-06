/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_in_a_nutshell.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:22:04 by ablaamim          #+#    #+#             */
/*   Updated: 2022/05/06 11:42:59 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct s_rbg
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_infos
{
	int		type;
	int		depth;
	int		iteration;
	double	width;
	double	height;
	double	scale;
	double	xr;
	double	yi;
	double	cr;
	double	ci;
}	t_infos;

typedef struct s_minilibx
{
	void	*mlx;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*win;
	int		color;
}	t_mlx;

typedef struct s_fractal
{
	t_mlx	mlx;
	t_rgb	color;
	t_infos	fractal;
}	t_fractal;

# define HEIGHT 1280
# define WIDTH 720
# define MSG "Welcome to fractol project !"

# define ESC 53
# define SPACE 49
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define UP_SCROLL 0x04
# define DOWN_SCROLL 0x05

void	ft_help(void)
{
	printf("Argument 1 : Choose a fractal : \n");
	printf("#######  MANDELBROT.....1 ######\n");
	printf("#######  JULIA SET......2 ######\n");
}

void	ft_selector(t_fractal *fractal, char **argv)
{
	if (!strcmp(argv[1], "mandelbrot"))
		fractal->fractal.type = 1;
	else if (!strcmp(argv[1], "julia"))
		fractal->fractal.type = 2;
	else
	{
		printf("ERROR : %s is not a valid argument\n", argv[1]);
		ft_help();
		exit (EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	if (argc >= 2)
	{
		ft_selector(&fractal, argv);
	}
	else
	{
		printf("ERROR : Missing argument\n");
		ft_help();
	}
	return (EXIT_SUCCESS);
}
