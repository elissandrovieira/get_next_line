NAME=libft.a
SRC=
OBJS=$(SRC:.c=.o)
CC=cc
CC_FLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $(OBJS)

.c.o:
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

run:
	clear
	$(CC) $(CC_FLAGS) main.c -L. -l:libft.a -lbsd
	./a.out

norm:
	clear
	norminette -R CheckForbiddenSourceHeader $(SRC) $(SRC_BONUS)
