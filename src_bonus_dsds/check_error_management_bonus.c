/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_management_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:42:07 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/09 11:58:21 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_args(char **av)
{
	int i;
	int cpt;

	i = 0;
	while (av[++i])
	{
		cpt = -1;
		if (av[i][0] == '+' || av[i][0] == '-')
			cpt++;
		
		while (av[i][++cpt])
		{
			if (!ft_isdigit(av[i][cpt]))
			{
				return (1);
			}
		}		
	}
	return (0);
}
int	check_args2(char **av)
{
	int i;

	i = 0;
	while (av[++i])
	{
		if (ft_strlen(av[i]) == 0)
			return (1);
	}
	return (0);
}

int	check_args_dublc(int len, int ta[len])
{
	int i;
	int j;

	i = -1;
	while (++i < len)
	{
		j = -1;		
		while (++j < len)
		{
			if (i != j && ta[i] == ta[j])
			{
				return (1);
			}
			j++;
		}		
	}
	return (0);
}
