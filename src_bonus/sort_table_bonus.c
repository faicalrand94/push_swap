/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_table_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:51:13 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/10 10:49:18 by fbouibao         ###   ########.fr       */
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

char	*str_j_c_cnt(char c)
{
	char	*str;

	str = (char *)malloc(2);
	if (!str)
		return (0);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*ft_strjoinchar(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (str_j_c_cnt(c));
	while (s[i])
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}

int	check_error_operration(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (ft_strncmp(s[i], "sa", 3) != 0
			&& ft_strncmp(s[i], "sb", 3) != 0
			&& ft_strncmp(s[i], "ss", 3) != 0
			&& ft_strncmp(s[i], "ra", 3) != 0
			&& ft_strncmp(s[i], "rb", 3) != 0
			&& ft_strncmp(s[i], "rr", 3) != 0
			&& ft_strncmp(s[i], "rra", 4) != 0
			&& ft_strncmp(s[i], "rrb", 4) != 0
			&& ft_strncmp(s[i], "rrr", 4) != 0
			&& ft_strncmp(s[i], "pa", 3) != 0
			&& ft_strncmp(s[i], "pb", 3) != 0)
			return (1);
	}
	return (0);
}
