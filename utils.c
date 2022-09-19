/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 01:01:37 by vcastilh          #+#    #+#             */
/*   Updated: 2022/09/17 01:01:40 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *stack)
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

void	set_mem_len(int dst, int src, t_stack *stack)
{
	stack->dst_len = dst;
	stack->src_len = src;
}

void	sort_index(t_stack *stack)
{
	int	size;
	int	i;
	int	j;

	size = stack->size_a;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (stack->tmp[i] == stack->b[j])
			{
				stack->a[j] = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	cpy_tmp_to_stack(t_stack *stack)
{
	ft_memmove(stack->a, stack->tmp, ((stack->size_a) * sizeof(long long)));
	ft_memmove(stack->b, stack->tmp, ((stack->size_a) * sizeof(long long)));
}

void	simplify_nb(t_stack *stack)
{
	int			size;
	int			j;
	int			i;
	long long	aux;

	size = stack->size_a;
	j = 0;
	i = 0;
	aux = 0;
	while (j < size)
	{
		i = 0;
		while (i < size -1)
		{
			if (stack->tmp[i] > stack->tmp[i + 1])
			{
				aux = stack->tmp[i];
				stack->tmp[i] = stack->tmp[i + 1];
				stack->tmp[i + 1] = aux;
			}
			i++;
		}
		j++;
	}
	sort_index(stack);
}
