/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_cross.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 23:00:36 by nsavry            #+#    #+#             */
/*   Updated: 2014/02/23 23:14:09 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

int		ft_cross_ant(t_anthill *ah)
{
	int		nb;
	int		i;

	nb = ah->nb_ant;
	while (nb != 0)
	{
		i = 0;
		while (ah->path[i + 1] != NULL)
		{
			ft_printf("L%d-%s\n", ah->nb_ant - nb + 1, ah->path[i + 1]);
			i++;
		}
		nb--;
	}
	return (1);
}
