/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <mgolban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:30:44 by mgolban           #+#    #+#             */
/*   Updated: 2016/11/03 20:33:17 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_map(char **map)
{
	int i;

	i = -1;
	while (map[++i])
		ft_putendl(map[i]);
}