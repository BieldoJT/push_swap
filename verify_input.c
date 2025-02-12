/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:02:57 by gda-conc          #+#    #+#             */
/*   Updated: 2025/02/12 18:03:19 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(char *str)
{
	int		i;
	long	num;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	num = ft_atoil(str);
	if (num > 2147483647)
		return (0);

	return (1);
}

static int	is_duplicate(t_stack *stack, int num)
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

static void	sort_list(int *lst, int size)
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

t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	int		num;
	char	**args;
	int		new_argc;

	stack = init_stack();
	if (!stack)
		return (NULL);
	args = split_arguments(argc, argv, &new_argc, stack);
	i = new_argc - 1;
	while (i != -1)
	{
		if (!is_valid_number(args[i]))
			print_error_malloc(stack);
		num = ft_atoi(args[i]);
		if (is_duplicate(stack, num))
			print_error_malloc(stack);
		push_stack(stack, num);
		i--;
	}
	if (argc == 2)
		free_args(args);
	stack->lst_int = sort_input(stack);
	return (stack);
}

