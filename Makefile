# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 11:29:35 by zcadinot          #+#    #+#              #
#    Updated: 2025/10/20 11:29:39 by zcadinot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f

# Dossiers
LIBFT_DIR   = ./libft
SRC_DIR     = ./src

# Fichiers
SRC         = $(SRC_DIR)/ft_printf.c \
              $(SRC_DIR)/utils.c

OBJ         = $(SRC:.c=.o)
LIBFT       = $(LIBFT_DIR)/libft.a

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJ)
	@echo "✅ libftprintf.a created successfully."

%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling: $<"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ)
	@echo "🧹 Object files cleaned."

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@echo "🗑️  All cleaned, including libftprintf.a."

re: fclean all

.PHONY: all clean fclean re
