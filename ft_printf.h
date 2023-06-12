#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "./libft/libft.h"

# define STD_OUT 1
# define BASE_HEX 16
# define UPPER 1
# define LOWER 0

int ft_printf(const char *format, ...);

#endif