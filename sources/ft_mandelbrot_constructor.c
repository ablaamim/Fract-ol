/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot_constructor.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:33:45 by ablaamim          #+#    #+#             */
/*   Updated: 2022/05/09 21:04:00 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_mandelbrot_constructor(t_fractal *fractal)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fractal->fractal.depth = 0x0;
	zr = 0x0;
	zi = 0x0;
	ci = fractal->fractal.w / fractal->fractal.scale + fractal->fractal.y_im;
	cr = fractal->fractal.h / fractal->fractal.scale + fractal->fractal.x_real;
	while (((zr * zr) + (zi * zi) < 4) && (fractal->fractal.depth \
		< fractal->fractal.iteration))
	{
		tmp_zr = zr;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = (2 * zi) * tmp_zr + ci;
		fractal->fractal.depth += 1;
	}
	return (fractal->fractal.depth);
}
