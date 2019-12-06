/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 15:54:39 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 16:28:33 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char	*remove_line_from_buff(char *buffer, char **line)
{
	size_t	i;
	size_t	x;
	size_t	len;
	printf("%s\n", "Remove line from buffer start");
	len = line_len(buffer);
	if (!(line = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	printf("%s\n", "Filling line");
	while (buffer[i++] != '\n')
		*line[i] = buffer[i];
	i++;
	x = 0;
	printf("%s\n", "Removing line from buffer");
	while (buffer[i])
	{
		buffer[x] = buffer[i];
		x++;
		i++;
	}
	printf("%s\n", "Filling end of buffer");
	while (buffer[x++])
		buffer[x] = '\0';
	printf("%s\n", "Remove line from buffer done.");
	return (buffer);
}

size_t	contain_line(char *str)
{
	size_t	i;
	printf("%s\n", "Contain line");
	i = 0;
	while (str[i++])
		if (str[i] == '\n')
			return (1);
	printf("%s\n", "Contain line len done");
	return (0);
}

size_t	line_len(char *line)
{
	size_t	i;
	printf("%s\n", "Line len start");
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			printf("%s\n", "Line len done");
			return (i);
		}
		i++;
	}
	printf("%s\n", "Line len done");
	return (0);
}