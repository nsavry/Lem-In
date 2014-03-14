/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 16:45:13 by nsavry            #+#    #+#             */
/*   Updated: 2014/02/23 17:53:53 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"
#include "libft.h"

void	ft_print_anthill(t_anthill *ah)
{
	char	**tab;
	int		i;

	i = 0;
	ft_printf("%d\n", ah->nb_ant);
	while (ah->room[i] != NULL)
	{
		tab = ft_strsplit(ah->room[i], ' ');
		if (ft_strequ(tab[0], ah->start))
			ft_printf("##start\n");
		else if (ft_strequ(tab[0], ah->end))
			ft_printf("##end\n");
		free(tab);
		ft_printf("%s\n", ah->room[i]);
		i++;
	}
	ft_put_str_tab(ah->pipe);
	ft_putchar('\n');
}

