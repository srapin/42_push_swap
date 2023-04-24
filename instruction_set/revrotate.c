/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:56:18 by srapin            #+#    #+#             */
/*   Updated: 2023/02/12 17:00:21 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction_set.h"

void	revrotate(t_list **head)
{
	t_list	*new_first;
	t_list	*iter;

	if (!head || !*head || !(*head)->next)
		return ;
	iter = *head;
	while (iter->next && iter->next->next)
		iter = iter->next;
	new_first = iter->next;
	iter->next = NULL;
	push(head, new_first);
}

void	rra(t_data_set *data, t_bool mute)
{
	revrotate(&(data->a));
	if (!mute)
		ft_printf("rra\n");
}

void	rrb(t_data_set *data, t_bool mute)
{
	revrotate(&(data->b));
	if (!mute)
		ft_printf("rrb\n");
}

void	rrr(t_data_set *data, t_bool mute)
{
	revrotate(&(data->a));
	revrotate(&(data->b));
	if (!mute)
		ft_printf("rrr\n");
}
