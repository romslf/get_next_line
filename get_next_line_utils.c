/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 15:54:39 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 19:04:39 by rolaforg    ###    #+. /#+    ###.fr     */
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
	if (!s1)
		return (ft_substr((char *)s2, 0, ft_linelen((char *)s2)));
	if (!s2)
		return (NULL);
	if (!(res = malloc(sizeof(char) * (ft_strlen((char *)s1) +
		ft_strlen((char *)s2) + 1))))
		return (NULL);
	while (s1[i])
		res[x++] = s1[i++];
	free((void *)s1);
	i = 0;
	while (s2[i])
		res[x++] = s2[i++];
	res[x] = '\0';
	return (res);
}

char	*ft_memchr(char *s, int c, size_t n)
{
	unsigned char	chr;
	char			*str;

	if (s && n)
	{
		str = s;
		chr = (unsigned char)c;
		while (n--)
		{
			if (*str == chr)
			{
				str++;
				return (str);
			}
			str++;
		}
		if ((char)c == '\0')
			return (str);
	}
	return (NULL);
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
	if (!str)
		return (0);
	if (str[0] == '\n')
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}
