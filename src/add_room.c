/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:23:42 by astrielov         #+#    #+#             */
/*   Updated: 2018/08/04 14:23:58 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	add_room(t_room **first_room, char *line, int ants_amount)
{
	t_room	*new_room;
	t_room	*tmp;

	new_room = (t_room *)ft_memalloc(sizeof(t_room));
	new_room->room_name = get_split_str_part(line, 0, ' ');
	new_room->bool_start_room = g_next_room_type == START ? TRUE : FALSE;
	new_room->bool_end_room = g_next_room_type == END ? TRUE : FALSE;
	new_room->ants_in_room = g_next_room_type == START ? ants_amount : 0;
	new_room->xstr = get_split_str_part(line, 1, ' ');
	new_room->ystr = get_split_str_part(line, 2, ' ');
	g_next_room_type = 0;
	if (!(*first_room))
		*first_room = new_room;
	else
	{
		new_room->next_input_room = *first_room;
		*first_room = new_room;
	}
	tmp = new_room->next_input_room;
	while (tmp)
	{
		if (ft_strequ(tmp->room_name, new_room->room_name))
			error();
		tmp = tmp->next_input_room;
	}
}
