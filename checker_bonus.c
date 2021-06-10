/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:13:00 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/10 10:40:44 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	norm_checker(t_pushswap	*all, char **s)
{
	if (check_args(all->args))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	all->ta = malloc(sizeof(int) * all->ac);
	all->len_ta = all->ac;
	rmp_t(all->args, all->ac, all->ta);
	if (check_args_dublc(all->len_ta, all->ta))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	all->tb = malloc(sizeof(int) * all->ac);
	all->tc = malloc(sizeof(int) * all->ac);
	all->len_tb = 0;
	all->len_tc = all->ac;
	rmp_t(all->args, all->ac, all->ta);
	rmp_t(all->args, all->ac, all->tc);
	sort_tc(all->len_tc, all->tc);
	if (check_sort(s, all) == 1)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (0);
}

int	norm2checker(char *av[], t_pushswap **all, char **s)
{
	if (check_args2(av))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	*all = new_vrbs();
	rem_args(av, *all);
	if (norm_checker(*all, s))
		return (1);
	return (0);
}

int	main(int ac, char *av[])
{
	t_pushswap	*all;
	char		*line;
	char		c;
	char		**s;

	line = NULL;
	if (ac > 1)
	{
		while (read(0, &c, 1) > 0)
		{
			line = ft_strjoinchar(line, c);
		}
		s = ft_split(line, '\n');
		if (check_error_operration(s) == 1)
		{
			free(line);
			my_free(s);
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		free(line);
		if (norm2checker(av, &all, s))
			return (0);
	}
	return (0);
}
