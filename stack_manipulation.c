#include "push_swap.h"

t_stack *init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void push(t_stack *stack, int value)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return;
	node->content = value;
	node->next = stack->top;
	stack->top = node;
	stack->size++;

}

int pop(t_stack *stack)
{
	t_node	*temp;
	int value;

	if (stack->size == 0)
		return (-1);
	temp = stack->top;
	value = temp->content;
	stack->top = temp->next;
	free(temp);
	stack->size--;
	return (value);
}

void free_stack(t_stack *stack)
{
	t_node	*node;

	if(stack->size != 0)
	{
		while(stack->size > 0)
		{
			node = stack->top->next;
			free(stack->top);
			stack->top = node;
			stack->size--;
		}
		free(stack);
	}
	else
	{
		free(stack);
	}
}
