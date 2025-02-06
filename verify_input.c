#include "push_swap.h"

static int is_valid_number(char *str)
{
	int	i;
	long num;

	i = 0;
	if (str[i] == '-' || str[i] == '+') // Permite sinais + e -
		i++;
	if (!str[i]) // Verifica se há números depois do sinal
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i])) // Se não for número, erro
			return (0);
		i++;
	}
	num = ft_atoil(str);
	if (num > 2147483647)
		return (0);

	return (1);
}

static int is_duplicate(t_stack *stack, int num)
{
	t_node *node;

	node = stack->top;
	while (node)
	{
		if (node->content == num)
			return (1);
		node = node->next;
	}
	return (0);
}

static void sort_list(int *lst, int size)
{
	int	modified;
	int	i;
	int	temp;

	modified = 1;
	while (modified)
	{
		i = 0;
		modified = 0;
		while(i < size -1)
		{
			if (lst[i] > lst[i + 1])
			{
				temp = lst[i];
				lst[i] = lst[i + 1];
				lst[i + 1] = temp;
				modified = 1;
			}
			i++;
		}
	}
}

static int	*sort_input(t_stack *stack)
{
	t_node	*aux;
	int		*lst;
	int		i;

	aux = stack->top;
	lst = (int*)malloc(stack->size * sizeof(int));
	i = 0;
	while(i < stack->size)
	{
		lst[i++] = aux->content;
		aux = aux->next;
	}
	sort_list(lst, stack->size);
	return (lst);
}

t_stack *parse_input(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	int		num;

	stack = init_stack();
	if (!stack)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[--argc]))
			print_error(1);
		num = ft_atoi(argv[argc]);
		if (is_duplicate(stack, num))
			print_error(1);
		push_stack(stack, num);
	}
	stack->lst_int = sort_input(stack);
	return (stack);
}

