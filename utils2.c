/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 04:27:45 by vcastilh          #+#    #+#             */
/*   Updated: 2022/09/19 04:27:47 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_rules(t_stack *stack)
{
	if (stack->size_a > 2)
	{
		if (stack->a[0] < stack->a[1]
			&& stack->a[1] > stack->a[stack->size_a - 1])
		{
			reverse_rotate(stack->a, stack->size_a, 'a');
			return (1);
		}
		if (check_sa(stack))
		{
			swap(stack->a, 'a');
			return (1);
		}
	}
	if (stack->size_a == 2)
	{
		if (stack->a[0] > stack->a[1])
		{
			swap(stack->a, 'a');
			return (1);
		}
	}
	return (0);
}

int	check_sa(t_stack *stack)
{
	if ((stack->a[0] > stack->a[1] \
		&& stack->a[1] < stack->a[stack->size_a -1]) \
		|| (stack->a[0] > stack->a[1] \
		&& stack->a[1] > stack->a[stack->size_a -1]))
		return (1);
	return (0);
}

int	is_sorted(t_stack *stack)
{
	int	size;
	int	i;

	size = stack->size_a - 1;
	i = 0;
	while (i < size)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
