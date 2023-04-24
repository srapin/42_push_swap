/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_set.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:07:20 by srapin            #+#    #+#             */
/*   Updated: 2023/02/14 18:44:36 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_SET_H
# define INSTRUCTION_SET_H

# include "../libft/ft_printf.h"
# include "../libft/gnl/get_next_line_bonus.h"
# include "../libft/mylibft/libft.h"
# include "../push_swap.h"

typedef enum e_bool
{
	false,
	true
}		t_bool;

typedef struct s_data_set
{
	t_list	*a;
	t_list	*b;
	int		size_a;
	int		size_b;
}			t_data_set;

t_list	*pop(t_list **lst);
void	push(t_list **lst, t_list *elem);

void	sa(t_data_set *data, t_bool mute);
void	sb(t_data_set *data, t_bool mute);
void	ss(t_data_set *data, t_bool mute);

void	pa(t_data_set *data, t_bool mute);
void	pb(t_data_set *data, t_bool mute);

void	ra(t_data_set *data, t_bool mute);
void	rb(t_data_set *data, t_bool mute);
void	rr(t_data_set *data, t_bool mute);

void	rra(t_data_set *data, t_bool mute);
void	rrb(t_data_set *data, t_bool mute);
void	rrr(t_data_set *data, t_bool mute);

#endif