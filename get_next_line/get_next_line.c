/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:21:58 by mnachit           #+#    #+#             */
/*   Updated: 2024/02/17 09:21:30 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

static void	ft_read(int fd, char *buf, char **str, ssize_t i)
{
	char	*tmp;

	if (!*str || !ft_strchr(*str, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		while (i > 0)
		{
			buf[i] = '\0';
			if (!*str)
				*str = ft_substr1(buf, 0, i);
			else
			{
				tmp = *str;
				*str = ft_strjoin(*str, buf);
				free(tmp);
			}
			if (ft_strchr(buf, '\n'))
				break ;
			i = read(fd, buf, BUFFER_SIZE);
		}
	}
	if (i == -1)
		ft_free(*&str);
	free(buf);
}

static char	*ft_finish(char **str)
{
	char	*ret;
	char	*tmp;
	int		i;
	int		j;

	if (!*str)
		return (NULL);
	if (!ft_strchr(*str, '\n'))
	{
		ret = ft_substr1(*str, 0, ft_strlen1(*str));
		ft_free(*&str);
		return (ret);
	}
	i = ft_strlen1(*str);
	j = ft_strlen1(ft_strchr(*str, '\n'));
	ret = ft_substr1(*str, 0, i - j + 1);
	tmp = *str;
	*str = ft_substr1(ft_strchr(*str, '\n'), 1, j - 1);
	if (!*str)
		return (NULL);
	free(tmp);
	if (**str == '\0')
		ft_free(*&str);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	ssize_t		i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	ft_read(fd, buf, &str, i);
	return (ft_finish(&str));
}
