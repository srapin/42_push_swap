/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 03:42:13 by srapin            #+#    #+#             */
/*   Updated: 2023/02/14 18:45:55 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	improve_move(t_data_set *data, t_move *move)
{
	t_test_cost	cost;
	int			rra;
	int			rrb;

	rra = get_rra(data, move);
	rrb = get_rrb(data, move);
	init_cost(move, rra, rrb, &cost);
	if (cost.ra_rb <= ft_min(ft_min(cost.rra_rrb, cost.ra_rrb), cost.rra_rb))
		change_move_ra_rb(move);
	else if (cost.rra_rrb < ft_min(cost.rra_rb, cost.ra_rrb))
		change_move_rra_rrb(move, rra, rrb);
	else if (cost.rra_rb < cost.ra_rrb)
	{
		move->rra = rra;
		move->ra = 0;
	}
	else
	{
		move->rrb = rrb;
		move->rb = 0;
	}
	set_cost(move);
}

void	set_current_move(t_data_set *data, t_move *current_move,
		int insert_in_b, int content)
{
	init_move(current_move);
	if (insert_in_b)
	{
		current_move->ra = current_move->from_pos;
		current_move->rb = get_insertion_cost(data->b, content, insert_in_b);
	}
	else
	{
		current_move->rb = current_move->from_pos;
		current_move->ra = get_insertion_cost(data->a, content, insert_in_b);
	}
	improve_move(data, current_move);
}

void	get_move(t_data_set *data, t_move *move, int insert_in_b)
{
	int		from_pos;
	t_move	current_move;
	t_list	*current_elem;

	from_pos = 0;
	if (insert_in_b)
		current_elem = data->a;
	else
		current_elem = data->b;
	while (current_elem)
	{
		current_move.from_pos = from_pos;
		set_current_move(data, &current_move, insert_in_b,
			current_elem->content);
		if (current_move.cost < move->cost)
			*move = current_move;
		if (move->cost <= 2)
			break ;
		from_pos++;
		current_elem = current_elem->next;
	}
}

void	make_move(t_data_set *data, t_move *move, int mute)
{
	while (move->ra--)
		ra(data, mute);
	while (move->rra--)
		rra(data, mute);
	while (move->rb--)
		rb(data, mute);
	while (move->rrb--)
		rrb(data, mute);
	while (move->rr--)
		rr(data, mute);
	while (move->rrr--)
		rrr(data, mute);
	while (move->pa--)
		pa(data, mute);
	while (move->pb--)
		pb(data, mute);
	while (move->sa--)
		sa(data, mute);
	while (move->sb--)
		sb(data, mute);
	while (move->ss--)
		ss(data, mute);
}
