/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <mgolban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:10:49 by mgolban           #+#    #+#             */
/*   Updated: 2016/11/04 20:50:33 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lst_add(t_tetri **tetri_list, t_tetri *new_tetri)
{
	t_tetri *temp;

	if (*tetri_list == NULL)
		*tetri_list = new_tetri;
	else
	{
		temp = *tetri_list;
		while (temp->next)
			temp = temp->next;
		temp->next = new_tetri;
		new_tetri->prev = temp;
	}
}

t_tetri		*ft_lst_new(char *buf)
{
	t_tetri		*new_tetri;
	char		*tetri;
	static int	n = 0;

	tetri = ft_clean_tetri(buf, n);
	new_tetri = (t_tetri *)malloc(sizeof(t_tetri));
	if (new_tetri == NULL)
		return (NULL);
	new_tetri->tetri = (char *)malloc(sizeof(char) * ft_strlen(tetri));
	if (new_tetri == NULL)
		return (NULL);
	new_tetri->tetri = tetri;
	new_tetri->next = NULL;
	new_tetri->prev = NULL;
	new_tetri->x = 0;
	new_tetri->y = 0;
	new_tetri->c = 'A' + n++;
	return (new_tetri);
}

static void	ft_clean_dot(char *buf)
{
	int i;

	i = -1;
	while (++i < 20)
	{
		if (i < 4 && buf[i] != '#' && buf[i + 5] != '#' &&
				buf[i + 10] != '#' && buf[i + 15] != '#')
		{
			buf[i] = 'R';
			buf[i + 5] = 'R';
			buf[i + 10] = 'R';
			buf[i + 15] = 'R';
		}
		if (i % 5 == 0 && buf[i] != '#' && buf[i + 1] != '#' &&
				buf[i + 2] != '#' && buf[i + 3] != '#')
		{
			buf[i] = 'R';
			buf[i + 1] = 'R';
			buf[i + 2] = 'R';
			buf[i + 3] = 'R';
		}
	}
}

char		*ft_clean_tetri(char *buf, int n)
{
	char	*tetri;
	int		i;
	int		j;

	tetri = ft_strnew(6);
	j = 0;
	ft_clean_dot(buf);
	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '#')
			tetri[j++] = 'A' + n;
		if (buf[i] == '.' || buf[i] == '\n')
			tetri[j++] = buf[i];
	}
	tetri[j] = '\0';
	return (ft_strtrim(tetri));
}
