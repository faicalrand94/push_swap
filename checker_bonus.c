/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:13:00 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/09 13:57:29 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// char	*ft_strjoin1(char *s1, char *s2)
// {
// 	size_t	size;
// 	char	*str;
// 	int		i;
// 	int		j;

// 	i = -1;
// 	j = 0;
// 	if (!s1)
// 		return ((str = ft_strdup(s2)));
// 	size = ft_strlen(s1) + ft_strlen(s2);
// 	str = (char *)malloc(sizeof(char) * size + 1);
// 	if (!str)
// 		return (NULL);
// 	while (s1[++i] != '\0')
// 		str[i] = s1[i];
// 	while (s2[j] != '\0')
// 		str[i++] = s2[j++];
// 	str[i] = '\0';
// 	free(s1);
// 	return (str);
// }

char    *ft_strjoinchar(char *s, char c)
{
	int        i;
	char    *str;
	i = 0;
	if(s == NULL)
	{
		if (!(str = (char *)malloc(2)))
			return (0);
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	while (s[i])
		i++;
	if (!(str = (char *)malloc(i + 2)))
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
	int i;

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
		else if (ft_strncmp(s[i], "ra", 3) == 0)
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
	i = -1;
	while (++i < all->len_ta)
	{
		if (all->ta[i] != all->tc[i])
			return (0);
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_pushswap	*all;
	char *line;
	line  = NULL;
	char c;
	char **s;
	if (ac > 1)
	{
		while (read(0, &c, 1) > 0)
		{
			line = ft_strjoinchar(line, c);
		}
		s = ft_split(line, '\n');
		if (check_error_operration(s) == 1)
		{
			free(line);
			my_free(s);
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		free(line);

		if (check_args2(av))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		all = new_vrbs();
		rem_args(av, all);
		if (check_args(all->args))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		all->ta = malloc(sizeof(int) * all->ac);
		all->len_ta = all->ac;
		rmp_t(all->args, all->ac, all->ta);
		if (check_args_dublc(all->len_ta, all->ta))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		all->tb = malloc(sizeof(int) * all->ac);
		all->tc = malloc(sizeof(int) * all->ac);
		all->len_tb = 0;
		all->len_tc = all->ac;
		rmp_t(all->args, all->ac, all->ta);
		rmp_t(all->args, all->ac, all->tc);
		sort_tc(all->len_tc, all->tc);
		if (check_sort(s, all) == 1)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	return (0);
}
