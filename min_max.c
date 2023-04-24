/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 03:07:33 by srapin            #+#    #+#             */
/*   Updated: 2023/02/12 16:25:09 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_max_or_min(t_list *lst, int value)
{
	if (!lst)
	{
		ft_printf("prob\n");
		return (5);
	}
	if (value > lst->content)
	{
		while (lst && value > lst->content)
			lst = lst->next;
		if (!lst)
			return (1);
		return (0);
	}
	while (lst && value < lst->content)
		lst = lst->next;
	if (!lst)
		return (1);
	return (0);
}

int	get_max(t_list *lst)
{
	int	current_max;

	current_max = lst->content;
	while (lst)
	{
		if (current_max < lst->content)
			current_max = lst->content;
		lst = lst->next;
	}
	return (current_max);
}

int	get_min(t_list *lst)
{
	int	current_min;

	current_min = lst->content;
	while (lst)
	{
		if (current_min > lst->content)
			current_min = lst->content;
		lst = lst->next;
	}
	return (current_min);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
