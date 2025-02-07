#include "push_swap.h"

long ft_atoil(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
		//preguiça, se for maior ou menos q o limite, retorna um long maior
		if (result * sign > 2147483647 || result * sign < -2147483648)
			return (2147483648);
	}
	return (result * sign);
}

char	**split_arguments(int argc, char **argv, int *new_argc)
{
	char	**args;

	if (argc == 2) // Caso seja uma string única com múltiplos números
	{
		if (argv[1][0] == '\0')
			print_error(1);
		args = ft_split(argv[1], ' '); // Divide a string por espaços
		if (!args)
			print_error(1);
		*new_argc = 0;
		while (args[*new_argc])
			(*new_argc)++;
		return (args);
	}
	*new_argc = argc - 1;
	return (&argv[1]); // Retorna os argumentos normais
}

void free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	verify_order(t_stack *stack)
{
	t_node	*aux;

	aux = stack->top;
	while (aux->next)
	{
		if(aux->content > aux->next->content)
			return (0);
		aux = aux->next;
	}
	return (1);
}
