/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_table_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:51:13 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/09 19:40:42 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_tc(int len_tc, int tc[len_tc])
{
	t_sort	sort;

	sort.i = -1;
	while (++(sort.i) < len_tc)
	{
		sort.j = sort.i;
		sort.min = tc[sort.j];
		sort.pos = sort.j;
		while (sort.j < len_tc)
		{
			if (tc[sort.j] < sort.min)
			{
				sort.min = tc[sort.j];
				sort.pos = sort.j;
			}
			sort.j++;
		}
		if (sort.pos != sort.i)
		{
			sort.swap = tc[sort.i];
			tc[sort.i] = tc[sort.pos];
			tc[sort.pos] = sort.swap;
		}
	}
}
