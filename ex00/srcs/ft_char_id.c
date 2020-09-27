/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 01:34:52 by nboisde           #+#    #+#             */
/*   Updated: 2020/09/26 20:17:08 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

int		c_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int		c_numeric(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int		c_printa(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

int		c_colon(char c)
{
	if (c == ':')
		return (1);
	return (0);
}

int		c_nline(char c)
{
	if (c == '\n')
		return (1);
	return (1);
}
