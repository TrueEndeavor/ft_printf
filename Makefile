# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 19:12:46 by lannur-s          #+#    #+#              #
#    Updated: 2023/08/01 16:00:08 by lannur-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTNAME = libft.a

LIBFTDIR = ./libft

CC = cc
CFLAGS = -Wall -Werror -Wextra -I $(LIBFTDIR)

AR = ar
ARFLAGS = rcs

HEADERS = ft_printf.h

SRCS =	ft_printf.c \
		print_char.c print_string.c \
		print_nbr_signed.c print_nbr_base.c 

OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS) $(LIBFTDIR)/$(LIBFTNAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFTDIR)/$(LIBFTNAME):
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTNAME) $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)
	cd $(LIBFTDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFTDIR) && make fclean
	
re: fclean 
	make

.PHONY: all clean fclean re
