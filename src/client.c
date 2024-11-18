/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:18:06 by jlorette          #+#    #+#             */
/*   Updated: 2024/11/18 17:25:14 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "../ft_printf/include/ft_printf.h"
#include "../libft/libft.h"

void    binary_to_ascii(int pid, char c)
{
    int    bit;

    bit = 7;
    while (bit >= 0)
    {
        if ((c >> bit) & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        bit--;
        usleep(300);
    }
}

int    main(int argc, char *argv[])
{
    int        pid;
    int        i;
    char    *str;

    i = 0;
    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        str = argv[2];
        if (pid <= 0)
            return (0);

        while (str[i] != '\0')
        {
            binary_to_ascii(pid, str[i++]);
        }
        binary_to_ascii(pid, str[i]);
    }
    else
        ft_printf("Message format not valide\n");
    return (0);
}
