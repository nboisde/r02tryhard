#include "../includes/rush02.h"

int		len_bundle(t_num arg)
{
	int i;

	i = 0;
	while (arg.bun[i].bun[0])
		i++;
	return (i);
}

void	set_deal_hun(t_dict *lang)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (lang[i].num)
	{
		j = ft_strlen(lang[i].num);
		lang[i].deal = -1;
		if (j == 1 && lang[i].num[0] == '0')
			lang[i].deal = 0;
		if ((j == 1 && lang[i].num[0] != '0') || (j == 2 &&
			lang[i].num[1] == '0') || (j == 3 && lang[i].num[1] == '0' &&
			lang[i].num[2] == '0' && lang[i].num[0] == '1') || (j == 2 &&
			lang[i].num[2] == '1'))
			lang[i].deal = 1;
		i++;
	}
}

void	set_deal_bigs(t_dict *lang)
{
	int		i;
	int		k;
	int		set;

	i = 0;
	k = 0;
	set = 1;
	while (lang[i].num)
	{
		if (ft_strlen(lang[i].num) > 3 && lang[i].num[0] == '1')
		{
			k = 1;
			while (lang[i].num[k])
			{
				if (lang[i].num[k] != '0')
					set = 0;
				k++;
			}
			if (set == 1)
				lang[i].deal = (ft_strlen(lang[i].num) / 3) + 1;
		}
		i++;
	}
}
/*
#include <stdio.h>

int		main(int ac, char **av)
{
	t_num arg;

	arg = create_nbr(av[1]);
	if (ac == 2)
	{
		printf("%i", len_bundle(arg));
	}
}
*/
