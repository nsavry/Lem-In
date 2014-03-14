/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_solve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 18:01:51 by nsavry            #+#    #+#             */
/*   Updated: 2014/02/23 23:00:26 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

int		ft_find_path(t_anthill *ah)
{
	int		i;
	char	**path;

	path = malloc(sizeof(char *) * 2);
	path[0] = ft_strdup(ah->start);
	path[1] = NULL;
	i = 0;
	if (ft_seek_path_room(path, ah->start, ah->link, ah) == 1)
		return (1);
	else
		return (0);
}

int		ft_seek_path_room(char **path, char *room, char **tmp, t_anthill *ah)
{
	char	**tab;
	int		i;
	int		ret;

	if (ft_strequ(room, ah->end))
		return ((*(int *)(ah->path = ft_tabdup(path)) * 0) + 1);
	tmp = ft_del_room_link(room, tmp);
	i = 0;
	while (ft_strequ(room, ah->name[i]) == 0)
		i++;
	tab = ft_strsplit(ah->link[i], ' ');
	i = 0;
	while (tab[i] != NULL)
	{
		if (ft_strequ(room, tab[i]) == 0)
		{
			path = ft_realloc_path(path, tab[i]);
			if ((ret = ft_seek_path_room(path, tab[i], tmp, ah)) == 1)
				return (1);
			else if (ret == -1)
				return (-1);
		}
	}
	return (-1);
}

char	**ft_realloc_path(char **path, char *str)
{
	int		n;

	n = ft_str_tab_len(path);
	path = ft_realloc_str_tab(path, n, n + 1);
	path[n] = ft_strdup(str);
	return (path);
}

char	**ft_del_room_link(char *room, char **tmp)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	while (tmp[i] != NULL)
	{
		j = 0;
		tab = ft_strsplit(tmp[i], ' ');
		while (tab[j] != NULL)
		{
			if (ft_strequ(tab[j], room))
				tab[j] = ft_strdup(" ");
			j++;
		}
		tmp[i] = ft_unsplit(tab);
		i++;
	}
	return (tmp);
}

char	*ft_unsplit(char **tab)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew(0);
	while (tab[i] != NULL)
	{
		tmp = ft_strjoin(tmp, tab[i]);
		tmp = ft_strjoin(tmp, " ");
		i++;
	}
	return (tmp);
}
