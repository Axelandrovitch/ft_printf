/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahetru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:11:50 by ahetru            #+#    #+#             */
/*   Updated: 2024/10/15 10:16:41 by ahetru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEXBASE_UPPER "0123456789ABCDEFG"
# define HEXBASE_LOWER "0123456789abcdefg"

# include <stdarg.h>
# include <unistd.h>

int		ft_print_nbr(int n, int len);

int		ft_print_unsigned(unsigned int n, int len);

int		ft_print_char(char c);

int		ft_print_str(char *s);

int		ft_printf(const char *fstr, ...);

int		handle_hexadecimal(unsigned int n, int uppercased);

int		handle_pointer(va_list ap);

#endif
