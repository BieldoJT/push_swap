#include "push_swap.h"

void print_Stack(t_stack *stack)
{
	t_node *aux;

	aux = stack->top;
	while (aux)
	{
		ft_printf("\n%d\n", aux->content);
		aux = aux->next;
	}

}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	if (argc < 2)
		return (0);
	stack_a = parse_input(argc, argv);
	if (!stack_a)
		return (1);
	stack_b = init_stack();
	if (!stack_b)
	{
		free_stack(stack_a);
		return (1);
	}
	if (verify_order(stack_a))
		finish_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	print_Stack(stack_a);
	finish_sort(stack_a, stack_b);
	return (0);
}
