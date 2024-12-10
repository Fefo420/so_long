/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:53:43 by fileonar          #+#    #+#             */
/*   Updated: 2024/12/10 17:46:10 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//LOCAL LIBS
# include "./libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

//EXTERNAL LIB

// TYPES

//PROTOTYPES

void	error_msg(char *error_msg, int *error_int);
int		check_if_ber(char *arg2);
char	*get_map(char *map_arg, int *error);

#endif
