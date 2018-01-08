/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiralle <rmiralle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:42:59 by rmiralle          #+#    #+#             */
/*   Updated: 2018/01/05 19:43:35 by rmiralle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_valide(char *t)
{
	int i;
	int p;

	i = 0;
	p = 0;
	if (t[4] != '\n' && t[9] != '\n' && t[14] != '\n' && t[19] != '\n')
		return (0);
	while (t[i] == 46 || t[i] == 35 || t[i] == '\n')
	{
		if (t[i] == 35)
		{
			if (t[i - 1] != 35 && t[i + 1] != 35 &&
                t[i - 5] != 35 && t[i + 5] != 35)
				return (0);
			p++;
		}
		i++;
	}
	if (i != 20 || p != 4)
		return (0);
	return (1);
}

char		**ft_piece_malloc(void)
{
	int		i;
	char	**fraiche;

	i = 0;
	if (!(fraiche = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	while (i < 5)
	{
		if (!(fraiche[i++] = (char *)malloc(sizeof(char) * 4)))
			return (NULL);
	}
	return (fraiche);
}

void		ft_print_piece(char **t)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			ft_putchar(t[i][j]);
			j++;
		}
		i++;
	}
    ft_putchar('\n');
}

char		**ft_piece(char *t)
{
	int		i;
	int		x;
	int		y;
	char	**fraiche;

	i = 0;
	x = 0;
	y = 0;
	fraiche = ft_piece_malloc();
	while (t[i])
	{
		if (t[i] == '\n')
		{
			x++;
			y = 0;
		}
		fraiche[x][y] = t[i];
		y++;
		i++;
	}
	ft_print_piece(fraiche);
	return (fraiche);
}
