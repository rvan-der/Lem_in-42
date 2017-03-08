/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 21:10:21 by rvan-der          #+#    #+#             */
/*   Updated: 2017/03/08 16:23:16 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				get_room(char *buf, t_room **rms, int cmd)
{
	int			i;
	char		name[25];
	t_room		*new;

	i = -1;
	while (buf[++i] && buf[i] != ' ')
		name[i] = buf[i];
	name[i] = '\0';
	if (is_inlist(name, *rms) && (new = new_room(name, cmd)) != NULL)
	{
		if (cmd == 1)
			room_add(rms, new);
		else
			room_pushback(rms, new);
		return (1);
	}
	return (0);
}
