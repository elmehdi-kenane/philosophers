SRCS = ft_atoi.c checker.c main.c time.c died_or_finish.c init.c
NAME = philo_bonus
OBJS = $(SRCS:.c=.o)
CC = cc
# O_FLAGS = -g -fsanitize=thread
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c philo_bonus.h
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr $(NAME)

re: fclean all