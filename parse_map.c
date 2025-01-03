/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:45:36 by fileonar          #+#    #+#             */
/*   Updated: 2024/12/10 19:58:59 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_if_ber(char *map_arg, int *error)
{
	int	len;

	len = ft_strlen(map_arg);
	len -= 4;
	if (len < 0)
		return(error_msg("Map not correct...\n", error), EXIT_FAILURE);
	if (ft_strncmp(&map_arg[len], ".ber", 4))
		return (error_msg("Map not correct...\n", error), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static	int check_elements(char *map, int *error)
{
	int	i;
	int	exit;
	int	player;

	i = 0;
	exit = 0;
	player = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			player++;
		if (map[i] == 'E')
			exit++;
		if (map[i] != '1' && map[i] != '0' && map[i] != 'P' && map[i] != 'E'
			&& map[i] != 'C' && map[i] != '\n')
			return (error_msg("Map has invalid elements...\n", error),
				EXIT_FAILURE);
		i++;
	}
	if (exit != 1 || player != 1)
		return (error_msg("Invalid number of E and/or P...\n", error),
			EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

char	*parse_map(char *map, int *error)
{
	if (check_elements(map, error))
		return (NULL);
	return (map);
}