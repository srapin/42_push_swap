/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:51:33 by srapin            #+#    #+#             */
/*   Updated: 2023/02/12 17:01:08 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction_set.h"

t_list	*pop(t_list **lst)
{
	t_list	*to_ret;

	if (!lst || !*lst)
		return (NULL);
	to_ret = *lst;
	*lst = (*lst)->next;
	to_ret->next = NULL;
	return (to_ret);
}

void	push(t_list **lst, t_list *elem)
{
	if (elem)
		ft_lstadd_front(lst, elem);
}

void	pop_from_push_on(t_list **from, t_list **on)
{
	push(on, pop(from));
}

void	pa(t_data_set *data, t_bool mute)
{
	pop_from_push_on(&(data->b), &(data->a));
	data->size_a++;
	data->size_b--;
	if (!mute)
		ft_printf("pa\n");
}

void	pb(t_data_set *data, t_bool mute)
{
	pop_from_push_on(&(data->a), &(data->b));
	data->size_a--;
	data->size_b++;
	if (!mute)
		ft_printf("pb\n");
}
