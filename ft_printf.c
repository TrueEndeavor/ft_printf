#include "ft_printf.h"

static void do_print(const char *format, va_list args, int radix)
{
    while ((c = *format) != '\0') 
    {
	    if (c != '%') 
        {
		    ft_putchar_fd(c);
		    format++;
	    }
    while (*format != '\0')
    {
        if (*(format+1) == 'c')
            ft_putchar_fd(va_arg(xformat, int), 1);
        else if (*format == 's')
            ft_putstr_fd(va_arg(xformat, char *), 1);
        else if (*format == 'd')
            ft_putnbr_fd(va_arg(xformat, int), 1);
        else if (*format == 'p')
        {
            int n = ft_atoi(va_arg(xformat, void *));
            ft_putnbr_base_fd(n, 1, 16);
        }
        // else if (*format == 'u')
        //     char u = va_arg(xformat, unsigned int);
        // else if (*format == 'd')
        //     int x = va_arg(xformat, int);
        // else if (*format == 'x')
        //     int x = va_arg(xformat, int);
        // else if (*format == 'X')
        //     int X = va_arg(xformat, int);
        else if (*format == '%')
            printf("%%");
        format++;
    }
}
int ft_printf(const char *format, ...)
{
    va_list xformat;
    
    va_start(xformat, format);
    do_print(format, &xformat);
    va_end(xformat);
    return (1);
}

int main()
{
    //printf("%d", 1+3);
    char *p;
    p = "rr";
    ft_printf(">>>%p\n", p);
    printf("<<<%p\n", p);
    
}
