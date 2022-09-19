/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:23:44 by vcastilh          #+#    #+#             */
/*   Updated: 2022/09/19 03:56:50 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sort(t_stack *stack)
{
	if (stack->size_a == 2)
		swap(stack->a, 'a');
	else if (stack->size_a == 3)
		sort_three(stack);
	else if (stack->size_a <= 5)
		small_sort(stack);
	else
		radix(stack);
}

void	sort_three(t_stack *stack)
{
	if (stack->a[0] < stack->a[1]
		&& stack->a[1] > stack->a[2]
		&& stack->a[0] < stack->a[2])
	{
		swap(stack->a, 'a');
		rotate(stack->a, stack->size_a, 'a');
	}
	else if (stack->a[0] > stack->a[1]
		&& stack->a[1] < stack->a[2]
		&& stack->a[0] < stack->a[2])
		swap(stack->a, 'a');
	else if (stack->a[0] < stack->a[1]
		&& stack->a[1] > stack->a[2]
		&& stack->a[0] > stack->a[2])
		reverse_rotate(stack->a, stack->size_a, 'a');
	else if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
	{
		swap(stack->a, 'a');
		reverse_rotate(stack->a, stack->size_a, 'a');
	}
	else if (stack->a[0] > stack->a[1]
		&& stack->a[1] < stack->a[2]
		&& stack->a[0] > stack->a[2])
		rotate(stack->a, stack->size_a, 'a');
}

void	small_sort(t_stack *stack)
{
	while (!is_sorted(stack) || stack->size_b != 0)
	{
		if (!min_rules(stack))
		{
			if (!is_sorted(stack))
			{
				set_mem_len(stack->size_b, stack->size_a, stack);
				push(stack->b, stack->a, stack, 'b');
			}
			else
			{
				set_mem_len(stack->size_a, stack->size_b, stack);
				push(stack->a, stack->b, stack, 'a');
			}
		}
	}
}

void	radix(t_stack *stack)
{
	int	bit;
	int	j;

	bit = 0;
	while (!is_sorted(stack))
	{
		j = 0;
		while (j < stack->size_a + stack->size_b && !is_sorted(stack))
		{
			if ((stack->a[0] >> bit) & 1)
				rotate(stack->a, stack->size_a, 'a');
			else
			{
				set_mem_len(stack->size_b, stack->size_a, stack);
				push(stack->b, stack->a, stack, 'b');
			}				
			j++;
		}
		bit++;
		while (stack->size_b > 0)
		{
			set_mem_len(stack->size_a, stack->size_b, stack);
			push(stack->a, stack->b, stack, 'a');
		}
	}
}
