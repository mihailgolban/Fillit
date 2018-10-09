/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 23:38:49 by mihail            #+#    #+#             */
/*   Updated: 2016/11/03 23:39:05 by mihail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_create_map(size_t square)
{
	char	**map;
	size_t	i;

	map = (char **)malloc(sizeof(char *) * (square + 1));
	if (map == NULL)
		return (NULL);
	i = -1;
	while (++i < square)
	{
		map[i] = (char *)malloc(sizeof(char) * (square + 1));
		if (map[i] == NULL)
			return (NULL);
		ft_memset(map[i], '.', square);
		map[i][square] = '\0';
	}
	map[i] = NULL;
	return (map);
}
