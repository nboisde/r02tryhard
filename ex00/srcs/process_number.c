/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:01:14 by nboisde           #+#    #+#             */
/*   Updated: 2020/09/27 02:16:20 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

int		valid_num(char *av)
{
	int		i;

	i = 0;
	while (av[i] && c_space(av[i]))
		i++;
	while (av[i] && c_numeric(av[i]))
		i++;
	while (av[i] && c_space(av[i]))
		i++;
	if (i == ft_strlen(av))
		return (1);
	return (0);
}

char	*cut_spaces(char *av)
{
	int		i;
	int		j;
	char	*cut;

	i = 0;
	j = 0;
	while (av[i] && c_space(av[i]))
		i++;
	while (av[i + j] && c_numeric(av[i + j]))
		j++;
	if (!(cut = (char*)malloc((j + 1) * sizeof(char))))
		return (0);
	j = 0;
	while (c_numeric(av[i]) && av[i])
	{
		cut[j] = av[i];
		i++;
		j++;
	}
	cut[j] = '\0';
	return (cut);
}

t_bundle	first_bundle(char *av)
{
	int			i;
	t_bundle	bun;

	bun.bun[3] = '\0';
	i = -1;
	while (++i < 3)
		bun.bun[i] = '0';
	if ((ft_strlen(cut_spaces(av)) % 3) == 1)
		bun.bun[2] = cut_spaces(av)[0];
	if ((ft_strlen(cut_spaces(av)) % 3) == 2)
	{
		bun.bun[1] = cut_spaces(av)[0];
		bun.bun[2] = cut_spaces(av)[1];
	}
	if ((ft_strlen(cut_spaces(av)) % 3) == 0)
	{
		bun.bun[0] = cut_spaces(av)[0];
		bun.bun[1] = cut_spaces(av)[1];
		bun.bun[2] = cut_spaces(av)[2];
	}
	bun.unit = (bun.bun[2] != '0') ? 1 : 0;
	bun.dec = (bun.bun[1] != '0') ? 1 : 0;
	bun.hun = (bun.bun[0] != '0') ? 1 : 0;
	return (bun);
}

t_bundle	create_bundle(char *str)
{
	int i;
	t_bundle bun;

	i = 0;
	while (i < 3)
	{
		bun.bun[i] = str[i];
		i++;
	}
	bun.bun[3] = '\0';
	bun.unit = (bun.bun[2] != '0') ? 1 : 0;
	bun.dec = (bun.bun[1] != '0') ? 1 : 0;
	bun.hun = (bun.bun[0] != '0') ? 1 : 0;
	return (bun);
}

t_num		create_nbr(char *av)
{
	t_num		nbr;
	int			i;
	int			l;

	nbr.len = ft_strlen(cut_spaces(av));
	i = 3;
	l = 1;
	if (!(nbr.av = (char*)malloc((nbr.len + 1) * sizeof(char))))
		return (nbr);
	if (!(nbr.bun = (t_bundle*)malloc(((nbr.len / 3)) * sizeof(t_bundle))))
		return (nbr);
	nbr.bun[0] = first_bundle(av);
	if (nbr.bun[0].dec == 1 && nbr.bun[0].hun == 0)
		i = 2;
	if (nbr.bun[0].unit == 1 && nbr.bun[0].dec == 0 && nbr.bun[0].hun == 0)
		i = 1;
	while (l <= nbr.len / 3 + 1)
	{
		nbr.bun[l] = create_bundle(&cut_spaces(av)[i]);
		l++;
		i += 3;
	}
	nbr.av = cut_spaces(av);
	return (nbr);
}
/*
#include <stdio.h>

int		main(int ac, char **av)
{
	//t_bundle	bun;
	t_num		nbr;

	if (ac == 2)
	{
		//printf("%i\n", valid_num(av[1]));
		if (valid_num(av[1]))
		{
			//ft_putstr(cut_spaces(av[1]));
			//ft_putstr("\n");
			//bun = first_bundle(av[1]);
			//ft_putstr(bun.bun);
			//printf("\n%i\n", bun.unit);
			nbr = create_nbr(av[1]);
			//printf("%i\n", nbr.len);
			//printf("%s\n", nbr.av);
			int i;
			i = 0;
			while (i <= nbr.len / 3)
			{
				printf("%s\n", nbr.bun[i].bun);
				i++;
			}
		}
		return (1);
	}
	return (0);
}
*/
