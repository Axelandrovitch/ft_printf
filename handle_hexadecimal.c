/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahetru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:29:44 by ahetru            #+#    #+#             */
/*   Updated: 2024/10/11 14:30:26 by ahetru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char *hexbase, int len)
{
	if (n > 15)
	{
		len = ft_puthex(n / 16, hexbase, len);
	}
//	ft_putchar_fd(hexbase[n % 16], 1);
	if (ft_print_char(hexbase[n % 16]) == -1)
		return (-1);
	return (len + 1);
}

int	handle_hexadecimal(unsigned int n, int uppercased)
{
	int		len;
	char	*hexbase;

	if (uppercased)
		hexbase = HEXBASE_UPPER;
	else
		hexbase = HEXBASE_LOWER;
	len = 0;
	len = ft_puthex(n, hexbase, len);
	return (len);
}
