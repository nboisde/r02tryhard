#include "../includes/rush02.h"

void	translate_hun(t_bundle bundle, t_dict *lang)
{
	int i;

	i = 0;
	if (bundle.hun == 1)
	{
		i = 0;
		if (bundle.bun[0] != '0')
		{
			while (ft_strlen(lang[i].num) == 1)
			{
				if (bundle.bun[0] == lang[i].num[0])
				{
					ft_putstr(lang[i].lettr);
					ft_putstr(" ");
				}
				i++;
			}
		}
		while (ft_strlen(lang[i].num) == 2)
			i++;
		if (lang[i].num[2] == '0' && lang[i].num[1] == '0')
			ft_putstr(lang[i].lettr);
		ft_putstr(" ");
	}
}

void	translate_unit(t_bundle bundle, t_dict *lang)
{
	int i;

	i = 0;
	if (bundle.unit == 1)
	{
		if (bundle.bun[2] != '0' && bundle.bun[1] != '1')
		{
			while (ft_strlen(lang[i].num) == 1)
			{
				if (bundle.bun[2] == lang[i].num[0])
				{
					ft_putstr(lang[i].lettr);
				}
				i++;
			}
		}
	}
}

void	translate_dec(t_bundle bundle, t_dict *lang)
{
	int i;

	i = 0;
	if (bundle.bun[1] == '1')
	{
		while (ft_strlen(lang[i].num) != 2)
			i++;
		while (lang[i].num[1] != bundle.bun[2])
			i++;
		ft_putstr(lang[i].lettr);
		ft_putstr(" ");
		return ;
	}
	while (ft_strlen(lang[i].num) == 1)
		i++;
	while (bundle.bun[1] != lang[i].num[0])
		i++;
	ft_putstr(lang[i].lettr);
	ft_putstr(" ");
	if (bundle.unit == 1)
		translate_unit(bundle, lang);
}

//void	translate_all()

#include <stdio.h>

int		main(int ac, char **av)
{
	char **s = ft_fsplit("../includes/numbers.dict");
	t_dict *lang = create_dict(s);
//	int j = 0;
//	while (lang[j].num)
//	{
//		printf("len %i\n", ft_strlen(lang[j].num));
//		ft_putstr(lang[j].num);
//		ft_putstr("\n");
//		j++;
//	}
	set_deal_hun(lang);
	//set_deal_bigs(lang);
	if (ac == 2)
	{
		t_num a = create_nbr(av[1]);
		int i = 0;
		while (a.bun[i].bun[0])
		{
			//ft_putstr(a.bun[i].bun);
			translate_hun(a.bun[i], lang);
			translate_dec(a.bun[i], lang);
			//translate_unit(a.bun[i], lang);
			//ft_putstr("\n");
			i++;
		}
	}
}
