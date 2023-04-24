/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 23:32:59 by srapin            #+#    #+#             */
/*   Updated: 2023/02/14 21:20:31 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "instruction_set/instruction_set.h"
# include "libft/ft_printf.h"
# include "libft/mylibft/libft.h"
# include <limits.h>

typedef struct s_data_set	t_data_set;

typedef struct s_test_cost
{
	int		ra_rb;
	int		ra_rrb;
	int		rra_rb;
	int		rra_rrb;
}			t_test_cost;

typedef struct s_move
{
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	int		rr;
	int		rrr;
	int		pa;
	int		pb;
	int		sa;
	int		sb;
	int		ss;
	int		cost;
	int		from_pos;
}			t_move;

int			ft_lst_is_in(t_list **head, int nb);
int			check_numbers(char *nptr);
int			check_input(int ac, char **av);
int			get_order_lst_cost(t_list *lst, int max);
int			get_insertion_cost(t_list *current, int value, int insert_in_b);
void		set_cost(t_move *move);
int			is_not_already_sorted(t_data_set *data);
int			is_micro_lst_min_sorted(t_data_set *data);
int			is_max_or_min(t_list *lst, int value);
int			get_max(t_list *lst);
int			get_min(t_list *lst);
int			ft_min(int a, int b);
void		improve_move(t_data_set *data, t_move *move);
void		get_move(t_data_set *data, t_move *move, int insert_in_b);
void		make_move(t_data_set *data, t_move *move, int mute);
t_data_set	*init_data(int i, int data_size);
void		init_move(t_move *move);
int			free_data(t_data_set *data);
void		sort_data(t_data_set *data);
t_data_set	*make_data(int ac, char **av);
int			is_pa_or_pb(char *command, t_move *move);
int			is_sa_or_sb_or_ss(char *command, t_move *move);
int			is_ra_or_rb_or_rr(char *command, t_move *move);
int			is_rra_or_rrb_or_rrr(char *command, t_move *move);
int			read_command(char *command, t_move *move);
int			get_rra(t_data_set *data, t_move *move);
int			get_rrb(t_data_set *data, t_move *move);
void		init_cost(t_move *move, int rra, int rrb, t_test_cost *cost);
void		change_move_ra_rb(t_move *move);
void		change_move_rra_rrb(t_move *move, int rra, int rrb);
#endif