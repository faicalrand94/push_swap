/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instraction_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:49:40 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/09 10:58:31 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_stack(int len, int ta[len])
{
	int	swap;

	swap = ta[0];
	ta[0] = ta[1];
	ta[1] = swap;
}

void	reverse_rotate_stack(int len, int ta[len])
{
	int	swap;
	int	i;

	swap = ta[len - 1];
	i = len;
	while (--i > 0)
	{
		ta[i] = ta[i - 1];
	}
	ta[0] = swap;
}

void	rotate_stack(int len, int ta[len])
{
	int	swap;
	int	i;

	swap = ta[0];
	i = -1;
	while (++i < len - 1)
	{
		ta[i] = ta[i + 1];
	}
	ta[len - 1] = swap;
}

void	push_stack(int *len, int ta[*len], int *lenb, int tb[*lenb])
{
	int	push;
	int	i;

	push = ta[0];
	i = -1;
	while (++i < *len - 1)
		ta[i] = ta[i + 1];
	(*len)--;
	i = *lenb + 1;
	while (--i > 0)
		tb[i] = tb[i - 1];
	tb[0] = push;
	(*lenb)++;
}
