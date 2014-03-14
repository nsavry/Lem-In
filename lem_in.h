/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 20:37:14 by nsavry            #+#    #+#             */
/*   Updated: 2014/02/23 23:07:02 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef struct	s_anthill
{
	int		nb_ant;
	char	*start;
	char	*end;
	char	**room;
	char	**name;
	char	**link;
	char	**pipe;
	char	**path;
}				t_anthill;

/*
** init
*/
void	ft_init_anthill(t_anthill *ah);
void	ft_init_name(t_anthill *ah);

/*
** error
*/
int		ft_error(int nb);

/*
** read
*/
int		ft_mount_anthill(t_anthill *ah);
int		ft_mount_pipes(char *line, int error, t_anthill *ah);
int		ft_grep_room(char *line, t_anthill *ah);
int		ft_grep_pipe(char *line, t_anthill *ah);
char	*ft_comment(char *line, t_anthill *ah);

/*
** check
*/
int		ft_check_name_room(char *str, char **tab);
int		ft_check_coord_room(char *s1, char *s2, char **tab);
int		ft_check_same_pipe(char *line, char **tab);
int		ft_check_valid_room(char **line);

/*
** print
*/
void	ft_print_anthill(t_anthill *ah);

/*
** link
*/
int		ft_link_room(t_anthill *ah);
char	*ft_found_link(char *str, char **tab);
char	*ft_test_pipe(char *name, char *pipe);

/*
** solve
*/
int		ft_find_path(t_anthill *ah);
int		ft_seek_path_room(char **path, char *room, char **tmp, t_anthill *ah);
char	**ft_realloc_path(char **path, char *str);
char	**ft_del_room_link(char *room, char **tmp);
char	*ft_unsplit(char **tab);

/*
** cross
*/
int		ft_cross_ant(t_anthill *ah);

#endif /* !LEM_IN_H */
