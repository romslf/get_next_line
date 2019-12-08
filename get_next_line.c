/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 13:36:14 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/08 16:19:41 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
    int         readedCnt;
    static char *buffer;

	// Init
	readedCnt = 0;
    if (!(buffer = malloc(sizeof(char) * BUFFER_SIZE + 1)))
        return (-1);
	
	// Buffer contain line(s)
	if (contain_line(buffer))
	{
		buffer = remove_line_from_buff(buffer, line);
		return (1);
	}
	// Need to read
    readedCnt = read(fd, buffer, BUFFER_SIZE);
	if (readedCnt == BUFFER_SIZE)
    {
		buffer = remove_line_from_buff(buffer, line);
        return (1);
    }
    else if (readedCnt < BUFFER_SIZE && readedCnt > -1)
        return (0);
    else
        return (-1);
}

int main()
{
	printf("1 - Start\n");
    const int fd = open("file.txt", O_RDONLY);
    char *str;
    for (int i; i < 20; i++)
	{
        if (get_next_line(fd, &str))
			printf("Readed: %s\n", str);
	}
	printf("Done\n");
}