/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiralle <rmiralle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 12:13:29 by rmiralle          #+#    #+#             */
/*   Updated: 2018/01/05 18:46:53 by rmiralle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	buf[21];
	char	space;

	i = 1;
	fd = open(argv[i], O_RDONLY);
	ft_bzero(buf, 21);
	if (argc != 2)
		return (0);
	while (read(fd, buf, 20) != 0)
	{
		read(fd, &space, 1);
		if (space != '\n' || (ft_valide(buf) == 0))
		{
			ft_putstr("error\n");
			return (0);
		}
		ft_piece(buf);
		ft_bzero(buf, 21);
	}
	return (0);
}
