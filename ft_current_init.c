/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 17:06:18 by nsavry            #+#    #+#             */
/*   Updated: 2014/02/23 23:15:33 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"
#include "libft.h"

void	ft_init_anthill(t_anthill *ah)
{
	ah->nb_ant = 0;
	ah->start = NULL;
	ah->end = NULL;
	ah->room = malloc(sizeof(char *));
	ah->room[0] = NULL;
	ah->pipe = malloc(sizeof(char *));
	ah->pipe[0] = NULL;
	ah->path = malloc(sizeof(char *));
	ah->path[0] = NULL;
	ah->link = malloc(sizeof(char *));
	ah->link[0] = NULL;
}

void	ft_init_name(t_anthill *ah)
{
	int		nb;
	char	**tab_name;
	int		i;

	nb = ft_str_tab_len(ah->room);
	ah->name = malloc(sizeof(char *) * (nb + 1));
	ah->name[nb] = NULL;
	i = 0;
	while (ah->room[i] != NULL)
	{
		tab_name = ft_strsplit(ah->room[i], ' ');
		ah->name[i] = ft_strdup(tab_name[0]);
		free(tab_name);
		i++;
	}
}
