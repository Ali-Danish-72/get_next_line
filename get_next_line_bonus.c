/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:20:03 by mdanish           #+#    #+#             */
/*   Updated: 2023/08/16 18:01:56 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_new_line(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = -1;
	while (line[++i])
	{
		if (line[i] == '\n')
		{
			if (line[i + 1])
				return (i + 1);
		}
	}
	return (0);
}

int	ft_strchr(char const *s)
{
	int	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '\n')
			return (i + 1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*line;
	static char	*save[4096];
	int			new_line;
	int			check_eof;

	line = NULL;
	new_line = 0;
	while (fd > -1 && !new_line && !(ft_strchr(line) == BUFFER_SIZE))
	{
		str = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!str)
			return (free_head_tail(save[fd], str, NULL, NULL));
		check_eof = read(fd, str, BUFFER_SIZE);
		if (check_eof == -1 || (!save[fd] && check_eof == 0))
		{
			save[fd] = free_head_tail(str, save[fd], NULL, NULL);
			break ;
		}
		line = ft_strjoin_and_free(line, save[fd], str);
		save[fd] = NULL;
		new_line = check_new_line(line);
	}
	save[fd] = ft_substr(line, new_line, ft_strlen(line) - (new_line - 1));
	return (line);
}
