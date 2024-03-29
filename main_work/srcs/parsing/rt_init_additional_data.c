/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_additional_data.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:43:28 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/15 14:20:23 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

//Object table initialization from linked list of obj_data
static t_object	**rt_init_object_tab(t_obj_data *obj_data)
{
	t_object	**objects;
	size_t		a;

	a = 0;
	objects = malloc(sizeof(t_object *) * (obj_data->lst_size + 1));
	if (!objects)
		return (rt_write_ptr_error(E_MALLOC, NULL));
	obj_data->lst = obj_data->start;
	while (a < obj_data->lst_size)
	{
		objects[a] = obj_data->lst->content;
		obj_data->lst = obj_data->lst->next;
		a++;
	}
	objects[a] = NULL;
	return (objects);
}

//Camera additional data initialization (C)
static void	rt_init_add_camera(t_camera **cam)
{
	t_matrix	newm_y;
	t_matrix	newm_x;

	(*cam)->radian = (*cam)->fov * M_PI / 180;
	(*cam)->focal = WIDTH / (2 * tan((*cam)->radian * 0.5));
	newm_y = rt_matrix_rot_x(-asin((*cam)->dir->y) + 0.0001);
	newm_x = rt_matrix_rot_y(atan2((*cam)->dir->x, (*cam)->dir->z) + 0.0005);
	(*cam)->rotate = rt_multiply_matrix(newm_y, newm_x);
	*(*cam)->pos = rt_add_vec(*(*cam)->pos, rt_scale_vec(*(*cam)->dir, 0.0005));
}

//Object additional data initialization (SP / PL / CY)
void	rt_init_add_object(t_object **object)
{
	(*object)->radius = 0.0;
	if ((*object)->id == SP || (*object)->id == CY)
		(*object)->radius = (*object)->diameter * 0.5;
	if ((*object)->id == CY)
		(*object)->radius += 0.0001;
}

//Master additional data initialization
int	rt_init_additional_data(t_master *master)
{
	int	a;

	a = 0;
	master->mlx = ft_calloc(1, sizeof(t_mlx_data));
	if (!master->mlx)
		return (rt_write_int_error(E_MALLOC, NULL));
	master->obj_data->objects = rt_init_object_tab(master->obj_data);
	if (!master->obj_data->objects)
		return (1);
	master->obj_data->lst = master->obj_data->start;
	rt_init_add_camera(&master->camera);
	while (master->obj_data->objects[a])
	{
		rt_init_add_object(&master->obj_data->objects[a]);
		master->obj_data->objects[a]->selected = 0;
		a++;
	}
	master->obj_data->fct[0] = &rt_inter_sphere;
	master->obj_data->fct[1] = &rt_inter_plane;
	master->obj_data->fct[2] = &rt_inter_cylinder;
	return (0);
}
