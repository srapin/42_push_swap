/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 03:41:39 by srapin            #+#    #+#             */
/*   Updated: 2023/02/14 21:28:27 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data_set	*init_data(int i, int data_size)
{
	t_data_set	*data;

	data = malloc(sizeof(t_data_set));
	data->a = ft_lstnew(i);
	data->b = NULL;
	data->size_a = data_size;
	data->size_b = 0;
	return (data);
}

void	init_move(t_move *move)
{
	move->ra = 0;
	move->rb = 0;
	move->rr = 0;
	move->rrr = 0;
	move->rrb = 0;
	move->rra = 0;
	move->pa = 0;
	move->pb = 0;
	move->sa = 0;
	move->sb = 0;
	move->ss = 0;
	move->cost = 1000000;
}

int	free_data(t_data_set *data)
{
	if (!data)
		return (0);
	ft_lstclear(&(data->a));
	ft_lstclear(&(data->b));
	free(data);
	return (0);
}

t_data_set	*make_data(int ac, char **av)
{
	int			i;
	t_data_set	*data;

	if (ac == 1)
		return (NULL);
	if (!check_input(ac, av))
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	data = init_data(ft_atoi(av[1]), ac - 1);
	i = 2;
	while (i < ac)
	{
		if (ft_lst_is_in(&(data->a), ft_atoi(av[i])))
		{
			write(2, "Error\n", 6);
			free_data(data);
			return (NULL);
		}
		ft_lstadd_back(&(data->a), ft_lstnew(ft_atoi(av[i])));
		i++;
	}
	return (data);
}
