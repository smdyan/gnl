/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:36:07 by smdyan            #+#    #+#             */
/*   Updated: 2022/01/09 19:24:24 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*pulln(int fd, char *old)
{
	char	*buf;
	int		len;
	int		p_size;
	int		old_len;

	buf = (char *)malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	old_len = 0;
	p_size = BUFFER_SIZE;
	if (old)
	{
		old_len = ft_strlen(old);
		p_size = BUFFER_SIZE - old_len;
		ft_strlcpy(buf, old, old_len + 1);
		free(old);
	}
	len = read(fd, buf + old_len, p_size);
	if (len == -1)
	{
		free(buf);
		return (NULL);
	}
	*(buf + old_len + len) = '\0';
	return (buf);
}

static int	parsen(char *buf, int *n)
{
	char	rep;

	rep = 1;
	while (*n < BUFFER_SIZE && rep == 1)
	{
		if (*(buf + *n) == '\n')
		{
			*n = *n + 1;
			rep = 0;
		}
		else if (*(buf + *n) == '\0')
			rep = -1;
		else
			*n = *n + 1;
	}
	return (rep);
}

static char	*cleanb(char *buf, int *n, int rep)
{
	char	*tmp;
	int		len;

	if (rep == 0)
	{
		len = ft_strlen(buf + *n);
		tmp = (char *)malloc(sizeof(char) * len + 1);
		if (!tmp)
			return (NULL);
		ft_strlcpy(tmp, buf + *n, len + 1);
	}
	else
		tmp = NULL;
	free(buf);
	*n = 0;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		*buf = NULL;
	char			*str;
	int				n;
	int				rep;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	rep = 1;
	n = 0;
	str = NULL;
	while (rep == 1)
	{
		buf = pulln(fd, buf);
		if (!buf)
			return (NULL);
		rep = parsen(buf, &n);
		str = join(str, buf, n);
		buf = cleanb(buf, &n, rep);
	}
	return (str);
}
