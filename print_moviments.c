/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moviments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:02:23 by gda-conc          #+#    #+#             */
/*   Updated: 2025/02/12 18:02:25 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
