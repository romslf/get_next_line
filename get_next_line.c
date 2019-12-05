/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 13:36:14 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 19:29:06 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
    int         readedCnt;
	int			linesCnt;
	char		*tmp;
    static char *buffer;

    if (!(buffer = malloc(sizeof(char) * BUFFER_SIZE + 1)))
        return (-1);
	readedCnt = read(fd, buffer, BUFFER_SIZE);
	linesCnt = count_lines(buffer);
    
	if (readedCnt == BUFFER_SIZE)
    {
        return (1);
    }
    else if (readedCnt < BUFFER_SIZE && readedCnt > -1)
        return (0);
    else
        return (-1);
}

int main()
{
    const int fd = open("file.txt", O_RDONLY);
    char *str;
    for (int i; i < 20; i++)
        printf("%d\n", get_next_line(fd, &str));
}