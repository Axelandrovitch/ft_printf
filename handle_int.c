/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahetru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:29:29 by ahetru            #+#    #+#             */
/*   Updated: 2024/10/12 16:29:30 by ahetru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n, int len)
{
	int	min_int;

	min_int = -2147483648;
	if (n == min_int)
	{
		return (ft_print_str("-2147483648"));
	}
	if (n < 0)
	{
		if (ft_print_char('-') == -1)
			return (-1);
		len++;
		return (ft_print_nbr(-n, len));
	}
	if (n > 9)
	{
		len = ft_print_nbr(n / 10, len);
	}
	if (ft_print_char((n % 10) + '0') == -1)
		return (-1);
	return (len + 1);
}
