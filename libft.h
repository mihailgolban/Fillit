/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 23:28:53 by mgolban           #+#    #+#             */
/*   Updated: 2016/11/04 21:00:43 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

typedef struct	s_tetri
{
	char			*tetri;
	size_t			x;
	size_t			y;
	char			c;
	struct s_tetri	*next;
	struct s_tetri	*prev;
}				t_tetri;
void			*ft_memset(void *s, int c, size_t n);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *s);
char			*ft_strnew(size_t size);
char			*ft_strtrim(char const *s);
void			ft_putendl(char const *s);
void			ft_exit(int fd);
t_tetri			*ft_check_tetrimonos(int *fd);
t_tetri			*ft_lst_new(char *buf);
void			ft_lst_add(t_tetri **tetri_list, t_tetri *new_tetri);
char			*ft_clean_tetri(char *buf, int n);
char			**ft_solve_fillit(t_tetri *tetri_list, size_t square);
char			**ft_create_map(size_t square);
void			ft_print_map(char **map);
void			ft_free_map(char **map);
void			ft_free_list(t_tetri *tetri_list);
void			ft_clear_xy(t_tetri *tetri_list);
#endif
