/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahetru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:28:42 by ahetru            #+#    #+#             */
/*   Updated: 2024/10/12 16:29:11 by ahetru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (ft_print_char(*s) == -1)
		{
			return (-1);
		}
		else
		{
			len++;
		}
		s++;
	}
	return (len);
}

int	ft_print_str(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		if (ft_putstr("(null)") == -1)
			return (-1);
		return (6);
	}
	len = ft_putstr(s);
	return (len);
}
