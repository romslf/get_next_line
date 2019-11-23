/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rolaforg <rolaforg@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 13:36:14 by rolaforg     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 15:57:25 by rolaforg    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
    size_t      i;
    int         res;
    static char *newBuffer;
    static char *oldBuffer;
    
    i = 0;
    if (!(buffer = malloc(sizeof(char) * BUFFER_SIZE + 1)))
        return (-1);
    buffer[BUFFER_SIZE + 1] = '\0';
    res = read(fd, newBuffer, BUFFER_SIZE);
    if (res == BUFFER_SIZE)
    {
        printf("Readed: %s\n", buffer);
		printf("Complete: %d\n", line_is_complete(line));
        return (1);
    }
    else if (res < BUFFER_SIZE && res > -1)
    {
        printf("Done.\n");
        return (0);
    }
    else
    {
        printf("Err: %s\n", buffer);
        return (-1);
    }
}

int main()
{
    const int fd = open("file.txt", O_RDONLY);
    char *str;
    get_next_line(fd, &str);
    //printf("%s\n", str);
    get_next_line(fd, &str);
    //printf("%s\n", str);
    get_next_line(fd, &str);
    //printf("%s\n", str);
    get_next_line(fd, &str);
    //printf("%s\n", str);
    get_next_line(fd, &str);
}