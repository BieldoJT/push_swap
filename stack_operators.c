#include "push_swap.h"

void	push_switch_stack(t_stack *to_lose, t_stack *to_recieve)
{
	int	value;

	if (to_lose->size == 0)
		return ;
	value = pop_stack(to_lose);
	push_stack(to_recieve, value);
}

void	rotate_stack(t_stack *stack)
{
	t_node	*aux;
	t_node	*temp;
	t_node	*first_node;

	if (!stack->top->next)
		return ;
	first_node = stack->top;
	aux = stack->top;
	temp = stack->top->next;
	while (aux->next)
		aux = aux->next;
	aux->next = first_node;
	first_node->next = NULL;
	stack->top = temp;
}

void reverse_rotate_stack(t_stack *stack)
{
	t_node	*aux;
	t_node	*last_node;

	if (!stack->top->next)
		return ;
	aux = stack->top;
	while (aux->next->next)
		aux = aux->next;
	last_node = aux->next;
	aux->next = NULL;
	last_node->next = stack->top;
	stack->top = last_node;
}
