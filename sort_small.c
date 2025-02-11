#include "push_swap.h"

static int	find_min_index(t_stack *a)
{
	t_node	*temp;
	int		min;
	int		min_index;
	int		i;

	temp = a->top;
	min = temp->content;
	min_index = 0;
	i = 0;
	while (temp)
	{
		if (temp->content < min)
		{
			min = temp->content;
			min_index = i;
		}
		temp = temp->next;
		i++;
	}
	return (min_index);
}


void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->content;
	second = a->top->next->content;
	third = a->top->next->next->content;
	if (first > second && second < third && first < third)
		execute_swap(a,"sa"); // sa
	else if (first > second && second > third)
	{
		execute_swap(a, "sa");; // sa
		execute_reverse_rotate(a, "rra"); // rra
	}
	else if (first > second && second < third)
		execute_rotate(a, "ra"); // ra
	else if (first < second && second > third && first < third)
	{
		execute_swap(a,"sa");; // sa
		execute_rotate(a, "ra"); // ra
	}
	else if (first < second && second > third)
		execute_reverse_rotate(a, "rra"); // rra
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = find_min_index(a);
	if (min_index == 1)
		swap_stack(a); // sa
	else if (min_index == 2)
	{
		execute_rotate(a, "ra"); // ra
		execute_rotate(a, "ra"); // ra
	}
	else if (min_index == 3)
		execute_reverse_rotate(a, "rra"); // rra
	execute_push(a, b, "pb"); // pb
	sort_three(a);
	execute_push(b, a, "pa"); // pa
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = find_min_index(a);
	if (min_index == 1)
		execute_swap(a, "sa"); // sa
	else if (min_index == 2)
	{
		execute_rotate(a, "ra"); // ra
		execute_rotate(a, "ra"); // ra
	}
	else if (min_index == 3)
	{
		execute_reverse_rotate(a, "rra"); // rra
		execute_reverse_rotate(a, "rra"); // rra
	}
	else if (min_index == 4)
		execute_reverse_rotate(a, "rra"); // rra
	execute_push(a, b, "pb"); // pb
	sort_four(a, b);
	execute_push(b, a, "pa"); // pa
}



