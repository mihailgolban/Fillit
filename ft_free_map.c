/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <mgolban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:50:55 by mgolban           #+#    #+#             */
/*   Updated: 2016/11/03 20:51:32 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_map(char **map)
{
	int i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}
