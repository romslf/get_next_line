/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 13:36:14 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 15:20:23 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substrdup(char *s, unsigned long start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*tab;

	count = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (NULL);
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
	free(s);
	return (tab);
}

char	*ft_substr(char *s, unsigned long start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*tab;

	count = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (NULL);
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

int		ft_extract(char **line, char **tmp, long index)
{
	*line = ft_substr(*tmp, 0, index);
	*tmp = ft_substrdup(*tmp, index + 1, ft_strlen(*tmp) - index);
	return (1);
}

int		ft_tmp_init(char **tmp)
{
	if (!*tmp)
	{
		if (!(*tmp = malloc(sizeof(char))))
			return (-1);
		*tmp[0] = '\0';
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*tmp;
	long		readcnt;
	long		index;

	if (!line || BUFFER_SIZE <= 0 || (readcnt = read(fd, 0, 0)) < 0 ||
		ft_tmp_init(&tmp) < 0)
		return (-1);
	readcnt = 1;
	while (!(index = ft_linelen(tmp)) && readcnt != 0)
	{
		readcnt = read(fd, buffer, BUFFER_SIZE);
		buffer[readcnt] = '\0';
		tmp = ft_strjoin(tmp, buffer);
	}
	(index < 0) ? index = 0 : index;
	if (readcnt == 0)
	{
		*line = ft_substr(tmp, 0, ft_strlen(tmp));
		free(tmp);
		tmp = NULL;
		return (0);
	}
	return (ft_extract(line, &tmp, index));
}
