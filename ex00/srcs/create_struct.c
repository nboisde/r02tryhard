#include "../includes/rush02.h"

/*
** We take as a truth that the dict is already valid.
*/

int		len_num(char *line)
{
	int i;

	i = 0;
	while (c_numeric(line[i]))
		i++;
	return (i - 1);
}

/*
** create elem as valid or non valid.
*/

int		get_end(char *line)
{
	int i;
	int j;

	i = valid_line(line);
	j = 0;
	while (line[i + j])
		j++;
	return(j + 1);
}

t_dict		create_dict_null(void)
{
	t_dict	elem;

	elem.num = 0;
	elem.lettr = 0;
	elem.deal = 0;
	return (elem);
}

t_dict		create_dict_elem(char *line)
{
	t_dict		elem;
	int			i;

	i = 0;
	if (!(elem.num = malloc((len_num(line) + 1) * sizeof(char))))
		return (create_dict_null());
	while (i <= len_num(line))
	{
		elem.num[i] = line[i];
		i++;
	}
	elem.num[i] = '\0';
	//elem.deal = (line[0] = '1') ? 2 : 0;
	//if (i == 2 || (i == 3 && line[1] == '0')|| (i == 4 && line[1] == '0'
	//			&& line[2] == '0'))
	elem.deal = 1;
	i = valid_line(line) - 1;
	if (!(elem.lettr = malloc((get_end(line) + 1) * sizeof(char))))
		return (create_dict_null());
	while (++i < ft_strlen(line))
		elem.lettr[i - valid_line(line)] = line[i];
	elem.lettr[i - valid_line(line)] = '\0';
	return (elem);
}

t_dict		*create_dict(char **dict)
{
	t_dict		*lang;
	int			len_dict;

	len_dict = 0;
	while (dict[len_dict])
		len_dict++;
	if (!(lang = (t_dict*)malloc((len_dict + 1) * sizeof(t_dict))))
		return (NULL);
	len_dict = 0;
	while (dict[len_dict])
	{
		lang[len_dict] = create_dict_elem(dict[len_dict]);
		len_dict++;
	}
	lang[len_dict] = create_dict_null();
	return (lang);
}

#include <stdio.h>

int		main(/*int ac, char **av*/void)
{
	char		**dict = ft_fsplit("../includes/numbers.dict");
	t_dict		*lang = create_dict(dict);
	int			i;
	int			dict_len;

	i = 0;
	dict_len = 0;
	set_deal_hun(lang);
	set_deal_bigs(lang);
	while (dict[dict_len])
	{
//		printf("================================\n");
//		printf("%s\n", dict[dict_len]);
//		printf("strlen %i\n", ft_strlen(dict[dict_len]));
//		printf("get_end %i\n", get_end(dict[dict_len]));
//		printf("valid_line %i\n", valid_line(dict[dict_len]));
//		printf("len_num %i\n", len_num(dict[dict_len]));
		dict_len++;
	}
	//printf("Show the language:\n");
	while (i <= dict_len)
	{
		//printf("Original line:\n");
		//printf("%s\n", dict[i]);
		//printf("valid line res%i:\n", valid_line(dict[i]));
		//printf("get_end %i\n", get_end(dict[i]));
		printf("word number %i:\n", i);
		printf("number :%s\n", lang[i].num);
		printf("letters :%s\n", lang[i].lettr);
		printf("deal: %i\n", lang[i].deal);
		printf("===================================\n");
		i++;
	}
//	if (ac == 2)
//	{
//		t_num		analyse = create_nbr(av[1]);
//		printf("Number to analyse\n");
//		printf("argument: %s\n", analyse.av);
//		printf("len: %i\n", analyse.len);
//		i = 0;
//		printf("bundle:\n");
//		while (analyse.bun[i].bun[0])
//		{
//			printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
//			printf("[ %s ]\n", analyse.bun[i].bun);
//			printf("unit: %i\n", analyse.bun[i].unit);
//			printf("dec: %i\n", analyse.bun[i].dec);
//			printf("hun: %i\n", analyse.bun[i].hun);
//			i++;
//		}
//	}
}

