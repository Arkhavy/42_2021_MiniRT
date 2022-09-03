/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:12:35 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/03 11:59:40 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

t_color	rt_set_ambient_light(t_color hit_color, t_ambient *ambient)
{
	t_color	amb_color;
	t_color	l_amb;

	amb_color = rt_scale_color(*ambient->rgb, ambient->ratio);
	l_amb = rt_reflt_color(amb_color, hit_color);
	return (l_amb);
}

t_color	rt_set_point_light(t_hit hit, t_light *light, t_coord l_dir)
{
	float	angle;
	float	l_dif;
	float	l_bright;
	t_color	spot;

	angle = rt_dot_prod(hit.normal, rt_scale_vec(l_dir, -1));
	l_dif = light->ratio * angle;
	if (l_dif < 0)
		l_dif = 0;
	l_bright = l_dif / rt_vec_length_sqr(l_dir);
	spot = rt_scale_color(hit.color, l_bright);
	return (spot);
}

t_color	rt_set_color(t_hit hit, t_master *master)
{
	t_ray	l_ray;
	t_color	l_amb;
	t_color	l_point;
	t_color	color;
	int		l_intensity;

	l_intensity = 1;
	l_ray.dir = rt_sub_vec(hit.point, *master->light->pos);
	l_ray.origin = *master->light->pos;
	l_amb = rt_set_ambient_light(hit.color, master->ambient);
	l_point = rt_set_point_light(hit, master->light, l_ray.dir);
	// if (rt_in_shadow(master->obj_data, &l_ray, hit))
	// 	l_intensity = 0;
	l_point = rt_scale_color(l_point, l_intensity);
	color = rt_add_color(l_amb, l_point);
	return (color);
}

// bool	rt_in_shadow(t_obj_data *obj_data, t_ray *l_ray, t_hit hit)
// {
// 	size_t		n;
// 	int			i;
// 	t_fcthit	fct[2];
// 	float		dist;

// 	fct[0] = &rt_check_inter_sphere;
// 	fct[1] = &rt_check_inter_plane;
// 	//fct[2] = &rt_inter_cylinder;
// 	// l_ray->dir = rt_sub_vec(rt_add_vec(hit.point, rt_scale_vec(hit.normal, 0.001), l_pos);
// 	// dist = rt_vector_length(shadow.dir);
// 	n = -1;
// 	while (++n < obj_data->lst_size)
// 	{
// 		i = 0;
// 		while (++i <= 2)
// 		{
// 			if (i == obj_data->objects[n]->id)
// 				if ((*fct[i - 1])(&shadow, obj_data->objects[n], 0))
// 					return (1);
// 		}
// 	}
// 	return (0);
// }