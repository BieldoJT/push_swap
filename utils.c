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
