/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:22:28 by mdanish           #+#    #+#             */
/*   Updated: 2023/08/15 13:16:31 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*free_head_tail(char *head, char *middle, char *tail, char *str);
char	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(char const *str, int len);
char	*ft_strjoin_and_free(char *head, char *middle, char *tail);
size_t	ft_strlen(char const *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif
