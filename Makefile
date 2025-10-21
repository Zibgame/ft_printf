# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcadinot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 11:29:35 by zcadinot          #+#    #+#              #
#    Updated: 2025/10/20 14:20:00 by zcadinot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I.
AR          = ar rcs
RM          = rm -f

# Dossiers
LIBFT_DIR   = ./libft
SRC_DIR     = ./src
TEST_DIR    = ./src     # tu peux mettre ./test si tu préfères

# Fichiers
SRC         = $(wildcard $(SRC_DIR)/*.c)
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
	@$(RM) test_printf
	@echo "🗑️  All cleaned, including libftprintf.a and test binary."

re: fclean all

# **************************************************************************** #
#                                   TESTS                                      #
# **************************************************************************** #

# Cherche les fichiers main*.c dans src (ou ./test si tu en fais un dossier plus tard)
TEST_SRC = $(wildcard $(SRC_DIR)/main*.c)
TEST_BIN = test_printf

test: all
	@if [ -z "$(TEST_SRC)" ]; then \
		echo "⚠️  Aucun fichier main*.c trouvé dans $(SRC_DIR)."; \
	else \
		echo "🧪 Compilation des fichiers de test..."; \
		$(CC) $(TEST_SRC) $(NAME) -I. -o $(TEST_BIN); \
		echo "✅ Test binaire créé : ./$(TEST_BIN)"; \
	fi
