/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_xy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:54:12 by mihail            #+#    #+#             */
/*   Updated: 2016/11/04 11:56:32 by mihail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clear_xy(t_tetri *tetri_list)
{
	t_tetri *temp;

	temp = tetri_list;
	while (temp)
	{
		temp->x = 0;
		temp->y = 0;
		temp = temp->next;
	}
}
