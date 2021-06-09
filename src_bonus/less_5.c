/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:52:03 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/09 18:07:00 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	norm_less_5(t_pushswap *all)
{
	all->idx = all->len_tc - 1;
	all->index_of_nbr = get_index_of_nbr(all->len_ta, all->ta, all);
	if (all->index_of_nbr == 0)
	{
		rotate_stack(all->len_ta, all->ta);
		write(1, "ra\n", 3);
		all->total_instrc++;
	}
	else if (all->index_of_nbr == 1)
	{
		reverse_rotate_stack(all->len_ta, all->ta);
		write(1, "rra\n", 4);
		all->total_instrc++;
	}
	if (all->ta[0] > all->ta[1])
		write(1, "sa\n", 3);
}

void	n2_less_5(t_pushswap *all)
{
	while (all->nbr_p > 0)
	{
		if (all->ta[0] == all->tc[all->idx])
		{
			push_stack(&all->len_ta, all->ta, &all->len_tb, all->tb);
			write(1, "pb\n", 3);
			all->total_instrc++;
			all->idx++;
			all->nbr_p--;
			continue ;
		}
		all->index_of_nbr = get_index_of_nbr(all->len_ta, all->ta, all);
		if (all->index_of_nbr <= (all->len_ta - all->index_of_nbr))
		{
			rotate_stack(all->len_ta, all->ta);
			write(1, "ra\n", 3);
			all->total_instrc++;
		}
		else
		{
			reverse_rotate_stack(all->len_ta, all->ta);
			write(1, "rra\n", 4);
			all->total_instrc++;
		}
	}
}

void	n_less_5(t_pushswap *all)
{
	all->idx = 0;
	all->nbr_p = all->len_ta - 3;
	n2_less_5(all);
	all->idx = all->len_ta - 1;
	all->index_of_nbr = get_max(all->len_ta, all->ta);
	if (all->index_of_nbr == 0)
	{
		rotate_stack(all->len_ta, all->ta);
		write(1, "ra\n", 3);
		all->total_instrc++;
	}
	else if (all->index_of_nbr == 1)
	{
		reverse_rotate_stack(all->len_ta, all->ta);
		write(1, "rra\n", 4);
		all->total_instrc++;
	}
}

void	norm2_less_5(t_pushswap *all)
{
	n_less_5(all);
	if (all->ta[0] > all->ta[1])
		write(1, "sa\n", 3);
	if (all->len_tb > 1 && all->tb[0] < all->tb[1])
		write(1, "sb\n", 3);
	while (all->len_tb > 0)
	{
		push_stack(&all->len_tb, all->tb, &all->len_ta, all->ta);
		write(1, "pa\n", 3);
		all->total_instrc++;
	}
}

void	less_5(t_pushswap *all)
{
	if (all->len_tc == 2)
	{
		if (all->ta[0] > all->ta[1])
			write(1, "sa\n", 3);
	}
	else if (all->len_tc == 3)
	{
		norm_less_5(all);
	}
	else if (all->len_tc > 3)
	{
		norm2_less_5(all);
	}
}
