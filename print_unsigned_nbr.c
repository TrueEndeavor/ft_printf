/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:27:22 by lannur-s          #+#    #+#             */
/*   Updated: 2023/06/15 14:28:38 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned_nbr(unsigned int un)
{
	long	nbr;
	int		len;

	nbr = un;
	len = 0;
	if (nbr >= 10)
		len += print_nbr(nbr / 10);
	ft_putchar_fd(nbr % 10 + '0', STD_OUT);
	len++;
	return (len);
}

