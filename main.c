/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:02:07 by gda-conc          #+#    #+#             */
/*   Updated: 2025/02/12 18:02:16 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		exit(1);
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
	finish_sort(stack_a, stack_b);
	return (0);
}
