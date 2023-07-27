/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:36:02 by dagabrie          #+#    #+#             */
/*   Updated: 2023/01/18 17:46:01 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"

//==========================|Enviar|==============================
void	send_sms(char octet, int pid)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (octet >> i & 1);
		if (bit == 0)
		{
			ft_printf("0");
			kill(pid, SIGUSR1);
		}
		else if (bit == 1)
		{
			ft_printf("1");
			kill(pid, SIGUSR2);
		}
		i--;
		usleep(100);
	}
}
//==================================================================
//==========================|Processo|============================

void	processo(int pids, int pidc, char *SMS)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	pidc++;
	while (SMS[i])
	{
		j++;
		send_sms(SMS[i], pids);
		if (0 == j % 5)
			ft_printf("\n");
		ft_printf(" ");
		i++;
	}
	send_sms(SMS[i], pids);
}
//================================================================
//==========================|Main verifica|=======================

int	main(int ac, char **av)
{
	int	pidc;

	pidc = getpid();
	ft_printf("\nClient Pid: %d \n", pidc);
	ft_printf("\n==========|Binario da mensagem|==============\n");
	ft_printf(" ");
	if (ac == 3)
		processo (ft_atoi (av[1]), pidc, av[2]);
	else
		ft_printf("Erro! falta argumentos\n : [PID Server][Mensegem]\n");
	ft_printf("\n=============================================\n\n");
	return (0);
}
//==================================================================