
NAME = libftprintf.a
LIBFTNAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = rcs

LIBFTDIR = .\libft

SRCS = ft_printf.c 
OBJS = $(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


$(NAME): makelibft $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

makelibft:
	make -C $(LIBFTDIR)
	copy $(LIBFTDIR)\$(LIBFTNAME) $(LIBFTNAME)
	move $(LIBFTNAME) $(NAME)




all: $(NAME)

clean: 
	del -f $(OBJS)
	cd $(LIBFTDIR) && make clean

fclean :
	del -f $(NAME)
	cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY: all clean fclean makelibft

