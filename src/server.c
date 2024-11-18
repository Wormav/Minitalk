/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:33:27 by jlorette          #+#    #+#             */
/*   Updated: 2024/11/18 17:27:51 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "../ft_printf/include/ft_printf.h"

char    *ft_strjoin_char(char const *s1, char c)
{
    int        len_total;
    int        i;
    char    *result;

    if (!s1 || !c)
        return (NULL);
    i = 0;
    len_total = ft_strlen(s1) + 1;
    result = malloc(sizeof(char) * (len_total + 1));
    if (result == NULL)
        return (NULL);
    while (s1[i])
    {
        result[i] = s1[i];
        i++;
    }
    result[i++] = c;
    result[i] = '\0';
    free((char *)s1);
    return (result);
}

void    handle_completion(char **buffer, unsigned char *current_byte,
        int *count_bits)
{
    if (*count_bits > 7)
    {
        if (*current_byte == 0)
        {
            ft_printf("%s", *buffer);
            free(*buffer);
            *buffer = NULL;
        }
        else
            *buffer = ft_strjoin_char(*buffer, *current_byte);
        *count_bits = 0;
        *current_byte = 0;
    }
}

void    sig_reception(int sig)
{
    static char                *buffer;
    static int                count_bits;
    static unsigned char    current_byte;

    if (!buffer)
    {
        buffer = malloc(1);
        if (!buffer)
            return ;
        buffer[0] = 0;
    }
    if (sig == SIGUSR1)
    {
        current_byte = (current_byte << 1) | 0;
        count_bits++;
    }
    else if (sig == SIGUSR2)
    {
        current_byte = (current_byte << 1) | 1;
        count_bits++;
    }
    handle_completion(&buffer, &current_byte, &count_bits);
}

int    main(void)
{
    ft_printf("PID [%d]\n", getpid());
    signal(SIGUSR1, sig_reception);
    signal(SIGUSR2, sig_reception);
    while (1)
        pause();
    return (0);
}
