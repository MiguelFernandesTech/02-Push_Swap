NAME = push_swap.a

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rc

LIBFT = ./libft/libft.a

SRCS = 	utils.c \
		utils2.c \
		push_swap.c \
		sort.c \
		values.c \
		./operations/push.c \
		./operations/reverse.c \
		./operations/rotate.c \
		./operations/swap.c \

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o push_swap

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME) push_swap

re: fclean all
