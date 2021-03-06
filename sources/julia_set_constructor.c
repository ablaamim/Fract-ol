/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set_constructor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:22:46 by ablaamim          #+#    #+#             */
/*   Updated: 2022/05/11 15:56:09 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_julia(t_fractal *fractal)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fractal->fractal.depth = 0;
	zi = fractal->fractal.w / fractal->fractal.scale + fractal->fractal.z.im;
	zr = fractal->fractal.h / fractal->fractal.scale + \
		 fractal->fractal.z.re;
	cr = -0.8;
	ci = 0.156;
	if (fractal->fractal.c.im != 0)
	{
		cr = fractal->fractal.c.re;
		ci = fractal->fractal.c.im;
	}
	while ((zr * zr) + (zi * zi) < 4 && fractal->fractal.depth \
	 < fractal->fractal.iteration)
	{
		tmp_zr = zr;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = (2 * zi) * tmp_zr + ci;
		fractal->fractal.depth += 1;
	}
	return (fractal->fractal.depth);
}
