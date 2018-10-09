/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:55:49 by mihail            #+#    #+#             */
/*   Updated: 2016/11/04 14:33:17 by mihail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_free_list(t_tetri *tetri_list)
{
	t_tetri *temp;

	temp = tetri_list;
	while (tetri_list)
	{
		temp = temp->next;
		free(tetri_list->tetri);
		free(tetri_list);
		tetri_list = temp;
	}
}
