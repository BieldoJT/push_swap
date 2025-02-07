#include "push_swap.h"

void print_error(int i)
{
	if(i == 1)
		ft_putstr_fd("Error\n",2);
	exit(EXIT_FAILURE);
}

void finish_sort(t_stack *a, t_stack *b)
{
	free(a->lst_int);
	free_stack(a);
	free_stack(b);
	exit(0);
}
