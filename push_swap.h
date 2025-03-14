/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:02:26 by gda-conc          #+#    #+#             */
/*   Updated: 2025/02/12 18:08:09 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libraries/Libft/libft.h"

typedef struct s_node
{
	int				content;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
	int				*lst_int;
}	t_stack;

//verify_input.c
t_stack	*parse_input(int argc, char **argv);

//error_handling.c
void	print_error(int i);
void	print_error_malloc(t_stack *a);
void	finish_sort(t_stack *a, t_stack *b);

//stack_manipulation.c
t_stack	*init_stack(void);
void	push_stack(t_stack *stack, int value);
void	swap_stack(t_stack *stack);
void	free_stack(t_stack *stack);
int		pop_stack(t_stack *stack);

//utils.c
long	ft_atoil(const char *str);
char	**split_arguments(int argc, char **argv, int *new_argc, t_stack *a);
void	free_args(char **args);
int		verify_order(t_stack *stack);

//stack_operators.c
void	push_switch_stack(t_stack *to_lose, t_stack *to_recieve);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

//radix.c
void	radix_sort(t_stack *stack_a, t_stack *stack_b);

//print_moviments.c
void	execute_push(t_stack *from, t_stack *to, char *op);
void	execute_rotate(t_stack *stack, char *op);
void	execute_reverse_rotate(t_stack *stack, char *op);
void	execute_swap(t_stack *stack, char *op);

//sort_small.c
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
#endif
