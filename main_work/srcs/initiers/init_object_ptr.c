/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:56:07 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:42:31 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Check splitlen and initialize object pointer depending on ID given
void	*rt_init_object_ptr(char **split, int valid_splitlen, char *name)
{
	void	*object_ptr;
	int		splitlen;

	object_ptr = NULL;
	splitlen = ft_splitlen(split);
	if (splitlen != valid_splitlen)
		return (rt_write_char_error(E_SPLIT_SIZE, name));
	if (!ft_strncmp(split[0], "A", 2))
		object_ptr = ft_calloc(1, sizeof(t_ambient));
	else if (!ft_strncmp(split[0], "C", 2))
		object_ptr = ft_calloc(1, sizeof(t_camera));
	else if (!ft_strncmp(split[0], "L", 2))
		object_ptr = ft_calloc(1, sizeof(t_light));
	else if (!ft_strncmp(split[0], "sp", 3))
		object_ptr = ft_calloc(1, sizeof(t_sphere));
	else if (!ft_strncmp(split[0], "pl", 3))
		object_ptr = ft_calloc(1, sizeof(t_plane));
	else if (!ft_strncmp(split[0], "cy", 3))
		object_ptr = ft_calloc(1, sizeof(t_cylinder));
	else
		return (rt_write_char_error(E_ID, NULL));
	if (!object_ptr)
		return (rt_write_char_error(E_MALLOC, NULL));
	return (object_ptr);
}