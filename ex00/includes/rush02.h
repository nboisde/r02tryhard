/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 23:58:55 by nboisde           #+#    #+#             */
/*   Updated: 2020/09/27 00:12:19 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

/*
** deal = 1, 2 or 0. 0 says we don't consider this num in analysis.
*/

typedef struct		s_dict
{
	char	*num;
	char	*lettr;
	int		deal;
}					t_dict;

typedef struct		s_bundle
{
	char	bun[4];
	int		unit;
	int		dec;
	int		hun;
}					t_bundle;

typedef struct		s_num
{
	char		*av;
	int			len;
	t_bundle	*bun;
}					t_num;

int		c_space(char c);

int		c_numeric(char c);

int		c_printa(char c);

int		c_colon(char c);

int		c_nline(char c);

char	**ft_fsplit(char *file);

int		ft_strlen(char *str);

void	ft_putstr(char *str);

t_num	create_nbr(char *av);

int		valid_line(char *line);

int		valid_dict(char **dict);

t_dict	*create_dict(char **dict);

#endif
