/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:21:19 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/14 14:53:55 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_H
# define RT_DATA_H

# include <mini_rt.h>

/*/////////////////////////////////////////////////////////////////////////////
		TYPEDEF
*//////////////////////////////////////////////////////////////////////////////

//RT_DATA_H
typedef struct s_master		t_master;
typedef struct s_mlx_data	t_mlx_data;

typedef struct s_obj_data	t_obj_data;
typedef struct s_object		t_object;

typedef struct s_hit		t_hit;
typedef struct s_ray		t_ray;

typedef struct s_color		t_color;
typedef struct s_coord		t_coord;

//RT_MATHS_H
typedef struct s_matrix		t_matrix;

//RT_OBJECTS_H
typedef struct s_ambient	t_ambient;
typedef struct s_camera		t_camera;
typedef struct s_light		t_light;

typedef float				(*t_fcthit)(t_ray*, t_object*);

/*/////////////////////////////////////////////////////////////////////////////
		MAIN STRUCTURES
*//////////////////////////////////////////////////////////////////////////////

/**Structure master, donnant accès à toute les données du programme
 * init		= pointeur d'initialisation de la mlx
 * wdw		= pointeur de fenêtre de la mlx
 * mlx		= structure contenant les données de la MLX
 * 
 * obj_data	= structure contenant les données des objets (SP, PL & CY)
 * 
 * ambient	= structure contenant les données de la lumière ambiante
 * camera	= structure contenant les données de la caméra
 * light	= structure contenant les données de la lumière
*/
struct	s_master
{
	void		*init;
	void		*wdw;
	t_mlx_data	*mlx;

	t_obj_data	*obj_data;

	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
};

/**Structure contenant les données d'image de la mlx
 * img			= ?
 * addr			= ?
 * bpp			= bit per pixel, 8 bits color
 * line_length	= ?
 * endian		= ?
*/
struct s_mlx_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
};

/**Structure contenant une liste chaînée des objets
 * lst		= libft linked list
 * lst_size	= nombre de maillon de la liste lst
 * start	= pointeur vers le début de lst
 * lst->content = t_object
 * objects	= tableau contenant les maillons de la list lst
 * fct[3]	= tableau de pointeur sur fonction pour les objets
*/
struct	s_obj_data
{
	t_list		*lst;
	size_t		lst_size;
	void		*start;
	t_object	**objects;
	t_fcthit	fct[3];
};

/**Structure contenant les données de couleur
 * r	= couleur rouge
 * g	= couleur verte
 * b	= couleur bleue
*/
struct	s_color
{
	float	r;
	float	g;
	float	b;
};

/**Structure contenant les données de coordonnées, position ou direction
 * x	= axe X
 * y	= axe Y
 * Z	= axe Z
 * O	= Origine
*/
struct	s_coord
{
	float	x;
	float	y;
	float	z;
};

/**Structure contenant les données d'un rayon
 * time		= distance que le rayon doit parcourir pour
 			atteindre le point d'intersection 
 * point	= coordonnées du point d'intersection
 * normal	= vecteur perpendiculaire à la surface du point d'intersection
 * color	= couleur du point d'int
 * obj		= lien vers l'objet qui intersecte notre rayon
*/
struct	s_hit
{
	float		time;
	t_coord		point;
	t_coord		normal;
	t_color		color;
	int			cy_plane;
	float		dist_for_normal;
};

/**Structure contenant les données d'un rayon
 * origin	= coordonnées d'origine du rayon
 * dir		= vecteur d'orientation du rayon
 * hit		= structure du point d'intersection du rayon avec un objet
 * inter	= ?
 * in_obj	= ?
*/
struct	s_ray
{
	t_coord		origin;
	t_coord		dir;
	t_hit		hit;
	bool		inter;
	bool		in_obj;
};

/**Structure contenant les données d'une matrice
 * x	= vecteur d'orientation concernant x avec les ratios de rotation
 * y	= vecteur d'orientation concernant y avec les ratios de rotation
 * z	= vecteur d'orientation concernant z avec les ratios de rotation
 * o	= position pour translation de l'origine du vecteur
*/
struct	s_matrix
{
	t_coord	x;
	t_coord	y;
	t_coord	z;
};

#endif //RT_DATA_H