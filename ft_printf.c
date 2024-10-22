/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahetru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:17:33 by ahetru            #+#    #+#             */
/*   Updated: 2024/10/10 17:17:34 by ahetru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_conversion(const char *fstr, va_list ap)
{
	int	len;

	len = 0;
	if (!fstr)
		return (-1);
	else if (*fstr == 'd' || *fstr == 'i')
		len = ft_print_nbr(va_arg(ap, int), 0);
	else if (*fstr == 'c')
		len = ft_print_char(va_arg(ap, int));
	else if (*fstr == 's')
		len = ft_print_str(va_arg(ap, char *));
	else if (*fstr == '%')
		len = ft_print_char('%');
	else if (*fstr == 'u')
		len = ft_print_unsigned(va_arg(ap, unsigned int), 0);
	else if (*fstr == 'x')
		len = handle_hexadecimal(va_arg(ap, unsigned int), 0);
	else if (*fstr == 'X')
		len = handle_hexadecimal(va_arg(ap, unsigned int), 1);
	else if (*fstr == 'p')
		len = handle_pointer(ap);
	else
		return (-1);
	return (len);
}

static int	parse_fstr(const char *fstr, va_list ap)
{
	int	i;
	int	len;
	int	curr_arg;

	i = 0;
	len = 0;
	curr_arg = 0;
	while (fstr[i])
	{
		if (fstr[i] == '%')
		{
			i++;
			curr_arg = handle_conversion(fstr + i, ap);
			if (curr_arg == -1)
				return (-1);
			len += curr_arg;
		}
		else
			len += ft_print_char(fstr[i]);
		i++;
	}
	return (len);
}

int	ft_printf(const char *fstr, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	va_start(ap, fstr);
	if (!fstr)
		return (-1);
	len = parse_fstr(fstr, ap);
	if (len == -1)
	{
		va_end(ap);
		return (-1);
	}
	va_end(ap);
	return (len);
}
