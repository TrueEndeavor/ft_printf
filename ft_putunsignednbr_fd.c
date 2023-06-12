#include "libft.h"

void	ft_putunsignednbr_fd(unsigned int n, int fd)
{
	unsigned long	nbr;

	nbr = n;
	if (nbr >= 10)
		ft_putunsignednbr_fd(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
}
