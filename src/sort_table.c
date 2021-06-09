/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:51:13 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/09 11:30:35 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_tc(int len_tc, int tc[len_tc])
{
	int	i;
	int	j;
	int	pos;
	int	min;
	int	swap;

	i = -1;
	while (++i < len_tc)
	{
		j = i;
		min = tc[j];
		pos = j;
		while (j < len_tc)
		{
			if (tc[j] < min)
			{
				min = tc[j];
				pos = j;
			}
			j++;
		}
		if (pos != i)
		{
			swap = tc[i];
			tc[i] = tc[pos];
			tc[pos] = swap;
		}
	}
}
