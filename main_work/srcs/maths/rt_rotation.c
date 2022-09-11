/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:17:16 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/09 12:10:28 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

// rotation haut/bas
void	x_axis_rotation(t_coord *xyz, float rad)
{
	float	prev_y;

	prev_y = xyz->y;
	xyz->y = prev_y * cos(rad) - xyz->z * sin(rad);
	xyz->z = prev_y * sin(rad) + xyz->z * cos(rad);
}

// rotation droite/gauche
void	y_axis_rotation(t_coord *xyz, float rad)
{
	float	prev_x;

	prev_x = xyz->x;
	xyz->x = prev_x * cos(rad) + xyz->z * sin(rad);
	xyz->z = -prev_x * sin(rad) + xyz->z * cos(rad);
}

// tanguage droite/gauche
void	z_axis_rotation(t_coord *xyz, float rad)
{
	float	prev_x;
	float	prev_y;

	prev_x = xyz->x;
	prev_y = xyz->y;
	xyz->x = prev_x * cos(rad) - prev_y * sin(rad);
	xyz->y = prev_x * sin(rad) + prev_y * cos(rad);
}