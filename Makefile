NAME = minitalk

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
INCLUDE_DIR = include
FT_PRINTF_DIR = ft_printf
LIBFT_DIR = libft

SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(FT_PRINTF_DIR)/*.c) $(wildcard $(LIBFT_DIR)/*.c)
OBJ = $(SRC:.c=.o)

HEADER = $(wildcard $(INCLUDE_DIR)/*.h) $(wildcard $(FT_PRINTF_DIR)/*.h) $(wildcard $(LIBFT_DIR)/*.h)

all: $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME)

$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF_DIR)/libftprintf.a:
	@$(MAKE) -C $(FT_PRINTF_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re