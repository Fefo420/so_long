/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:53:32 by fileonar          #+#    #+#             */
/*   Updated: 2024/12/10 17:45:22 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*get_and_parse_map(char	*map_arg, int *error)
{
	char	*finished_map;

	finished_map = get_map(map_arg, error);






	return (finished_map);
}

int main(int argc, char **argv)
{
	int		error;
	char	*map;

	error = 0;
	if (argc != 2)
		return (error_msg("Need exactly 2 arguments...\n", error), EXIT_FAILURE);
	if (check_if_ber(argv[1]))
		return (error_msg("Map is not a .ber file...\n", error), EXIT_FAILURE);
	map = get_and_parse_map(argv[1], &error);
	
	return (EXIT_SUCCESS);
}