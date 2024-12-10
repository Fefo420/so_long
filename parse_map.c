/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:45:36 by fileonar          #+#    #+#             */
/*   Updated: 2024/12/10 17:46:00 by fileonar         ###   ########.fr       */
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