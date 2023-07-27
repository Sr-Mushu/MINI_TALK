/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:36:10 by dagabrie          #+#    #+#             */
/*   Updated: 2023/01/18 17:47:52 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	inverter_ascii(int byte)
{
	int	ret;

	ret = 255 - byte;
	if (ret < 0)
		ret *= -1;
	return (ret);
}

void	verif(int num)
{
	static int	power;
	static int	byte;

	if (num == SIGUSR1)
		byte += 1 << (7 - power);
	power++;
	if (power == 8)
	{
		byte = inverter_ascii(byte);
		ft_printf ("%c", byte);
		if (byte == '\0')
			ft_printf("\n");
		power = 0;
		byte = 0;
	}
}

int	main(void)
{
	printf("\nServer PID: %d\n", getpid());
	signal(SIGUSR1, verif);
	signal(SIGUSR2, verif);
	while (1)
	{
	}
}
