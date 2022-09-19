/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:09:37 by vcastilh          #+#    #+#             */
/*   Updated: 2022/09/15 15:32:20 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(long long *vector, char stack)
{
	long long	tmp;

	tmp = vector[0];
	vector[0] = vector[1];
	vector[1] = tmp;
	if (stack == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	rotate(long long *vector, int size, char stack)
{
	long long	tmp;

	size -= 1;
	tmp = vector[0];
	ft_memmove(&vector[0], &vector[1], sizeof(long long) * (size));
	vector[size] = tmp;
	if (stack == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	reverse_rotate(long long *vector, int size, char stack)
{
	long long	tmp;

	tmp = vector[size - 1];
	ft_memmove(&vector[1], &vector[0], sizeof(long long) * (size - 1));
	vector[0] = tmp;
	if (stack == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	push(long long *dst, long long *src, t_stack *stack, char move)
{
	long long	tmp;

	tmp = src[0];
	if (stack->size_a > 0)
	{
		ft_memmove(src, &src[1], (stack->src_len - 1) * sizeof(long long));
		ft_memmove(&dst[1], dst, (stack->dst_len) * sizeof(long long));
		dst[0] = tmp;
	}
	if (move == 'a')
	{
		stack->size_b--;
		stack->size_a++;
		write(1, "pa\n", 3);
	}
	else
	{
		stack->size_b++;
		stack->size_a--;
		write(1, "pb\n", 3);
	}
}
