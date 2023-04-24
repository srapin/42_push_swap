/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 03:30:59 by srapin            #+#    #+#             */
/*   Updated: 2023/02/12 16:33:20 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_is_in(t_list **head, int nb)
{
	t_list	*lst;

	lst = *head;
	while (lst)
	{
		if (lst->content == nb)
		{
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

int	check_numbers(char *nptr)
{
	int				i;
	int				neg;
	long long int	number;

	i = 0;
	neg = 1;
	number = 0;
	while (nptr[i] && is_whitespace(nptr[i]))
		i++;
	if (nptr[i] && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			neg = -neg;
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		number = number * 10 + (nptr[i] - 48);
		i++;
	}
	if (nptr[i] || neg * number > INT_MAX)
		return (0);
	return (1);
}

int	check_input(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!check_numbers(av[i]))
			return (0);
		i++;
	}
	return (1);
}
