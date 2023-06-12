#include "libft.h"

void	ft_putnbr_base_fd(unsigned int n, int fd, int base, int uppercase)
{
	unsigned long	nbr;
	int				digit;

	nbr = n;
    if (nbr < 0)
    {
        ft_putchar_fd('-', fd);
        nbr = -nbr;
    }	
	if (nbr >= base)
		ft_putunsignednbr_fd(nbr / 10, fd, base, uppercase);
	ft_putchar_fd(nbr % 10 + '0', fd);

    digit = nbr % base;
    if (digit > 10)
	{
		if (uppercase == 1)
			ft_putchar_fd(digit - 10 + 'A'), fd);
		else if (uppercase == 0)
			ft_putchar_fd(digit - 10 + 'a'), fd);
	}
	else
		ft_putchar_fd(digit + '0', fd);
}
