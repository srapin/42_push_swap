/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improve_move_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:36:46 by srapin            #+#    #+#             */
/*   Updated: 2023/02/14 18:39:48 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rra(t_data_set *data, t_move *move)
{
	if (ft_lstsize(data->a))
		return ((ft_lstsize(data->a) - move->ra) % ft_lstsize(data->a));
	else
		return (0);
}

int	get_rrb(t_data_set *data, t_move *move)
{
	if (ft_lstsize(data->b))
		return ((ft_lstsize(data->b) - move->rb) % ft_lstsize(data->b));
	else
		return (0);
}

void	init_cost(t_move *move, int rra, int rrb, t_test_cost *cost)
{
	cost->ra_rb = move->ra + move->rb - ft_min(move->ra, move->rb);
	cost->rra_rrb = rra + rrb - ft_min(rra, rrb);
	cost->rra_rb = rra + move->rb;
	cost->ra_rrb = move->ra + rrb;
}

void	change_move_ra_rb(t_move *move)
{
	move->rr = ft_min(move->ra, move->rb);
	move->ra -= move->rr;
	move->rb -= move->rr;
}

void	change_move_rra_rrb(t_move *move, int rra, int rrb)
{
	move->rrr = ft_min(rra, rrb);
	move->rra = rra - move->rrr;
	move->rrb = rrb - move->rrr;
	if (rra || rrb)
	{
		move->ra = 0;
		move->rb = 0;
	}
}
