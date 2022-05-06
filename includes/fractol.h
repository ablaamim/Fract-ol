/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:38:15 by ablaamim          #+#    #+#             */
/*   Updated: 2022/05/06 17:47:34 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>

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

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_infos
{
	int		depth;
	int		type;
	int		iteration;
	double	h;
	double	w;
	double	scale;
	double	x_real;
	double	y_im;
	double	c_real;
	double	c_im;
}	t_infos;

typedef struct s_minilib_x
{
	void	*mlx;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*win;
	int		color;
}	t_minilib_x;

typedef struct s_fractal
{
	t_infos		fractal;
	t_rgb		color;
	t_minilib_x	mlx;
}	t_fractal;

int		main(int argc, char **argv);
int		ft_strcmp(char *s1, char *s2);
void	options(void);
void	ft_initialize(t_fractal *fractal);
void	selector(t_fractal *fractal, char **argv);
int		key(int hook, t_fractal *fractal);
int		ft_draw(t_fractal *f);
int		ft_mandelbrot_constructor(t_fractal *fractal);

#endif
