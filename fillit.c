/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiralle <rmiralle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 12:13:29 by rmiralle          #+#    #+#             */
/*   Updated: 2018/01/01 18:36:51 by rmiralle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

static int		ft_valide(char *t)
{
	int i;
	int p;

	i = 0;
	p = 0;
	if (t[4] != '\n' && t[9] != '\n' && t[14] != '\n' && t[19] != '\n')
	{
		printf("%d\n%d\n%d\n%d\n", t[4], t[9], t[14], t[19]);
		return (0);
	}
	while (t[i] == 46 || t[i] == 35 || t[i] == '\n')
	{
		if (t[i] == 35)
		{
			if (t[i - 1] != 35 && t[i + 1] != 35 && t[i - 5] != 35 && t[i + 5] != 35)
				return (0);
			p++;
		}
		i++;
	}
	if (i != 20 || p != 4)
		return (0);
	return (1);
}

char		**ft_piece(char *t)
{
	int		i;
	char	**fraiche;

	i = 0;
	if (!(fraiche = (char)malloc(sizeof(char) * )))
	// while (t[i] != 35)
	// 	i++;
	// printf("%d;%d\n", i/5, i%5);

	return (0);
}

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
		// ft_putstr(buf);
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
