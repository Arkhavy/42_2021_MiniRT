/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_split_from_raw.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 08:48:26 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/07 13:40:59 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// Check the existence of the given value, split it and check splitlen
char	**rt_get_split_from_raw(char *value, char c, int splitlen, char *name)
{
	char	**split;

	if (!value || !value[0])
		return (rt_write_split_error(E_MISSING, name));
	split = ft_split(value, c);
	if (!split)
		return (rt_write_split_error(E_MALLOC, NULL));
	if ((int)ft_splitlen(split) != splitlen)
	{
		ft_free_split(split);
		return (rt_write_split_error(E_SPLIT_SIZE, name));
	}
	return (split);
}