#include "minishell.h"

//<Makefile cat <main.c | wc -l;

// t_global			*my_global;

int	ther_are_pipe(char *str)
{
	int	i;
	int	quotes;

	i = 0;
	quotes = 0;
	while (str[i])
	{
		if (str[i] == '|')
			return (1);
		i++;
	}
	return (0);
}

void	print_cmd(t_cmd *cmd)
{
	int		i;
	t_cmd	*tmp;

	i = 0;
	tmp = cmd;
	while (tmp)
	{
		i = 0;
		while (tmp->cmd && tmp->cmd[i])
		{
			printf("%s\n", tmp->cmd[i]);
			i++;
		}
		printf("infile = %d\n", tmp->infile);
		printf("outfile = %d\n", tmp->outfile);
		i = 0;
		while (tmp->herdoc && tmp->herdoc[i])
		{
			printf("herdoc = %s\n", tmp->herdoc[i]);
			i++;
		}
		tmp = tmp->next;
	}
}

int	alot_of_spliter(char *s)
{
	int	i;

	i = 0;
	while (find_spliter(s[i], "|<> \t"))
		i++;
	if (s[i] && !find_spliter(s[i], "|<> \t"))
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv, char **env)
{
	char			*str;
	t_list			*cmd;
	t_cmd			*commands;
	t_cmd			*tmp;
	t_mini			*mini;
	int				i;
	struct termios	term;
	struct termios	term2;
	char			*str_2;

	i = 0;
	mini = NULL;
	tmp = NULL;
	(void)argc;
	(void)argv;
	str_2 = NULL;
	my_global = malloc(sizeof(t_global));
	mini = env_iniit(env);
	my_global->m_env = mini;
	my_global->m_cmd = NULL;
	my_global->hrdsize = 0;
	my_global->status = 0;
	my_global->hrd = NULL;
	my_global->hrd_id = 0;
	my_global->count_cmd = 0;
	my_global->id = malloc(sizeof(pid_t) * 1);
	my_global->id[0] = 0;
	tcgetattr(0, &term);
	term2 = term;
	term.c_lflag &= ~ISIG;
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &term);
	signal(SIGINT, ctrlc_handler);
	signal(SIGQUIT, ctrld_handler);
	while (1)
	{
		str = readline("minishell>");
		if (!str)
		{
			write(1, "exit\n", 5);
			exit(0);
		}
         //printf("----|||||---%s\n",new_expand(str,mini));
        //  printf("%d\n",check_eroor(str));
		str_2 = new_expand(str, mini);
       
        //printf("ehre00%s\n",str_2);
        //str_2=string_no_quotes(str_2);
        // printf("hhhhh\n");
        // printf("size_ofquotes  %s\n",string_no_quotes(str_2));
        // printf("%s\n",str_2);
		if (str_2!=NULL && alot_of_spliter(str_2)&&check_eroor(str_2))
		{
			//add expanding variables
			if (str_2[0])
			{
				// s = split_command(str);
				cmd = ft_split_them(str_2);
                //printf("size_of%d\n",size_of_quotes(str_2));
                //printf("->>>%s\n->>>>>",cmd->data);
                //printf("->>>%s\n->>>>>",cmd->next->data);
                // printf("%s\n",cmd->data);
                // printf("%d\n",cmd->next->token);
				commands = split_to_commands(cmd);
				if (commands == NULL)
					continue ;
				tmp = commands;
			//print_cmd(commands);
				 if (commands->outfile != -1 && commands->outfile != -1)
					exec_cmd(mini, commands, env);
			}
		}
		add_history(str);
		free(str);
	}
}

//printf("kkk\n");
// if(commands->cmd[0]==NULL)
// printf("yes\n");
// while (commands)
// {
// 	// 	while (commands->cmd[i])
// 	// 	{
// 	// 		printf("%s\n", commands->cmd[i]);
// 	// 		i++;
// 	// 	}
// 		i = 0;
// 		if (commands->cmd[i] == NULL)
// 		printf("%s\n", commands->cmd[i]);
// 	while (commands->cmd[i])
// 	{
// 		printf("command==");
// 		printf("%s\n", commands->cmd[i]);
// 		i++;
// 	}
// 	i = 0;
// 	if (commands->herdoc[i] == NULL)
// 		printf("%s\n", commands->herdoc[i]);
// 	else
// 	{
// 		while (commands->herdoc[i])
// 		{
// 			printf("herdoc==");
// 			printf("%s\n", commands->herdoc[i]);
// 			i++;
// 		}
// 	}
// 		printf("%d\n", commands->infile);
// 		printf("%d\n", commands->outfile);
// 	// printf("%d\n", commands->herdoc_token);
// 	commands = commands->next;
// 	//printf("kllko\n");
// }