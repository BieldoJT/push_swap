#include "push_swap.h"

//fazer as funções operadoras

void push_switch_stack(t_stack *to_lose, t_stack *to_recieve)
{
    int value;

    if (to_lose->size == 0)
        return ;
    value = pop_stack(to_lose);
    push_stack(to_recieve, value);
}