/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_150_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:54:35 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/09 11:59:39 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	more_150(t_pushswap *all)
{
	all->group_nbrs = 1;
	int i = 0;
	int j = all->len_ta;
	all->idx = 0;
	all->nbr_p = all->len_ta / 12;
	all->nbr_g = all->len_ta / 12;
	while (all->nbr_p > 0)
	{
		if (all->len_ta <= 0)
			break ;
		if (check_nbr_in_list(all, all->ta[0]))
		{
			push_stack(&all->len_ta, all->ta, &all->len_tb, all->tb);
			write(1, "pb\n", 3);
			all->total_instrc++;
			all->idx++;
			all->nbr_p--;
			if (all->nbr_p == 0)
			{
				all->group_nbrs++;
				all->nbr_p = all->nbr_g;
			}
			continue ;
		}
		
		if (i < j && check_nbr_in_list(all, all->ta[++i]))
		{
			rotate_stack(all->len_ta, all->ta);
			write(1, "ra\n", 3);
			i = 0;
			j = all->len_ta;
		}
		else if (i < j && check_nbr_in_list(all, all->ta[--j]))
		{
			reverse_rotate_stack(all->len_ta, all->ta);
			write(1, "rra\n", 4);
			i = 0;
			j = all->len_ta;
		}
	}
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
}
