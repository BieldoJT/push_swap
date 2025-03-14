NAME = push_swap

LIBFT = libraries/Libft/libft.a

CC = cc

CC_FLAGS = -Wall -Werror -Wextra


VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

SCRS =  main.c \
		verify_input.c \
		error_handling.c \
		stack_manipulation.c \
		stack_operators.c \
		utils.c \
		radix.c \
		print_moviments.c \
		sort_small.c \


all: ${LIBFT} ${NAME}


${NAME}:
		${CC} ${SCRS} ${LIBFT} ${CC_FLAGS} -g -o ${NAME}
		@echo "\n${NAME} is compiled."
		@echo

${LIBFT}:
		make bonus -C libraries/Libft

clean:
		make clean -C libraries/Libft

fclean: clean
		make fclean -C libraries/Libft
		rm -rf ${NAME}

re: fclean all

test:
		${VALGRIND} ./${NAME}


.PHONY:	all clean fclean re rebonus test
