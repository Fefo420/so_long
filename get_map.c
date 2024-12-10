/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:15:57 by fileonar          #+#    #+#             */
/*   Updated: 2024/12/10 17:45:53 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



static	char *get_map(char *map_arg, int *error)
{
	char	*map;
	int		fd;

	map = NULL;
	fd = open(map_arg, O_RDONLY);
	if (fd < 0)
		return (error_msg("Something went wrong with fd...\n", error), NULL);
	map = get_next_line(fd);
	if (!map)
		return (error_msg("Map empty...\n", error), NULL);
	map = make_map_string(fd, map);
}


