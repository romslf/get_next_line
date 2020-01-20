/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 13:36:14 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 10:50:20 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	ft_extract(char **line, char **tmp)
{
	*line = extract_first_line(*tmp);
	*tmp = extract_last_lines(*tmp);
}

void	add_to_tmp(char **tmp, char *str, int readCnt)
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

int		get_next_line(int fd, char **line)
{
    char		*buffer;
	static char	*tmp;
	int			readCnt;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (-1);
	if ((readCnt = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		add_to_tmp(&tmp, buffer, readCnt);
		if (!ft_linelen(tmp))
			return(get_next_line(fd, line));
		ft_extract(line, &tmp);
		return (1);
	}
	else if (readCnt < 0)
		return (-1);
	ft_extract(line, &tmp);
	if (!tmp || !ft_strlen(tmp))
		return (0);
	return (1);
}