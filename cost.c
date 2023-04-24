/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 03:39:06 by srapin            #+#    #+#             */
/*   Updated: 2023/02/12 16:33:55 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_order_lst_cost(t_list *lst, int max)
{
	int	cmp;
	int	r;

	r = 0;
	if (max && lst)
		cmp = get_max(lst);
	else if (lst)
		cmp = get_min(lst);
	else
		return (r);
	while (lst && lst->content != cmp)
	{
		r++;
		lst = lst->next;
	}
	return (r);
}

int	get_insertion_cost(t_list *current, int value, int insert_in_b)
{
	int	r;
	int	current_value;
	int	prev_value;

	if (is_max_or_min(current, value))
		return (get_order_lst_cost(current, insert_in_b));
	prev_value = current->content;
	current = current->next;
	current_value = current->content;
	r = 1;
	while (current && !(!insert_in_b && value > prev_value
			&& value < current_value) && !(insert_in_b && value < prev_value
			&& value > current_value))
	{
		prev_value = current_value;
		current = current->next;
		if (current)
			current_value = current->content;
		r++;
	}
	if (!current)
		r = 0;
	return (r);
}

void	set_cost(t_move *move)
{
	move->cost = move->ra + move->rb + move->rr + move->rra + move->rrb
		+ move->rrr;
}
