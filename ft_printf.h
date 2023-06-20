/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:04:15 by lannur-s          #+#    #+#             */
/*   Updated: 2023/06/20 13:42:00 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h> 
# include <stdio.h>
# include <limits.h>
# include "./libft/libft.h"

# define STD_OUT 1
# define BASE_HEX 16
# define UPPER 1
# define LOWER 0
# define NULL_STRING "(null)"
# define NIL_STRING "(nil)"

int		ft_printf(const char *format, ...);
int		print_char(char c);
int		print_string(char *s);
int		print_nbr(int n);
int		print_unsigned_nbr(unsigned int un);
int		print_hexa(unsigned int n, int base, int uppercase);
int		print_pointer(unsigned long nbr, int base, int uppercase);

#endif
