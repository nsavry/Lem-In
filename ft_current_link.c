/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 15:51:53 by nsavry            #+#    #+#             */
/*   Updated: 2014/02/23 23:14:33 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

int		ft_link_room(t_anthill *ah)
{
	int		i;
	int		nb;

	i = 0;
	nb = ft_str_tab_len(ah->room);
	ah->link = malloc(sizeof(char *) * (nb + 1));
	ah->link[nb] = NULL;
	while (ah->room[i] != NULL)
	{
		ah->link[i] = ft_found_link(ah->room[i], ah->pipe);
		i++;
	}
	return (1);
}

char	*ft_found_link(char *str, char **tab)
{
	char	*tmp;
	char	*link;
	char	**tab_name;
	int		i;

	i = 0;
	tab_name = ft_strsplit(str, ' ');
	link = ft_strnew(0);
	while (tab[i] != NULL)
	{
		if ((tmp = ft_test_pipe(tab_name[0], tab[i])) != NULL)
		{
			link = ft_strjoin(link, tmp);
			link = ft_strjoin(link, " ");
		}
		i++;
	}
	i = ft_strlen(link);
	link[i - 1] = 0;
	return (link);
}

char	*ft_test_pipe(char *name, char *pipe)
{
	char	**tab;

	tab = ft_strsplit(pipe, '-');
	if (ft_strequ(name, tab[0]))
		return (tab[1]);
	else if (ft_strequ(name, tab[1]))
		return (tab[0]);
	else
		return (NULL);
}

