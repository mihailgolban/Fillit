/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <mgolban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 10:54:47 by mgolban           #+#    #+#             */
/*   Updated: 2016/11/04 20:42:21 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(int argc, char **argv)
{
	t_tetri	*tetri_list;
	char	**map;
	int		fd;

	if (argc == 1)
	{
		ft_putendl("usage: no input file");
		exit(0);
	}
	if (argc > 2)
	{
		ft_putendl("usage: must be one input file");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exit(fd);
	tetri_list = ft_check_tetrimonos(&fd);
	close(fd);
	map = ft_solve_fillit(tetri_list, 2);
	ft_print_map(map);
	ft_free_map(map);
	ft_free_list(tetri_list);
	return (0);
}
