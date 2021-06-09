/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:47:22 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/09 11:26:54 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rem_args(char **av, t_pushswap	*all)
{
	int		i;
	char	**ar;
	int		c;

	i = 0;
	c = 0;
	while (av[++i])
	{
		ar = ft_split(av[i], ' ');
		add_in_list(all, ar);
		free(ar);
	}
	i = -1;
	while (all->args[++i])
		c++;
	all->ac = c;
}

int	check_nbr_in_list(t_pushswap *all, int nbr)
{
	int	i;

	i = (all->group_nbrs * all->nbr_g) - all->group_nbrs * all->nbr_g - 1;
	while (++i < all->len_tc && i < all->group_nbrs * all->nbr_g)
	{
		if (all->tc[i] == nbr)
			return (1);
	}
	return (0);
}

void	norm_list(t_pushswap *all, char **ar)
{
	int		i;

	i = 0;
	while (all->args && all->args[i])
	{
		all->tmp[i] = all->args[i];
		i++;
	}
	all->j = 0;
	while (ar[all->j])
	{
		all->tmp[i] = ar[all->j];
		i++;
		all->j++;
	}
	all->tmp[i] = NULL;
	all->args = all->tmp;
}

void	add_in_list(t_pushswap	*all, char **ar)
{
	int		i;

	all->c = 0;
	all->c2 = 0;
	i = -1;
	if (!ar)
		return ;
	while (ar[++i])
		all->c++;
	i = -1;
	while (all->args && all->args[++i])
		all->c2++;
	all->tmp = malloc(sizeof(char *) * (all->c + all->c2) + 1);
	norm_list(all, ar);
}
