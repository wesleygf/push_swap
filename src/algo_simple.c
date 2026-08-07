/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 23:04:25 by wgolbert          #+#    #+#             */
/*   Updated: 2026/07/29 23:04:25 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_position(t_stack *stack, int index)
{
	t_list	*tmp;
	int		position;

	tmp = stack->head;
	position = 0;
	while (tmp)
	{
		if (tmp->index == index)
			return (position);
		position++;
		tmp = tmp->next;
	}
	return (-1);
}

void	process_a(t_push_swap *stack, int position)
{
	if (position < stack->a->size / 2)
	{
		while (position)
		{
			ra(stack);
			position--;
		}
	}
	else
	{
		while (position < stack->a->size)
		{
			rra(stack);
			position++;
		}
	}
	pb(stack);
}

void	process_b(t_push_swap *stack)
{
	while (stack->b->size != 0)
		pa(stack);
}

void	algo_simple(t_push_swap *stack)
{
	int	i;
	int	size;

	size = stack->a->size;
	i = 0;
	while (i < size && is_sorted(stack->a) == 0)
	{
		process_a(stack, find_position(stack->a, i));
		i++;
	}
	process_b(stack);
}
