/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:39:13 by smdyan            #+#    #+#             */
/*   Updated: 2022/01/09 19:39:28 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlcpy(char *dst, char *src, int size)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (*(src + len))
		len++;
	if (size == 0)
		return (len);
	size--;
	while ((size > 0) && (i < len))
	{
		*(dst + i) = *(src + i);
		size--;
		i++;
	}
	*(dst + i) = '\0';
	return (len);
}

int	ft_strlen(char *s)
{
	int	n;

	if (!s)
		return (0);
	n = 0;
	while (*(s + n) != '\0')
		n++;
	return (n);
}

char	*join(char *s1, char *s2, int n)
{
	char	*str;
	int		len_s1;

	if (!n)
		return (s1);
	len_s1 = ft_strlen(s1);
	if (!s1)
		s1 = malloc(0);
	str = (char *) malloc(sizeof (char) * (len_s1 + n + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, (len_s1 + 1));
	ft_strlcpy((str + len_s1), s2, (n + 1));
	free(s1);
	return (str);
}
