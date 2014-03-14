/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 22:04:29 by nsavry            #+#    #+#             */
/*   Updated: 2014/02/23 22:57:48 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int		ft_error(int error)
{
	if (error == 0)
		ft_putendl_fd("Lem-In: Parse Error\nInvalid Number of Ant", 2);
	else if (error == 1)
		ft_putendl_fd("Lem-In: Parse Error\nNo Start in Anthill", 2);
	else if (error == 2)
		ft_putendl_fd("Lem-In: Parse Error\nNo End in Anthill", 2);
	else if (error == 3)
		ft_putendl_fd("Lem-In: Parse Error\nNo Pipes Referenced", 2);
	else if (error == 4)
		ft_putendl_fd("Lem-In: Parse Error\nRoom With Same Name", 2);
	else if (error == 5)
		ft_putendl_fd("Lem-In: Parse Error\nRoom With Same Coordinate", 2);
	else if (error == 6)
		ft_putendl_fd("Lem-In: Solve Error\nNo Way Found", 2);
	return (-1);
}
