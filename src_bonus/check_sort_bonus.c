/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:32:38 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/10 10:43:23 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_sort_cnt(t_pushswap *all, int i, char **s)
{
	if (ft_strncmp(s[i], "ra", 3) == 0)
		rotate_stack(all->len_ta, all->ta);
	else if (ft_strncmp(s[i], "rb", 3) == 0)
		rotate_stack(all->len_tb, all->tb);
	else if (ft_strncmp(s[i], "rr", 3) == 0)
	{
		rotate_stack(all->len_ta, all->ta);
		rotate_stack(all->len_tb, all->tb);
	}
	else if (ft_strncmp(s[i], "rra", 4) == 0)
		reverse_rotate_stack(all->len_ta, all->ta);
	else if (ft_strncmp(s[i], "rrb", 4) == 0)
		reverse_rotate_stack(all->len_tb, all->tb);
	else if (ft_strncmp(s[i], "rrr", 4) == 0)
	{
		reverse_rotate_stack(all->len_ta, all->ta);
		reverse_rotate_stack(all->len_tb, all->tb);
	}
	else if (ft_strncmp(s[i], "pa", 3) == 0)
		push_stack(&all->len_ta, all->ta, &all->len_tb, all->tb);
	else if (ft_strncmp(s[i], "pb", 3) == 0)
		push_stack(&all->len_tb, all->tb, &all->len_ta, all->ta);
}

int	check_sort(char **s, t_pushswap *all)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (ft_strncmp(s[i], "sa", 3) == 0)
			swap_stack(all->len_ta, all->ta);
		else if (ft_strncmp(s[i], "sb", 3) == 0)
			swap_stack(all->len_tb, all->tb);
		else if (ft_strncmp(s[i], "ss", 3) == 0)
		{
			swap_stack(all->len_ta, all->ta);
			swap_stack(all->len_tb, all->tb);
		}
		else
			check_sort_cnt(all, i, s);
	}
	i = -1;
	while (++i < all->len_ta)
	{
		if (all->ta[i] != all->tc[i])
			return (0);
	}
	return (1);
}
