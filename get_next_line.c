/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 13:36:14 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 17:15:21 by rolaforg    ###    #+. /#+    ###.fr     */
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
	*line = ft_substr(*tmp, 0, index);
	*tmp = ft_substr(*tmp, index + 1, ft_strlen(*tmp) - index);
	return (1);
}

int		get_next_line(int fd, char **line)
{
    char		buffer[BUFFER_SIZE + 1];
	static char	*tmp;
	int			readCnt;
	int			index;

	if (!line || BUFFER_SIZE <= 0 || (readCnt = read(fd, 0, 0)) < 0)
	{
		if (tmp)
		{
			free(tmp);
			tmp = NULL;
		}
		return (-1);
	}
	if (!tmp)
	{
		if (!(tmp = malloc(sizeof(char))))
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
		free(tmp);
		tmp = NULL;
		return (0);
	}
	return (ft_extract(line, &tmp, index));
}

int main()
{
	int fd = open("get_next_line.c", O_RDONLY);
	char *str;
	while (get_next_line(fd, &str))
	{
		printf("%s\n", str);
		free(str);
	}
	printf("%s\n", str);
}
