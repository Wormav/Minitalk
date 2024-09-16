/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:43:34 by jlorette          #+#    #+#             */
/*   Updated: 2024/09/16 13:57:02 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf/include/ft_printf.h"

int	main(void)
{
	ft_printf("Hello from ft_printf!\n");
	const char *test_str = "Test string for libft";
	size_t len = ft_strlen(test_str);
	ft_printf("The length of the test string is: %zu\n", len);
	return (0);
}