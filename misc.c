/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:21:43 by fileonar          #+#    #+#             */
/*   Updated: 2024/12/10 20:01:37 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(char *error_msg, int *error_int)
{
	*error_int = 1;
	write(STDERR_FILENO, "Error\n", 7);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	return ;
}