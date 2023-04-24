/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 03:32:17 by srapin            #+#    #+#             */
/*   Updated: 2023/02/14 21:13:59 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_micro_lst_min_sorted(t_data_set *data)
{
	t_list	*a;

	a = data->a;
	if (ft_lstsize(a) == 1)
		return (1);
	if (ft_lstsize(a) == 2)
		return (a->content < a->next->content);
	if (a->content < a->next->content)
		return (!(a->content < a->next->next->content
				&& a->next->content > a->next->next->content));
	return (a->content > a->next->next->content
		&& a->next->content < a->next->next->content);
}

int	is_not_already_sorted(t_data_set *data)
{
	t_list	*a;

	if (!data || !&(data->a))
		return (0);
	a = data->a;
	while (a)
	{
		if (a->next && a->content > a->next->content)
			return (1);
		a = a->next;
	}
	return (0);
}
