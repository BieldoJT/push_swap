/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:02:19 by gda-conc          #+#    #+#             */
/*   Updated: 2025/02/12 18:02:20 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(int i)
{
	if (i == 1)
	{
		ft_putstr_fd("Error\n",2);
	}
	exit(EXIT_FAILURE);
}

void	print_error_malloc(t_stack *a)
{
	free_stack(a);
	print_error(1);
}

void	finish_sort(t_stack *a, t_stack *b)
{
	free(a->lst_int);
	free(b->lst_int);
	free_stack(a);
	free_stack(b);
	exit(0);
}
