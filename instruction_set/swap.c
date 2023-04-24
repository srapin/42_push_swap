/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:04:39 by srapin            #+#    #+#             */
/*   Updated: 2023/02/12 17:01:46 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction_set.h"

void	swap(t_list **top)
{
	t_list	*tmp;

	if (!top || !*top || !(*top)->next)
		return ;
	tmp = *top;
	*top = (*top)->next;
	tmp->next = (*top)->next;
	(*top)->next = tmp;
}

void	sa(t_data_set *data, t_bool mute)
{
	if (!mute)
		ft_printf("sa\n");
	swap(&(data->a));
}

void	sb(t_data_set *data, t_bool mute)
{
	if (!mute)
		ft_printf("sb\n");
	swap(&(data->b));
}

void	ss(t_data_set *data, t_bool mute)
{
	if (!mute)
		ft_printf("ss\n");
	swap(&(data->a));
	swap(&(data->b));
}
