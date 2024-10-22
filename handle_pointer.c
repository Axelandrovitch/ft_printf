/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahetru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:43:46 by ahetru            #+#    #+#             */
/*   Updated: 2024/10/11 15:43:50 by ahetru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_hex(unsigned long int n, char *hexbase, int len)
{
	if (n > 15)
	{
		len = ft_print_unsigned_hex(n / 16, hexbase, len);
	}
	if (ft_print_char(hexbase[n % 16]) == -1)
		return (-1);
	return (len + 1);
}

int	handle_unsigned_hexadecimal(unsigned long int n, int uppercased)
{
	char	*hexbase;
	int		len;

	len = 0;
	if (uppercased)
	{
		hexbase = HEXBASE_UPPER;
	}
	else
	{
		hexbase = HEXBASE_LOWER;
	}
	len = ft_print_unsigned_hex(n, hexbase, 0);
	return (len);
}

int	handle_pointer(va_list ap)
{
	unsigned long int		address;
	int						len;

	address = (unsigned long int)(va_arg(ap, void *));
	if (address == 0)
	{
		if (ft_print_str("(nil)") == -1)
			return (-1);
		return (5);
	}
	len = ft_print_str("0x");
	if (len == -1)
		return (-1);
	len += handle_unsigned_hexadecimal(address, 0);
	return (len);
}
