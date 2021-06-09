/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_20_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:52:45 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/09 11:58:56 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	less_20(t_pushswap *all)
{
	all->idx = 0;
	all->nbr_p = all->len_ta;
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

	all->nbr_p = all->len_tb;
	while (all->nbr_p > 0)
	{
		push_stack(&(all->len_tb), all->tb, &(all->len_ta), all->ta);
		write(1, "pa\n", 3);
		all->total_instrc++;
		all->nbr_p--;
	}
}
