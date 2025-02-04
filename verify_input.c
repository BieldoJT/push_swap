#include "push_swap.h"

int is_valid_number(char *str)
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

int is_duplicate(t_stack *stack, int num)
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
		push(stack, num);
	}
	return (stack);
}

