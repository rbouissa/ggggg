/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:53:00 by met-tahe          #+#    #+#             */
/*   Updated: 2023/05/11 15:03:56 by rbouissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    echo(char **cmd)
{
    int        n;
    int        nb_arg;
    size_t    i;

    i = 0;
    n = 0;
    nb_arg = 1;
    if (cmd[1])
    {
        if(ft_strcmp(cmd[1], "-n") == 0)
        {
            n = 1;
            nb_arg = 2;
        }
    }
    while (cmd[nb_arg])
    {
        if(ft_strcmp(cmd[nb_arg], "-n") == 0)
        {
            n = 1;
            nb_arg++;
            continue ;
        }
        printf("%s", cmd[nb_arg]);
        nb_arg++;
        if (cmd[nb_arg])
            printf(" ");
    }
    if (n == 0)
        printf("\n");
}
// int	main(int c, char **v)
// {
// 	(void)c;
// 	echo(v);
// }