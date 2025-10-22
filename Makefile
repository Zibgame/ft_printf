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

NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I.
AR          = ar rcs
RM          = rm -f

SRC_DIR     = ./src
LIBFT_DIR   = ./libft
LIBFT_A     = $(LIBFT_DIR)/libft.a

SRC         = $(wildcard $(SRC_DIR)/*.c)
OBJ         = $(SRC:.c=.o)

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	@echo "📦 Building libft..."
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT_A) $(NAME)
	@$(AR) $(NAME) $(OBJ)
	@echo "✅ libftprintf.a created successfully (includes libft)."

%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling: $<"

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "🧹 Object files cleaned."

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) test_printf
	@echo "🗑️  All cleaned, including libftprintf.a and test binary."

re: fclean all

# **************************************************************************** #
#                                   TESTS                                      #
# **************************************************************************** #

TEST_SRC = $(wildcard $(SRC_DIR)/main*.c)
TEST_BIN = test_printf

test: all
	@if [ -z "$(TEST_SRC)" ]; then \
		echo "⚠️  Aucun fichier main*.c trouvé dans $(SRC_DIR)."; \
	else \
		echo "🧪 Compilation du binaire de test..."; \
		$(CC) $(TEST_SRC) $(NAME) -I. -o $(TEST_BIN); \
		echo "✅ Test binary created: ./$(TEST_BIN)"; \
	fi

