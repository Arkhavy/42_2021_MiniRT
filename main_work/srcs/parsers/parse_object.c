/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:42:32 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:43:34 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Add an object to the object list by initializing the corresponding structure
int	rt_parse_object(t_master *master, char **split)
{
	t_obj_link	*obj_link;

	obj_link = ft_calloc(1, sizeof(t_obj_link));
	if (!obj_link)
		return (rt_write_int_error(E_MALLOC, NULL));
	if (!ft_strncmp(split[0], "sp", 3))
		obj_link->object_ptr = rt_parse_sphere(&obj_link->id, split);
	else if (!ft_strncmp(split[0], "pl", 3))
		obj_link->object_ptr = rt_parse_plane(&obj_link->id, split);
	else if (!ft_strncmp(split[0], "cy", 3))
		obj_link->object_ptr = rt_parse_cylinder(&obj_link->id, split);
	if (!obj_link->object_ptr)
		return (1);
	master->object->lst_size++;
	ft_lstadd_back(&master->object->lst, ft_lstnew(obj_link));
	return (0);
}