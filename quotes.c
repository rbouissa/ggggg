

#include "minishell.h"
int	size_of_quotes(char *c)
{
    int i;
    int j;
    i= 0 ;
    j = 0;
    while (c[i] != '\0')
    {
        if (c[i] == '\"')
        {
            i++;
            while (c[i] && c[i] != '\"')
                {
                    i++;
                    j++;
                }
            if (c[i])
                i++;
            continue ;
        }
        if (c[i] == '\'')
        {
            i++;
            while (c[i] && c[i] != '\'')
                {
                    i++;
                    j++;
                }
            if (c[i])
                i++;
            continue ;
        }
        i++;
        j++;
    }
    //printf("i%s--------->%i\n",c,j);
    return (j);
}
// int	size_of_quotes(char *string)
// {
// 	int	i;
// 	int	j;
// 	int	e;

// 	j = 0;
// 	i = 0;
// 	e = 0;
// 	while (string[i])
// 	{
// 		if (string[i] == 39)
// 		{
			
// 			while (string[++i] && string[i] != 39)
// 			{
// 				j++;
				
// 			}
// 			if (string[i])
// 				{ continue ;}
// 		}
// 		if (string[i] == 34)
// 		{
			
// 			while (string[++i] && string[i] != 34)
// 			{
// 				j++;
				
// 			}
// 			if (string[i])
// 				{ continue ;}
// 		}
// 		e++;
// 		i++;
// 	}
// 	return (e+j);
// }

char	*string_no_quotes(char *str)
{
	char	*string;
	int		i;
	int		j;

	i = 0;
	j = 0;
    int t = size_of_quotes(str);
	string = malloc(t + 1);
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
            {
                i++;
				continue ;
            }
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
            {
                i++;
				continue ;
            }
		}
		string[j] = str[i];
		i++;
		j++;
	}
    //dprintf(2, "t = [%d]\n", t);

    string[j] = '\0';
    //printf("kkkkkkkk\n");
	return (string);
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
// 			tmp->data=string_no_quotes(tmp->data);
//         }
// 		tmp = tmp->next;
// 	}
// }
