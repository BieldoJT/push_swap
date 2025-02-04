#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_a;

	if (argc < 2)
		return (0); // Se não houver argumentos, apenas encerra o programa

	stack_a = parse_input(argc, argv);
	if (!stack_a)
		return (1); // Erro ao criar pilha

	printf("okok\n");

	// TODO: Implementar radix_sort(stack_a)

	free_stack(stack_a);
	return (0);
}
