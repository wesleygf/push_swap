/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 02:09:38 by wgolbert          #+#    #+#             */
/*   Updated: 2026/07/30 02:09:38 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	convert_array(char **argv, int *array, int size)
{
	int		i;
	long	converted;

	i = 0;
	while (i < size)
	{
		if (is_number(argv[i]) == 0)
		{
			free(array);
			error();
		}
		converted = ft_atol(argv[i]);
		if (converted > INT_MAX || converted < INT_MIN)
		{
			free(array);
			error();
		}
		if (is_duplicate(array, i, converted) == 1)
		{
			free(array);
			error();
		}
		array[i] = (int)converted;
		i++;
	}
}

static t_flags	get_flags(char *str, t_flags flags)
{
	if (ft_strcmp(str, "--bench") == 0)
		flags.bench = 1;
	else if (ft_strcmp(str, "--simple") == 0)
	{
		if (flags.flag != 'a')
			error();
		flags.flag = 's';
	}
	else if (ft_strcmp(str, "--medium") == 0)
	{
		if (flags.flag != 'a')
			error();
		flags.flag = 'm';
	}
	else if (ft_strcmp(str, "--complex") == 0)
	{
		if (flags.flag != 'a')
			error();
		flags.flag = 'c';
	}
	else if (ft_strcmp(str, "--adaptive") == 0)
		flags.flag = 'a';
	else
		error();
	return (flags);
}

t_push_swap	*parse_argv(char **argv, int argc)
{
	int			i;
	t_flags		flags;
	int			*array;
	t_push_swap	*ps;

	flags.bench = 0;
	flags.flag = 'a';
	i = 1;
	while (argv[i] && ft_strncmp(argv[i], "--", 2) == 0)
		flags = get_flags(argv[i++], flags);
	if (i > 3 || argc == i)
		error();
	array = malloc(sizeof(int) * (argc - i));
	if (!array)
		error();
	convert_array(argv + i, array, argc - i);
	ps = init_push_swap(array, argc - i, flags.bench, flags.flag);
	if (!ps)
	{
		free(array);
		error();
	}
	free(array);
	return (ps);
}
