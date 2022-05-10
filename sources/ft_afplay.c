/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_afplay.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:55:52 by ablaamim          #+#    #+#             */
/*   Updated: 2022/05/10 15:56:40 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_afplay(void)
{
	char *afplay[3];
	int pid;

	afplay[0] = "/usr/bin/afplay";
	afplay[1] = "/Users/ablaamim/Desktop/FRACTALS/sources/.sound/fourpointfour-110019.mp3";
	afplay[2] = 0;
	pid = fork();
	if (pid == 0)
		execve(afplay[0], afplay, 0);
}
