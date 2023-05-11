/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:53:36 by met-tahe          #+#    #+#             */
/*   Updated: 2023/05/10 11:13:49 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
char	*get_path()
{
	t_mini	*tmp;
	char	*s;

	s = NULL;
	tmp = my_global->m_env;
	while (tmp)
	{
		if (ft_strcmp(tmp->data_var, "PWD") == 0)
		{
			s = ft_strdup(tmp->data_val);
			break ;
		}
		else
			tmp = tmp->next;
	}
	return (s);
}

void	ft_pwd(void)
{
	char	*rep;

	rep = NULL;
	rep = getcwd(NULL, 1);
	if (rep == NULL)
	{
		rep = get_path();
	}
	printf("%s\n", rep);
	free(rep);
}
