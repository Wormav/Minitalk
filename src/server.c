/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:33:27 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/17 13:54:59 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../ft_printf/include/ft_printf.h"

void	binary_to_ascii(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n", 2);
		return (1);
	}
	pid = getpid();
	ft_printf("Server PID: [%d]\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, binary_to_ascii);
		signal(SIGUSR2, binary_to_ascii);
		pause();
	}
}
