NAME=get_next_line.a
SRC=get_next_line.c \
	get_next_line_utils.c
OBJS=$(SRC:.c=.o)
CC=cc
CC_FLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $(OBJS)

.c.o:
	$(CC) $(CC_FLAGS) -c $< -o $@ -D BUFFER_SIZE=42000

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

run:
	clear
	$(CC) $(CC_FLAGS) main.c $(SRC) -D BUFFER_SIZE=42000
	./a.out

norm:
	clear
	norminette -R CheckForbiddenSourceHeader $(SRC) $(SRC_BONUS)
