# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 19:12:46 by lannur-s          #+#    #+#              #
#    Updated: 2023/06/21 17:10:06 by lannur-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTNAME = libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = rcs

LIBFDIR = ./libft

SRCS =	ft_printf.c \
		print_char.c print_string.c \
		print_nbr_signed.c print_nbr_base.c 

OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS) $(LIBFDIR)/$(LIBFTNAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFDIR)/$(LIBFTNAME):
	make -C $(LIBFDIR)
	cp $(LIBFDIR)/$(LIBFTNAME) $(LIBFTNAME)
	mv $(LIBFTNAME) $(NAME)	

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)
	cd $(LIBFDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFDIR) && make fclean
	
re: fclean all

.PHONY: all clean fclean
