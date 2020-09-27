/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 00:15:58 by nboisde           #+#    #+#             */
/*   Updated: 2020/09/27 01:29:59 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

int		ft_size_tab(char *file)
{
	int				fd;
	char			buf;
	int				line;

	line = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
			line++;
	}
	close(fd);
	return (line);
}

int		*tab_line(char *file)
{
	int		*lengths;
	int		i;
	int		j;
	int		fd;
	char	buf;

	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	if (!(lengths = (int*)malloc(ft_size_tab(file) * sizeof(int))))
		return (0);
	while (i <= ft_size_tab(file))
	{
		j = 0;
		while (read(fd, &buf, 1) > 0 && buf != '\n')
			j++;
		if (i == 0)
			j--;
		read(fd, &buf, 1);
		lengths[i] = j + 2;
		i++;
	}
	close(fd);
	return (lengths);
}

char	*ft_strfdup(char *file, int line)
{
	int		i;
	int		j;
	int		fd;
	char	buf;
	char	*dup;

	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, &buf, 1) > 0 && j < line)
	{
		if (buf == '\n')
			j++;
	}
	if (!(dup = (char*)malloc((tab_line(file)[line]) * sizeof(char))))
		return (0);
	while (j >= 0 && buf != '\n')
	{
		dup[i] = buf;
		i++;
		j = read(fd, &buf, 1);
	}
	dup[i] = '\0';
	close(fd);
	return (dup);
}

char	**ft_fsplit(char *file)
{
	char	**fsplit;
	int		i;
	int		lines;

	i = 0;
	lines = ft_size_tab(file);
	if (!(fsplit = (char**)malloc(((lines) * sizeof(char*)))))
		return (0);
	while (i < lines)
	{
		fsplit[i] = ft_strfdup(file, i);
		i++;
	}
	fsplit[i] = 0;
	return (fsplit);
}
