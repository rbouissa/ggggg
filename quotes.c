

#include "minishell.h"

int	size_of_quotes(char *string)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (string[i])
	{
		if (string[i] == 39)
		{
			i++;
			while (string[i] && string[i] != 39)
			{
				j++;
				i++;
			}
			if (string[i])
				continue ;
		}
		if (string[i] == 34)
		{
			i++;
			while (string[i] && string[i] != 34)
			{
				j++;
				i++;
			}
			if (string[i])
				continue ;
		}
		i++;
	}
	return (j);
}

char	*string_no_quotes(char *str)
{
	char	*string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	string = malloc(size_of_quotes(str));
	while (str[i])
	{
		if (str[i] == 39)
		{
			i++;
			while (str[i] && str[i] != 39)
			{
				string[j] = str[i];
				i++;
				j++;
			}
			if (str[i])
				continue ;
		}
		if (str[i] == 34)
		{
			i++;
			while (str[i] && str[i] != 34)
			{
				string[j] = str[i];
				i++;
				j++;
			}
			if (str[i])
				continue ;
		}
		string[j] = str[i];
		i++;
		j++;
	}
    return string;
}
// char	*remove_quotes(t_list *node)
// {
// 	t_list	*tmp;
// 	int		i;

// 	i = 0;
// 	while (tmp)
// 	{
// 		if (tmp->token = 0)
// 		{
// 			while (tmp->data[i])
// 			{
// 				if (tmp->data[i] == 39)
// 				{
// 				}
// 				i++;
// 			}
// 		}
// 		tmp = tmp->next;
// 	}
// }
