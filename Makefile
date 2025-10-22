# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 11:29:35 by zcadinot          #+#    #+#              #
#    Updated: 2025/10/22 22:20:00 by zcadinot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I.
AR			= ar rcs
RM			= rm -f

LIBFT_DIR	= libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

SRC			= src/ft_printf.c \
			  src/parser.c \
			  src/str.c \
			  src/utils.c

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@if [ -f "$(LIBFT_A)" ]; then \
		echo "libft already built."; \
	else \
		if [ -f "$(LIBFT_DIR)/Makefile" ]; then \
			make -C $(LIBFT_DIR); \
		else \
			echo "Warning: no libft Makefile found."; \
		fi; \
	fi
	@cp $(LIBFT_A) $(NAME) 2>/dev/null || true
	@$(AR) $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@if [ -f "$(LIBFT_DIR)/Makefile" ]; then \
		make -C $(LIBFT_DIR) clean; \
	fi

fclean: clean
	@$(RM) $(NAME)
	@if [ -f "$(LIBFT_DIR)/Makefile" ]; then \
		make -C $(LIBFT_DIR) fclean; \
	fi

re: fclean all

.PHONY: all clean fclean re
