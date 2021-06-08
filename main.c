/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:13:00 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/07 19:33:21 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "libft1/libft.h"

typedef struct s_pushswap
{
	int	i;
	int	*ta;
	int	*tb;
	int	*tc;
	int	idx;
	int len_ta;
	int len_tb;
	int len_tc;
	int nbr_p;
	int nbr_g;
	int index_of_nbr;
	int total_instrc;
	int group_nbrs;
}					t_pushswap;

int	check_args(char **av)
{
	int i;
	int cpt;

	i = 0;
	while (av[++i])
	{
		cpt = -1;
		if (av[i][0] == '+' || av[i][0] == '-')
			cpt++;
		while (av[i][++cpt])
		{
			if (!ft_isdigit(av[i][cpt]))
			{
				return (1);
			}
		}		
	}
	return (0);
}


void	ft_allc(int **ta, int la)
{
	if (*ta)
		free(*ta);
	*ta = malloc(sizeof(int) * la);
}


void sort_swap(char *ta, char *tb)
{
	
}
void	rmp_t(char **av, int ac, int ta[ac])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (++i < ac)
	{
		ta[j] = atoi(av[i]);
		j++;
	}
}

void	sort_tc(int len_tc, int tc[len_tc])
{
	int i;
	int j;
	int pos;
	int min;
	int swap;

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

void	swap_stack(int len, int ta[len])
{
	int swap;

	swap = ta[0];
	ta[0] = ta[1];
	ta[1] = swap;
}

void	reverse_rotate_stack(int len, int ta[len])
{
	int swap;
	int i;

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
	int swap;
	int i;

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
	int push;
	int i;

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

int	get_index_of_nbr(int len, int ta[len], t_pushswap *all)
{
	int i;

	i = -1;
	while (++i < len)
	{
		if (ta[i] == all->tc[all->idx])
			return (i);
	}
	return (-1);
}

t_pushswap	*new_vrbs(int ac, char **av)
{
	t_pushswap	*all;

	all = malloc(sizeof(t_pushswap));
	all->ta = malloc(sizeof(int) * ac);
	all->tb = malloc(sizeof(int) * ac);
	all->tc = malloc(sizeof(int) * ac);
	all->len_ta = ac - 1;
	all->len_tb = 0;
	all->len_tc = ac - 1;
	all->total_instrc = 0;
	return (all);
}

int	get_max(int len, int ta[len])
{
	int	i;
	int max;
	int	pos;

	i = 0;
	max = ta[0];
	pos = 0;
	while (++i < len)
	{
		if (ta[i] > max)
		{
			max = ta[i];
			pos = i;
		}		
	}
	return (pos);
}

void	less_5(t_pushswap *all)
{
	if (all->len_tc == 2)
	{
		if (all->ta[0] > all->ta[1])
		{
			write(1, "sa\n", 3);
		}
	}
	else if (all->len_tc == 3)
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
		{
			write(1, "sa\n", 3);
		}
	}
	else if (all->len_tc > 3)
	{
		all->idx = 0;
		all->nbr_p = all->len_ta - 3;
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
		if (all->ta[0] > all->ta[1])
		{
			write(1, "sa\n", 3);
		}
		if (all->len_tb > 1 && all->tb[0] < all->tb[1])
		{
			write(1, "sb\n", 3);
		}
		while (all->len_tb > 0)
		{
			push_stack(&all->len_tb, all->tb, &all->len_ta, all->ta);
			write(1, "pa\n", 3);
			all->total_instrc++;
		}		
	}
}

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

int		check_nbr_in_list(t_pushswap *all, int nbr)
{
	int i;

	i = (all->group_nbrs * all->nbr_g) - all->group_nbrs * all->nbr_g - 1;
	while (++i < all->len_tc && i < all->group_nbrs * all->nbr_g)
	{
		if (all->tc[i] == nbr)
			return (1);
	}
	return (0);
}

void	less_150(t_pushswap *all)
{
	all->group_nbrs = 1;
	int i = 0;
	int j = all->len_ta;
	all->idx = 0;
	all->nbr_p = all->len_ta / 6;
	all->nbr_g = all->len_ta / 6;
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

void	more_150(t_pushswap *all)
{
	all->group_nbrs = 1;
	int i = 0;
	int j = all->len_ta;
	all->idx = 0;
	all->nbr_p = all->len_ta / 13;
	all->nbr_g = all->len_ta / 13;
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

int	main(int ac, char *av[])
{
	t_pushswap	*all;

	all = new_vrbs(ac, av);
	if (ac > 1)
	{
		rmp_t(av, ac, all->ta);
		rmp_t(av, ac, all->tc);
		sort_tc(all->len_tc, all->tc);
		if (all->len_ta <= 5)
		{
			less_5(all);
		}
		else if (all->len_ta < 20)
		{
			less_20(all);
		}
		else if (all->len_ta < 150)
		{
			less_150(all);
		}
		else if (all->len_ta > 150)
		{
			more_150(all);
		}




		
		// swap_stack(len_ta, ta);
		// rotate_stack(len_ta, ta);
		// reverse_rotate_stack(len_ta, ta);
		// push_stack(&len_ta, ta, &len_tb, tb);
		// push_stack(&len_ta, ta, &len_tb, tb);
		// printf("stack a\n");
		// while (++i < len_ta)
		// {
		// 	printf("%d\n", ta[i]);
		// }
		// printf("\nstack b\n");
		// i = -1;
		// while (++i < len_tb)
		// {
		// 	printf("%d\n", tb[i]);
		// }
		// push_stack(&len_tb, tb, &len_ta, ta);
		// printf("stack a\n");
		// all->i = -1;
		// while (++all->i < all->len_ta)
		// {
		// 	printf("%d\n", all->ta[all->i]);
		// }
		// printf("\nstack b\n");
		// all->i = -1;
		// while (++all->i < all->len_tb)
		// {
		// 	printf("%d\n", all->tb[all->i]);
		// }
		//printf("total instruction : %d", all->total_instrc);
	}
	else
	{
		ft_putstr_fd("Error\n", 1);
	}
	return (0);
}
