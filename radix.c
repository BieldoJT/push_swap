#include "push_swap.h"

static int calculate_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	return max_bits;
}

static void	process_stack(t_stack *stack_a, t_stack *stack_b, int i, int *index_map)
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

	if (stack_a->size == 2)
		execute_rotate(stack_a, "sa");
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
	else
	{
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
}
