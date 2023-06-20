# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 19:12:46 by lannur-s          #+#    #+#              #
#    Updated: 2023/06/20 11:48:23 by lannur-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTNAME = libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = rcs

LIBFDIR = ./libft

SRC = ft_printf.c print_char.c print_string.c print_nbr.c \
		print_unsigned_nbr.c print_hexa.c print_pointer.c

OBJ = $(SRC:%.c=%.o)

%.o: %.c
	@echo Compiling $<
	$(CC) $(CFLAGS) -c $< -o $@
	

$(NAME): $(OBJ) makelibft
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	
makelibft:
	make -C $(LIBFDIR)
	cp $(LIBFDIR)/$(LIBFTNAME) $(LIBFTNAME)
	mv $(LIBFTNAME) $(NAME)
	
all: $(NAME)

clean:
	rm -f $(OBJ)
	cd $(LIBFDIR) && make clean

fclean:
	rm -f $(NAME)
	cd $(LIBFDIR) && make fclean
	
re: fclean all

.PHONY: all clean fclean makelibft 