/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 17:07:25 by nsavry            #+#    #+#             */
/*   Updated: 2014/02/07 17:28:19 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"
#include "libft.h"

int		ft_check_name_room(char *str, char **tab)
{
	char	**tmp;
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		tmp = ft_strsplit(tab[i], ' ');
		if (ft_strequ(tmp[0], str))
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_coord_room(char *s1, char *s2, char **tab)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		tmp = ft_strsplit(tab[i], ' ');
		if (ft_strequ(tmp[1], s1))
		{
			while (tab[j] != NULL)
			{
				if (ft_strequ(tmp[2], s2))
					return (1);
				j++;
			}
		}
		i++;
	}
	return (0);
}

int		ft_check_same_pipe(char *line, char **tab)
{
	int		i;
	char	**tmp;

	i = 0;
	while (tab[i] != NULL)
	{
		if (ft_strequ(line, tab[i]))
			return (1);
		i++;
	}
	tmp = ft_strsplit(line, '-');
	line = ft_strdup(tmp[1]);
	line = ft_strjoin(line, "-");
	line = ft_strjoin(line, tmp[0]);
	i = 0;
	while (tab[i] != NULL)
	{
		if (ft_strequ(line, tab[i]))
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_valid_room(char **line)
{
	int		i;
	char	**tab;

	ft_get_next_line(0, line);
	tab = ft_strsplit(*line, '-');
	i = ft_str_tab_len(tab);
	if (i >= 2)
		return (0);
	tab = ft_strsplit(*line, ' ');
	i = ft_str_tab_len(tab);
	if (i != 3)
		return (0);
	if (!ft_isnumber(tab[1]) || !ft_isnumber(tab[2]))
		return (0);
	return (1);
}
