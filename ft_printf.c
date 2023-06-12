#include "ft_printf.h"

static int ft_num_digits_base(unsigned long number, int base)
{
    int num_digits = 1;

    while ((int) number >= base)
    {
        number /= base;
        num_digits++;
    }

    return num_digits;
}

static void add_leading_zeros(unsigned long address)
{
    int leading_zeros;

    leading_zeros = sizeof(address) * 2 - ft_num_digits_base(address, BASE_HEX);
    while (leading_zeros > 0)
    {
        ft_putchar_fd('0', STD_OUT);
        leading_zeros--;
    }
}
static int do_print(const char *format, void *arg)
{
    char            c;
    unsigned long   address;

    while ((c = *format) != '\0') 
    {
	    if (c == '%') 
		    ft_putchar_fd(c, STD_OUT);
        else if (c == 'c')
            ft_putchar_fd((int)arg, STD_OUT);
        else if (c == 's')
            ft_putstr_fd((char *)arg, STD_OUT);
        else if (c == 'd')
            ft_putnbr_fd((int)arg, STD_OUT);
        else if (c == 'u')
            ft_putunsignednbr_fd((unsigned int)arg, STD_OUT);
        else if (c == 'x')
            ft_putnbr_base_fd((unsigned int)arg, STD_OUT, BASE_HEX, LOWER);
        else if (c == 'X')
            ft_putnbr_base_fd((unsigned int)arg, STD_OUT, BASE_HEX, UPPER);                               
        else if (c == 'p')
        {
            address = (unsigned long)arg;
            add_leading_zeros(address);
            ft_putnbr_base_fd((unsigned long)arg, STD_OUT, BASE_HEX, UPPER);
        }
        format++;
    }
    return (1);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    
    va_start(args, format);
    while (*format != '\0')
    {
        if (*format == '%')
		{
            format++;
            if (ft_strchr("cspdiuxX",*format ))
                do_print(format, va_arg(args, void *));
            else if(*format == '%')
                ft_putchar_fd('%', STD_OUT);
        }
        else
            ft_putchar_fd(*format, STD_OUT);
        format++;
    }
    
    va_end(args);
    return (1);
}

int main(void)
{
    //printf("%d", 1+3);
    char *p;
    p = "rrrrrrrrrrrr";
    printf("%d\n",sizeof(p)*2);
    printf(">>%p\n", p);    
     ft_printf(">>%p\n", p);

    return 0;
}
