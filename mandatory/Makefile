SRCS = ft_atoi.c checker.c main.c set_table_list.c thread_work.c routine_funcs.c
NAME = philo
OBJS = $(SRCS:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c philo.h
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr $(NAME)

re: fclean all