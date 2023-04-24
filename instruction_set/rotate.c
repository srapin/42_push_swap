/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:54:01 by srapin            #+#    #+#             */
/*   Updated: 2023/02/12 17:01:33 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction_set.h"

void	rotate(t_list **lst)
{
	ft_lstadd_back(lst, pop(lst));
}

void	ra(t_data_set *data, t_bool mute)
{
	rotate(&(data->a));
	if (!mute)
		ft_printf("ra\n");
}

void	rb(t_data_set *data, t_bool mute)
{
	rotate(&(data->b));
	if (!mute)
		ft_printf("rb\n");
}

void	rr(t_data_set *data, t_bool mute)
{
	rotate(&(data->a));
	rotate(&(data->b));
	if (!mute)
		ft_printf("rr\n");
}
