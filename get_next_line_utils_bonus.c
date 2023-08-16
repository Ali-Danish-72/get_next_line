/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanish <mdanish@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:04:33 by mdanish           #+#    #+#             */
/*   Updated: 2023/08/16 13:49:12 by mdanish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char const *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*free_head_tail(char *head, char *middle, char *tail, char *str)
{
	if (head)
		free(head);
	if (middle)
		free(middle);
	if (tail)
		free(tail);
	return (str);
}

char	*ft_strjoin_and_free(char *head, char *middle, char *tail)
{
	int		len_head;
	int		len_middle;
	int		len_tail;
	int		total_len;
	char	*str;

	len_head = ft_strlen(head);
	len_middle = ft_strlen(middle);
	len_tail = ft_strlen(tail);
	total_len = len_head + len_middle + len_tail;
	str = (char *)malloc(sizeof(char) * total_len + 1);
	if (!str)
		return (0);
	str[total_len] = '\0';
	while (len_tail--)
		str[--total_len] = tail[len_tail];
	while (len_middle--)
		str[--total_len] = middle[len_middle];
	while (len_head--)
		str[--total_len] = head[len_head];
	return (free_head_tail(head, middle, tail, str));
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*str;

	if (!start || !s)
		return (0);
	if (!*s)
		len = 0;
	else
	{
		s_len = ft_strlen(s);
		if (s_len <= len)
			len = s_len - start;
		if ((start + len) > s_len)
			len--;
		if (s_len < start || (len == (unsigned long)-1))
			len = 0;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
		str[len] = s[start + len];
	s[start] = '\0';
	return (str);
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	int		len;

	if (count > UINT32_MAX)
		return (NULL);
	len = count * size;
	ptr = (char *)malloc(len);
	if (!ptr)
		return (NULL);
	while (len--)
		ptr[len] = '\0';
	return (ptr);
}
