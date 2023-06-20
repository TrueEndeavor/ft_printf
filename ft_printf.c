/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:03:58 by lannur-s          #+#    #+#             */
/*   Updated: 2023/06/20 13:45:50 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_p(unsigned long adr)
{
	if (adr)
	{
		print_string("0x");
		return (print_pointer(adr, BASE_HEX, LOWER) + 2);
	}
	return (print_string(NIL_STRING));
}

static int	do_print(const char c, va_list args)
{
	if (c == 'c')
		return (print_char(va_arg(args, int)));
	else if (c == 's')
		return (print_string(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (print_nbr(va_arg(args, int)));
	else if (c == 'u')
		return (print_unsigned_nbr(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (print_hexa(va_arg(args, unsigned int), BASE_HEX, LOWER));
	else if (c == 'X')
		return (print_hexa(va_arg(args, unsigned int), BASE_HEX, UPPER));
	else if (c == 'p')
		return (print_p(va_arg(args, unsigned long)));
	else if (c == '%')
		return (ft_putchar_fd('%', STD_OUT), 1);
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;

	length = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%' && ft_strchr("csdiuxXp%", *(format + 1)) != 0)
		{
			format++;
			length += do_print(*format, args);
		}
		else
		{
			ft_putchar_fd(*format, STD_OUT);
			length++;
		}
		format++;
	}
	va_end(args);
	return (length);
}
