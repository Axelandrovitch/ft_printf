/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahetru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:32:55 by ahetru            #+#    #+#             */
/*   Updated: 2024/10/12 16:33:37 by ahetru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n, int len)
{
	if (n > 9)
	{
		len = ft_print_unsigned(n / 10, len);
	}
	if (ft_print_char((n % 10) + '0') == -1)
	{
		return (-1);
	}
	return (len + 1);
}
