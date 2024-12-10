/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:21:43 by fileonar          #+#    #+#             */
/*   Updated: 2024/12/10 17:38:24 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *error_msg, int *error_int)
{
	*error_int = 1;
	write(1, "Error: ", 7);
	write(1, error_msg, ft_strlen(error_msg));
	return ;
}