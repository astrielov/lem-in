/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:31:02 by astrielov         #+#    #+#             */
/*   Updated: 2018/07/17 17:53:03 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static t_room	*find_room_by_name(t_room *room, char *name)
{
	while (room && !ft_strequ(room->room_name, name))
		room = room->next_input_room;
	return room;
}

static void	paste_link(t_room *dst_room, t_room *tolink, int rooms_amount)
{
	t_room	**nearby_rooms;

	if (!dst_room->nearby_rooms)
		dst_room->nearby_rooms = (t_room **)ft_memalloc((rooms_amount + 1) *
															sizeof(t_room *));
	nearby_rooms = dst_room->nearby_rooms;
	while (*nearby_rooms && *nearby_rooms != tolink)
		nearby_rooms++;
	*nearby_rooms = tolink;
}

void 	add_rooms_link(t_room *first_room, char *line)
{
	t_room	*room1;
	t_room	*room2;
	int 	rooms_amount;
	char 	*node_name1 = get_split_str_part(line, 0, '-');
	char 	*node_name2 = get_split_str_part(line, 1, '-');

	rooms_amount = count_rooms(first_room);
	room1 = find_room_by_name(first_room, node_name1);
	room2 = find_room_by_name(first_room, node_name2);
	if (!room1 || !room2)
		error();
	paste_link(room1, room2, rooms_amount);
	paste_link(room2, room1, rooms_amount);
}
