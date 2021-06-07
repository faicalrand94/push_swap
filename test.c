/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:13:00 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/07 12:29:48 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "libft1/libft.h"

typedef struct s_filerdr
{
	char				stack_a;
	int					stack_b;
	int					stack_c;
}					t_filerdr;

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

int	get_index_of_nbr(int len, int ta[len], int idx, int len_tc, int tc[len_tc])
{
	int i;

	i = -1;
	while (++i < len)
	{
		if (ta[i] == tc[idx])
			return (i);
	}
	return (-1);
}

int	main(int ac, char *av[])
{
	int	i = -1;
	int	ta[ac];
	int	tb[ac];
	int	tc[ac];
	int len_ta;
	int len_tb;
	int len_tc;
	int nbr_p;
	int index_of_nbr;

	// if (ac > 1)
	// {
	// 	len_ta = ac - 1;
	// 	len_tb = 0;
	// 	len_tc = ac - 1;
	// 	rmp_t(av, ac, ta);
	// 	rmp_t(av, ac, tc);
	// 	sort_tc(len_tc, tc);
	// 	nbr_p = len_ta;
	// 	int idx = 0;
		
	// 	while (nbr_p > 0)
	// 	{
	// 		if (ta[0] == tc[idx])
	// 		{
	// 			push_stack(&len_ta, ta, &len_tb, tb);
	// 			idx++;
	// 			nbr_p--;
	// 		}
	// 		index_of_nbr = get_index_of_nbr(len_ta, ta, idx, len_tc, tc);
	// 		fprintf(stderr, "%d\n", index_of_nbr);
	// 		break ;
	// 	}
		







		
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
		// i = -1;
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
	// }
	// else
	// {
	// 	ft_putstr_fd("Error\n", 1);
	// }
	return (0);
}
