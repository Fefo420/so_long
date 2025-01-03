/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:15:57 by fileonar          #+#    #+#             */
/*   Updated: 2024/12/10 19:36:38 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	char	*make_map_string(int fd, int *error)
{
	static char	*return_line = NULL;
	static char	*tmp = NULL;
	char		*line;

	line = get_next_line(fd);
	if (!line)
		return (error_msg("Map is empty...\n", error), NULL);
	while (line)
	{
		if (!return_line)
		{
			return_line = ft_strdup(line);
			ft_free_n_null((void **)&line);
		}
		else
		{
			tmp = return_line;
			return_line = ft_strjoin(return_line, line);
			ft_free_n_null((void **)&tmp);
			ft_free_n_null((void **)&line);
		}
		line = get_next_line(fd);
	}
	return (return_line);
}

char *get_map(char *map_arg, int *error)
{
	char	*map;
	int		fd;

	fd = 0;
	map = NULL;
	fd = open(map_arg, O_RDONLY);
	if (fd < 0)
		return (error_msg("Something went wrong with fd...\n", error), NULL);
	map = make_map_string(fd, error);
	return (map);
}


