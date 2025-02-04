#include "push_swap.h"

void print_error(int i) //definir qual o tipo de erro
{
	if(i == 1)
		ft_putstr_fd("Error\n",2);
	exit(EXIT_FAILURE);
}
