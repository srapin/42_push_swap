/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:29:30 by srapin            #+#    #+#             */
/*   Updated: 2023/02/14 20:35:12 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_pa_or_pb(char *command, t_move *move)
{
	if (!(ft_strlen(command) == 2 || (ft_strlen(command) == 3
				&& command[2] == '\n')))
		return (false);
	if (command[1] == 'a')
		move->pa = 1;
	else if (command[1] == 'b')
		move->pb = 1;
	else
		return (false);
	return (true);
}

int	is_sa_or_sb_or_ss(char *command, t_move *move)
{
	if (!(ft_strlen(command) == 2 || (ft_strlen(command) == 3
				&& command[2] == '\n')))
		return (false);
	if (command[1] == 'a')
		move->sa = 1;
	else if (command[1] == 'b')
		move->sb = 1;
	else if (command[1] == 's')
		move->ss = 1;
	else
		return (false);
	return (true);
}

int	is_ra_or_rb_or_rr(char *command, t_move *move)
{
	if (!(ft_strlen(command) == 2 || (ft_strlen(command) == 3
				&& command[2] == '\n')))
		return (false);
	if (command[1] == 'a')
		move->ra = 1;
	else if (command[1] == 'b')
		move->rb = 1;
	else if (command[1] == 'r')
		move->rr = 1;
	else
		return (false);
	return (true);
}

int	is_rra_or_rrb_or_rrr(char *command, t_move *move)
{
	if (!(ft_strlen(command) == 3 || (ft_strlen(command) == 4
				&& command[3] == '\n')))
		return (false);
	if (command[2] == 'a')
		move->rra = 1;
	else if (command[2] == 'b')
		move->rrb = 1;
	else if (command[2] == 'r')
		move->rrr = 1;
	else
		return (false);
	return (true);
}
