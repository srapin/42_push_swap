/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 03:37:35 by srapin            #+#    #+#             */
/*   Updated: 2023/02/14 19:20:46 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_b(t_data_set *data)
{
	t_move	move;

	if (data->a)
	{
		pb(data, false);
		if (data->a)
			pb(data, false);
	}
	init_move(&move);
	while (data->a)
	{
		get_move(data, &move, 1);
		make_move(data, &move, false);
		pb(data, false);
		init_move(&move);
	}
	init_move(&move);
	move.rb = get_order_lst_cost(data->b, 1);
	improve_move(data, &move);
	make_move(data, &move, false);
}

void	insertion_sort(t_data_set *data)
{
	fill_b(data);
	while (data->b)
	{
		pa(data, false);
	}
}

void	micro_sort(t_data_set *data)
{
	t_move	move;

	init_move(&move);
	while (ft_lstsize(data->a) > 3)
		pb(data, false);
	if (!is_micro_lst_min_sorted(data))
		sa(data, false);
	while (data->b)
	{
		init_move(&move);
		get_move(data, &move, 0);
		make_move(data, &move, false);
		pa(data, false);
	}
	init_move(&move);
	move.ra = get_order_lst_cost(data->a, 0);
	improve_move(data, &move);
	make_move(data, &move, false);
	return ;
}

void	sort_data(t_data_set *data)
{
	if (!data || !is_not_already_sorted(data))
		return ;
	if (ft_lstsize(data->a) <= 6)
		micro_sort(data);
	else
		insertion_sort(data);
}
