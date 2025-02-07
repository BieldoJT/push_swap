#include "push_swap.h"

static void	execute_push(t_stack *from, t_stack *to, char *op)
{
	push_switch_stack(from, to);
	ft_printf("%s\n", op);
}
static void	execute_rotate(t_stack *stack, char *op)
{
	rotate_stack(stack);
	ft_printf("%s\n", op);
}

static int calculate_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	return max_bits;
}

static void process_stack(t_stack *stack_a, t_stack *stack_b, int i, int *index_map)
{
	int	j;
	int	size;
	int	num;
	int	index;

	j = 0;
	size = stack_a->size;
	while (j < size)
	{
		num = stack_a->top->content;
		index = 0;
		while (index_map[index] != num)
			index++;
		if ((index >> i) & 1)
			execute_rotate(stack_a, "ra");
		else
			execute_push(stack_a, stack_b, "pb");
		j++;
	}
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	*index_map;
	int	i;

	max_bits = calculate_max_bits(stack_a->size);
	index_map = stack_a->lst_int;
	i = 0;
	while (i < max_bits)
	{
		process_stack(stack_a, stack_b, i, index_map);
		while (stack_b->size > 0)
			execute_push(stack_b, stack_a, "pa");
		i++;
	}
}
