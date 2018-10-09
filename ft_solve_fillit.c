/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_fillit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <mgolban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:48:00 by mgolban           #+#    #+#             */
/*   Updated: 2016/11/04 20:40:54 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_try(t_tetri *tetri_list, char **map, size_t square)
{
	size_t	i;
	size_t	j;
	char	*s;

	j = tetri_list->x;
	i = tetri_list->y;
	s = tetri_list->tetri;
	while (*s)
	{
		if (*s >= 'A' && *s <= 'Z' && i < square &&
				j < square && map[i][j] == '.')
			map[i][j++] = *s;
		else if (*s == '\n')
		{
			i++;
			j = tetri_list->x;
		}
		else if (*s == '.')
			j++;
		else
			return (0);
		s++;
	}
	return (1);
}

static void	ft_clear_tetri(t_tetri *tetri_list, char **map, size_t square)
{
	size_t	i;
	size_t	j;
	char	*s;

	j = tetri_list->x;
	i = tetri_list->y;
	s = tetri_list->tetri;
	while (*s)
	{
		if (i < square && j < square && map[i][j] == tetri_list->c)
			map[i][j++] = '.';
		else if (*s == '\n')
		{
			i++;
			j = tetri_list->x;
		}
		else if (*s == '.')
			j++;
		s++;
	}
}

static int	ft_xy(t_tetri *tetri_list, char **map, size_t square)
{
	ft_clear_tetri(tetri_list, map, square);
	if (tetri_list->x < square)
	{
		tetri_list->x += 1;
		return (1);
	}
	if (tetri_list->y < square)
	{
		tetri_list->x = 0;
		tetri_list->y += 1;
		return (1);
	}
	return (0);
}

static int	ft_place_on_map(t_tetri *tetri_list, char **map, size_t square)
{
	while (tetri_list)
	{
		if (ft_try(tetri_list, map, square) == 0)
		{
			if (ft_xy(tetri_list, map, square) == 0)
			{
				tetri_list->x = 0;
				tetri_list->y = 0;
				if (tetri_list->prev)
				{
					ft_xy(tetri_list->prev, map, square);
					tetri_list = tetri_list->prev;
				}
				else
					return (0);
			}
		}
		else
			tetri_list = tetri_list->next;
	}
	return (1);
}

char		**ft_solve_fillit(t_tetri *tetri_list, size_t square)
{
	char **map;

	map = ft_create_map(square);
	if (ft_place_on_map(tetri_list, map, square) == 0)
	{
		ft_free_map(map);
		ft_clear_xy(tetri_list);
		return (ft_solve_fillit(tetri_list, square + 1));
	}
	return (map);
}
