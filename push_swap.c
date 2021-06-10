/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:44:28 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/10 11:26:39 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_a(t_pushswap *all)
{
	int	i;

	all->tb = malloc(sizeof(int) * all->ac);
	all->tc = malloc(sizeof(int) * all->ac);
	all->len_tb = 0;
	all->len_tc = all->ac;
	rmp_t(all->args, all->ac, all->ta);
	rmp_t(all->args, all->ac, all->tc);
	sort_tc(all->len_tc, all->tc);
	i = -1;
	while (++i < all->len_ta)
	{
		if (all->ta[i] != all->tc[i])
			return (1);
	}
	return (0);
}

int	start_program(t_pushswap *all)
{
	all->ta = malloc(sizeof(int) * all->ac);
	all->len_ta = all->ac;
	rmp_t(all->args, all->ac, all->ta);
	if (check_args_dublc(all->len_ta, all->ta))
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	if (!check_a(all))
		return (0);
	if (all->len_ta <= 5)
		less_5(all);
	else if (all->len_ta < 20)
		less_20(all);
	else if (all->len_ta <= 150)
		less_150(all);
	else if (all->len_ta > 150)
		more_150(all);
	return (0);
}

void	free_all(t_pushswap *all)
{
	int	i;

	i = -1;
	free(all->ta);
	free(all->tb);
	free(all->tc);
	while (all->args[++i])
		free(all->args[i]);
	free(all->args);
	free(all);
}

int	main(int ac, char *av[])
{
	t_pushswap	*all;

	if (ac > 1)
	{
		if (check_args2(av))
		{
			ft_putstr_fd("Error\n", 1);
			return (1);
		}
		all = new_vrbs();
		rem_args(av, all);
		if (check_args(all->args))
		{
			ft_putstr_fd("Error\n", 1);
			free_all(all);
			return (1);
		}
		if (start_program(all))
		{
			free_all(all);
			return (1);
		}
		free_all(all);
	}
	return (0);
}
