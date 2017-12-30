/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiralle <rmiralle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 12:13:29 by rmiralle          #+#    #+#             */
/*   Updated: 2017/12/30 19:41:39 by rmiralle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int		ft_valide(char *t)
{
	(void) t;
	return (0);
}


int		main(int argc, char **argv)
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
		ft_putstr(buf);
		ft_bzero(buf, 21);
		read(fd, &space, 1);
	}
	return (0);
}
