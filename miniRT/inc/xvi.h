/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xvi.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:50:51 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 11:57:36 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XVI_H
# define XVI_H

# define X_RES 1280
# define Y_RES 720

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_ENTER 36

# define WHITESPACE " \t\n\v\f\r"

typedef struct s_data		t_data;
typedef struct s_obj		t_obj;
typedef struct s_light		t_light;
typedef struct s_camera		t_camera;
typedef struct s_ambient	t_ambient;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;

typedef struct s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*addr;
	int					bpp;
	int					len;
	int					endian;
}						t_mlx;

typedef struct s_parse
{
	char				*filestr;
	char				**filetab;
	int					a_counter;
	int					c_counter;
	int					l_counter;
	int					sp_counter;
	int					pl_counter;
	int					cy_counter;
}						t_parse;

// EXITTERS.C
void					err_exit_void(char *msg);
void					err_exit_free(char *msg, t_data *data);
void					free_tab(char **tab);

// CHECK_ARGS.C
void					check_params(int argc, char **argv);

// UTILS.C
int						is_space(char c);
int						tablen(char **tab);
void					tab_trimmer(char **tab);
void					print_tab(char **tab);
int						is_empty_line(char *str);

// INIT_DATA.C
void					init_data_parse(t_parse *parse);

// MAIN_PARSE.C
void					init_data(t_data *data, char *filename);

// UTILS_DOUBLE.C
double					ft_atod(char *str);
double					parse_double(char *str, t_data *data);
int						check_dir_values(double direction[3], t_data *data);
// UTILS_INT.C
int						parse_int(char *str, t_data *data);
void					check_rgb_values(int rgb[3], t_data *data);

// AMBIENT.C
void					parse_ambient(t_data *data, char *line);
// CAMERA.C
void					parse_camera(t_data *data, char *line);
// LIGHT.C
void					parse_light(t_data *data, char *line);
// SPHERE.C
void					parse_sphere(t_data *data, char *line);
// PLANE.C
void					parse_plane(t_data *data, char *line);
// CYLINDER.C
void					parse_cylinder(t_data *data, char *line);

// DEBUG.C
void					print_camera(t_camera *camera);
void					print_ambient(t_ambient *ambient);
void					print_light(t_light *light);
void					print_sphere(t_sphere *sphere);
void					print_plane(t_plane *plane);
void					print_cylinder(t_cylinder *cylinder);

#endif
