NAME_SERVER = server
NAME_CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
INCLUDE_DIR = include
FT_PRINTF_DIR = ft_printf
LIBFT_DIR = libft

SRC_SERVER = $(SRC_DIR)/server.c $(wildcard $(FT_PRINTF_DIR)/*.c) $(wildcard $(LIBFT_DIR)/*.c)
SRC_CLIENT = $(SRC_DIR)/client.c $(wildcard $(FT_PRINTF_DIR)/*.c) $(wildcard $(LIBFT_DIR)/*.c)

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

HEADER = $(wildcard $(INCLUDE_DIR)/*.h) $(wildcard $(FT_PRINTF_DIR)/*.h) $(wildcard $(LIBFT_DIR)/*.h)

all: $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(OBJ_SERVER) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(OBJ_CLIENT) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME_CLIENT)

$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF_DIR)/libftprintf.a:
	@$(MAKE) -C $(FT_PRINTF_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -c $< -o $@

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re