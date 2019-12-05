/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 15:54:39 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 19:15:49 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

// char    *fill_line(char **line, char *oldBuffer, char *newBuffer)
// {

// }

size_t  line_is_complete(char **line)
{
    char *tmp;

    tmp = *line;
    while (*tmp != '\0')
    {
        if (*tmp == '\n')
            return (1);
        tmp++;
    }
    return (0);
}

size_t  count_lines(char *text)
{
    size_t  i;
    size_t  cnt;

    i = 0;
    cnt = 0;
	while (text[i])
	{
		if (text[i] == '\n')
    		cnt++;
		i++;
	}
	return (cnt);
}

size_t	line_len(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\n')
		i++;
	return (i);
}