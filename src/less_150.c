/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_150.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:53:59 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/09 16:44:45 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	n1_less_150(t_pushswap *all, int *i, int *j)
{
	if (check_nbr_in_list(all, all->ta[0]))
	{
		push_stack(&all->len_ta, all->ta, &all->len_tb, all->tb);
		write(1, "pb\n", 3);
		all->total_instrc++;
		all->idx++;
		all->nbr_p--;
		(*i) = 0;
		(*j) = all->len_ta;
		if (all->nbr_p == 0)
		{
			all->group_nbrs++;
			all->nbr_p = all->nbr_g;
		}
		return (1);
	}
	if ((*i) < (*j) && check_nbr_in_list(all, all->ta[++(*i)]))
	{
		rotate_stack(all->len_ta, all->ta);
		write(1, "ra\n", 3);
		(*i) = 0;
		*j = all->len_ta;
		return (1);
	}
	return (0);
}

void	norm1_less_150(t_pushswap *all)
{
	int	i;
	int	j;

	i = 0;
	j = all->len_ta;
	while (all->nbr_p > 0)
	{
		if (all->len_ta <= 0)
			break ;
		if (n1_less_150(all, &i, &j))
			continue ;
		if (i < j && check_nbr_in_list(all, all->ta[--j]))
		{
			reverse_rotate_stack(all->len_ta, all->ta);
			write(1, "rra\n", 4);
			i = 0;
			j = all->len_ta;
		}
	}
}

void	n2_less_150(t_pushswap *all)
{
	if (all->index_of_nbr <= (all->len_tb - all->index_of_nbr))
	{
		rotate_stack(all->len_tb, all->tb);
		write(1, "rb\n", 3);
		all->total_instrc++;
	}
	else
	{
		reverse_rotate_stack(all->len_tb, all->tb);
		write(1, "rrb\n", 4);
		all->total_instrc++;
	}
}

void	norm2_less_150(t_pushswap *all)
{
	all->idx = all->len_tc - 1;
	all->nbr_p = all->len_tc;
	while (all->nbr_p > 0)
	{
		if (all->tb[0] == all->tc[all->idx])
		{
			push_stack(&all->len_tb, all->tb, &all->len_ta, all->ta);
			write(1, "pa\n", 3);
			all->total_instrc++;
			all->idx--;
			all->nbr_p--;
			continue ;
		}
		all->index_of_nbr = get_index_of_nbr(all->len_tb, all->tb, all);
		n2_less_150(all);
	}
}

void	less_150(t_pushswap *all)
{
	int	i;
	int	j;

	all->group_nbrs = 1;
	i = 0;
	j = all->len_ta;
	all->idx = 0;
	all->nbr_p = all->len_ta / 6;
	all->nbr_g = all->len_ta / 6;
	norm1_less_150(all);
	norm2_less_150(all);
}
