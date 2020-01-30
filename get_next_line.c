/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 13:36:14 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 18:36:37 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char        *ft_substr(char *s, unsigned int start, size_t len)
{
    size_t  count;
    size_t  size;
    char    *tab;
    count = 0;
    if (!s)
        return (NULL);
    if (ft_strlen(s) < start)
        return (ft_calloc(1, 1));
    size = ft_strlen(s + start);
    if (size < len)
        len = size;
    if (!(tab = (char *)malloc((len + 1) * sizeof(char))))
        return (NULL);
    while (count < len)
    {
        tab[count] = s[start + count];
        count++;
    }
    tab[count] = '\0';
    return (tab);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*p;

	i = 0;
	if (!(p = malloc(count * size)))
		return (NULL);
	while (size--)
		p[size] = 0;
	return (p);
}

int		ft_extract(char **line, char **tmp, int index)
{
	if (!tmp)
	{
		*line = ft_calloc(1, sizeof(char));
		return (1);
	}
	*line = ft_substr(*tmp, 0, index);
	*tmp = ft_substr(*tmp, index + 1, ft_strlen(*tmp) - index);
	return (1);
}

int		get_next_line(int fd, char **line)
{
    char		*buffer;
	static char	*tmp;
	int			readCnt;
	int			index;

	if (!line || BUFFER_SIZE <= 0 || (readCnt = read(fd, 0, 0)) < 0)
			return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!tmp)
	{
		if (!(tmp = malloc(1)))
			return (-1);
		tmp[0] = '\0';
	}
	readCnt = 1;
	while (!(index = ft_linelen(tmp)) && (readCnt = read(fd, buffer, BUFFER_SIZE)) != 0)
	{
		buffer[readCnt] = '\0';
		tmp = ft_strjoin(tmp, buffer);
	}
	if (index < 0)
		index = 0;
	if (readCnt == 0)
	{
		*line = ft_substr(tmp, 0, ft_strlen(tmp));
		tmp = NULL;
		return (0);
	}
	
	return (ft_extract(line, &tmp, index));
}

// char	*extract_last_lines(char *str)
// {
// 	char *res;

// 	res = ft_memchr(str, '\n', ft_strlen(str));
// 	return (res);
// }

// void	ft_extract(char **line, char **tmp)
// {
// 	*line = ft_substr(*tmp, 0, ft_linelen(*tmp) - 1);
// 	*tmp = extract_last_lines(*tmp);
// }

// void	add_to_tmp(char **tmp, char *str)
// {
// 	// size_t	i;
	
// 	// i = 0;
// 	// if (!*tmp)
// 	// 	*tmp = str;
// 	// else
// 	*tmp = ft_strjoin(*tmp, str);
// }
