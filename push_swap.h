#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdio.h>
# include <stdlib.h>
# include "libraries/Libft/libft.h"

typedef struct s_node
{
	int				content;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*top;  // Ponteiro para o topo da pilha
	int				size;  // Tamanho da pilha
}	t_stack;

//verify_input.c
t_stack *parse_input(int argc, char **argv);
int is_duplicate(t_stack *stack, int num);
int is_valid_number(char *str);

//error_handling.c
void print_error(int i);

//stack_manipulation.c
t_stack *init_stack(void);
void push_stack(t_stack *stack, int value);
void swap_stack(t_stack *stack);
void free_stack(t_stack *stack);
int pop_stack(t_stack *stack);

//utils.c
long ft_atoil(const char *str);

//stack_operators.c
void push_switch_stack(t_stack *to_lose, t_stack *to_recieve);
void rotate_stack(t_stack *stack);
void reverse_rotate_stack(t_stack *stack);




#endif
