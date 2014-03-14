/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 20:40:05 by nsavry            #+#    #+#             */
/*   Updated: 2014/02/19 18:47:58 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"
#include "libft.h"

int		ft_mount_anthill(t_anthill *ah)
{
	char	*line;
	int		error;

	ft_get_next_line(0, &line);
	if (ft_isnumber(line) == 0)
		return (ft_error(0));
	if (ft_atoi(line) <= 0)
		return (ft_error(0));
	ah->nb_ant = ft_atoi(line);
	ft_get_next_line(0, &line);
	if (line[0] == '#')
		line = ft_comment(line, ah);
	if (line[0] == 'L')
		return (ft_error(4));
	while ((error = ft_grep_room(line, ah)) == 1)
	{
		ft_get_next_line(0, &line);
		if (line[0] == '#')
			line = ft_comment(line, ah);
		if (line[0] == 'L')
			return (ft_error(4));
	}
	if (ft_mount_pipes(line, error, ah) == -1)
		return (-1);
	return (1);
}

int		ft_mount_pipes(char *line, int error, t_anthill *ah)
{
	if (error == -2)
		return (ft_error(4));
	if (error == -3)
		return (ft_error(5));
	if (ah->start == NULL)
		return (ft_error(1));
	if (ah->end == NULL)
		return (ft_error(2));
	if (error == -1)
		return (ft_error(3));
	if (line[0] == '#')
		ft_get_next_line(0, &line);
	while ((error = ft_grep_pipe(line, ah)))
	{
		if (ft_get_next_line(0, &line) == 0)
			break ;
		if (line[0] == '#')
			ft_get_next_line(0, &line);
	}
	return (1);
}

int		ft_grep_room(char *line, t_anthill *ah)
{
	char	**tab;
	int		i;

	tab = ft_strsplit(line, '-');
	i = ft_str_tab_len(tab);
	if (i >= 2)
		return (0);
	tab = ft_strsplit(line, ' ');
	i = ft_str_tab_len(tab);
	if (i != 3)
		return (-1);
	if (!ft_isnumber(tab[1]) || !ft_isnumber(tab[2]))
		return (-1);
	i = ft_str_tab_len(ah->room);
	if (ft_check_name_room(tab[0], ah->room))
		return (-2);
	if (ft_check_coord_room(tab[1], tab[2], ah->room))
		return (-3);
	ah->room = ft_realloc_str_tab(ah->room, i, i + 1);
	ah->room[i] = ft_strdup(line);
	return (1);
}

int		ft_grep_pipe(char *line, t_anthill *ah)
{
	char	**tab;
	int		i;

	tab = ft_strsplit(line, '-');
	i = ft_str_tab_len(tab);
	if (i != 2)
		return (0);
	if (ft_check_name_room(tab[0], ah->room) == 0)
		return (0);
	if (ft_check_name_room(tab[1], ah->room) == 0)
		return (0);
	if (ft_check_same_pipe(line, ah->pipe))
		return (0);
	i = ft_str_tab_len(ah->pipe);
	ah->pipe = ft_realloc_str_tab(ah->pipe, i, i + 1);
	ah->pipe[i] = ft_strdup(line);
	return (1);
}

char	*ft_comment(char *line, t_anthill *ah)
{
	char	**tab;

	if (ft_strstr_bool(line, "##start"))
	{
		if (ft_check_valid_room(&line) == 0)
			return (line);
		tab = ft_strsplit(line, ' ');
		ah->start = ft_strdup(tab[0]);
		return (line);
	}
	else if (ft_strstr_bool(line, "##end"))
	{
		if (ft_check_valid_room(&line) == 0)
			return (line);
		tab = ft_strsplit(line, ' ');
		ah->end = ft_strdup(tab[0]);
		return (line);
	}
	ft_get_next_line(0, &line);
	return (line);
}
