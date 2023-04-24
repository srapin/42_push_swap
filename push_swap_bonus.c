/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:16:14 by srapin            #+#    #+#             */
/*   Updated: 2023/02/14 21:17:53 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	read_command(char *command, t_move *move)
{
	int	ret;

	if (command[0] == 'p')
		ret = is_pa_or_pb(command, move);
	else if (command[0] == 's')
		ret = is_sa_or_sb_or_ss(command, move);
	else if (ft_strlen(command) == 3 && command[0] == 'r')
		ret = is_ra_or_rb_or_rr(command, move);
	else if (ft_strlen(command) == 4 && command[0] == 'r' && command[1] == 'r')
		ret = is_rra_or_rrb_or_rrr(command, move);
	else
		ret = false;
	if (command)
		free(command);
	return (ret);
}

int	main(int ac, char **av)
{
	t_data_set	*data;
	t_move		move;
	char		*command;

	data = make_data(ac, av);
	if (!data || !(data->a))
		return (free_data(data));
	command = get_next_line(0);
	while (data && command)
	{
		init_move(&move);
		if (!read_command(command, &move))
		{
			free_data(data);
			write(2, "Error\n", 6);
			return (0);
		}
		make_move(data, &move, true);
		command = get_next_line(0);
	}
	if (data && (!is_not_already_sorted(data) && data->b == NULL))
		ft_printf("OK");
	else
		ft_printf("KO");
	free_data(data);
}
