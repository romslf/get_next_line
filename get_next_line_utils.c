/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: romainlaforgue <romainlaforgue@student.    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 15:54:39 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 16:10:38 by romainlafor ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	x;
	char	*res;

	i = 0;
	x = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(res = malloc(sizeof(char) * (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1))))
		return (NULL);
	while (s1[i])
		res[x++] = s1[i++];
	i = 0;
	while (s2[i])
		res[x++] = s2[i++];
	res[x] = '\0';
	return (res);
}

void add_to_tmp(char **tmp, char *str, int readCnt)
{
	size_t	i;
	
	i = 0;
	str[readCnt] = '\0';
	if (!*tmp)
	{
		*tmp = str;
	}
	else
		*tmp = ft_strjoin(*tmp, str);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		chr;
	const unsigned char	*str;
	
	if (s && n)
	{
		str = s;
		chr = (unsigned char)c;
		while (n--)
		{
			if (*str == chr)
			{
				str++;
				return ((void *)str);
			}
			str++;
		}
		if ((char)c == '\0')
			return ((void *)str);
	}
	return (NULL);
}

char	*extract_first_line(char *str)
{
	size_t	i;
	char	*res;
	int		len;

	len = ft_linelen(str);
	if (len == 0)
	 	len = ft_strlen(str);
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*extract_last_lines(char *str)
{
	char *res;

	res = ft_memchr(str, '\n', ft_strlen(str));
	return (res);
}

size_t	ft_strlen(char *str)
{
	size_t	i;
	
	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_linelen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i++])
	{
		if (str[i] == '\n')
			return (i + 1);
	}
	return (0);
}