/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valide_fillit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <mgolban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 14:46:04 by mgolban           #+#    #+#             */
/*   Updated: 2016/11/15 17:32:56 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_symbols(char *buf)
{
	int i;
	int count;
	int tetri;

	i = -1;
	count = 0;
	tetri = 0;
	while (++i < 20)
	{
		if ((i + 1) % 5 != 0 && buf[i] != '.' && buf[i] != '#')
			return (0);
		if (buf[i] == '#' && ++count < 4)
			tetri += ((buf[i + 1] == '#') + (buf[i + 5] == '#'));
		if ((i + 1) % 5 == 0 && buf[i] != '\n')
			return (0);
	}
	if (count != 4 || !(tetri == 3 || tetri == 4))
		return (0);
	return (1);
}

t_tetri		*ft_check_tetrimonos(int *fd)
{
	char	buf[20];
	int		p;
	int		flagn;
	t_tetri	*tetri_list;

	flagn = 1;
	tetri_list = NULL;
	while ((p = read(*fd, buf, 20)))
	{
		flagn = 0;
		if (p < 20 || (ft_check_symbols(buf) == 0))
			ft_exit(*fd);
		ft_lst_add(&tetri_list, ft_lst_new(buf));
		if (read(*fd, buf, 1) == 0)
			break ;
		if (buf[0] != '\n')
			ft_exit(*fd);
		flagn = 1;
	}
	if (flagn == 1)
		ft_exit(*fd);
	return (tetri_list);
}
