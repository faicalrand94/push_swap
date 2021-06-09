/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:44:40 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/09 10:59:51 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	my_free(char **l)
{
	int	i;

	i = -1;
	while (l[++i])
	{
		free(l[i]);
	}
	free(l);
}

void	rmp_t(char **av, int ac, int ta[ac])
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < ac)
	{
		ta[j] = atoi(av[i]);
		j++;
	}
}

int	get_index_of_nbr(int len, int ta[len], t_pushswap *all)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (ta[i] == all->tc[all->idx])
			return (i);
	}
	return (-1);
}

t_pushswap	*new_vrbs(void)
{
	t_pushswap	*all;

	all = malloc(sizeof(t_pushswap));
	all->total_instrc = 0;
	all->args = NULL;
	return (all);
}

int	get_max(int len, int ta[len])
{
	int	i;
	int	max;
	int	pos;

	i = 0;
	max = ta[0];
	pos = 0;
	while (++i < len)
	{
		if (ta[i] > max)
		{
			max = ta[i];
			pos = i;
		}		
	}
	return (pos);
}
