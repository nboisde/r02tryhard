#include "../includes/rush02.h"

int		valid_line(char *line)
{
	int		index_w;

	index_w = 0;
	if (!c_numeric(line[index_w]))
		return (0);
	while (c_numeric(line[index_w]))
		index_w++;
	if (!(c_space(line[index_w]) || c_colon(line[index_w])))
		return (0);
	while (c_space(line[index_w]))
		index_w++;
	if (!c_colon(line[index_w]))
		return (0);
	else
		index_w++;
	while (c_space(line[index_w]))
		index_w++;
	if (index_w == ft_strlen(line))
		return (0);
	return (index_w);
}

int		valid_dict(char **dict)
{
	int		i;

	i = 0;
	while (dict[i])
	{
		if (!valid_line(dict[i]))
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>

int		main(void)
{
	char **file = ft_fsplit("../includes/numbers.dict");

	printf("%i\n", valid_dict(file));
	printf("%i\n", ft_strlen(file[1]));
	printf("%i\n", valid_line(file[1]));
}
*/
