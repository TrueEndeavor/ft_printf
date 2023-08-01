# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 12:46:34 by lannur-s          #+#    #+#              #
#    Updated: 2023/06/22 11:46:49 by lannur-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Usage:
#   - Run 'make' to build the $(NAME) target (default)
#   - Run 'make clean' to remove object files
#   - Run 'make fclean' to remove object files and the $(NAME) archive
#   - Run 'make re' to perform a clean build by removing all generated files 
#     and rebuilding the project
#   - Run 'make so' to create a shared library using the object files
#   - Run 'make all' to build the $(NAME) target (same as the default 'make')
#
# Note: Adjust variables $(CC), $(CFLAGS), $(AR), $(ARFLAGS), $(SRCS), $(BONUS)
#       according to project requirements

# Name of the archive
NAME = libft.a

# Compiler options
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Archive options
AR = ar
ARFLAGS = rcs

# Mandatory source (.c) files
SRCS = ft_strlen.c ft_strchr.c \
	   ft_putchar_fd.c ft_putstr_fd.c \

# Variable assignment with pattern substitution:
# Generate a list of object files 
# by replacing the ".c" extension with ".o" for each source file
OBJS = $(SRCS:%.c=%.o)

# Target rule: $(NAME)
# Builds the final archive by linking object files 
# $(OBJS) and $(BONUSOBJS)
$(NAME): $(OBJS)
	@echo "Linking $@"
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "Done!"

# Pattern rule: %.o
# Generic rule to compile source files to object files.
# Uses the compiler $(CC) with flags $(CFLAGS) to compile 
# the source file ($<) and produce the object file ($@)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
# Target rule: all
# Builds the default target $(NAME) by invoking the target $(NAME)
all: $(NAME)

# Target rule: clean
# Removes object files $(OBJS) and $(BONUSOBJS) 
# from the current directory
clean:
	rm -f $(OBJS)

# Target rule: fclean
# Removes object files $(OBJS) and $(BONUSOBJS), 
# and the archive $(NAME) from the current directory
# Calls the target 'clean' to remove object files first	
fclean: clean
	rm -f $(NAME)

# Target rule: re
# Performs a clean build by removing all generated files 
# (object files and the archive) and rebuilding the project 
# from scratch by invoking the targets 'fclean' and 'all'
re: fclean all

# Target rule: .PHONY
# Specifies phony targets that do not represent actual files.
# 'all', 'clean', 'fclean', and 're' are marked as phony targets.
# This prevents conflicts if there are files with the same names.
.PHONY: all clean fclean re
