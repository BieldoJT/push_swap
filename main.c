#include "push_swap.h"

void print_array(int *array, int size) {
    int i = 0;
    while (i < size) {
        printf("%d, ", array[i]);
        i++;
    }
    printf("\n");
}

void print_stack(t_stack *stack)
{
	t_node *aux;

	aux = stack->top;
	while (aux)
	{
		ft_printf("value: %d\n",aux->content);
		aux = aux->next;
	}

}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc < 2)
		return (0); // Se não houver argumentos, apenas encerra o programa

	//aceitar uma lista de strings // por exemplo: ./push_swap "2 -2 5 -1 7"

	//se a pilha/argumentos . estiver ordenada, o programa não faz nada

	stack_a = parse_input(argc, argv);
	stack_b = init_stack();
	if (!stack_a)
		return (1); // Erro ao criar pilha


	printf("okok\n");
	ft_printf("\nlista dos elementos ordenada\n");
	print_array(stack_a->lst_int, stack_a->size);
	ft_printf("\nSTACK A:\n");
	print_stack(stack_a);

	ft_printf("\nStack apos usar o SWAP A\n");
	swap_stack(stack_a);
	print_stack(stack_a);

	ft_printf("\nStack apos usar o PUSH B\n");
	push_switch_stack(stack_a,stack_b);
	ft_printf("\nSTACK A:\n");
	print_stack(stack_a);
	ft_printf("\n");
	ft_printf("\nSTACK B:\n");
	print_stack(stack_b);


	ft_printf("\nStack apos usar o ROTATE A\n\n");
	rotate_stack(stack_a);
	ft_printf("\nSTACK A:\n");
	print_stack(stack_a);


	ft_printf("\nStack apos usar o REVERSE ROTATE A\n");
	reverse_rotate_stack(stack_a);
	ft_printf("\nSTACK A:\n");
	print_stack(stack_a);




	// TODO: Implementar radix_sort(stack_a)

	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
