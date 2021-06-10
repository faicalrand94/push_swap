/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:39:15 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/10 10:37:59 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_pushswap
{
	int		i;
	int		*ta;
	int		*tb;
	int		*tc;
	int		idx;
	int		len_ta;
	int		len_tb;
	int		len_tc;
	int		nbr_p;
	int		nbr_g;
	int		index_of_nbr;
	int		total_instrc;
	int		group_nbrs;
	char	**args;
	int		ac;
	int		c;
	int		c2;
	char	**tmp;
	int		j;
}					t_pushswap;

typedef struct s_sort
{
	int		i;
	int		j;
	int		pos;
	int		min;
	int		swap;
}					t_sort;

int			check_args_dublc(int len, int ta[len]);
int			check_args2(char **av);
int			check_args(char **av);
char		**ft_split(char const *s, char c);
void		less_5(t_pushswap *all);
void		less_20(t_pushswap *all);
void		less_150(t_pushswap *all);
void		more_150(t_pushswap *all);
void		push_stack(int *len, int ta[*len], int *lenb, int tb[*lenb]);
void		rotate_stack(int len, int ta[len]);
void		reverse_rotate_stack(int len, int ta[len]);
void		swap_stack(int len, int ta[len]);
int			get_max(int len, int ta[len]);
t_pushswap	*new_vrbs(void);
int			get_index_of_nbr(int len, int ta[len], t_pushswap *all);
void		rmp_t(char **av, int ac, int ta[ac]);
void		my_free(char **l);
int			check_nbr_in_list(t_pushswap *all, int nbr);
void		rem_args(char **av, t_pushswap	*all);
void		sort_tc(int len_tc, int tc[len_tc]);
void		add_in_list(t_pushswap	*all, char **ar);
void		*ft_calloc(size_t count, size_t size);
int			ft_isdigit(int number);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(char const *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			check_error_operration(char **s);
char		*ft_strjoinchar(char *s, char c);
int			check_sort(char **s, t_pushswap *all);

#endif