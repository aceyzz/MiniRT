/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <42-xvi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:42:43 by cedmulle          #+#    #+#             */
/*   Updated: 2024/04/25 11:06:01 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	init_ambient(t_data *data)
{
	data->objs->ambient = malloc(sizeof(t_ambient));
	if (!data->objs->ambient)
		err_exit_free("Malloc error", data);
}

static void	check_ratio(double ratio, t_data *data)
{
	if (ratio < 0 || ratio > 1)
		err_exit_free("Invalid ambient light ratio", data);
}

void	parse_ambient(t_data *data, char *line)
{
	int		i;
	char	**tmp;

	data->parse->a_counter++;
	if (data->parse->a_counter > 1)
		err_exit_free("Too many ambient lights", data);
	init_ambient(data);
	tmp = ft_split(line + 1, ' ');
	if (tablen(tmp) != 4)
	{
		free_tab(tmp);
		err_exit_free("Invalid ambient light", data);
	}
	i = 0;
	data->objs->ambient->ratio = parse_double(tmp[i++], data);
	data->objs->ambient->rgb[0] = parse_int(tmp[i++], data);
	data->objs->ambient->rgb[1] = parse_int(tmp[i++], data);
	data->objs->ambient->rgb[2] = parse_int(tmp[i], data);
	free_tab(tmp);
	check_rgb_values(data->objs->ambient->rgb, data);
	check_ratio(data->objs->ambient->ratio, data);
	print_ambient(data->objs->ambient);
}