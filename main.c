/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:06:19 by vcastilh          #+#    #+#             */
/*   Updated: 2022/09/15 15:32:16 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack->tmp);
}

int	init_stack(int argc, char *argv[], t_stack *stack)
{
	int	i;

	stack->a = malloc(sizeof(long long) * (argc - 1));
	stack->b = malloc(sizeof(long long) * (argc - 1));
	stack->tmp = malloc(sizeof(long long) * (argc - 1));
	if (stack->a == NULL || stack->b == NULL || stack->tmp == NULL)
		return (1);
	stack->size_a = argc -1;
	stack->size_b = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		stack->tmp[i - 1] = (long long)ft_atol(argv[i]);
		i++;
	}
	cpy_tmp_to_stack(stack);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	stack;

	if (argc < 2)
		return (0);
	if (!is_valid_numbers(argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (init_stack(argc, argv, &stack) || is_duplicated(&stack))
	{
		free_stack(&stack);
		write(1, "Error\n", 6);
		return (1);
	}
	simplify_nb(&stack);
	ft_memset(stack.b, 0, stack.size_b * sizeof(long long));
	if (is_sorted(&stack))
	{
		free_stack(&stack);
		return (0);
	}
	choose_sort(&stack);
	free_stack(&stack);
	return (0);
}
