/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 02:09:34 by wgolbert          #+#    #+#             */
/*   Updated: 2026/07/30 02:09:34 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	*ps;

	ps = parse_argv(argv, argc);
	if (ps->flags.flag == 's')
		algo_simple(ps);
	else if (ps->flags.flag == 'm')
		algo_medium(ps);
	else if (ps->flags.flag == 'c')
		algo_complex(ps);
	else if (ps->flags.flag == 'a')
		algo_adaptive(ps);
	if (ps->flags.bench == 1)
		print_benchmark(ps->benchmark);
	free_push_swap(ps);
}
