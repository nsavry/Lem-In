/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 20:41:21 by nsavry            #+#    #+#             */
/*   Updated: 2014/02/23 23:08:56 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lem_in.h"

int		main(void)
{
	t_anthill	*ah;

	ah = malloc(sizeof(*ah));
	ft_init_anthill(ah);
	if (ft_mount_anthill(ah) == -1)
		return (-1);
	if (ah->pipe[0] == NULL)
		return (ft_error(3));
	ft_link_room(ah);
	ft_init_name(ah);
	if (ft_find_path(ah) == 1)
	{
		ft_print_anthill(ah);
		ft_cross_ant(ah);
	}
	else
		ft_error(6);
	return (0);
}
