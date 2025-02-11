#include "push_swap.h"

void	execute_push(t_stack *from, t_stack *to, char *op)
{
	push_switch_stack(from, to);
	ft_printf("%s\n", op);
}
void	execute_rotate(t_stack *stack, char *op)
{
	rotate_stack(stack);
	ft_printf("%s\n", op);
}

void	execute_reverse_rotate(t_stack *stack, char *op)
{
	reverse_rotate_stack(stack);
	ft_printf("%s\n", op);
}

void	execute_swap(t_stack *stack, char *op)
{
	swap_stack(stack);
	ft_printf("%s\n", op);
}
